#include "..\PollardRhoAlg\include\BigIntegerLibrary.hh"

BigInteger countPoints(BigInteger q, BigInteger a, BigInteger b){

    BigInteger counter = 1; // Point of infinity
    BigInteger rhs;

    //Legendre symbol (rhs/q)
    for(BigInteger i=0;i<q;i++){
        rhs = (((i*i)%q)*i+a*i+b)%q;
        BigInteger temp = powmod(rhs,(q-1)/2,q);
        // << "temp ======" << temp.toInt() << endl;
        if(temp == 1)    counter+=2;
        else if(temp == 0)  counter++;

        }
    return counter;
    }

//finds approximate position of number in primes-array (max. deviation is 5)
BigInteger position(BigInteger N) {
    bool Nprime=0;
    BigInteger i= prm/2;
    BigInteger p = prm/2;
    bool pm;
    bool check = 0;
    while (check == 0) {
        if (N<primes[p.toInt()]) { // MAY CAUSE TROUBLE SINCE WE USED toInt() which is less than limit
//            int t = p;
//            p = p-abs(p-p2)/2 ;
//            p2=t;
            i = i/2;
            p = p - i;
        }
        else if (N>primes[p.toInt()]) {
//            int t = p;
//            p = p + abs(p - p2)/2;
//            p2=t;
            i = i/2;
            p = p + i;
        }
        else {
                check = 1;
                Nprime = 1;
        }
        if (i <= 1) {check = 1;}
        //if (abs(p-p2)<=1) {check = 1;}
    }
return (p+5); //just in case
}

//finds largest prime factor of a number
BigInteger factor(BigInteger N) {
//    for (int i=0; i<10; i++){
//        if (N%primes[position(N)-i]==0) {return primes[position(N) - i];}
//    }
//    for (int i=N/2; i>=0; i+=(-1)){
//         if (N%primes[position(i)]==0){return primes[i];}
//    }
BigInteger M=N;
BigInteger p=1;
BigInteger i=0;
while (p!=N){
    if (M%primes [i.toInt()]==0){
        M=M/primes [i.toInt()];
        p=p*primes [i.toInt()];
    }
    else{i++;}
}
return primes[i.toInt()];

//for (BigInteger i = position(N); i>=0; i=i-1) {
//    if (N%primes[i.toInt()]==0){return primes[i.toInt()];}
//}
}
//int factor(int N) {


    //search for largest prime divisor of N


//    float N1 = N/2;
//    float f = N1/(log N1 -1);
//    int ini = (int) f;

//}

