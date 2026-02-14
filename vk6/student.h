#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student {
private:
    std::string name;
    int age;

public:
    // Oletusrakentaja
    Student() : name(""), age(0) {}

    // Parametrillinen rakentaja
    Student(const std::string& n, int a) : name(n), age(a) {}

    // Getterit
    std::string getName() const { return name; }
    int getAge() const { return age; }

    // Tulostusfunktio
    void printStudentInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

#endif
