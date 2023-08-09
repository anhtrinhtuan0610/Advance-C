/*
* File Name: main.cpp
* Author: Anh Trinh
* Date: 08/08/2023
* Description: This file is a Source file that contains all the prototypes to manager for the hotel
*/


#include <iostream>
#include <stdint.h>
#include <string.h>
#include <vector>
#include "Employee.h"
#include "Manager_Room.h"
#include "Manager_Customer.h"

using namespace std;


int main(int argc, char const *argv[])
{
    roommanager();
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
    

    User admin("admin", "admin");
    Schedule schedule = { {1, 1, 2022}, {0, 0, 0}, IN };
    Employee employee1("anhtrinh", "1802", RECEPTIONIST, schedule, admin);
    EmployeeManager manager;
    manager.addEmployee(employee1);
    manager.displayEmployee();
    manager.removeEmployee();
    manager.displayEmployee();

    return 0;
}

