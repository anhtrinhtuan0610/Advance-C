#include <iostream>
using namespace std;

class ToanHoc{
    public: 
        void sum(int a, int b);
        void sum2(int a, int b, int c);
        int tong(int a, double b);
};

void ToanHoc::sum (int a, int b){
   cout<< "tong cua a va b la " << a+b<<endl;
}

void ToanHoc::sum2 (int a, int b, int c){
    cout<< "tong cua a va b la " << a+b+c <<endl;
}
int ToanHoc::tong(int a, double b){
    return a + (int)b;
}
int main(int argc, char const *argv[])
{
    ToanHoc th;
    th.sum(8,2);
    th.sum2(5,2,1);
    cout<< th.tong(3, 5);
    
    
    return 0;
}