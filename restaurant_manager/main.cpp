#include <iostream>
#include <list>
#include <cstdint>
using namespace std;

typedef enum {
    QUAN_LY = 1,
    NHANVIEN = 2,
} TypeSelection;

class Mon {
private:
    uint8_t ID;
    string TEN;
    double GIA;

    void setTen();
    void setGia();
public:
    Mon(uint8_t id, string ten, double gia);
    void setID();
    int getID();
    string getTen();
    double getGia();
    void getDanhSachMon();
};

Mon::Mon(uint8_t id, string ten, double gia) {
    this->ID = id;
    this->TEN = ten;
    this->GIA = gia;
}

void Mon::getDanhSachMon() {
    cout << "ID: " << getID() << endl;
    cout << "Ten mon an: " << getTen() << endl;
    cout << "Gia: " << getGia() << endl;
}

void Mon::setID() {
    static int id = 100;
    this->ID = id;
    id++;
}

int Mon::getID() {
    return this->ID;
}

string Mon::getTen() {
    return this->TEN;
}

double Mon::getGia() {
    return this->GIA;
}

class QuanLy {
private:
    int SOBAN;
    void themMon();
    void suaMon();
    void xoaMon();
    void thietlapSoBan();
public:
    list<Mon> DATABASE;
    QuanLy();
    list<Mon>& getDatabase();
    int getSoBan();
    void Select_Quanly();
    void hienThiDanhSachMon();
};

QuanLy::QuanLy() {
    SOBAN = 0;
}

list<Mon>& QuanLy::getDatabase() {
    return this->DATABASE;
}

void QuanLy::thietlapSoBan() {
    int soban;
    cout << "Nhap vao so ban an: " << endl;
    cin >> soban;
    QuanLy::SOBAN = soban;
}

int QuanLy::getSoBan() {
    return this->SOBAN;
}

void QuanLy::hienThiDanhSachMon() {
    if (DATABASE.empty()) {
        cout << "Danh sach mon an rong!" << endl;
        return;
    }

    for (auto mon : DATABASE) {
        mon.getDanhSachMon();
    }
}

void QuanLy::themMon() {
    string ten;
    double gia;
    cout << "Nhap vao ten mon an moi: " << endl;
    cin >> ten;
    cout << "Nhap gia mon an moi: " << endl;
    cin >> gia;

    Mon newMon(0, ten, gia);
    newMon.setID();
    DATABASE.push_back(newMon);
    cout << "Da them mon moi!" << endl;
}

void QuanLy::suaMon() {
    int id;
    cout << "Nhap vao ID mon can sua: " << endl;
    cin >> id;

    for (auto& mon : DATABASE) {
        if (mon.getID() == id) {
            string ten;
            double gia;

            cout << "Nhap vao ten mon an moi: " << endl;
            cin >> ten;
            cout << "Nhap vao gia mon an moi: " << endl;
            cin >> gia;

            mon = Mon(id, ten, gia);
            cout << "Da sua mon thanh cong!" << endl;
            return;
        }
    }

    cout << "Khong tim thay mon an voi ID da cho!" << endl;
}

void QuanLy::xoaMon() {
    int id;
    cout << "Nhap vao ID mon can xoa: " << endl;
    cin >> id;

    for (auto it = DATABASE.begin(); it != DATABASE.end(); ++it) {
        if (it->getID() == id) {
            DATABASE.erase(it);
            cout << "Da xoa mon thanh cong!" << endl;
            return;
        }
    }

    cout << "Khong tim thay mon an voi ID da cho!" << endl;
}

void QuanLy::Select_Quanly() {
    while (true) {
        int phim;
        cout << "1. Them mon" << endl;
        cout << "2. Sua mon" << endl;
        cout << "3. Xoa mon" << endl;
        cout << "4. Danh sach mon" << endl;
        cout << "5. Thiet lap so ban" << endl;
        cout << "0. Quay lai" << endl;
        cout << "Vui long chon: " << endl;
        cin >> phim;

        switch (phim) {
        case 1:
            themMon();
            break;
        case 2:
            suaMon();
            break;
        case 3:
            xoaMon();
            break;
        case 4:
            hienThiDanhSachMon();
            break;
        case 5:
            thietlapSoBan();
            break;
        case 0:
            return;
        default:
            break;
        }
    }
}

class thongTinBan {
private:
    uint8_t SOBAN;
    bool TRANGTHAI;
    typedef struct {
        Mon MON_AN;
        int SO_LUONG;
    } TypeMon;
    list<TypeMon> DATABASE_MON;
public:
    thongTinBan(uint8_t soban, bool trangthai);
    int getSoBan();
    bool getTrangThai();
    void setTrangThai();
    void getDanhSachMon();
    void themMon(list<Mon>& database, thongTinBan& a);
    void suaMon(int id, int soLuong);
    void xoaMon(int id);
};

thongTinBan::thongTinBan(uint8_t soban, bool trangthai) {
    this->SOBAN = soban;
    this->TRANGTHAI = trangthai;
}

int thongTinBan::getSoBan() {
    return thongTinBan::SOBAN;
}

void thongTinBan::setTrangThai() {
    thongTinBan::TRANGTHAI = true;
}

bool thongTinBan::getTrangThai() {
    return thongTinBan::TRANGTHAI;
}

void thongTinBan::getDanhSachMon() {
    for (auto mon : DATABASE_MON) {
        cout << "Mon an: " << mon.MON_AN.getTen() << endl;
        cout << "So luong: " << mon.SO_LUONG << endl;
    }
}

void thongTinBan::themMon(list<Mon>& database, thongTinBan& a) {
    int id;
    int soluong;
    cout << "Nhap vao ID mon an: " << endl;
    cin >> id;
    cout << "Nhap vao so luong: " << endl;
    cin >> soluong;

    for (auto mon : database) {
        if (mon.getID() == id) {

            cout << "Da them mon moi!" << endl;
            return;
        }
    }

    cout << "Khong tim thay mon an voi ID da cho!" << endl;
}

void thongTinBan::suaMon(int id, int soLuong) {
    for (auto& mon : DATABASE_MON) {
        if (mon.MON_AN.getID() == id) {
            mon.SO_LUONG = soLuong;
            cout << "Da sua mon thanh cong!" << endl;
            return;
        }
    }

    cout << "Khong tim thay mon an voi ID da cho!" << endl;
}

void thongTinBan::xoaMon(int id) {
    for (auto it = DATABASE_MON.begin(); it != DATABASE_MON.end(); ++it) {
        if (it->MON_AN.getID() == id) {
            DATABASE_MON.erase(it);
            cout << "Da xoa mon thanh cong!" << endl;
            return;
        }
    }

    cout << "Khong tim thay mon an voi ID da cho!" << endl;
}
int main(int argc, char const *argv[])
{   QuanLy quanLy;
    thongTinBan ban(1, false);

    while (true) {
        int phim;
        cout << "1. Quan ly" << endl;
        cout << "2. Nhan vien" << endl;
        cout << "0. Thoat" << endl;
        cout << "Vui long chon: " << endl;
        cin >> phim;

        switch (phim) {
        case QUAN_LY:
            quanLy.Select_Quanly();
            break;
        case NHANVIEN:
            if (ban.getTrangThai()) {
                ban.getDanhSachMon();
            }
            else {
                cout << "Ban an chua duoc mo!" << endl;
            }
            break;
        case 0:
            return 0;
        default:
            break;
        }
    }

    return 0;
}
