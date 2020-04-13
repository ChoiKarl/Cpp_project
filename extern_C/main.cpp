//
//  main.cpp
//  extern c
//
//  Created by 蔡浩浩 on 2020/4/14.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace std;

// 1: 被extern C修饰的代码,编译时是按照C语言的特性去编译.
// 2: 可单独修饰,也可用大括号括起来修饰.
// 3: 申明和实现分开写的函数,extern "C"要么只修饰申明,要么就申明和实现都修饰.不能只去修饰申明.
// 4: 直接用extern "C"去修饰c代码的头文件,就可以直接在c++里调用c的函数.
// 5: 如果想编写一个c语言和c++都能用的的库,就可以在c的.h文件里加上__cplusplus宏判断,详情见math.h.

// 例子1: 单独修饰: C语言没有函数重载,被extern "C" 修饰了以后,就会编译报错
extern "C"
void example1() {}
//extern "C"
//void example1(int i) {}


// 例子2: 大括号修饰
extern "C" {
    void example2() {}
//    void example2(int i) {}
}


// 例子3: 修饰申明和实现分开的函数
 extern "C"
 void example3();
 extern "C"
 void example3() {
     cout << "func" << endl;
 }


// 例子4: 可以直接用extern "C" 包含c的头文件,这样整个头文件的函数都能直接在c++中使用
 extern "C" {
    #include "math.h"
 }
// 也可以用extern "C"指到部分c语言的函数.
 extern "C" {
    int sum(int, int);
    void test();
 }

int main(int argc, const char * argv[]) {
    
    cout << sum(200, 300) << endl;
    test();
    return 0;
}
