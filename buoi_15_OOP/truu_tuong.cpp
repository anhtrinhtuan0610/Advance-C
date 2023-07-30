#include <iostream>
using namespace std;class A {
public:
    // khai bao constructor
    A(int i = 0)
    {
        tong = i;
    }
    // du lieu ma la nhin thay voi ben ngoai
    void congThem(int motso)
    {
        tong += motso;
    }
    // du lieu ma la nhin thay voi ben ngoai
    int tinhTong()
    {
        return tong;
    };
private:
    // du lieu ma la bi an voi ben ngoai
    int tong;
};
int main()
{
    A a;
 
    a.congThem(10);
    a.congThem(20);
    a.congThem(50);
    cout << "Tong gia tri la: " << a.tinhTong() << endl;
    return 0;
}