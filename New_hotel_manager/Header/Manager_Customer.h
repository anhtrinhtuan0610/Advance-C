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
    string getName();
    void addBookingHistory(bookingHistory bookingDetails);
    void displayBookingHistory();
    string getPhoneNumber();
    string getAddress();
    void setPhoneNumber(string phone);
    void setAddress(string addr);
};
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