#include <iostream>
#include <string>

using namespace std;

class Course
{
private:
    string courseName;
    int couseCode;

public:
    Course() {}
    void setCourseName(string name) { courseName = name; }
    void setCourseCode(int code) { couseCode = code; }
    string getCourseName() { return courseName; }
    int getCourseCode() { return couseCode; }
};

class Student : public Course
{
private:
    string firstName;
    string lastName;
    string department;
    int admissionYear;
    int rollNo;

    string previousCourse[6];
    int previousCourseCode[6];

public:
    int numpreviouscouse;
    Student() { numpreviouscouse = 0; }
    void addStudent(string fname, string lname, string dep, int year, int roll);
    void enrollCourse(string course, int code);
    void dropCourse(int code);
    void displayStudentInfo();
};

int main()
{
    Student student[10];

    string fname, lname, dep;
    int year, id;

    string course;
    int courseCode;

    int index = 0;
    int roll = 0;
    int choice;

    cout << "\tStudent Management System\n"
         << endl;

    do
    {

        cout << "\n\t1. Add a new student\n";
        cout << "\t2. Enroll a student in a course\n";
        cout << "\t3. Drop a course for a student\n";
        cout << "\t4. Display information of all students\n";
        cout << "\t5. Quit\n";

        cout << "\tEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\n\t1. Add a new student\n";
            cout << "Enter Student First Name: ";
            cin >> fname;
            cout << "Enter Student Last Name: ";
            cin >> lname;
            cout << "Enter Department Name: ";
            cin >> dep;
            cout << "Enter Admission Year: ";
            cin >> year;
            student[index].addStudent(fname, lname, dep, year, roll + 1);
            index++;
            roll++;
            break;
        case 2:
            cout << "\n\t2. Enroll a student in a course\n";
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Course Name: ";
            cin >> course;
            cout << "Enter Course Code: ";
            cin >> courseCode;
            student[id % 1000 - 1].enrollCourse(course, courseCode);
            student[id % 1000 - 1].displayStudentInfo();
            break;
        case 3:
            cout << "\n\t3. Drop a course for a student\n";
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Course Code: ";
            cin >> courseCode;
            student[id % 1000 - 1].dropCourse(courseCode);
            student[id % 1000 - 1].displayStudentInfo();
            break;
        case 4:
            cout << "\n\t4. Display information of all students\n";
            for (int i = 0; i < index; i++)
            {
                student[i].displayStudentInfo();
            }
            break;
        case 5:
            return 0;
            break;
        default:
            cout << "\n\tInvalid Choice\n";
            break;
        }

    } while (choice != 5);

    return 0;
}

void Student::addStudent(string fname, string lname, string dep, int year, int roll)
{
    firstName = fname;
    lastName = lname;
    department = dep;
    admissionYear = year;
    rollNo = admissionYear * 1000 + roll;

    cout << "Succcessfully Admitted!" << endl;
    cout << firstName << " " << lastName << endl;
    cout << "ID: " << rollNo << endl;
}

void Student::enrollCourse(string course, int code)
{
    setCourseName(course);
    setCourseCode(code);
    if (numpreviouscouse < 6)
    {
        previousCourse[numpreviouscouse] = course;
        previousCourseCode[numpreviouscouse] = code;
        numpreviouscouse++;

        cout << "Succcessfully Enrolled!" << endl;
    }
    else
    {
        cout << "Failed to Enroll!" << endl;
        cout << "Maximum number of courses reached!" << endl;
    }
}

void Student::dropCourse(int code)
{
    bool courseFound = false;
    for (int i = 0; i < numpreviouscouse; i++)
    {
        if (previousCourseCode[i] == code)
        {
            courseFound = true;

            for (int j = i; j < numpreviouscouse - 1; j++)
            {
                previousCourse[j] = previousCourse[j + 1];
                previousCourseCode[j] = previousCourseCode[j + 1];
            }
            numpreviouscouse--;
            cout << "Successfully Dropped!" << endl;
            break;
        }
    }
    if (!courseFound)
    {
        cout << "Failed to Drop! Course not found!" << endl;
    }
}

void Student::displayStudentInfo()
{
    cout << "Student Name: " << firstName << " " << lastName << endl;
    cout << "Student ID: " << rollNo << endl;
    cout << "Department: " << department << endl;
    cout << "Admission Year: " << admissionYear << endl;
    cout << "Courses:\tCode:" << endl;
    for (int i = 0; i < numpreviouscouse; i++)
    {
        cout << "" << previousCourse[i] << "\t\t" << previousCourseCode[i] << endl;
    }
    cout << endl;
}