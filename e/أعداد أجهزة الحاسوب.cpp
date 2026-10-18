أعداد أجهزة الحاسوب
يحتوي مختبر على 5 أجهزة حاسوب. اكتب برنامجًا يخزن أعداد الأجهزة المتوفرة في 5 مختبرات داخل مصفوفة، ثم يستخدم دالة باسم countAvailable() لحساب عدد المختبرات التي يتوفر فيها جهاز واحد على الأقل


#include <iostream>
using namespace std;

int calculateTotal(int expenses[], int size) {
    int total = 0;

    for (int i = 0; i < size; i++) {
        total += expenses[i];
    }

    return total;
}

int main() {
    int expenses[7] = {5000, 3000, 4000, 2000, 6000, 3500, 2500};

    cout << "Total Expenses = " << calculateTotal(expenses, 7);

    return 0;
}
