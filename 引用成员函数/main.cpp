//
//  main.cpp
//  引用成员函数
//
//  Created by 蔡浩浩 on 2020/4/26.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace std;

// 引用成员函数必须在定义的时候就要初始化,或者在构造函数里面进行初始化.
class Person {
public:
    int age = 0;
    int &refAge = age;
    
    Person() {
        
    }
    
    Person(int &age): refAge(age) {
        
    }
};

int main(int argc, const char * argv[]) {
    
    // 修改num或者修改refAge也都能互相影响到.
    int num = 100;
    Person per(num);
    cout << per.refAge << endl;
    per.refAge = 200;
    cout << num << endl;
    
    
    // ====================
    // 修改age或者修改refAge都会互相影响到
    Person per2;
    per2.age = 101;
    cout << per2.refAge << endl;
    per2.refAge = 202;
    cout << per2.age << endl;
    
    return 0;
}
