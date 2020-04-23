//
//  main.cpp
//  抽象类和纯虚函数
//
//  Created by 蔡浩浩 on 2020/4/23.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 1: 只有声明没有实现且初始化为0的虚函数叫做纯虚函数,用来定义接口.
 2: 有纯虚函数的类叫做抽象类,抽象类不能实例化.
 3: 抽象类也可以有非纯虚函数,也可以定义变量.
 4: 如果父类是抽象类,子类也没有完全实现父类的纯虚函数,那么这个子类也还是抽象类.
 */

// 抽象类
class Animal {
public:
    int age;
    
    virtual void speak() = 0;
    virtual void run() = 0;
    virtual void eat() {
        cout << "Animal::eat" << endl;
    }
};

// 没有完全实现抽象类的纯虚函数,所以这个类也还是抽象类
class Dog: Animal {
public:
    
    void run() {
        cout << "Dog:run" << endl;
    }
    void eat() {
        cout << "Dog::eat" << endl;
    }
};

// 可以实例化,父类实现了部分纯虚函数,自己实现了剩下的纯虚函数.
class HaShiQi: Dog {
public:
    void speak() {
        cout << "HaShiQi:speak" << endl;
    }
};

// 可以实例化,实现了所有纯虚函数
class Cat: Animal {
public:
    void speak() {
        cout << "Dog:speak" << endl;
    }
    
    void run() {
        cout << "Dog:run" << endl;
    }
    
    void eat() {
        cout << "Dog::eat" << endl;
    }
};

int main(int argc, const char * argv[]) {
    
//    Animal ani;
//    Dog dog;
    Cat cat;
    HaShiQi hsq;
    return 0;
}
