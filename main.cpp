
#include "header.h"
#include "insertion.cpp"

std::vector<Student> students;


int main() {

    loadStudentsFromFile();
    int userSelection;

    while (true) {
        std::cout << "\n\n=======MAIN MENU=======";
        std::cout << "\nSelect a menu by inserting a number\n";
        std::cout << "1. Insertion\n";
        std::cout << "2. Search\n";
        std::cout << "3. Sorting Option\n";
        std::cout << "4. Exit\n";
        std::cin >> userSelection;

        switch (userSelection) {
            case 1:
                insertion();
                break;
            case 2:
                search();
                break;
            case 3:
                sortingOption();
                break;
            case 4:
                exitProgram();
                saveToFile();
                return 0;
            default:
                std::cout << "Select one from the provided menus" << std::endl;
        }
    }
}

void insertion() {
    Student student;
    getStudentInfo(student); // Implement getStudentInfo to fill 'student' struct
    students.push_back(student);

    std::ofstream writeFile("student_data.txt", std::ios::app);

    if (writeFile.is_open()) {
        writeFile << student.name << "," << student.studentID << "," << student.birthyear << ","
                  << student.department << "," << student.tel << "\n";

        writeFile.close();
        std::cout << "** Success to insert! **\n\n";
    } else {
        std::cerr << "Error: Fail to open file for writing.\n\n";
    }
}


void search() {

    int searchOption;
    while (true) {
        std::cout << "Select search option:\n";
        std::cout << "1. Search by Name\n";
        std::cout << "2. Search by Student ID\n";
        std::cout << "3. Search by Admission Year\n";
        std::cout << "4. Search by Department\n";
        std::cout << "5. Back to Main Menu\n";
        std::cin >> searchOption;

        switch (searchOption) {
            case 1:
                searchByName();
                break;
            case 2:
                searchByStudentID();
                break;
            case 3:
                searchByAdmissionYear();
                break;
            case 4:
                searchByDepartment();
                break;
            case 5:
                return;
            default:
                std::cout << "Invalid search option" << std::endl;
        }
    }
}

void searchByName() {
     
    std::string query;
    std::cout << "Enter the name to search for: ";
    std::cin.ignore();
    std::getline(std::cin, query);

    auto found = std::find_if(students.begin(), students.end(), [&query](const Student& student) {
        return student.name == query;
    });

    if (found != students.end()) {
        std::cout << "Name: " << found->name << "\n";
        std::cout << "Student ID: " << found->studentID << "\n";
        std::cout << "Birth Year: " << found->birthyear << "\n";
        std::cout << "Department: " << found->department << "\n";
        std::cout << "Tel: " << found->tel << "\n";
        std::cout << "--------------------------\n";
    }
    else {
        std::cout << "Name not found." << "\n";
    }
}

void searchByStudentID() {

    loadStudentsFromFile();

    int query;
    std::cout << "Enter the student ID to search for: ";
    std::cin >> query;

    auto found = std::find_if(students.begin(), students.end(), [&query](const Student& student) {
        return student.studentID == query;
    });

    if (found != students.end()) {
        std::cout << "Name: " << found->name << "\n";
        std::cout << "Student ID: " << found->studentID << "\n";
        std::cout << "Birth Year: " << found->birthyear << "\n";
        std::cout << "Department: " << found->department << "\n";
        std::cout << "Tel: " << found->tel << "\n";
        std::cout << "--------------------------\n";
    }
    else {
        std::cout << "Student ID not found." << "\n";
    }
}

void searchByAdmissionYear() {
    int query;
    std::cout << "Enter the Admission Year to search for: ";
    std::cin >> query;

    auto found = std::find_if(students.begin(), students.end(), [&query](const Student& student) {
        return student.studentID / 10000 == query;
    });

    if (found != students.end()) {
        std::cout << "Name: " << found->name << "\n";
        std::cout << "Student ID: " << found->studentID << "\n";
        std::cout << "Birth Year: " << found->birthyear << "\n";
        std::cout << "Department: " << found->department << "\n";
        std::cout << "Tel: " << found->tel << "\n";
        std::cout << "--------------------------\n";
    } else {
        std::cout << "Admission Year not found." << "\n";
    }
}

