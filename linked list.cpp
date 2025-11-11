#include <bits/stdc++.h>
using namespace std;


struct Student {
    int rollNo;
    string name;
    float marks;
    Student* next;
};


Student* head = NULL;


void addStudent(int rollNo, string name, float marks) {
    Student* newStudent = new Student;
    newStudent->rollNo = rollNo;
    newStudent->name = name;
    newStudent->marks = marks;
    newStudent->next = NULL;

    if (head == NULL) {
        head = newStudent;
    } else {
        Student* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newStudent;
    }
    cout << "Student record added successfully!\n";
}


void deleteStudent(int rollNo) {
    if (head == NULL) {
        cout << "No records found.\n";
        return;
    }

    Student* temp = head;
    Student* prev = NULL;

    
    if (temp != NULL && temp->rollNo == rollNo) {
        head = temp->next;
        delete temp;
        cout << "Record deleted successfully.\n";
        return;
    }

    
    while (temp != NULL && temp->rollNo != rollNo) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Record not found.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Record deleted successfully.\n";
}


void updateStudent(int rollNo) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->rollNo == rollNo) {
            cout << "Enter new name: ";
            cin >> temp->name;
            cout << "Enter new marks: ";
            cin >> temp->marks;
            cout << "Record updated successfully!\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Record not found.\n";
}


void searchStudent(int rollNo) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->rollNo == rollNo) {
            cout << "\nRecord found:\n";
            cout << "Roll No: " << temp->rollNo << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Marks: " << temp->marks << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Record not found.\n";
}


void display() {
    if (head == NULL) {
        cout << "No records to display.\n";
        return;
    }

    cout << "\nStudent Records:\n";
    Student* temp = head;
    while (temp != NULL) {
        cout << "Roll No: " << temp->rollNo << " | Name: " << temp->name << " | Marks: " << temp->marks << endl;
        temp = temp->next;
    }
}


void sortRecords(bool sortByMarks = false, bool ascending = true) {
    if (head == NULL || head->next == NULL) {
        cout << "Not enough records to sort.\n";
        return;
    }

    for (Student* i = head; i != NULL; i = i->next) {
        for (Student* j = i->next; j != NULL; j = j->next) {
            bool condition;
            if (sortByMarks)
                condition = ascending ? (i->marks > j->marks) : (i->marks < j->marks);
            else
                condition = ascending ? (i->rollNo > j->rollNo) : (i->rollNo < j->rollNo);

            if (condition) {
                swap(i->rollNo, j->rollNo);
                swap(i->name, j->name);
                swap(i->marks, j->marks);
            }
        }
    }

    cout << "Records sorted successfully.\n";
}

int main() {
    int choice;
    do {
        cout << "\n===== Student Record Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Update Student\n";
        cout << "4. Search Student\n";
        cout << "5. Display All Records\n";
        cout << "6. Sort Records\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int rollNo;
        string name;
        float marks;

        switch (choice) {
        case 1:
            cout << "Enter Roll No: ";
            cin >> rollNo;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Marks: ";
            cin >> marks;
            addStudent(rollNo, name, marks);
            break;

        case 2:
            cout << "Enter Roll No to delete: ";
            cin >> rollNo;
            deleteStudent(rollNo);
            break;

        case 3:
            cout << "Enter Roll No to update: ";
            cin >> rollNo;
            updateStudent(rollNo);
            break;

        case 4:
            cout << "Enter Roll No to search: ";
            cin >> rollNo;
            searchStudent(rollNo);
            break;

        case 5:
            display();
            break;

        case 6:
            int sortChoice, orderChoice;
            cout << "Sort by: 1. Roll No  2. Marks: ";
            cin >> sortChoice;
            cout << "Order: 1. Ascending  2. Descending: ";
            cin >> orderChoice;
            sortRecords(sortChoice == 2, orderChoice == 1);
            break;

        case 7:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
