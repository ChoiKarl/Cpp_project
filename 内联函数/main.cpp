//
//  main.cpp
//  内联函数
//
//  Created by 蔡浩浩 on 2020/4/15.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace std;

// 1: inline是编译器特性,会将整个函数体直接放在调用的地方.
// 2: 如果函数申明和函数实现分开写的话,建议申明和实现都加上inline.(只加一个地方也可以)
// 3: 递归函数就算标记为inline也不会生效.

inline int sum(int a, int b) {
    return a + b;
}

inline void test();
inline void test() {
    cout << "test()" << endl;
}

int main(int argc, const char * argv[]) {
    
    int res = sum(6, 7);
    cout << res << endl;
    
    return 0;
}
