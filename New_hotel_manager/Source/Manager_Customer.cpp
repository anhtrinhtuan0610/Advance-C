/*
* File Name: Manager_Customer.cpp
* Author: Anh Trinh
* Date: 08/08/2023
* Description: This file is a Source file that contains all the prototypes to manage customer for the hotel
*/



#include <iostream>
#include <stdint.h>
#include <string.h>
#include <vector>
#include "Manager_Customer.h"
#include "Manager_Room.h"
#include "Employee.h"
using namespace std;


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
