//Find the inverse of x in F_mod
int invert(int x, int mod){

    int k = 0;
    int temp = mod-2; // -2 because of the littel fermat theorem
    int tmp = mod-2;
    while (temp !=0){ // find size of the array
        temp = temp/2;
        k++;
    }
    bool z[k];
    int j = 0;
    while (tmp!=0){ // create binary array representation of the number, (it is flipped)
        z[j] = tmp%2;
        j++;
        tmp = tmp/2;
    }
    int p = 1;
    for(int m=0; m < k; m++ ){ // use binary array to create the inverse
        if(z[m]==1){
            p= (p*x)%mod;
        }
        x = (x*x)%mod;
    }
    return p;
}

int powmod(int base, int exp, int mod) {
    int k = 0;
    int temp = exp;
    while (temp !=0){
        temp = temp/2;
        k++;
    }
    bool z[k];
    int j = 0;
    while (exp!=0){
        z[j] = exp%2;
        j++;
        exp = exp/2;
    }
    int p = 1;
    for(int m=0; m < k; m++ ){
        if(z[m]==1){
            p= (p*base)%mod;
        }
        base = (base*base)%mod;
    }
    return p;
}

int power(int base, int exp) {
    int k = 0;
    int temp = exp;
    while (temp !=0){
        temp = temp/2;
        k++;
    }
    bool z[k];
    int j = 0;
    while (exp!=0){
        z[j] = exp%2;
        j++;
        exp = exp/2;
    }
    int p = 1;
    for(int m=0; m < k; m++ ){
        if(z[m]==1){
            p= (p*base);
        }
        base = (base*base);
    }
    return p;
}


class Point{
public:
    int x, y;

    //constructor
    Point();
    Point(int, int);

    Point operator + (const Point&);

    //operations
    //Point add(Point, Point);
    Point scalar(int);
};

Point::Point(){
    x=1;
    y=2;
}

Point::Point(int x1, int y1){
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
            if (y == param.y and y != 0) {
                R.x= ((((3*x*x+a)*(invert(2*y,q)))*((3*x*x+a)*(invert(2*y,q)))) - 2*x)%q;
                R.y= (((3*x*x+a)*(invert(2*y,q)))*(x - R.x) - y)%q;
            }
            else {
                R.x=q;
                R.y=q;
            }
    }
    else {
    R.x= (((param.y - y)*(invert(param.x - x,q)))*((param.y - y)*(invert(param.x - x,q))) - x - param.x)%q;
    R.y= (((param.y - y)*(invert(param.x - x,q)))*(x - R.x) - y)%q;
    }

    if (R.x<0){
        R.x=q+R.x;
    }
    if (R.y<0){
        R.y=q+R.y;
    }
    return R;
}

//Point Point::add(Point P, Point Q) {
//    Point R;
//
//    //check if point in infinity (O)
//    if (P.x == q) {
//        R.x=Q.x;
//        R.y=Q.y;
//    }
//    else if (Q.x == q) {
//        R.x = P.x;
//        R.y = P.y;
//    }
//
//    //check if x-coordinate is equal
//    else if (P.x == Q.x) {
//
//            //adding a point to itself
//            if (y == Q.y and y != 0) {
//                R.x= ((((3*P.x*P.x+a)*(invert(2*P.y,q)))*((3*P.x*P.x+a)*(invert(2*P.y,q)))) - 2*P.x)%q;
//                R.y= (((3*P.x*P.x+a)*(invert(2*P.y,q)))*(P.x - R.x) - P.y)%q;
//            }
//
//            //adding a point and its inverse
//            else {
//                R.x=q;
//                R.y=q;
//            }
//    }
//
//    //normal addition
//    else {
//    R.x= (((Q.y - P.y)*(invert((Q.x - P.x),q)))*((Q.y - P.y)*(invert((Q.x - P.x),q))) - P.x - Q.x)%q;
//    R.y= (((Q.y - P.y)*(invert((Q.x - P.x),q)))*(P.x - R.x) - P.y)%q;
//    }
//
//    //check if result is negative
//    if (R.x<0){
//        R.x=q+R.x;
//    }
//    if (R.y<0){
//        R.y=q+R.y;
//    }
//    return R;
//}

//multiplication
Point Point::scalar(int i){
    Point G(x,y);
    Point p(q,q);

    for (int j=0; j<i; j++){
        p=p+G;
    }



//
//    int k = 0;
//    int temp = i;
//    while (temp !=0){
//        temp = temp/2;
//        k++;
//    }
//    bool z[k];
//    int j = 0;
//    while (i!=0){
//        z[j] = i%2;
//        j++;
//        i = i/2;
//    }
//
//    for(int m=0; m < k; m++ ){
//        if(z[m]==1){
//            p = p+G;
//        }
//        G = G+G;
//    }
    return p;
}
