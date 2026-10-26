Project 1: Library Management System – نظام إدارة المكتبة
الفكرة: إنشاء برنامج لإدارة الكتب، وإضافة الكتب وعرضها والبحث عنها واستعارتها وإرجاعها.
المفاهيم المطلوبة: Structures, Arrays, Functions, Loops, If-Else, Strings.

#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isBorrowed;
};

Book books[100];
int count = 0;

void addBook() {
    if (count >= 100) {
        cout << "Library is full!\n";
        return;
    }

    cout << "Enter book ID: ";
    cin >> books[count].id;
    cin.ignore();

    cout << "Enter book title: ";
    getline(cin, books[count].title);

    cout << "Enter author name: ";
    getline(cin, books[count].author);

    books[count].isBorrowed = false;
    count++;

    cout << "Book added successfully!\n";
}

void displayBooks() {
    if (count == 0) {
        cout << "No books available.\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << "\nBook ID: " << books[i].id;
        cout << "\nTitle: " << books[i].title;
        cout << "\nAuthor: " << books[i].author;
        cout << "\nStatus: ";

        if (books[i].isBorrowed)
            cout << "Borrowed\n";
        else
            cout << "Available\n";
    }
}

void searchBook() {
    int id;
    cout << "Enter book ID to search: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            cout << "Book found!\n";
            cout << "Title: " << books[i].title << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "Status: ";

            if (books[i].isBorrowed)
                cout << "Borrowed\n";
            else
                cout << "Available\n";

            return;
        }
    }

    cout << "Book not found!\n";
}

void borrowBook() {
    int id;
    cout << "Enter book ID to borrow: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (!books[i].isBorrowed) {
                books[i].isBorrowed = true;
                cout << "Book borrowed successfully!\n";
            } else {
                cout << "Book is already borrowed!\n";
            }
            return;
        }
    }

    cout << "Book not found!\n";
}

void returnBook() {
    int id;
    cout << "Enter book ID to return: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].isBorrowed) {
                books[i].isBorrowed = false;
                cout << "Book returned successfully!\n";
            } else {
                cout << "Book was not borrowed!\n";
            }
            return;
        }
    }

    cout << "Book not found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Borrow Book\n";
        cout << "5. Return Book\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            addBook();
        else if (choice == 2)
            displayBooks();
        else if (choice == 3)
            searchBook();
        else if (choice == 4)
            borrowBook();
        else if (choice == 5)
            returnBook();
        else if (choice == 0)
            cout << "Goodbye!\n";
        else
            cout << "Invalid choice!\n";

    } while (choice != 0);

    return 0;
}
 ============================================================================================


Project 2: Student Grades Management System – نظام إدارة درجات الطلبة
الفكرة: إنشاء برنامج لتخزين درجات الطلبة وحساب المعدل وتحديد النجاح أو الرسوب واستخراج أعلى معدل.
المفاهيم المطلوبة: Structures, Arrays, Functions, Loops, If-Else, Arithmetic Operations.




#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float grades[3];
    float average;
};

Student students[100];
int count = 0;

void addStudent() {
    if (count >= 100) {
        cout << "Student list is full!\n";
        return;
    }

    cout << "Enter student ID: ";
    cin >> students[count].id;
    cin.ignore();

    cout << "Enter student name: ";
    getline(cin, students[count].name);

    for (int i = 0; i < 3; i++) {
        cout << "Enter grade " << i + 1 << ": ";
        cin >> students[count].grades[i];
    }

    students[count].average =
        (students[count].grades[0] +
         students[count].grades[1] +
         students[count].grades[2]) / 3.0;

    count++;

    cout << "Student added successfully!\n";
}

void displayStudents() {
    if (count == 0) {
        cout << "No students available!\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << "\nID: " << students[i].id;
        cout << "\nName: " << students[i].name;
        cout << "\nAverage: " << students[i].average;

        if (students[i].average >= 50)
            cout << "\nResult: Passed\n";
        else
            cout << "\nResult: Failed\n";
    }
}

void searchStudent() {
    int id;

    cout << "Enter student ID: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            cout << "\nName: " << students[i].name;
            cout << "\nAverage: " << students[i].average;

            if (students[i].average >= 50)
                cout << "\nResult: Passed\n";
            else
                cout << "\nResult: Failed\n";

            return;
        }
    }

    cout << "Student not found!\n";
}

void findHighestAverage() {
    if (count == 0) {
        cout << "No students available!\n";
        return;
    }

    int highestIndex = 0;

    for (int i = 1; i < count; i++) {
        if (students[i].average >
            students[highestIndex].average) {
            highestIndex = i;
        }
    }

    cout << "\nStudent with highest average:\n";
    cout << "Name: " << students[highestIndex].name << endl;
    cout << "Average: " << students[highestIndex].average << endl;
}

