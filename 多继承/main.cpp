//
//  main.cpp
//  多继承
//
//  Created by 蔡浩浩 on 2020/4/24.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 C++支持多继承
 1: 先继承的类里的属性,会在对象内存的前面.
 2: 调用父类的构造函数,在初始化列表里依次调用父类的构造函数.
 3: 如果子类继承的多个父类都有虚函数,那么子类将会有多张虚表.
 4: 继承的多个父类有相同的方法,子类如果要用,子类就必须重写这个方法.如果希望单独调用某一个父类的方法,需要指定父类类型.
    Undergraduate un; // 实例化子类
    un.eat(); // 调用子类自己的方法
    un.Undergraduate::eat(); // 调用子类自己的方法,不过没必要这样写.
    un.Student::eat(); // 调用父类的方法
    un.Worker::eat(); // 调用父类的方法
 5: 继承的多个父类有同名的属性,子类如果要用,子类也必须重写这个属性.
    un.age = 10; // 给子类的age赋值
    un.Undergraduate::age = 10; // 给子类的age赋值,没必要这样写
    un.Student::age = 11; // 给父类的age赋值
    un.Worker::age = 12; // 给父类的age赋值
 */

class Student {
public:
    int age;
    int score;
    
    Student(int score): score(score) {}
    
    virtual void study() {
        cout << "study" << endl;
    }
    
    virtual void eat() {
        cout << "Student::eat" << endl;
    }
    
    virtual ~Student() {}
};

class Worker {
public:
    int age;
    int salary;
    
    Worker(int salary): salary(salary) {}
    
    virtual void work() {
        cout << "work" << endl;
    }
    
    virtual void eat() {
        cout << "Worker::eat" << endl;
    }
    
    virtual ~Worker() {}
};

class Undergraduate: public Student, public Worker {
public:
    int age;
    int grade;
    
    Undergraduate(): Student(0), Worker(0) {
        
    }
    
    Undergraduate(int grade, int score, int salary): grade(grade), Student(score), Worker(salary) {
        
    }
    
    void play() {
        cout << "play" << endl;
    }
    
    void eat() {
        cout << "Undergraduate::eat" << endl;
    }
};

int main(int argc, const char * argv[]) {
    
    Undergraduate un;
    un.eat();
    un.Student::eat();
    un.Worker::eat();
    un.Undergraduate::eat();
    
    un.age = 10; // 给子类的age赋值
    un.Undergraduate::age = 10; // 给子类的age赋值,没必要这样写
    un.Student::age = 11; // 给父类的age赋值
    un.Worker::age = 12; // 给父类的age赋值
    return 0;
}
