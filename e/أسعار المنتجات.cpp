أسعار المنتجات
اكتب برنامجًا يخزن أسعار 4 منتجات داخل مصفوفة، ثم يستخدم دالة باسم findMax() لإيجاد أعلى سعر وطباعته.


#include <iostream>
using namespace std;

int findMax(int prices[], int size) {
    int max = prices[0];

    for (int i = 1; i < size; i++) {
        if (prices[i] > max) {
            max = prices[i];
        }
    }

    return max;
}

int main() {
    int prices[4] = {100, 250, 150, 300};

    cout << "Max Price = " << findMax(prices, 4);

    return 0;
}
