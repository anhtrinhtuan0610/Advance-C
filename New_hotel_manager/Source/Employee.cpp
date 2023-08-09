/*
* File Name: Employee.cpp
* Author: Anh Trinh
* Date: 08/08/2023
* Description: This file is a Source file that contains all the prototypes to Employee for the hotel
*/



#include <iostream>
#include <stdint.h>
#include <string.h>
#include <vector>
#include "Manager_Customer.h"
#include "Manager_Room.h"
#include "Employee.h"

using namespace std;



User::User(string username, string password) {
    this->username = username;
    this->password = password;
}

string User::getUsername() {
    return username;
}

bool User::authenticate(string inputPassword) {
    return inputPassword == password;
}



Employee::Employee(string name, string phoneNumber, jobPosition position, bookingHistory bookingHistory, User user) {
    this->name = name;
    this->phoneNumber = phoneNumber;
    this->position = position;
    this->bookingHistory = bookingHistory;
    this->user = user;
    this->checkAuthenticate = true; // Set checkAuthenticate to true initially
}

string Employee::getName(string inputPassword) {
    if (user.authenticate(inputPassword) || inputPassword == "admin") {
        checkAuthenticate = false;
        return this->name;
    }
    return ""; // Return an empty string if authentication fails
}

string Employee::getName() {
    if (checkAuthenticate == true) {
        return this->name;
    }
    return ""; // Return an empty string if checkAuthenticate is false
}

void Employee::setName(string name) {
    this->name = name;
}

string Employee::getPhoneNumber() {
    return phoneNumber;
}

jobPosition Employee::getPosition() {
    return position;
}

Schedule Employee::getSchedule() {
    return schedule;
}


void EmployeeManager::addEmployee(Employee employee) {
    databaseEmployee.push_back(employee);
}

void EmployeeManager::removeEmployee() {
    string name;
    cout << "Enter the name of the employee you want to remove: ";
    cin >> name;

    for (int i = 0; i < databaseEmployee.size(); i++) {
        if (databaseEmployee[i].getName() == name) {
            databaseEmployee.erase(databaseEmployee.begin() + i);
            cout << "Employee " << name << " has been removed." << endl;
            return;
        }
    }

    cout << "Employee " << name << " not found." << endl;
}

void EmployeeManager::updateEmployee() {
    string name;
    cout << "Enter the name of the employee you want to update: ";
    cin >> name;

    for (int i = 0; i < databaseEmployee.size(); i++) {
        if (databaseEmployee[i].getName() == name) {
            string newName;
            cout << "Enter the new name for the employee: ";
            cin >> newName;
            databaseEmployee[i].setName(newName);
            cout << "Employee " << name << " has been updated to " << newName << "." << endl;
            return;
        }
    }

    cout << "Employee " << name << " not found." << endl;
}

void EmployeeManager::displayEmployee() {
    for (int i = 0; i < databaseEmployee.size(); i++) {
        cout << "Employee " << i + 1 << ":" << endl;
        cout << "Name: " << databaseEmployee[i].getName() << endl;
        cout << "Phone Number: " << databaseEmployee[i].getPhoneNumber() << endl;
        cout << "Position: " << databaseEmployee[i].getPosition() << endl;
        cout << "BookingHistory: " << endl;
        cout << "  Date: " << databaseEmployee[i].getbookingHistory().date.Day << "/" << databaseEmployee[i].getbookingHistory().date.Month << "/" << databaseEmployee[i].getSchedule().date.Year << endl;
        cout << "  Time: " << databaseEmployee[i].getbookingHistory().time.hour << ":" << databaseEmployee[i].getbookingHistory().time.minute << ":" << databaseEmployee[i].getSchedule().time.second << endl;
        cout << "  Status: " << (databaseEmployee[i].getbookingHistory().status == IN ? "IN" : "OUT") << endl;
        cout << endl;
    }
}
