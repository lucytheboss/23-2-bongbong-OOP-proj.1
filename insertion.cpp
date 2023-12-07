#include "header.h"
#include "Student.h"

void getStudentName(Student& student);
void getStudentID(Student& student);
void getStudentBirthYear(Student& student);
void getStudentDepartment(Student& student);
void getStudentTel(Student& student);
void getStudentInfo(Student& student);

void getStudentInfo(Student& student) {
    getStudentName(student);
    getStudentID(student);
    getStudentBirthYear(student);
    getStudentDepartment(student);
    getStudentTel(student);
}

void getStudentName(Student& student) {
    bool validInput = false;
    do {
        std::cout << "Name: ";
        std::cin.ignore();
        std::getline(std::cin, student.name);

        if (student.name.empty() || student.name.length() > 15) {
            std::cout << "Invalid input. Name length should not exceed 15 characters." << std::endl;
        } else {
            validInput = true;
        }
    } while (!validInput);
}

void getStudentID(Student& student) {
    bool validInput = false;
    do {
        std::cout << "Student ID (10 digits): ";
        std::string studentIDInput;
        std::cin >> studentIDInput;

        if (studentIDInput.length() != 10 || !std::all_of(studentIDInput.begin(), studentIDInput.end(), ::isdigit)) {
            std::cout << "Invalid input. Please enter a 10-digit student ID." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            student.studentID = std::stoi(studentIDInput);
            validInput = true;
        }
    } while (!validInput);
}


void getStudentBirthYear(Student& student) {
    bool validInput = false;
    do {
        std::cout << "Birth Year (4 digits): ";
        std::cin >> student.birthyear;

        if (std::cin.fail() || student.birthyear < 1900 || student.birthyear > 2100) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a 4-digit birth year." << std::endl;
        } else {
            validInput = true;
        }
    } while (!validInput);
}

void getStudentDepartment(Student& student) {
    std::cout << "Department: ";
    std::cin.ignore();
    std::getline(std::cin, student.department);
}

void getStudentTel(Student& student) {
    bool validInput = false;
    do {
        std::cout << "Tel (up to 12 digits): ";
        std::string telInput;
        std::cin >> telInput;

        if (telInput.length() > 12 || !std::all_of(telInput.begin(), telInput.end(), ::isdigit)) {
            std::cout << "Invalid input. Tel cannot exceed 12 digits." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            student.tel = std::stoi(telInput);
            validInput = true;
        }
    } while (!validInput);
}