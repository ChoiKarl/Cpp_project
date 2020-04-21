//
//  main.cpp
//  继承和成员的访问权限
//
//  Created by 蔡浩浩 on 2020/4/21.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace::std;

// 1: 类里面的3中访问权限
// 2: public: 任何地方都可以访问(struct的成员变量和继承的默认权限)
// 3: protected: 当前类和子类可以访问
// 4: private: 只有自己可以访问(class的成员变量和继承的默认权限)

// 1: 继承的方式也可以使用public\protected\private这三种方式去继承
/*
class A {
public:
 int num;
}
class B : private A {}
class C {}
 */
// 2: 如上继承方式,那么C就不能访问A里面定义的变量和方法,因为B是私有继承A的,那么A里面的东西只能在B里面用,B的子类是无法使用的.即使在A里面的变量和方法是用public定义的.
/*
class A {
private:
 int num;
}
class B : public A {}
class C {}
 */
// 3: 如上继承方式,A里面的num在B和C里面都无法使用.即使B用的public的方式去继承,因为A在定义的时候就规定num是私有的.
// 总结: 变量和方法的访问权限取决于变量定义的访问权限和父类继承的访问权限,取访问权限最低的那个.

// class定义的类,默认是private的方法去继承
// struct定义的类,默认是public方式去继承.


class Person {
public:
    int age;
private:
protected:
};

class Student: public Person {
public:
    int score;
};

class GoodStudent: public Student {
public:
    int money;
};


int main(int argc, const char * argv[]) {
    
    // 类占4个字节
    Person per;
    // 类占8个字节
    Student stu;
    // 类占12个字节
    GoodStudent gs;
    
    cout << sizeof(Person) << endl;
    cout << sizeof(Student) << endl;
    cout << sizeof(GoodStudent) << endl;
    
    return 0;
}
