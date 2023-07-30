#include <iostream>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    list <int> array;

    array.push_back(4);
    array.push_back(2);
    array.push_back(7);

    for(int x : array){
        cout << x << endl;
    }
    return 0;
}