int main() {
    int choice;

    do {
        cout << "\n===== Student Grades Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Find Highest Average\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            addStudent();
        else if (choice == 2)
            displayStudents();
        else if (choice == 3)
            searchStudent();
        else if (choice == 4)
            findHighestAverage();
        else if (choice == 0)
            cout << "Goodbye!\n";
        else
            cout << "Invalid choice!\n";

    } while (choice != 0);

    return 0;
}
 =======================================================================================================


Project 3: University Cafeteria Ordering System – نظام طلبات كافتيريا الجامعة
الفكرة: إنشاء برنامج لعرض قائمة الطعام واستقبال طلبات الزبائن وحساب الكمية والسعر الكلي وطباعة الفاتورة.
المفاهيم المطلوبة: Structures, Arrays, Functions, Loops, If-Else, Arithmetic Operations


#include <iostream>
#include <string>
using namespace std;

struct Food {
    int id;
    string name;
    float price;
};

Food menu[5] = {
    {1, "Burger", 5000},
    {2, "Pizza", 7000},
    {3, "Sandwich", 3000},
    {4, "Juice", 1500},
    {5, "Tea", 1000}
};

struct Order {
    int foodId;
    int quantity;
    float total;
};

Order orders[100];
int orderCount = 0;

void displayMenu() {
    cout << "\n===== University Cafeteria Menu =====\n";

    for (int i = 0; i < 5; i++) {
        cout << menu[i].id << ". "
             << menu[i].name << " - "
             << menu[i].price << " IQD\n";
    }
}

void addOrder() {
    if (orderCount >= 100) {
        cout << "Order list is full!\n";
        return;
    }

    int id, quantity;

    displayMenu();

    cout << "\nEnter food ID: ";
    cin >> id;

    if (id < 1 || id > 5) {
        cout << "Invalid food ID!\n";
        return;
    }

    cout << "Enter quantity: ";
    cin >> quantity;

    if (quantity <= 0) {
        cout << "Invalid quantity!\n";
        return;
    }

    orders[orderCount].foodId = id;
    orders[orderCount].quantity = quantity;
    orders[orderCount].total =
        menu[id - 1].price * quantity;

    orderCount++;

    cout << "Order added successfully!\n";
}

void printInvoice() {
    if (orderCount == 0) {
        cout << "No orders available!\n";
        return;
    }

    float grandTotal = 0;

    cout << "\n========== INVOICE ==========\n";

    for (int i = 0; i < orderCount; i++) {
        int index = orders[i].foodId - 1;

        cout << "\nFood: " << menu[index].name;
        cout << "\nPrice: " << menu[index].price << " IQD";
        cout << "\nQuantity: " << orders[i].quantity;
        cout << "\nTotal: " << orders[i].total << " IQD\n";

        grandTotal += orders[i].total;
    }

    cout << "\n-----------------------------\n";
    cout << "Grand Total: " << grandTotal << " IQD\n";
    cout << "=============================\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== University Cafeteria System =====\n";
        cout << "1. Display Menu\n";
        cout << "2. Add Order\n";
        cout << "3. Print Invoice\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            displayMenu();
        }
        else if (choice == 2) {
            addOrder();
        }
        else if (choice == 3) {
            printInvoice();
        }
        else if (choice == 0) {
            cout << "Thank you for visiting!\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
 ==========================================================================================================



Project 4: Computer Lab Reservation System – نظام حجز مختبرات الحاسوب
الفكرة: إنشاء برنامج لعرض الحواسيب المتاحة في المختبر وحجز الحاسوب والتحقق من عدم وجود حجز مسبق.
المفاهيم المطلوبة: Structures, 2D Arrays, Functions, Loops, If-Else.



#include <iostream>
using namespace std;

struct Computer {
    int id;
    bool isReserved;
};

Computer labs[3][5];

void initializeLabs() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            labs[i][j].id = j + 1;
            labs[i][j].isReserved = false;
        }
    }
}

void displayComputers() {
    cout << "\n===== Computer Lab Status =====\n";

    for (int i = 0; i < 3; i++) {
        cout << "\nLab " << i + 1 << ":\n";

        for (int j = 0; j < 5; j++) {
            cout << "Computer " << labs[i][j].id << " - ";

            if (labs[i][j].isReserved)
                cout << "Reserved\n";
            else
                cout << "Available\n";
        }
    }
}

