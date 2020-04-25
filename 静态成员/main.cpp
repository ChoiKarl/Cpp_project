//
//  main.cpp
//  静态成员
//
//  Created by 蔡浩浩 on 2020/4/25.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
#include "Person.hpp"
#include "SharedInstance.hpp"

using namespace std;

/*
 1: 静态成员变量必须要初始化(在Person.cpp里)
 2: 静态成员(变量\方法)对象和类都能去访问,不同的对象访问的是同一块内存.
 */

int main(int argc, const char * argv[]) {
    
    Person per;
    per.age = 1;
    per.run();
    
    Person per2;
    per2.age = 2;
    per2.run();
    
    Person *per3 = new Person();
    per3->age = 3;
    per3->run();
    delete per3;
    
    Person::age = 4;
    Person::run();
    
    cout << per2.age << endl;
    
    
    cout << SharedInstance::sharedInstance() << endl;
    cout << SharedInstance::sharedInstance() << endl;
    cout << SharedInstance::sharedInstance() << endl;
    
    return 0;
}
