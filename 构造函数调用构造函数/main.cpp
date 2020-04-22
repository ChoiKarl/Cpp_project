//
//  main.cpp
//  构造函数调用构造函数
//
//  Created by 蔡浩浩 on 2020/4/22.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 1: 构造函数调用构造函数,只能写在初始化列表里面.
 2: 如果父类有无参构函数,子类的构造函数会默认调用父类的无参构造函数
 3: 如果父类没有构造函数,子类则不会默认去调用父类的构造函数.
 4: 如果子类显示调用了父类的有参构造函数,则不会再去默认调用父类的无参构造函数
 5: 如果父类只有有参的构造函数,没有无参的构造函数,子类必须显示的调用父类的有参构造函数.
 */

class Person {
public:
    int age;
    
    Person(): Person(0) {
        cout << "Person()" << endl;
    }
    
    Person(int age): age(age) {
        cout << "Person(int age)" << endl;
    }
};

class Student: Person {
public:
    int score;
    Student() {
        cout << "Student()" << endl;
    }
};


int main(int argc, const char * argv[]) {
    
    Person per;
    cout << per.age << endl;
    
    Student stu;
    return 0;
}
