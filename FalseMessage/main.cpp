#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;

#include "..\PollardRhoAlg\include\BigIntegerLibrary.hh"

BigInteger input[11]= {874403, 3597, 8602, 219006, 855195, 437201, 216161, 405157, 275592, 44419, 42};

BigInteger q = input[0];
BigInteger a = input[1];
BigInteger b = input[2];
BigInteger n = input[5];
BigInteger r = input[8];
BigInteger s = input[9];
BigInteger e = input[10];

#include "..\PollardRhoAlg\include\point.h"

Point G(input[3],input[4]);
Point Q(input[6],input[7]);


int main()
{
srand (time(NULL));

    BigInteger d = 29530;
    e = 45;

//Signing
    BigInteger k,k1,r,s;
    bool check = 1;//not necessary ?
    while (check == 1) {
    while (check == 1) {
    //ephemeral k
    k = rand();
    k = k % (n-1) + 1;

    Point R = G.scalar(k);

    r = R.x % n;

    if (r != 0) {check = 0;}
    }

    check = 1;
    k1 = invert(k, n);
    s = (k1 * (e + d*r)%n )% n;
    if (s != 0) {check = 0;}
    }
    cout << "{"<< q << ", " << a << ", " << b << ", " << G.x << ", " << G.y << ", " << n << ", " << Q.x << ", " << Q.y << ", " << r << ", " << s << ", " << e << "};"<< endl;
}
