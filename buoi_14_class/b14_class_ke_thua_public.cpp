#include <iostream>

using namespace std;

class DoiTuong{
    public:
    string name;
    int age;
    int grape;
    void NhapThongTin(string name, int age, int grape);
    void hienthi();

    private:
    
};

void DoiTuong::NhapThongTin(string name, int age, int grape){
    cout <<"This is Class DoiTuong!\n";                                    
    DoiTuong::name = name;                              // vì trong chương trình có input parameter tên là name lên cần xác định rõ xem name ở đây là gì
    DoiTuong::age = age;
    DoiTuong::grape = grape;
}
void DoiTuong::hienthi(){
    cout << "This is Class DoiTuong!\n";
    cout << name << endl;
    cout << age << endl;
    cout << grape << endl;

}
class SinhVien : public DoiTuong{
    public:
    int mssv;
    void NhapThongTin(string name, int age, int grape, int mssv);
    void hienthi();

    private:

};

void SinhVien::NhapThongTin(string name, int age, int grape, int mssv){
    cout <<"This is Class SinhVien!\n";                                    
    SinhVien::name = name;                              // vì trong chương trình có input parameter tên là name lên cần xác định rõ xem name ở đây là gì
    SinhVien::age = age;
    SinhVien::grape = grape;
    SinhVien::mssv = mssv;

}
void SinhVien::hienthi(){
    cout << "This is Class SinhVien!\n";
    cout << name << endl;
    cout << age << endl;
    cout << grape << endl;
    cout << mssv << endl;

}

int main(int argc, char const *argv[])
{
    SinhVien sv;
    sv.NhapThongTin("anh",18,12,1102);
    sv.hienthi();
    return 0;
}
