#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    string name;
    int age;
    string grade;
};

void accept(Student* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter details for student " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Age: ";
        cin >> students[i].age;
        cout << "Grade: ";
        cin >> students[i].grade;
    }
}

void save(Student* students, int numStudents, fstream& file) {
    for (int i = 0; i < numStudents; i++) {
        file << students[i].name << "," << students[i].age << "," << students[i].grade << endl;
    }
    cout << "Records saved successfully." << endl;
}

void readRecord(fstream& file) {
    string line;
    cout << "Student Records:" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
}

void display(Student* students, int numStudents) {
    cout << "Student Records:" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Grade: " << students[i].grade << endl;
        cout << endl;
    }
}

int main() {
    int numStudents;

    cout << "What do you want to do?" << "\n"
         << "1. Add new student" << "\n"
         << "2. Display all students" << "\n"
         << "3. Exit" << "\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Enter the number of students: ";
        cin >> numStudents;

        Student* students = new Student[numStudents];

        accept(students, numStudents);

        fstream file("Records.txt", ios::out | ios::in);
        if (!file) {
            cout << "Error opening file." << endl;
            return 1;
        }

        save(students, numStudents, file);

        delete[] students;
        file.close();
    } 
    else if (choice == 2) {
        fstream file("Records.txt", ios::in);
        if (!file) {
            cout << "Error opening file." << endl;
            return 1;
        }

        readRecord(file);
        file.close();
    } 
    else if (choice == 3) {
        return 0;
    } 
    else {
        cout << "Invalid choice.\n";
    }
    
    return 0;
}