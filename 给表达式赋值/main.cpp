//
//  main.cpp
//  给表达式赋值
//
//  Created by 蔡浩浩 on 2020/4/15.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int a = 10;
    int b = 20;
    
    // 在C++中可以给表达式赋值
    // a += b =>> a = a + b, 所以100会赋值是a.
    (a += b) = 100;
    
    cout << a << endl;
    cout << b << endl;
    
    bool f = true;
    
    // f为true,200会赋值给a, f为false,200会赋值给b.
    (f ? a : b) = 200;
    cout << a << endl;
    cout << b << endl;
    return 0;
}
