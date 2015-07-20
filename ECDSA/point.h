//int q=47;
//int a=34;
//int b=10;

int invert(int x, int mod){
    int k = 0;
    int temp = mod-2;
    int tmp = mod-2;
    while (temp !=0){
        temp = temp/2;
        k++;
    }
    bool z[k];
    int j = 0;
    while (tmp!=0){
        z[j] = tmp%2;
        j++;
        tmp = tmp/2;
    }
    int p = 1;
    for(int m=0; m < k; m++ ){
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
    Point();
    Point(int, int);
    Point operator + (const Point&);
    Point scalar(int);
};

const Point O(q,q);

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
            if (y == param.y && y!=0) {
                    //std::cout << "invert(2*y,q) : " << invert(2*y,q) << std::endl;
                    //std::cout << "3*x*x+a : " << (3*x*x+a)%q << std::endl;
                    //std::cout << "(3*x*x+a)*(invert(2*y,q)*(3*x*x+a)*(invert(2*y,q)) : " << ((((3*x*x+a)*(invert(2*y,q)))%q)*(((3*x*x+a)*(invert(2*y,q)))%q))%q << std::endl;
                R.x= (((((((3*x*x+a)%q)*(invert(2*y,q)))%q)*((((3*x*x+a)%q)*(invert(2*y,q)))%q))%q) - 2*x)%q;
                R.y= (((((3*x*x+a)%q)*(invert(2*y,q)))%q)*(x - R.x) - y)%q;
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

Point Point::scalar(int i){

    Point G(x,y);
    Point p(q,q);
//    for(int j=0;j<i;j++){
//        p=G+p;
//    }
//    return p;

    int k = 0;
    int temp = i;
    while (temp !=0){
        temp = temp/2;
        k++;
    }

    bool z[k];
    int j = 0;
    while (i!=0){
        z[j] = i%2;
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

