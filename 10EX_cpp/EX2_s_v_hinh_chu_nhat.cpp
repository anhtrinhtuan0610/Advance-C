#include <iostream>
#include<math.h>

class HinhChuNhat {
private:
    float chieuDai;
    float chieuRong;

public:
    // Constructor
    HinhChuNhat(float dai, float rong) {
        chieuDai = dai;
        chieuRong = rong;
    }

    // Phương thức tính chu vi
    float tinhChuVi() {
        return 2 * (chieuDai + chieuRong);
    }

    // Phương thức tính diện tích
    float tinhDienTich() {
        return chieuDai * chieuRong;
    }

    // Phương thức tính đường chéo
    float tinhDuongCheo() {
        return sqrt(pow(chieuDai, 2) + pow(chieuRong, 2));
    }

    // Phương thức kiểm tra xem có phải hình vuông hay không
    bool laHinhVuong() {
        if (chieuDai == chieuRong) {
            return true;
        }
        return false;
    }
};

int main() {
    float dai, rong;
    std::cout << "Nhap chieu dai cua hinh chu nhat: ";
    std::cin >> dai;
    std::cout << "Nhap chieu rong cua hinh chu nhat: ";
    std::cin >> rong;

    HinhChuNhat hcn(dai, rong);

    std::cout << "Chu vi cua hinh chu nhat la: " << hcn.tinhChuVi() << std::endl;
    std::cout << "Dien tich cua hinh chu nhat la: " << hcn.tinhDienTich() << std::endl;
    std::cout << "Duong cheo cua hinh chu nhat la: " << hcn.tinhDuongCheo() << std::endl;

    if (hcn.laHinhVuong()) {
        std::cout << "Day la hinh vuong." << std::endl;
    } else {
        std::cout << "Day khong phai la hinh vuong." << std::endl;
    }

    return 0;
}