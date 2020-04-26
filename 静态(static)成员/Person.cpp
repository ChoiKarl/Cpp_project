//
//  Person.cpp
//  静态成员
//
//  Created by 蔡浩浩 on 2020/4/25.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include "Person.hpp"
#include <iostream>

using namespace std;

// 初始化静态成员变量
int Person::age = 0;

void Person::run() {
    cout << "Person::run" << endl;
}
