#include "BigIntegerLibrary.hh"

//BigInteger q=3037;
//BigInteger a=1609;
//BigInteger b=1709;

BigInteger invert(BigInteger x, BigInteger mod){
    int k = 0;
    BigInteger temp=mod-2;
    BigInteger tmp=mod-2;
    while (temp != 0){
        temp = temp/2;
        k++;
    }
    bool z[k];
    int j = 0;
    while (tmp!= 0){
        z[j] = (tmp%2).toInt();
        j++;
        tmp = tmp/2;
    }
    BigInteger p = 1;
    for(int m=0; m < k; m++ ){
        if(z[m]==1){
            p= (p*x)%mod;
        }
        x = (x*x)%mod;
    }
    return p;
}

BigInteger powmod(BigInteger base, BigInteger exp, BigInteger mod) {
    int k = 0;
    BigInteger temp = exp;
    while (temp !=0){
        temp = temp/2;
        k++;
    }
    bool z[k];
    int j = 0;
    while (exp != 0){
        z[j] = (exp%2).toInt();
        j++;
        exp = exp/2;
    }
    BigInteger p = 1;
    for(int m=0; m < k; m++ ){
        if(z[m]==1){
            p= (p*base)%mod;
        }
        base = (base*base)%mod;
    }
    return p;
}



class Point{
public:
    BigInteger x, y;
    Point();
    Point(BigInteger, BigInteger);
    Point operator + (const Point&);
    Point scalar(BigInteger);
};

const Point O(q,q);

Point::Point(){
    x=1;
    y=2;
}

Point::Point(BigInteger x1, BigInteger y1){
    x=x1;
    y=y1;
}

Point Point::operator + (const Point& param){
    Point R;

    if (x == q) {
        R.x=param.x;
        R.y=param.y;
    }
    else if (param.x == q) {
        R.x = x;
        R.y = y;
    }
    else if (x == param.x) {
            if (y == param.y && y!=0) {
                    //std::cout << "invert(2*y,q) : " << invert(2*y,q) << std::endl;
                    //std::cout << "3*x*x+a : " << (3*x*x+a)%q << std::endl;
                    //std::cout << "(3*x*x+a)*(invert(2*y,q)*(3*x*x+a)*(invert(2*y,q)) : " << ((((3*x*x+a)*(invert(2*y,q)))%q)*(((3*x*x+a)*(invert(2*y,q)))%q))%q << std::endl;
                R.x= (((((((x*x*3+a)%q)*(invert(y*2,q)))%q)*((((x*x*3+a)%q)*(invert(y*2,q)))%q))%q) - x*2)%q;
                R.y= ((((x*x*3+a)*(invert(y*2,q)))%q)*(x - R.x) - y)%q;
            }
            else {
                R.x=q;
                R.y=q;
            }
    }
    else {
    //std::cout << "(invert(param.x - x,q)) : " << (invert(param.x - x,q)) << std::endl;
    //std::cout << "3*x*x+a : " << (3*x*x+a)%q << std::endl;
    R.x= (((((param.y - y)*(invert(param.x - x,q)))%q)*(((param.y - y)*(invert(param.x - x,q)))%q)) - x - param.x)%q;
    R.y= ((((param.y - y)*(invert(param.x - x,q)))%q)*(x - R.x) - y)%q;
    }
    if (R.x<0){
        R.x=q+R.x;
    }
    if (R.y<0){
        R.y=q+R.y;
    }
    return R;
}

Point Point::scalar(BigInteger i){

    Point G(x,y);
    Point p(q,q);

//    for(BigInteger j=0;j<i;j++){
//        p=G+p;
//    }
//    return p;

    int k = 0;
    BigInteger temp = i;
    while (temp !=0){
        temp = temp/2;
        k++;
    }

    int z[k];
    int j = 0;
    while (i!=0){
        z[j] = (i%2).toInt();
        j++;
        i = i/2;
    }

    for(int m=0; m < k; m++ ){
        if(z[m]==1){
            p = p+G;
        }
        G = G+G;
    }
    return p;

}

