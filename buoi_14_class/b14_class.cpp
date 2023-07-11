#include <iostream>

using namespace std;


class SinhVien{
    public:
    void setthongtin();
    void hien_thi();

    private:
    string name;
    int tuoi;
    int lop;
};

void SinhVien::setthongtin(){
    cout << "Please enter your name : .....";
    cin >> name;
    cout << "Please enter your age: ...";
    cin >> tuoi;
    cout << "please enter your class: ...";
    cin >> lop;
}

void SinhVien::hien_thi(){
    cout << "TEN: " << name <<endl;
    cout << "TUOI: " << tuoi <<endl;
    cout << "LOP: " << lop<< endl;
}
    

    

int main(int argc, char const *argv[])
{
    SinhVien anh;
    anh.setthongtin();
    anh.hien_thi();
    return 0;
}

