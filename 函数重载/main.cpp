//
//  main.cpp
//  函数重载
//
//  Created by 蔡浩浩 on 2020/4/11.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace std;

// 函数重载的本质是name mangling.
// C++编译器会对函数的符号名(如函数名)进行改编和修饰.
// 例如下面函数编译完成后可能会变成:
// sumii, sumiii
// func1id, func1di.
// 不同的编译器修饰规则可能会不同.

// 参数个数不同,可以造成重载
int sum(int num1, int num2) {
    return num1 + num2;
}

int sum(int num1, int num2, int num3) {
    return num1 + num2 + num3;
}

// 参数类型不同,可以造成重载
void func1(int v1, double v2) {
    cout << "func1(int v1, double v2)" << endl;
}

void func1(double v1, int v2) {
    cout << "func1(double v1, int v2)" << endl;
}

 
int main(int argc, const char * argv[]) {
    
    cout << sum(10, 20) << endl;
    
    cout << sum(10, 20, 30) << endl;
    
    func1(10, 20.2);
    func1(20.2, 1);
    
    return 0;
}
