#include <iostream>
#include <stdint.h>
#include <string.h>
#include <vector>

using namespace std;

typedef struct {
    int Day;
    int Month;
    int Year;
} Date;

typedef struct {
    int second;
    int minute;
    int hour;
} Time;

typedef enum {
    IN,
    OUT
} Status;

typedef struct {
    Date date;
    Time time;
    Status status;  
} bookingHistory;

class Customer {
private:
    uint8_t idRoom;
    string name;
    string phoneNumber;
    string address;
    vector<bookingHistory> bookingHistorys;

public:
    Customer(string customerName, string customerPhone, string customerAddress);
    string getName();
    void addBookingHistory(bookingHistory bookingDetails);
    void displayBookingHistory();
    string getPhoneNumber();
    string getAddress();
    void setPhoneNumber(string phone);
    void setAddress(string addr);
};

Customer::Customer(string customerName, string customerPhone, string customerAddress)
{
    name = customerName;
    phoneNumber = customerPhone;
    address = customerAddress;
}

string Customer::getName()
{
    return name;
}

string Customer::getPhoneNumber()
{
    return phoneNumber;
}

string Customer::getAddress()
{
    return address;
}

void Customer::setPhoneNumber(string phone)
{
    phoneNumber = phone;
}

void Customer::setAddress(string addr)
{
    address = addr;
}

void Customer::addBookingHistory(bookingHistory bookingDetails)
{
    bookingHistorys.push_back(bookingDetails);
}

void Customer::displayBookingHistory()
{
    cout << "Booking History:" << endl;
    for (int i = 0; i < bookingHistorys.size(); i++) {
        cout << "Date: " << bookingHistorys[i].date.Day << "/" << bookingHistorys[i].date.Month << "/" << bookingHistorys[i].date.Year << endl;
        cout << "Time: " << bookingHistorys[i].time.hour << ":" << bookingHistorys[i].time.minute << ":" << bookingHistorys[i].time.second << endl;
        cout << "Status: " << (bookingHistorys[i].status == IN ? "IN" : "OUT") << endl;
        cout << endl;
    }
}

class CustomerManager {
private:
    vector<Customer> databaseCustomers;

public:
    void addCustomer();
    void editCustomer();
    void deleteCustomer();
    void displayCustomerInfo();
    void customerMenu();
};

void CustomerManager::addCustomer()
{
    string customerName;
    string customerPhone;
    string customerAddress;
    cout << "Enter customer name: ";
    cin >> customerName;
    cout << "Enter customer phone number: ";
    cin >> customerPhone;
    cout << "Enter customer address: ";
    cin >> customerAddress;
    Customer customer(customerName, customerPhone, customerAddress);

    databaseCustomers.push_back(customer);
}

void CustomerManager::editCustomer()
{
    string customerName;
    string customerPhone;
    string customerAddress;
    cout << "Please enter the name of the customer you want to edit: ";
    cin >> customerName;

    for (int i = 0; i < databaseCustomers.size(); i++) {
        if (databaseCustomers[i].getName() == customerName) {
            cout << "Customer Information:" << endl;
            cout << "Name: " << databaseCustomers[i].getName() << endl;
            cout << "Phone: " << databaseCustomers[i].getPhoneNumber() << endl;
            cout << "Address: " << databaseCustomers[i].getAddress() << endl;

            cout << "Enter new phone number: ";
            cin >> customerPhone;
            cout << "Enter new address: ";
            cin >> customerAddress;

            databaseCustomers[i].setPhoneNumber(customerPhone);
            databaseCustomers[i].setAddress(customerAddress);

            cout << "Customer information has been updated." << endl;
            return;
        }
    }

    cout << "Customer not found." << endl;
}

void CustomerManager::deleteCustomer()
{
    string customerName;
    cout << "Please enter the name of the customer you want to delete: ";
    cin >> customerName;

    for (int i = 0; i < databaseCustomers.size(); i++) {
        if (databaseCustomers[i].getName() == customerName) {
            databaseCustomers.erase(databaseCustomers.begin() + i);

            cout << "Customer has been deleted." << endl;
            return;
        }
    }

    cout << "Customer not found." << endl;
}

void CustomerManager::displayCustomerInfo()
{
    if (databaseCustomers.empty()) {
        cout << "No customers found." << endl;
        return;
    }

    cout << "Customer Information:" << endl;
    for (int i = 0; i < databaseCustomers.size(); i++) {
        cout << "Customer " << i + 1 << ":" << endl;
        cout << "Name: " << databaseCustomers[i].getName() << endl;
        cout << "Phone: " << databaseCustomers[i].getPhoneNumber() << endl;
        cout << "Address: " << databaseCustomers[i].getAddress() << endl;
        cout << endl;
    }
}

void CustomerManager::customerMenu()
{
    int choice;
    do {
        cout << "------ Customer Management Menu ------" << endl;
        cout << "1. Add Customer" << endl;
        cout << "2. Edit Customer" << endl;
        cout << "3. Delete Customer" << endl;
        cout << "4. Display Customer Information" << endl;
        cout << "5. Exit" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addCustomer();
            break;
        case 2:
            editCustomer();
            break;
        case 3:
            deleteCustomer();
            break;
        case 4:
            displayCustomerInfo();
            break;
        case 5:
            cout << "Exiting Customer Management Menu..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 5);
}

int main(int argc, char const* argv[])
{

        // Tạo một khách hàng mới
    Customer customer("anhtrinh", "1802", "36 Quang Trung Street");

    // Tạo một lịch sử đặt phòng
    bookingHistory booking1;
    booking1.date.Day = 1;
    booking1.date.Month = 1;
    booking1.date.Year = 2022;
    booking1.time.hour = 10;
    booking1.time.minute = 30;
    booking1.time.second = 0;
    booking1.status = IN;

    bookingHistory booking2;
    booking2.date.Day = 2;
    booking2.date.Month = 1;
    booking2.date.Year = 2022;
    booking2.time.hour = 15;
    booking2.time.minute = 0;
    booking2.time.second = 0;
    booking2.status = OUT;

    // Thêm lịch sử đặt phòng vào khách hàng
    customer.addBookingHistory(booking1);
    customer.addBookingHistory(booking2);

    // Hiển thị lịch sử đặt phòng
    customer.displayBookingHistory();
    return 0;
}