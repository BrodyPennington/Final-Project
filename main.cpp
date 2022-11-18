#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <stdlib.h>

#define NUM_STUDENTS 20

struct StudentData{
    int id = 0;
    std::string first{};
    std::string last{};
    std::string classification{};
    float gpa = 0.00;
};

int main() {

    std::string line;   // To read each line from code
    StudentData students[NUM_STUDENTS];
    std::ifstream file("StudentData.txt");
    size_t count = 0;

    if(file.is_open()) {
        while(file.peek()!=EOF) {
            getline(file, line);
            size_t end_position = 0;
            int item_number = 0;
            while (item_number <= 4) {
                end_position = line.find(" ");
                switch (item_number) {
                    case 0:
                        students[count].id = std::stoi(line.substr(0, end_position));
                        break;
                    case 1:
                        students[count].first = line.substr(0, end_position);
                        break;
                    case 2:
                        students[count].last = line.substr(0, end_position);
                        break;
                    case 3:
                        students[count].classification = line.substr(0, end_position);
                        break;
                    case 4:
                        students[count].gpa = std::stof(line);
                        break;
                    default:
                        break;
                }
                line.erase(0, end_position + 1);
                ++item_number;  
            }
            count++;
        }
        file.close();
    }

    //printing to the console

    std::cout << "Please select the student classification:" << std::endl;
    std::cout <<    "1.  Freshman\n"
                    "2.  Sophomore\n"
                    "3.  Junior\n"
                    "4.  Senior" << std::endl;
    std::cout << "----------------------" << std::endl;
    int selection = 0;
    float min_gpa = 0.00;
    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "Selection:  ";
    std::cin >> selection;
    std::cout << "\n\n";
    std::cout << "Please enter the minimum GPA to lookup: ";
    std::cin >> min_gpa;

    std::string stringselection{};
    switch (selection) {
        case 1:
            stringselection = "Freshman";
            break;
        case 2:
            stringselection = "Sophomore";
            break;
        case 3:
            stringselection = "Junior";
            break;
        case 4:
            stringselection = "Senior";
            break;
        default:
            std::cout << "Invalid selection" << std::endl;
            exit(EXIT_SUCCESS);
    }
    std::cout << "\n\n";
    std::cout << std::setw(10) << std::left << "ID" << std::setw(10) << "First" << std::setw(10) << "Last" << std::setw(10) << "Class" << std::setw(10) << "GPA" << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
    for (int student_index = 0; student_index < NUM_STUDENTS; student_index++) {
        StudentData this_student = students[student_index];
        if (this_student.classification == stringselection && this_student.gpa >= min_gpa) {
            std::cout << std::setw(10) << std::left << this_student.id << std::setw(10) << this_student.first << std::setw(10) << this_student.last << std::setw(10) << this_student.classification << std::setw(10) << this_student.gpa << std::endl;
        }
    }
    std::cout << "\n\n";

system("pause");

}
