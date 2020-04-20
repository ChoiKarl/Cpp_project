//
//  main.cpp
//  对象的内存管理
//
//  Created by 蔡浩浩 on 2020/4/20.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace std;

// 1: 使用malloc申请的内存,需要用frss来释放掉掉.
// 2: new 申请的内存,需要用delete来释放掉.
// 3: 使用new[]申请的内存,需要用delete[]来释放掉.
// 4: 通过memset初始化指针,可以将内存的每一个字节都初始化一个值, 具体见`C_StyleinitPointer`函数.


void CPP_StyleinitPointer();
int main(int argc, const char * argv[]) {
    CPP_StyleinitPointer();
    
}

void CPP_StyleinitPointer() {
    // 不给默认初始化值(xcode默认初始化为了0,但是有的平台没有初始化,就是垃圾数据)
    int *p = new int;
    // 默认初始化0
    int *p1 = new int();
    // 默认初始化6
    int *p2 = new int(6);
    
//    cout << *p << endl;
//    cout << *p1 << endl;
//    cout << *p2 << endl;
    
    delete p;
    delete p1;
    delete p2;
    
    // 未初始化,元素的值为垃圾数据.
    int *arr1 = new int[3];
    // 所有元素初始化为0
    int *arr2 = new int[3]();
    // 所有元素初始化为0
    int *arr3 = new int[3]{};
    // 首元素为5,其他元素初始化为0
    int *arr4 = new int[3]{5};
 
    for (int i = 0; i < 3; i++) {
        cout << *(arr1 + i) << endl;
    }
    
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
    delete [] arr4;
}


void C_StyleinitPointer() {
    // 不同的平台有不同的初始化效果,xcode默认就给初始化为了0,有的平台就没有给初始化,默认值是垃圾数据.
    int *intp = (int *)malloc(4);
    // memset可以初始化一个指针
    // memset(初始化的指针, 初始化的值, 初始化的长度);
    // 可以将内存的每一个字节都初始化一个值
    // 用下面的例子来说,申请了4个字节,每个字节占8位,每一个字节都初始化成1.
    // 0000 0001 0000 0001 0000 0001 0000 0001
    memset(intp, 1, 4);
    // 如果每一个字节都初始化成2
    // 0000 0010 0000 0010 0000 0010 0000 0010
    memset(intp, 2, 4);
    // 都初始化成0
    // 0000 0000 0000 0000 0000 0000 0000 0000
    memset(intp, 0, 4);
    cout << *intp << endl;
    free(intp);
}

void test() {
    int *intp = (int *)malloc(4);
    *intp = 10;
    cout << *intp << endl;
    free(intp);
    
    int *intp2 = new int();
    *intp2 = 22;
    cout << *intp2 << endl;
    delete intp2;
    
    char *charp = new char[4]();
    *charp = 'a';
    *(charp + 1) = 'b';
    *(charp + 2) = 'c';
    *(charp + 3) = 'd';
    for (int i = 0; i < 4; i++) {
        cout << *(charp + i) << endl;
    }
    delete [] charp;
}
