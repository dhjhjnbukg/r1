#include <iostream>
using namespace std;
int main() {
    int i;
    i = 69;
    int number = 72;
    i = 69 + number;
    int arr[3] = {};
    int* iPointer = &i;
    number = *iPointer;
    *iPointer = 15;
    iPointer = &arr[0];
    iPointer += 2;
    arr[0] = 5;
    *iPointer = 6;
    cout << "i: " << i << endl;
    cout << "number: " << number << endl;
    cout << "arr[0]: " << arr[0] << endl;
    cout << "arr[2]: " << arr[2] << endl;

    return 0;
}
