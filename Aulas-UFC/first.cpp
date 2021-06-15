//include em c++

#include <iostream>

class frac{
    int num, den;
    public:
    frac(int a, int b){
        num=a;
        den=b;
    }
    void print(){
        std::cout << num << '/'
                    << den;
    }
};
class x;

int main(){
    frac f (4,36);
}