#include <iostream>

using namespace std;


class SinhVien{
    public:                                         // public là phạm vy truy cập
    int tuoi;                                      // các biến được khai báo trong class được gọi là property
    int lop;
    void hien_thi()                                // các fuction trong class được gọi là method
    {
        cout << "Hello girls";
    }
};

int main(int argc, char const *argv[])
{
    SinhVien anh;                                    // tạo 1 biến mang tên anh có kiểu class "anh" ở đây được gọi là object
    anh.tuoi = 18;                                   // khởi tạo giá trị 
    anh.lop = 12;

    cout << anh.tuoi <<endl ;
    cout << anh.lop << endl;
    anh.hien_thi();
    return 0;
}
