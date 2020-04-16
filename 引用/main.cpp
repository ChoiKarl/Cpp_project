//
//  main.cpp
//  引用
//
//  Created by 蔡浩浩 on 2020/4/16.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace std;

void p_swap(int &a, int &b) {
    int tmp = b;
    b = a;
    a = tmp;
}


int main(int argc, const char * argv[]) {
    
    int age = 10;
    
    // 引用只能赋值变量(基本数据类型,枚举,结构体,类,指针,数组等都可以)
    // 一旦被赋值后不能在改变去引用其他变量.
    // 引用相当于变量的别名,可以用引用去操作变量.
    // 一个变量可以赋值多个引用.
    // 引用对比指针要更加安全.
    int &ref = age;
    int &ref2 = age;
    int &ref3 = age;
    
    ref = 100;
    cout << age << endl;
    
    ref2 = 1000;
    cout << age << endl;
    
    ref3 = 888;
    cout << age << endl;
    
    // 使用引用交换两个变量的值.
    // 通过引用在函数内部修改传进去的参数的值.
    int num1 = 1;
    int num2 = 2;
    p_swap(num1, num2);
    cout << "num1:" <<num1 << "num2:" << num2 << endl;
    
    return 0;
}
