#include <iostream>
using namespace std;

int calculateSum(int grades[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += grades[i];
    }

    return sum;
}

int main() {
    int grades[5] = {80, 90, 70, 85, 75};

    cout << "Sum = " << calculateSum(grades, 5);

    return 0;
}
