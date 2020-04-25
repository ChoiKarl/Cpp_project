//
//  main.cpp
//  析构函数
//
//  Created by 蔡浩浩 on 2020/4/21.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace std;

// 1: 析构函数在对象内存即将被回收的时候调用.
// 2: 析构函数有且只能有一个,不能重载
// 3: 如果外部需要手动delete,那么析构函数就必须是public的

class Car {
public:
    Car() {
        cout << "Car::Car()" << endl;
    }
    
    // 析构函数
    ~Car() {
        cout << "~Car()" << endl;
    }
};

class Person {
public:
    int age = 0;
    Car *car;
    void run() {
        
    }
    
    // 在析构函数里释放申请的内存
    ~Person() {
        delete car;
    }
};



Car g_car;
int main(int argc, const char * argv[]) {
    
    Car *car = new Car();
    
    Person *person = new Person();
    person->car = car;
    delete person;
    
    getchar();
    return 0;
}
