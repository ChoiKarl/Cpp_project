//
//  main.cpp
//  析构函数
//
//  Created by 蔡浩浩 on 2020/4/21.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace std;

// 1: 析构函数在对象内存即将被回收的时候调用.
// 2: 析构函数有且只能有一个,不能重载
// 3: 和构造函数一样,析构函数必须是public的.

class Car {
public:
    Car() {
        cout << "Car::Car()" << endl;
    }
    
    // 析构函数
    ~Car() {
        cout << "~Car()" << endl;
    }
};

Car g_car;
int main(int argc, const char * argv[]) {
    
    Car *car = new Car();
    delete car;
    
    getchar();
    return 0;
}
