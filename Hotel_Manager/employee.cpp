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
} Schedule;

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

class Employee {
private:
    string name;
    string phoneNumber;
    jobPosition position;
    Schedule schedule;
    bool checkAuthenticate;
    User user;
public:
    Employee(string name, string phoneNumber, jobPosition position, Schedule schedule, User user);
    string getName(string inputPassword);
    string getName();
    void setName(string name);
    string getPhoneNumber();
    jobPosition getPosition();
    Schedule getSchedule();
};

Employee::Employee(string name, string phoneNumber, jobPosition position, Schedule schedule, User user) {
    this->name = name;
    this->phoneNumber = phoneNumber;
    this->position = position;
    this->schedule = schedule;
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

class EmployeeManager {
private:
    vector<Employee> databaseEmployee;
public:
    void addEmployee(Employee employee);
    void removeEmployee();
    void updateEmployee();
    void displayEmployee();
};

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
        cout << "Schedule: " << endl;
        cout << "  Date: " << databaseEmployee[i].getSchedule().date.Day << "/" << databaseEmployee[i].getSchedule().date.Month << "/" << databaseEmployee[i].getSchedule().date.Year << endl;
        cout << "  Time: " << databaseEmployee[i].getSchedule().time.hour << ":" << databaseEmployee[i].getSchedule().time.minute << ":" << databaseEmployee[i].getSchedule().time.second << endl;
        cout << "  Status: " << (databaseEmployee[i].getSchedule().status == IN ? "IN" : "OUT") << endl;
        cout << endl;
    }
}

int main() {
    User admin("admin", "admin");
    Schedule schedule = { {1, 1, 2022}, {0, 0, 0}, IN };
    Employee employee1("John Doe", "123456789", RECEPTIONIST, schedule, admin);
    EmployeeManager manager;
    manager.addEmployee(employee1);
    manager.displayEmployee();
    manager.removeEmployee();
    manager.displayEmployee();
    return 0;
}