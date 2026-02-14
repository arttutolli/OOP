#include <iostream>
#include <vector>
#include <algorithm>
#include "Student.h"

using namespace std;

int main ()
{
    int selection = 0;
    vector<Student> studentList;

    do {
        cout << endl;
        cout << "Select" << endl;
        cout << "Add students = 0" << endl;
        cout << "Print all students = 1" << endl;
        cout << "Sort and print students according to Name = 2" << endl;
        cout << "Sort and print students according to Age = 3" << endl;
        cout << "Find and print student = 4" << endl;
        cin >> selection;

        switch(selection)
        {
        case 0: {
            // Lisää opiskelija
            string name;
            int age;

            cout << "Enter name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;

            studentList.emplace_back(name, age);
            break;
        }

        case 1: {
            // Tulosta kaikki opiskelijat
            cout << "All students:" << endl;
            for (const auto& s : studentList) {
                s.printStudentInfo();
            }
            break;
        }

        case 2: {
            // Järjestä nimen mukaan
            sort(studentList.begin(), studentList.end(),
                 [](const Student& a, const Student& b) {
                     return a.getName() < b.getName();
                 });

            cout << "Students sorted by name:" << endl;
            for (const auto& s : studentList) {
                s.printStudentInfo();
            }
            break;
        }

        case 3: {
            // Järjestä iän mukaan
            sort(studentList.begin(), studentList.end(),
                 [](const Student& a, const Student& b) {
                     return a.getAge() < b.getAge();
                 });

            cout << "Students sorted by age:" << endl;
            for (const auto& s : studentList) {
                s.printStudentInfo();
            }
            break;
        }

        case 4: {
            // Etsi opiskelija nimen perusteella
            string name;
            cout << "Enter name to search: ";
            cin >> name;

            auto it = find_if(studentList.begin(), studentList.end(),
                              [&](const Student& s) {
                                  return s.getName() == name;
                              });

            if (it != studentList.end()) {
                cout << "Student found:" << endl;
                it->printStudentInfo();
            } else {
                cout << "Student not found." << endl;
            }
            break;
        }

        default:
            cout << "Wrong selection, stopping..." << endl;
            break;
        }

    } while (selection < 5);

    return 0;
}
