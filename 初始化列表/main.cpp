//
//  main.cpp
//  初始化列表
//
//  Created by 蔡浩浩 on 2020/4/22.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 1: 初始化列表的赋值顺序是按照定义变量的顺序来的.先定义的哪个变量,在初始化列表里就会先初始化哪个
 2: 参数默认值可以和初始化列表混着用
 3: 如果函数的声明和实现分开\
    * 默认参数必须放在声明里\
    * 初始化列表必须放在实现里
 */

int myAge() {
    cout << "myAge()" << endl;
    return 10;
}
int myHeight() {
    cout << "myHeight()" << endl;
    return 20;
}

class Person {
public:
    int age;
    int height;
    Person(int age = 0, int height = 0): height(myHeight()), age(myAge()) {
        
    }
};

class Student {
public:
    int score;
    Student(int score = 0);
};

Student::Student(int score): score(score) {}


int main(int argc, const char * argv[]) {
    
    Person per1;
    Person per2(10);
    Person per3(0, 0);
    
    cout << "age:" << per1.age << ", height:" << per1.height << endl;
    
    return 0;
}