void reserveComputer() {
    int labNumber, computerNumber;

    cout << "Enter lab number (1-3): ";
    cin >> labNumber;

    cout << "Enter computer number (1-5): ";
    cin >> computerNumber;

    if (labNumber < 1  labNumber > 3 
        computerNumber < 1  computerNumber > 5) {
        cout << "Invalid lab or computer number!\n";
        return;
    }

    if (labs[labNumber - 1][computerNumber - 1].isReserved) {
        cout << "This computer is already reserved!\n";
    }
    else {
        labs[labNumber - 1][computerNumber - 1].isReserved = true;
        cout << "Computer reserved successfully!\n";
    }
}

void cancelReservation() {
    int labNumber, computerNumber;

    cout << "Enter lab number (1-3): ";
    cin >> labNumber;

    cout << "Enter computer number (1-5): ";
    cin >> computerNumber;

    if (labNumber < 1  labNumber > 3 
        computerNumber < 1  computerNumber > 5) {
        cout << "Invalid lab or computer number!\n";
        return;
    }

    if (labs[labNumber - 1][computerNumber - 1].isReserved) {
        labs[labNumber - 1][computerNumber - 1].isReserved = false;
        cout << "Reservation cancelled successfully!\n";
    }
    else {
        cout << "This computer is not reserved!\n";
    }
}

int main() {
    int choice;

    initializeLabs();

    do {
        cout << "\n===== Computer Lab Reservation System =====\n";
        cout << "1. Display Computers\n";
        cout << "2. Reserve Computer\n";
        cout << "3. Cancel Reservation\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            displayComputers();
        }
        else if (choice == 2) {
            reserveComputer();
        }
        else if (choice == 3) {
            cancelReservation();
        }
        else if (choice == 0) {
            cout << "Goodbye!\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
 =====================================================================================================


Project 5: Student Attendance Management System – نظام إدارة حضور وغياب الطلبة
الفكرة: إنشاء برنامج لتسجيل حضور وغياب الطلبة وحساب عدد أيام الحضور ونسبة الالتزام.
المفاهيم المطلوبة: Structures, Arrays, Functions, Loops, If-Else, Arithmetic Operations




#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    int presentDays;
    int absentDays;
    float attendanceRate;
};

Student students[100];
int count = 0;
int totalDays = 0;

void addStudent() {
    if (count >= 100) {
        cout << "Student list is full!\n";
        return;
    }

    cout << "Enter student ID: ";
    cin >> students[count].id;
    cin.ignore();

    cout << "Enter student name: ";
    getline(cin, students[count].name);

    students[count].presentDays = 0;
    students[count].absentDays = 0;
    students[count].attendanceRate = 0;

    count++;

    cout << "Student added successfully!\n";
}

void recordAttendance() {
    if (count == 0) {
        cout << "No students available!\n";
        return;
    }

    int id;
    char status;

    cout << "Enter student ID: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            cout << "Enter P for Present or A for Absent: ";
            cin >> status;

            if (status == 'P' || status == 'p') {
                students[i].presentDays++;
                cout << "Attendance recorded!\n";
            }
            else if (status == 'A' || status == 'a') {
                students[i].absentDays++;
                cout << "Absence recorded!\n";
            }
            else {
                cout << "Invalid attendance status!\n";
            }

            return;
        }
    }

    cout << "Student not found!\n";
}

void calculateAttendance() {
    for (int i = 0; i < count; i++) {
        int recordedDays = students[i].presentDays
                         + students[i].absentDays;

        if (recordedDays > 0) {
            students[i].attendanceRate =
                (float)students[i].presentDays
                / recordedDays * 100;
        }
        else {
            students[i].attendanceRate = 0;
        }
    }
}

void displayStudents() {
    if (count == 0) {
        cout << "No students available!\n";
        return;
    }

    calculateAttendance();

    cout << "\n===== Student Attendance Report =====\n";

    for (int i = 0; i < count; i++) {
        cout << "\nID: " << students[i].id;
        cout << "\nName: " << students[i].name;
        cout << "\nPresent Days: " << students[i].presentDays;
        cout << "\nAbsent Days: " << students[i].absentDays;
        cout << "\nAttendance Rate: "
             << students[i].attendanceRate << "%";

        if (students[i].attendanceRate >= 75)
            cout << "\nStatus: Regular\n";
        else
            cout << "\nStatus: Low Attendance\n";
    }
}

