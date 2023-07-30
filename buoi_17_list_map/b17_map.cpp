#include <iostream>
#include <list>
#include <map>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    map<string, string> sinhvien;

    sinhvien["name"] = "anh";
    sinhvien["age"] = "12";
    sinhvien["msv"] = "2001";

    for(auto i: sinhvien){
        cout << "key: " << i.first << ", value: " << i.second << endl;
    }
    return 0;
}