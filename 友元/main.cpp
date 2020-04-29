//
//  main.cpp
//  友元
//
//  Created by 蔡浩浩 on 2020/4/29.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <stdio.h>
using namespace std;

/*
 1: 友元函数:
    在友元函数里可以访问类的私有私有属性.
    友元函数只允许是全局函数,即定义在类外面的函数.
 
 2: 友元类:
    在友元类里可以访问当前类的私有属性.
 
 3: 友元函数或者类可以写在类的任意位置.
 */

class Car {
    friend class Person;
    friend void setPrict(int);
    
    int price;
    
    void fly() {}
public:
    void run() {
        
    }
};

class Person {
    int age;
public:
    Person() {
        // Person是Car的友元类,所以可以访问Car的私有变量.
        Car car;
        car.price = 100;
    }
};

// setPrict是Car的友元函数,所以可以访问Car里面的私有变量和方法.
void setPrict(int price) {
    Car car;
    car.price = price;
    car.fly();
}

int main(int argc, const char * argv[]) {
    
    Car car;
//    car.fly();
    return 0;
}
