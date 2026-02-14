#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student {
private:
    std::string name;
    int age;

public:
    Student() : name(""), age(0) {}
    Student(std::string n, int a) : name(n), age(a) {}

    std::string getName() const { return name; }
    int getAge() const { return age; }

    void printStudentInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

#endif
