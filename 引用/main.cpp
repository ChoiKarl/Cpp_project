//
//  main.cpp
//  引用
//
//  Created by 蔡浩浩 on 2020/4/16.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace std;

// 引用的本质还是指针,是被编译器弱化了的指针.
// 引用只能赋值变量(基本数据类型,枚举,结构体,类,指针,数组等都可以)
// 一旦被赋值后不能在改变去引用其他变量.
// 引用相当于变量的别名,可以用引用去操作变量.
// 一个变量可以赋值多个引用.
// 引用对比指针要更加安全.

struct Test1 {
    int *number;
};

struct Test2 {
    int &number;
};


int main(int argc, const char * argv[]) {
    
    // 引用和指针占用的内存大小是一样的.
    cout << sizeof(Test1) << endl;
    cout << sizeof(Test2) << endl;
    
    // 通过汇编可以看出引用和指针是一样的.
    int age = 10;
    /* 指针的汇编
     0x1000010e4 <+20>: movl   $0xa, -0x14(%rbp)
     0x1000010eb <+27>: leaq   -0x14(%rbp), %rcx
     0x1000010ef <+31>: movq   %rcx, -0x20(%rbp)
     0x1000010f3 <+35>: movq   -0x20(%rbp), %rcx
     0x1000010f7 <+39>: movl   (%rcx), %edx
     0x1000010f9 <+41>: addl   $0x1, %edx
     
     int *ptr = &age;
     (*ptr) += 1;
     */
    
    /* 引用的汇编
     0x1000010e4 <+20>: movl   $0xa, -0x14(%rbp)
     0x1000010eb <+27>: leaq   -0x14(%rbp), %rcx
     0x1000010ef <+31>: movq   %rcx, -0x20(%rbp)
     0x1000010f3 <+35>: movq   -0x20(%rbp), %rcx
     0x1000010f7 <+39>: movl   (%rcx), %edx
     0x1000010f9 <+41>: addl   $0x1, %edx
     */
    int &ref = age;
    ref += 1;
    
    return 0;
}

void p_swap(int &a, int &b) {
    int tmp = b;
    b = a;
    a = tmp;
}


void test() {
    int age = 10;
    
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
}
