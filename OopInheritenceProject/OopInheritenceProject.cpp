// OopInheritanceProject.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
    string name;
    int age;
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

    User user("Bob", 23);

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
