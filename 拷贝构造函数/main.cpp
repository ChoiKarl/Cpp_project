//
//  main.cpp
//  拷贝构造函数
//
//  Created by 蔡浩浩 on 2020/4/26.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 1: 拷贝构造函数的书写格式是固定的.
 2: 如果对象没有实现拷贝构造函数,但是你用拷贝的形式去创建一个新对象,这个时候其实内部并没有去拷贝,只是将一个对象里面的值挨个赋值给另一个对象.
 3: 可以在拷贝构造函数的初始化列表里调用父类的拷贝函数去初始化写在父类里面的属性.
 */

class Car {
private:
    // deep copy
    void copyName(const char *name) {
        if (name == NULL) return;

        // c语言字符串最后会多一位'\0'表示结尾.
        this->name = new char[strlen(name) + 1]{};
        strcpy(this->name, name);
    }
    
public:
    int price;
    char *name;
    
    Car(const char *name = NULL, int price = 0): price(price) {
        copyName(name);
        cout << "Car(const char *name = NULL, int price = 0)" << endl;
    }
    
    Car(const Car &car): price(car.price) {
        copyName(car.name);
    }

    ~Car() {
        if (name == NULL) return;
        delete [] name;
    }
};

class Person {
public:
    int age;
    int height;
    int weight;
    Person(int age, int height, int weight): age(age), height(height), weight(weight) {
        cout << "Person(int age, int height)" << endl;
    }
    
    // 拷贝构造函数
    Person(const Person &person): age(person.age), height(person.height) {
        cout << "Person(const Person &person)" << endl;
    }
    
    void desc() {
        cout << "age:" << age << ", height:" << height << ", weight:" << weight << endl;
    }
};

class Student: public Person {
public:
    int score;
    Car car;
    
    Student(int score, Car car): Person(0, 0, 0), score(score), car(car) {
        
    }
    
    // 可以调用父类的拷贝构造函数去拷贝父类里面的属性.
    Student(const Student &student): Person(student), score(student.score), car(student.car) {

    }
};



int main(int argc, const char * argv[]) {
    
    const char *name = "bmw";
    Car car(name, 100);
    cout << car.name << endl;
    
    Car car2(car);
    
    
    Student stu1(100, car);
    
    Student stu2(stu1);
    
    Person per1(1, 2, 3);
    per1.desc();
    
    Person per2(per1);
    per2.desc();
    
    // 这个等价于Person per3(per2),也会调用拷贝构造函数
    Person per3 = per2;
    
    per2.age = 99;
    per1.desc();
    per2.desc();
    
    
    return 0;
}
