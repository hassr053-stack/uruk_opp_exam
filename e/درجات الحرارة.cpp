درجات الحرارة
اكتب برنامجًا يخزن درجات الحرارة لمدة 5 أيام داخل مصفوفة، ثم يستخدم دالة باسم calculateAverage() لحساب معدل درجات الحرارة وطباعته.

#include <iostream>
using namespace std;

double calculateAverage(int temp[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += temp[i];
    }

    return (double)sum / size;
}

int main() {
    int temp[5] = {20, 25, 30, 35, 40};

    cout << "Average = " << calculateAverage(temp, 5);

    return 0;
}
