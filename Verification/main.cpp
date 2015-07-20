#include <iostream>
#include <cmath>

#include "..\PollardRhoAlg\include\BigIntegerLibrary.hh"

using namespace std;

BigInteger q, a, b, n;
BigInteger e, r, s;

#include "..\PollardRhoAlg\include\point.h"


int main()
{
    //array couted by ecdsa-programm, needs to be copied and pasted
    BigInteger input[11]= {873403, 3597, 8602, 219006, 855195, 437201, 458149, 201734, 405126, 261264, 42};
    q = input[0];
    a = input[1];
    b = input[2];
    Point G(input[3],input[4]);
    n = input[5];
    Point Q(input[6],input[7]);
    r = input[8];
    s = input[9];
    e = input[10];

    //for checking purposes
    cout << "q: "<< q << endl << "a, b: " << a << ", " << b << endl << "G: " << G.x << ", " << G.y << endl << "n: " << n << endl << endl << "Pk Q: " << Q.x << ", " << Q.y << endl << endl << "r, s: " << r << ", " << s << endl << "e: " << e << endl << endl;


    bool check = 1;
        //r,s must be in (1, p-1)
        if (r <1 or r >= n or s<1 or s>=n){
            check = 0;
            cout << "intervall";
        }
        else{
            BigInteger w = invert(s,n);
            BigInteger u1 = (e*w) %n;
            BigInteger u2 = (r*w) %n;
            Point X = G.scalar(u1)+Q.scalar(u2);

            //X may not be O
            if (X.x == q or X.y == q) {
                    check = 0;
                    cout << "Point in Infinity" << endl;
            }
            else {
                    //actual verification
                BigInteger v = X.x %n;
                if (v != r) {
                    check = 0;
                    cout << v << endl;
                    cout << "v != r" << endl;
                }
            }
        }

    if (check == 1){cout << "Good key";}
    else {cout << "BUUUUU";}
    return 42;
}
