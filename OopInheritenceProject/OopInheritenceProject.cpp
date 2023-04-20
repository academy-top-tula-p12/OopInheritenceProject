#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
    string name;
    int age;

    void Method()
    {
        cout << name << " - Base Method work\n";
    }

public:
    Person(string name, int age)
        : name{ name }, age{ age } 
    {
        cout << this << " Person construct\n";
    }
    string Name() { return name; }
    int& Age() { return age; }

    friend ostream& operator<<(ostream& out, const Person& person);

    string ToString()
    {
        return "Name: " + name + " (" + to_string(age) + ")";
    }

    void Method2()
    {
        cout << name << " - Base Method2 work\n";
    }

    ~Person()
    {
        cout << this << " Person destruct\n";
    }
};
ostream& operator<<(ostream& out, const Person& person)
{
    out << "Name: " << person.name << " (" << person.age << ")";
    return out;
}


//class User
//{
//    int code;
//    Person person;
//public:
//    User(string name, int age) : person(Person(name, age))
//    {
//        cout << this << " User construct\n";
//    }
//};


class Student : public Person
{
    string groupName;
public:
    Student(string name, int age) : Person(name, age)
    {
        cout << this << " Student construct\n";
    }

    string& GroupName() { return groupName; }

    void AddYear()
    {
        this->age++;
    }

    friend ostream& operator<<(ostream& out, const Student& student);

    string ToString()
    {
        return Person::ToString() + " Group: " + groupName;
    }

    using Person::Method;

    void Method2() = delete;

    ~Student()
    {
        cout << this << " Student destruct\n";
    }
};

ostream& operator<<(ostream& out, const Student& student)
{
    out << "Name: " << student.name << " ("
        << student.age << ")"
        << " Group: " << student.groupName;
    return out;
}

int main()
{
    /*Student student("Bob", 23);
    student.GroupName() = "PV21";
    cout << student << "\n";*/

    //User user("Bob", 23);

    Student student("Bob", 23);
    ((Person)student).Method2();

    static_cast<Person>(student).Method2();
}
