#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string> 
#include <stdlib.h>
#include <crtdbg.h>
using namespace std;

//enumerated list for departments
enum Department {math, science, engineering, english, arts, music, none} department;

class Student{
    
    private:
    int  ID;
    string firstName;
    string lastName;
    float GPA;
    
public:
    //default constructor
    Student(){
        ID = 0;
        firstName = "";
        lastName  = "";
        GPA = 0.0;
    }
    //parametrized student constructor
    Student(int ID, string firstName, string lastName, float GPA){
        this->ID = ID;
        this->firstName = firstName;
        this->lastName = lastName;
        this->GPA = GPA;
    }
    
    //copy constructor
    Student(Student &init){
        this->ID = init.ID;
        this->firstName = "Shaquille";
        this->lastName = "O'neal";
        this->GPA = init.GPA;
    }
    
    //accessors
    int getStudentID() const{
        return ID;
    }
    string getStudentFirstName() const{
        return firstName;
    }
    string getStudentLastName() const{
        return lastName;
    }
    float getStudentGPA() const {
        return GPA;
    }
    
    //mutators
    void setStudentID(int newID){
        ID = newID;
    }
    void setStudentFirstName(string newFirstName){
        firstName = newFirstName;
    }
    void setStudentLastName(string newLastName){
        lastName = newLastName;
    }
    void setStudentGPA(float newGPA){
        GPA = newGPA;
    }
    
    friend ostream& operator << (ostream& ostr, const Student& stud);
    
    //destructor
    ~Student(){
        printf("\n");
        cout << "Destroyed Student(s)" << endl;
    }
};

ostream& operator << (ostream& ostr, const Student& stud){
    ostr << stud.getStudentID() << ", " << stud.getStudentFirstName() << ", " << stud.getStudentLastName() << ", " << stud.getStudentGPA();
    return ostr;
}

class Professor : public Student{
    
private:
    
    Department department;
    int ID;
    string firstName;
    string lastName;
    float salary;
    bool tenured;

public:
    
    //default professor constructor
    Professor(){
        department = none;
        ID = 0;
        firstName = "";
        lastName  = "";
        salary = 0.0;
        tenured = 0;
    }
    
    //parametrized professor constructor
    Professor(Department department, int ID, string firstName, string lastName, float salary, bool tenured){
        this->department = department;
        this->ID = ID;
        this->firstName = firstName;
        this->lastName = lastName;
        this->salary = salary;
        this->tenured = tenured;
    }
    
    //copy constructor
    Professor(Professor &init){
        this->department = init.department;
        this->ID = init.ID;
        this->firstName = "Al";
        this->lastName = "Gore";
        this->salary = init.salary;
        this->tenured = 0;
    }
    
    //accessors
    float getSalary() const {
        return salary;
    }
    
    float getTenured() const {
        return tenured;
    }
    
    float getDepartment() const {
        return department;
    }
    
    //mutators
    void setSalary(float newSalary){
        salary = newSalary;
    }
    
    void setTenured(float newTenured){
        tenured = newTenured;
    }
    
    void setDepartment(Department newDepartment){
        department = newDepartment;
    }
    
    friend ostream& operator << (ostream& ostr, const Professor& prof);
    
    //destructor
    ~Professor(){
        printf("\n");
        cout << "Destroyed Professor(s)" << endl;
    }
};

ostream& operator << (ostream& ostr, const Professor& prof){
    ostr << prof.getStudentID() << ", " << prof.getStudentFirstName() << ", " << prof.getStudentLastName() << ", " << prof.getSalary() << ", " 
        << prof.getTenured() << ", " << prof.getDepartment();
    return ostr;
}

class Employee : public Student{
    
    private:
    int  ID;
    string firstName;
    string lastName;
    float salary;
    
public:

    // default constructor
    Employee(){
        ID = 0;
        firstName = "";
        lastName  = "";
        salary = 0.0;
    }
        
    // parametrized employee constructor
    Employee(int ID, string firstName, string lastName, float salary){
        this->ID = ID;
        this->firstName = firstName;
        this->lastName = lastName;
        this->salary = salary;
    }
    
    //copy constructor
    Employee(Employee &init){
        this->ID = init.ID;
        this->firstName = "Marie";
        this->lastName = "Curie";
        this->salary = init.salary;
    }
    
    //accessors
    float getSalary() const {
        return salary;
    }
    
    //mutators
    void setSalary(float newSalary){
        salary = newSalary;
    }
    
    friend ostream& operator << (ostream& ostr, const Employee& emp);
    
    //destructor
    ~Employee(){
        printf("\n");
        cout << "Destroyed Employee(s)" << endl;
    }
};

ostream& operator << (ostream& ostr, const Employee& emp){
    ostr << emp.getStudentID() << ", " << emp.getStudentFirstName() << ", " << emp.getStudentLastName() << ", " << emp.getSalary();
    return ostr;
}

int main()
{

    //Professor tests
    printf("\n");
    cout << "Professor Tests" << endl;
    
    Professor p1;
    
    //cout << p1 << endl;
    
    p1.setDepartment(math);
    p1.setStudentFirstName("Eric");
    p1.setStudentLastName("Holder");
    p1.setStudentID(821);
    p1.setSalary(200000);
    p1.setTenured(1);
    
    cout << p1 << endl;
    
    //copy
    //Employee Tests
    
    printf("\n");
    cout << "Employee Tests" << endl;
    
    Employee e2;
    
    e2.setStudentID(523);
    e2.setStudentFirstName("Niels");
    e2.setStudentLastName("Bohr");
    e2.setSalary(385888);
    
    cout << e2 << endl;
    
    _CrtDumpMemoryLeaks();
}


