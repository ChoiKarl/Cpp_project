//
//  main.cpp
//  对象属性的初始化
//
//  Created by 蔡浩浩 on 2020/4/21.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>

#include <iostream>
using namespace std;

// 0: 注意:!! xcode给所有情况创建的都默认初始化了,其他ide不一定会这么做.
// 1: 在默认情况下,类如果没有提供构造方法,那就只有全局对象或者是调用了Person()这种形式来创建出来的对象.对象里的属性才会被初始化
// 2: 如果类提供了初始化方法,那么就只有全局区的对象会被默认初始化,其他的都不会默认初始化

class Person {
public:
    int age;
};

// 全局的变量
Person g_per;
int main(int argc, const char * argv[]) {
    
    Person per1;
    
    Person *per2 = new Person;
    Person *per3 = new Person();
    
    cout << g_per.age << endl;
    cout << per1.age << endl;
    cout << per2->age << endl;
    cout << per3->age << endl;
    
    delete per2;
    delete per3;
    
    return 0;
}
