#include <iostream>
using namespace std;

class HinhTron {
private:
    double banKinh;

public:
    // Constructor
    HinhTron(double r) {
        banKinh = r;
    }

    // Phương thức tính chu vi của hình tròn
    double tinhChuVi() {
        return 2 * 3.14159 * banKinh;
    }

    // Phương thức tính diện tích của hình tròn
    double tinhDienTich() {
        return 3.14159 * banKinh * banKinh;
    }
};

int main() {
    double banKinh;
    cout << "Nhập bán kính của hình tròn: ";
    cin >> banKinh;

    HinhTron hinhTron(banKinh);

    cout << "Chu vi của hình tròn: " << hinhTron.tinhChuVi() << endl;
    cout << "Diện tích của hình tròn: " << hinhTron.tinhDienTich() << endl;

    return 0;
}