//
//  main.cpp
//  函数默认参数
//
//  Created by 蔡浩浩 on 2020/4/12.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace std;

// 默认值必须是从右往左
// 如果函数又有声明又有实现,默认参数只能放在声明中.
// 默认参数的值可以是常量,全局符号(全局变量,函数名)
void func(int v1, int v2 = 3) {}

void func1(int v1 = 1, int v2 = 2);

int a = 10;
void func2(int v1, int v2 = a) {
    cout << v1 << "," << v2 << endl;
}

// 默认参数也可以是一个函数名
void func3(int v1, void(*f)(int, int) = func2) {
    f(v1, 20);
}


int main(int argc, const char * argv[]) {
    
    func(1);
    func1();
    func2(10);
    func3(100);
    
    return 0;
}


void func1(int v1, int v2) {
    
}
