//
//  main.cpp
//  命名空间
//
//  Created by 蔡浩浩 on 2020/4/21.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
#include "Car.hpp"
#include "Student.hpp"

using namespace std;

class Person {
public:
    int height = 0;
};

// 定义命名空间
// 命名空间里可定义类,变量,函数.
namespace KL {
    int g_num;

    void func() {
        cout << g_num << endl;
    }

    class Person {
    public:
        int age = 0;
        Car *car;
        
        ~Person() {
            delete car;
        }
    };
}

//
void test2() {
    // 可以在函数中使用using namespace
    // 这个using namespace就只在当前函数的作用域中.
    using namespace KL;
    Student student;
    student.sudy();
}


int main(int argc, const char * argv[]) {
    test2();
    // 使用命名空间里面的类
    KL::Person *p = new KL::Person();
    delete p;
    
    KL::g_num = 100;
    
    KL::func();
    return 0;
}


void test() {
    KL::Person p;
    p.age = 18;
    
    // C++默认有个无名的命名空间
    // 这样就是使用外面的那个Person
    ::Person p1;
    p1.height = 188;
    
}
