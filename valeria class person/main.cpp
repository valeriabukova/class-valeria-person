//
//  main.cpp
//  valeria class person
//
//  Created by Valeria  Bukova on 13.11.2024.
//

#include <iostream>

class Person {
protected:
    const char* name;
    int age;

public:
    Person(const char* name, int age) : name(name), age(age) {}
    virtual void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

class Student : public Person {
    const char* univer;

public:
    Student(const char* name, int age, const char* univer)
        : Person(name, age), univer(univer) {}

    void display() const override {
        Person::display();
        std::cout << "University: " << univer << std::endl;
    }
};

class Teacher : public Person {
    double salary;
    const char* subjects[10]; // Максимум 10 предметів

public:
    Teacher(const char* name, int age, double salary, const char* subjects[], int subjectCount)
        : Person(name, age), salary(salary) {
        for (int i = 0; i < subjectCount && i < 10; i++) {
            this->subjects[i] = subjects[i];
        }
        // Заповнюємо решту масиву значенням nullptr
        for (int i = subjectCount; i < 10; i++) {
            this->subjects[i] = nullptr;
        }
    }

    void display() const override {
        Person::display();
        std::cout << "Salary: " << salary << ", Subjects: ";
        for (int i = 0; i < 10 && subjects[i] != nullptr; i++) {
            std::cout << subjects[i] << " ";
        }
        std::cout << std::endl;
    }
};

class Driver : public Person {
    const char* carNumber;
    const char* licenseNumber;

public:
    Driver(const char* name, int age, const char* carNumber, const char* licenseNumber)
        : Person(name, age), carNumber(carNumber), licenseNumber(licenseNumber) {}

    void display() const override {
        Person::display();
        std::cout << "Car Number: " << carNumber << ", License Number: " << licenseNumber << std::endl;
    }
};

class Doctor : public Person {
    const char* specialization;

public:
    Doctor(const char* name, int age, const char* specialization)
        : Person(name, age), specialization(specialization) {}

    void display() const override {
        Person::display();
        std::cout << "Specialization: " << specialization << std::endl;
    }
};

int main() {
    const char* subjects[] = {"Math", "Physics", nullptr};

    Student student("Alice", 20, "MIT");
    Teacher teacher("Dr. Bob", 45, 75000, subjects, 2);
    Driver driver("John", 30, "AB1234", "XYZ7890");
    Doctor doctor("Dr. Smith", 40, "Cardiologist");

    student.display();
    teacher.display();
    driver.display();
    doctor.display();

    return 0;
}
