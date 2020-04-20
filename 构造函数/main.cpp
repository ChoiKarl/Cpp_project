//
//  main.cpp
//  构造函数
//
//  Created by 蔡浩浩 on 2020/4/21.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace std;


// 1: 对象一旦被初始化,就一定会调用构造函数
// 2: 一旦自定义了构造函数,就必须要用自定义的构造函数来初始化对象
// 3: 构造函数也可以重载

class Person {
    int age = 0;
public:
    // 构造函数
    Person() {
        age = 0;
        cout << "Person()" << endl;
    }
    
    // 重载构造函数
    Person(int age) {
        this->age = age;
        cout << "Person(int age)" << endl;
    }
    
    void setAge(int value) {
        age = value;
    }
    
    int getAge() {
        return age;
    }
    
    void log() {
        cout << "age: " << age << endl;
    }
};

// 调用无参的构造函数
Person g_per;
int main(int argc, const char * argv[]) {
    
    // 调用无参的构造函数
    Person *per  = new Person;
    per->log();
    delete per;
    
    // 调用无参的构造函数
    Person *per1 = new Person();
    per1->log();
    delete per1;
    
    // 调用传参的构造函数
    Person *per2 = new Person(22);
    per2->log();
    delete per2;
    
    // 调用无参的构造函数
    Person per3;
    per3.log();
    
    // 调用传参的构造函数
    Person per4(20);
    per4.log();
    
    // 调用传参的构造函数
    Person per5 = Person(99);
    per5.log();
    
    // 调用无参的构造函数
    Person per6 = Person();
    per6.log();
    
    // 这个也是调用构造函数,只是没有变量接收返回值.
    Person Person(77);
    
    // !!这不是调用构造函数, 这只是一个函数申明,
    //Person Person();
    return 0;
}
