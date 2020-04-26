//
//  main.cpp
//  const成员
//
//  Created by 蔡浩浩 on 2020/4/26.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 1: const变量必须要初始化,可以在定义变量的时候初始化,或者是在构造函数的初始化列表里面去初始化.
 2: const函数
 2.1: 如果声明和实现分开,那么声明和实现都要标记为const.
 2.2: const函数里面不能修改非静态的成员变量.
 2.3: const内部只能调用const函数和static函数.
 2.4: 非const函数可以调用const函数
 2.5: const成员函数和非const成员函数可以进行重载.如果重载了const成员函数,那么只有创建const对象才能调用到const成员函数,而非const对象调用的都是非const成员函数.\
      如果没有重载const成员函数,那么const对象和非const对象都能调用到const成员函数.\
 3: const对象不能调用非const成员函数.(因为非const函数内部可能修改变量,但是const对象的变量值是不允许修改的.)

 */
class Person {
public:
    static int height;
    const int age = 0;
    
    Person(): age(0) {}
    
    void run() const;
    
    // 重载const函数.
    void run() {
        cout << "void run()" << endl;
    }
    
    void study() const {
        cout << "study() const" << endl;
    }
    
    static void test() {
        
    }
    
};

// 如果声明和实现分开,实现也要加const.
void Person::run() const {
    height = 181;
    test();
    cout << "run() const" << endl;
}

int Person::height = 180;

int main(int argc, const char * argv[]) {
    
    Person per;
    per.run(); // 调用的是非const函数
    
    const Person per1;
    per1.run(); // 调用的是const函数
    
    return 0;
}
