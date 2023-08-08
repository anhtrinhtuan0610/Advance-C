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

using namespace std;

typedef enum {
    JANITOR,
    RECEPTIONIST,
    LAUNDRY_STAFF,
    LUGGAGE_STAFF,
    GARDENER
} jobPosition;



typedef struct {
    Date date;
    Time time;
    Status status;
} bookingHistory;

class User {
private:
    string username;
    string password;
public:
    User() {
        username = "";
        password = "";}
    User(string username, string password);
    string getUsername();
    bool authenticate(string inputPassword);
};



class Employee {
private:
    string name;
    string phoneNumber;
    jobPosition position;
    bookingHistory bookingHistory;
    bool checkAuthenticate;
    User user;
public:
    Employee(string name, string phoneNumber, jobPosition position, bookingHistory bookingHistory, User user);
    string getName(string inputPassword);
    string getName();
    void setName(string name);
    string getPhoneNumber();
    jobPosition getPosition();
    bookingHistory getbookingHistory();
};


class EmployeeManager {
private:
    vector<Employee> databaseEmployee;
public:
    void addEmployee(Employee employee);
    void removeEmployee();
    void updateEmployee();
    void displayEmployee();
};