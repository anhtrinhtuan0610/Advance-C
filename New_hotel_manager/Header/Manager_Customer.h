/*
* File Name: Manager_customer.h
* Author: Anh Trinh
* Date: 08/08/2023
* Description: This file is a header file that contains all the prototypes to manage customer for the hotel
*/

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
    /*
     - Constructor cho lớp Customer.
     - Tham số:
     - customerName: tên của khách hàng.
     - customerPhone: số điện thoại của khách hàng.
     - customerAddress: địa chỉ của khách hàng.
    
    */




    string getName();
    /*- Trả về tên của khách hàng.*/




    void addBookingHistory(bookingHistory bookingDetails);
    /*
     - Thêm một lịch sử đặt phòng vào danh sách lịch sử đặt phòng của khách hàng.
     - Tham số:
     - bookingDetails: thông tin lịch sử đặt phòng cần thêm.
    
    
    */



    void displayBookingHistory();


    /*
    
    - Hiển thị tất cả lịch sử đặt phòng của khách hàng.
    
    
    
    */
    string getPhoneNumber();


    /*
     - Trả về số điện thoại của khách hàng.
    
    */
    string getAddress();

    /*
     - Trả về địa chỉ của khách hàng.
    
    */
    void setPhoneNumber(string phone);

    /*
     - Đặt số điện thoại mới cho khách hàng.
     - Tham số:
     - phone: số điện thoại mới.
    
    */
    void setAddress(string addr);

    /*
     - Đặt địa chỉ mới cho khách hàng.
     - Tham số:
     - addr: địa chỉ mới.
    
    */
};
class CustomerManager {
private:
    vector<Customer> databaseCustomers;

public:
    void addCustomer();

    /*
     - Thêm một khách hàng mới vào cơ sở dữ liệu khách hàng.
     - Yêu cầu người dùng nhập tên, số điện thoại và địa chỉ của khách hàng.
    
    */
    void editCustomer();

    /*
     - Chỉnh sửa thông tin của một khách hàng đã tồn tại.
     - Yêu cầu người dùng nhập tên của khách hàng cần chỉnh sửa.
     - Nếu khách hàng được tìm thấy, yêu cầu người dùng nhập số điện thoại và địa chỉ mới.
     - Cập nhật thông tin của khách hàng.
    */

    void deleteCustomer();

    /*
     - Xóa một khách hàng đã tồn tại khỏi cơ sở dữ liệu khách hàng.
     - Yêu cầu người dùng nhập tên của khách hàng cần xóa.
     - Nếu khách hàng được tìm thấy, xóa khách hàng khỏi cơ sở dữ liệu.
    
    */


    void displayCustomerInfo();
    /*
    
     - Hiển thị thông tin của tất cả khách hàng trong cơ sở dữ liệu khách hàng.
    
    */
    void customerMenu();

    /*
     - Hiển thị menu quản lý khách hàng và xử lý lựa chọn của người dùng.
     - Cung cấp các tùy chọn để thêm, chỉnh sửa, xóa hoặc hiển thị thông tin khách hàng.
     - Thoát khỏi menu khi người dùng chọn thoát.
    
    
    */
};