void displayStudentAttendance() {
    int id;

    cout << "Enter student ID: ";
    cin >> id;

    calculateAttendance();

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            cout << "\nName: " << students[i].name;
            cout << "\nPresent Days: " << students[i].presentDays;
            cout << "\nAbsent Days: " << students[i].absentDays;
            cout << "\nAttendance Rate: "
                 << students[i].attendanceRate << "%\n";
            return;
        }
    }

    cout << "Student not found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== Student Attendance Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Record Attendance\n";
        cout << "3. Display All Students\n";
        cout << "4. Search Student Attendance\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            addStudent();
        else if (choice == 2)
            recordAttendance();
        else if (choice == 3)
            displayStudents();
        else if (choice == 4)
            displayStudentAttendance();
        else if (choice == 0)
            cout << "Goodbye!\n";
        else
            cout << "Invalid choice!\n";

    } while (choice != 0);

    return 0;
}
==================================================================================================



Project 6: Network Lab Inventory Management System – نظام إدارة وجرد أجهزة مختبر الشبكات
الفكرة: إنشاء برنامج لتسجيل أجهزة مختبر الشبكات وعرضها والبحث عنها ومعرفة كمياتها والأجهزة المتضررة.
المفاهيم المطلوبة: Structures, Arrays, Functions, Loops, If-Else, Strings.






#include <iostream>
#include <string>
using namespace std;

struct Device {
    int id;
    string name;
    int quantity;
    int damaged;
};

Device devices[100];
int count = 0;

void addDevice() {
    if (count >= 100) {
        cout << "Inventory is full!\n";
        return;
    }

    cout << "Enter device ID: ";
    cin >> devices[count].id;
    cin.ignore();

    cout << "Enter device name: ";
    getline(cin, devices[count].name);

    cout << "Enter device quantity: ";
    cin >> devices[count].quantity;

    cout << "Enter damaged quantity: ";
    cin >> devices[count].damaged;

    if (devices[count].quantity < 0 ||
        devices[count].damaged < 0 ||
        devices[count].damaged > devices[count].quantity) {
        cout << "Invalid quantities!\n";
        return;
    }

    count++;
    cout << "Device added successfully!\n";
}

void displayDevices() {
    if (count == 0) {
        cout << "No devices available!\n";
        return;
    }

    cout << "\n===== Network Lab Inventory =====\n";

    for (int i = 0; i < count; i++) {
        cout << "\nDevice ID: " << devices[i].id;
        cout << "\nDevice Name: " << devices[i].name;
        cout << "\nTotal Quantity: " << devices[i].quantity;
        cout << "\nDamaged Devices: " << devices[i].damaged;
        cout << "\nWorking Devices: "
             << devices[i].quantity - devices[i].damaged;

        if (devices[i].damaged > 0)
            cout << "\nStatus: Contains Damaged Devices\n";
        else
            cout << "\nStatus: All Devices Working\n";
    }
}

void searchDevice() {
    int id;

    cout << "Enter device ID to search: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (devices[i].id == id) {
            cout << "\nDevice Found!\n";
            cout << "Name: " << devices[i].name << endl;
            cout << "Total Quantity: " << devices[i].quantity << endl;
            cout << "Damaged Quantity: " << devices[i].damaged << endl;
            cout << "Working Quantity: "
                 << devices[i].quantity - devices[i].damaged << endl;
            return;
        }
    }

    cout << "Device not found!\n";
}

void displayDamagedDevices() {
    bool found = false;

    cout << "\n===== Damaged Devices =====\n";

    for (int i = 0; i < count; i++) {
        if (devices[i].damaged > 0) {
            cout << "\nID: " << devices[i].id;
            cout << "\nName: " << devices[i].name;
            cout << "\nDamaged Quantity: " << devices[i].damaged << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No damaged devices found!\n";
}

void updateDamagedQuantity() {
    int id, damaged;

    cout << "Enter device ID: ";
    cin >> id;

    for (int i = 0; i < count; i++) {
        if (devices[i].id == id) {
            cout << "Enter new damaged quantity: ";
            cin >> damaged;

            if (damaged < 0 || damaged > devices[i].quantity) {
                cout << "Invalid damaged quantity!\n";
                return;
            }

            devices[i].damaged = damaged;
            cout << "Inventory updated successfully!\n";
            return;
        }
    }

    cout << "Device not found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== Network Lab Inventory Management =====\n";
        cout << "1. Add Device\n";
        cout << "2. Display All Devices\n";
        cout << "3. Search Device\n";
        cout << "4. Display Damaged Devices\n";
        cout << "5. Update Damaged Quantity\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            addDevice();
        else if (choice == 2)
            displayDevices();
        else if (choice == 3)
            searchDevice();
        else if (choice == 4)
            displayDamagedDevices();
        else if (choice == 5)
            updateDamagedQuantity();
        else if (choice == 0)
            cout << "Goodbye!\n";
        else
            cout << "Invalid choice!\n";

    } while (choice != 0);

    return 0;
}
=================================================================================