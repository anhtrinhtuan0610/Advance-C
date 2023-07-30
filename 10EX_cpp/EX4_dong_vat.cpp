#include <iostream>
using namespace std;

class DongVat {
public:
    string ten;
    int tuoi;
    double trongLuong;

    // Constructor
    DongVat(string t, int tu, double tl) {
        ten = t;
        tuoi = tu;
        trongLuong = tl;
    }

    // Phương thức tính chỉ số BMI
    double tinhBMI() {
        double chieuCao = 1.5; // Giả sử chiều cao cố định là 1.5m
        return trongLuong / (chieuCao * chieuCao);
    }

    // Phương thức so sánh tuổi với động vật khác
    void soSanhTuoi(DongVat dongVatKhac) {
        if (tuoi > dongVatKhac.tuoi) {
            cout << ten << " lớn tuổi hơn " << dongVatKhac.ten << endl;
        } else if (tuoi < dongVatKhac.tuoi) {
            cout << ten << " nhỏ tuổi hơn " << dongVatKhac.ten << endl;
        } else {
            cout << ten << " cùng tuổi với " << dongVatKhac.ten << endl;
        }
    }

    // Phương thức so sánh trọng lượng với động vật khác
    void soSanhTrongLuong(DongVat dongVatKhac) {
        if (trongLuong > dongVatKhac.trongLuong) {
            cout << ten << " nặng hơn " << dongVatKhac.ten << endl;
        } else if (trongLuong < dongVatKhac.trongLuong) {
            cout << ten << " nhẹ hơn " << dongVatKhac.ten << endl;
        } else {
            cout << ten << " cùng trọng lượng với " << dongVatKhac.ten << endl;
        }
    }
};

int main() {
    DongVat dongVat1("Chó", 5, 10.5);
    DongVat dongVat2("Mèo", 3, 5.2);

    double bmi1 = dongVat1.tinhBMI();
    double bmi2 = dongVat2.tinhBMI();

    cout << "Chỉ số BMI của " << dongVat1.ten << ": " << bmi1 << endl;
    cout << "Chỉ số BMI của " << dongVat2.ten << ": " << bmi2 << endl;

    dongVat1.soSanhTuoi(dongVat2);
    dongVat1.soSanhTrongLuong(dongVat2);

    return 0;
}