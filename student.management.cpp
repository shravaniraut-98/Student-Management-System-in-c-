#include <iostream>
#include <fstream>
using namespace std;
class Student
{
public:
    int rollno;
    char name[50];
    float marks;

    void getData()
    {
        cout << "Enter Roll No: ";
        cin >> rollno;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void showData()
    {
        cout << "\nRoll No: " << rollno;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks << endl;
    }
};
  void addStudent()
{
    Student s;
    ofstream file("student.data");

    s.getData();

    file.write((char*)&s, sizeof(s));

    file.close();

    cout << "\nRecord Added Successfully\n";
    return;
}
void displayStudents()
{
    Student s;
    ifstream file("student.data");

    while(file.read((char*)&s, sizeof(s)))
    {
        s.showData();
    }

    file.close();
}
void searchStudent()
{
    int roll;
    Student s;

    cout << "Enter Roll No: ";
    cin >> roll;

    ifstream file("student.dat");

    while(file.read((char*)&s, sizeof(s)))
    {
        if(s.rollno == roll)
        {
            s.showData();
            return;
        }
    }

    cout << "Record Not Found";
    file.close();
}
void deleteStudent()
{
    int roll;
    Student s;

    cout << "Enter Roll No to Delete: ";
    cin >> roll;

    ifstream file("student.data");
    ofstream temp("temp.data");

    while(file.read((char*)&s, sizeof(s)))
    {
        if(s.rollno != roll)
        {
            temp.write((char*)&s, sizeof(s));
        }
    }

    file.close();
    temp.close();

    remove("student.data");
    rename("temp.data","student.data");

    cout << "Record Deleted";
}
void updateStudent()
{
    int roll;
    Student s;

    cout << "Enter Roll No to Update: ";
    cin >> roll;

    fstream file("student.data");

    while(file.read((char*)&s, sizeof(s)))
    {
        if(s.rollno == roll)
        {
            cout << "Enter New Details:\n";
            s.getData();

            file.seekp(sizeof(s));

            file.write((char*)&s, sizeof(s));

            cout << "Record Updated";
            break;
        }
    }

    file.close();
}
int main()
{
    int choice;

    do
    {
        cout << "\n===== Student Management System =====";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student";
        cout << "\n4. Update Student";
        cout << "\n5. Delete Student";
        cout << "\n6. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: cout<<"Thank You"; break;
            default: cout<<"Invalid Choice";
        }

    } while(choice != 6);

    return 0;
}