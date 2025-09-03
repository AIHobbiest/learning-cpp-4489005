// Learning C++ 
// Challenge 04_05
// Calculate a GPA, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include "records.h"

int main(){
    float GPA = 0.0f;
    int id;
    
    std::vector<Student> students = {Student(1, "George P. Burdell"),
                                    Student(2, "Nancy Rhodes")};

    std::vector<Course> courses = {Course(1, "Algebra", 5),
                                Course(2, "Physics", 4),
                                Course(3, "English", 3),
                                Course(4, "Economics", 4)};

    std::vector<Grade> grades = {Grade(1, 1, 'B'), Grade(1, 2, 'A'), Grade(1, 3, 'C'),
                                Grade(2, 1, 'A'), Grade(2, 2, 'A'), Grade(2, 4, 'B')};

    std::cout << "Enter a student ID: " << std::flush;
    std::cin >> id;

    // Calculate the GPA for the selected student.
    // Write your code here
    float c_pts = 0.0f;

    for (auto x : grades) {
        if (x.get_student_id() == id){
        switch (x.get_grade()){
            case 'A':
                for (auto c : courses){
                    if (c.get_id() == x.get_course_id()){
                        c_pts += (c.get_credits() * 4);
                    }
            }
                break;
            case 'B':
                for (auto c : courses){
                    if (c.get_id() == x.get_course_id()){
                        c_pts += (c.get_credits() * 3);
                    }
            }
                break;
            case 'C':
                for (auto c : courses){
                    if (c.get_id() == x.get_course_id()){
                        c_pts += (c.get_credits() * 2);
                    }
            }
                break;
            default:
                std::cout << "nothing is matched" << " " << std::endl;
        } 
    }
    }

    GPA = c_pts / (5+4+3);

    std::string student_str;
    student_str = students[id - 1].get_name(); // Change this to the selected student's name

    std::cout << "The GPA for " << student_str << " is " << GPA << std::endl;
    
    std::cout << std::endl << std::endl;
    return (0);
}
