//
//  main.cpp
//  菱形继承
//
//  Created by 蔡浩浩 on 2020/4/25.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 菱形继承:
 1: 如果Student和Worker没有虚继承Person,那个Undergraduate将没法使用age,因为Student和Worker都会从Person上继承到age,Undergraduate就会有两份age,使用age就会产生二义性.
 2: 使Student和Worker同时虚继承自Person就可以使用age
 3: 使用虚继承后,父类的属性将会加到本类的最后面.跟直接继承不一样,直接继承是加到最前面.
 */

class Person {
public:
    int age;
};

class Student: virtual public Person {
public:
    int score;
};

class Worker: virtual public Person {
public:
    int salary;
};

class Undergraduate: public Student, public Worker {
public:
    
};

int main(int argc, const char * argv[]) {
    
    Undergraduate ug;
    ug.age = 0;
    
    return 0;
}