void searchByDepartment() {
    std::string query;
    std::cout << "Enter the Department to search for: ";
    std::cin.ignore();
    std::getline(std::cin, query);

    auto found = std::find_if(students.begin(), students.end(), [&query](const Student& student) {
        return student.department == query;
    });

    if (found != students.end()) {
        std::cout << "Name: " << found->name << "\n";
        std::cout << "Student ID: " << found->studentID << "\n";
        std::cout << "Birth Year: " << found->birthyear << "\n";
        std::cout << "Department: " << found->department << "\n";
        std::cout << "Tel: " << found->tel << "\n";
        std::cout << "--------------------------\n";
    }
    else {
        std::cout << "Department not found." << "\n";
    }
}

void sortingOption() {

    int sortOption;
    while (true) {
        std::cout << "Select sorting option:\n";
        std::cout << "1. Sort by Name\n";
        std::cout << "2. Sort by Student ID\n";
        std::cout << "3. Sort by Admission Year\n";
        std::cout << "4. List All\n";
        std::cout << "5. Back to Main Menu\n";
        std::cin >> sortOption;

        switch (sortOption) {
            case 1:
                sortByName();
                listAll();
                break;
            case 2:
                sortByStudentID();
                listAll();
                break;
            case 3:
                sortByAdmissionYear();
                listAll();
                break;
            case 4:
                listAll();
            case 5:
                return;
            default:
                std::cout << "Invalid sorting option" << std::endl;
        }
    }
}

void sortByName() {
    std::sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        return a.name < b.name;
    });
}

void sortByStudentID() {
    std::sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        return a.studentID < b.studentID;
    });
}

void sortByAdmissionYear() {
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        // Extract the first four digits from the student ID for admission year
        int admissionYearA = a.studentID / 10000;
        int admissionYearB = b.studentID / 10000;
        
        return admissionYearA < admissionYearB;
    });
}

void sortByDepartment() {
    std::sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        return a.department < b.department;
    });
}

void listAll() {
    std::cout << "Student Records:\n";

    if (students.empty()) {
        std::cout << "No student records found.\n";
    } else {
        for (const Student& student : students) {
            std::cout << "Name: " << student.name << "\n";
            std::cout << "Student ID: " << student.studentID << "\n";
            std::cout << "Birth Year: " << student.birthyear << "\n";
            std::cout << "Department: " << student.department << "\n";
            std::cout << "Tel: " << student.tel << "\n";
            std::cout << "--------------------------\n";
        }
    }
}

void loadStudentsFromFile() {
    students.clear();
    std::ifstream file("student_data.txt");

    if (!file) {
        std::cerr << "File 'student_data.txt' not found or cannot be opened." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::size_t commaPos1 = line.find(',');
        std::size_t commaPos2 = line.find(',', commaPos1 + 1);
        std::size_t commaPos3 = line.find(',', commaPos2 + 1);
        std::size_t commaPos4 = line.find(',', commaPos3 + 1);

        if (commaPos1 == std::string::npos || commaPos2 == std::string::npos ||
            commaPos3 == std::string::npos || commaPos4 == std::string::npos) {
            std::cerr << "Invalid line: " << line << std::endl;
            continue;
        }

        Student student;
        student.name = line.substr(0, commaPos1);
        student.studentID = std::stoi(line.substr(commaPos1 + 1, commaPos2 - commaPos1 - 1));
        student.birthyear = std::stoi(line.substr(commaPos2 + 1, commaPos3 - commaPos2 - 1));
        student.department = line.substr(commaPos3 + 1, commaPos4 - commaPos3 - 1);
        student.tel = std::stoi(line.substr(commaPos4 + 1));

        students.push_back(student);
    }

    file.close();
    std::cout << "Data loaded from student_data.txt." << std::endl;
}

// Implement the exitProgram and saveToFile functions

void exitProgram() {
    std::cout << "Exiting the program..." << std::endl;
    // You can add any necessary cleanup or saving operations here
}

void saveToFile() {
    std::ofstream writeFile("student_data.txt");
    if (writeFile.is_open()) {
        for (const Student& student : students) {
            writeFile << student.name << "," << student.studentID << "," << student.birthyear << ","
                      << student.department << "," << student.tel << "\n";
        }
        writeFile.close();
        std::cout << "Data saved to student_data.txt." << std::endl;
    } else {
        std::cerr << "Error: Fail to open file for writing.\n";
    }
}