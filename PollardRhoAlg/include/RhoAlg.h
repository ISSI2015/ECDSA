#include "point.h"

int alpha = 0;
int beta = 0;
int gamma = 0;
int delta = 0;

int findOrder(Point G){
    int counter=0;
    while(G.x!=q){
        G = G + G;
        counter++;
    }
}

//Pollard Rho Attack returns m s.t. G^m=Q when order of G equals n
int pollardAttack(Point G, Point Q, int n){
    Point z = O;
    Point y = O;
    do{ Point z = f(z, G, Q);
        Point w = g(g(w, G, Q), G, Q);
    }while(z!=w)
    int m = (alpha-gamma)*invert((delta-beta),n);
    return m;
}

Point f(Point z, Point x, Point y){
    if(z.x<q/3) {alpha++; return x + z;}
    if(z.x>q/3) {alpha = 2*alpha; beta = 2*beta; return y + z;}
    beta++; return z + z;
}

Point g(Point z, Point x, Point y){
    if(z.x<q/3) {gamma++; return x + z;}
    if(z.x>q/3) {gamma = 2*gamma; delta = 2*delta; return y + z;}
    delta++; return z + z;
}
