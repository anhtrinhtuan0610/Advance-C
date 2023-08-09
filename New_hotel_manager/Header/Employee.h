/*
* File Name: Employee.h
* Author: Anh Trinh
* Date: 08/08/2023
* Description: This file is a header file that contains all the prototypes to manage Employee for the hotel
*/



#include <iostream>
#include <stdint.h>
#include <string.h>
#include <vector>
#include "Manager_Customer.h"
using namespace std;

typedef enum {
    JANITOR,
    RECEPTIONIST,
    LAUNDRY_STAFF,
    LUGGAGE_STAFF,
    GARDENER
} jobPosition;


class User {
private:
    string username;
    string password;
public:
    User() {
        username = "";
        password = "";}



    User(string username, string password);

    /*
     - Constructor cho lớp User.
     - Tham số:
     - username: tên người dùng.
     - password: mật khẩu của người dùng.
    
    */


    string getUsername();

    /*
    
    
    - Trả về tên người dùng.
    
    
    */


    bool authenticate(string inputPassword);

    /*
     - Xác thực mật khẩu của người dùng.
     - Tham số:
     - inputPassword: mật khẩu được nhập.
     - Trả về true nếu mật khẩu trùng khớp, ngược lại trả về false.
    
    */


};



class Employee {
private:
    string name;
    string phoneNumber;
    jobPosition position;
    bokingHistory schedule;
    bool checkAuthenticate;
    User user;
public:
    Employee(string name, string phoneNumber, jobPosition position, bokingHistory schedule, User user);


    /*
     - Constructor cho lớp Employee.
     - Tham số:
     - name: tên của nhân viên.
     - phoneNumber: số điện thoại của nhân viên.
     - position: vị trí công việc của nhân viên.
     - bookingHistory: lịch sử đặt phòng của nhân viên.
     - user: thông tin người dùng của nhân viên.
    */


    string getName(string inputPassword);

    /*
    
     - Trả về tên của nhân viên.
     - Tham số:
     - inputPassword: mật khẩu được nhập để xác thực.
     - Nếu mật khẩu trùng khớp hoặc là mật khẩu của admin, trả về tên của nhân viên.
     - Nếu xác thực thất bại, trả về một chuỗi rỗng.
    
    */

    string getName();

    /*
     - Trả về tên của nhân viên.
     - Nếu biến checkAuthenticate là true, trả về tên của nhân viên.
     - Nếu biến checkAuthenticate là false, trả về một chuỗi rỗng.

    */


    void setName(string name);

    /*
     - Đặt tên mới cho nhân viên.
     - Tham số:
     - name: tên mới của nhân viên.
    */



    string getPhoneNumber();

    /*
    
     - Trả về số điện thoại của nhân viên.
    
    */



    jobPosition getPosition();


    /*
    
     - Trả về vị trí công việc của nhân viên.
    
    
    */
    bookingHistory getSchedule();

    /*
    
     - Trả về lịch làm việc của nhân viên.
    
    */
};


class EmployeeManager {
private:
    vector<Employee> databaseEmployee;
public:

    void addEmployee(Employee employee);


    /*
     - Thêm một nhân viên vào cơ sở dữ liệu nhân viên.
     - Tham số:
     - employee: nhân viên cần thêm
    */



    void removeEmployee();



    /*
     - Xóa một nhân viên từ cơ sở dữ liệu nhân viên.
     - Yêu cầu người dùng nhập tên của nhân viên cần xóa.
     - Nếu nhân viên được tìm thấy, xóa nhân viên khỏi cơ sở dữ liệu.

    */



    void updateEmployee();

    /*
     - Cập nhật thông tin của một nhân viên trong cơ sở dữ liệu.
     - Yêu cầu người dùng nhập tên của nhân viên cần cập nhật.
     - Nếu nhân viên được tìm thấy, yêu cầu người dùng nhập tên mới cho nhân viên và cập nhật thông tin.
    */




    void displayEmployee();

    /*
     - Hiển thị thông
    
    */

};