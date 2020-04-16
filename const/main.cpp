//
//  main.cpp
//  const
//
//  Created by 蔡浩浩 on 2020/4/16.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace std;
// const只修饰其右边的内容

struct Person {
    int age;
};

int main(int argc, const char * argv[]) {
    
    Person per = {18};
    Person per2 = {30};
    
    const Person *p = &per;
    // 被const修饰的结构体指针,不但是指针不能被修改,就连其指向的结构体的内容也不能被修改
    // (*p).age = 20;
    // p->age = 20;
    
    // p没有被修饰,所有可以改.
    p = &per2;
    // p->age = 10; // 不能被修改
    
    cout << per.age << endl;
    cout << (*p).age << endl;
    
    return 0;
}


void test() {
    int age = 10;
    int number = 20;
        
    const int *p1 = &age;
    int const *p2 = &age;
    int * const p3 = &age;
    const int * const p4 = &age;
    int const * const p5 = &age;
        
        
    // *p1 = number; // 报错,const修饰右边的内容,也就是修饰了*p1,所以*p1不能改.
    p1 = &number; // 但是p1没有被修饰,虽有p1可以改.
        
    // p2同p1.
    // *p2 = number;
    p2 = &number;
        
    *p3 = number; // const修饰的是p3,所有*p3可以改
    // p3 = &number; // p3被const修饰,所有p3不能改.
        
    // *p4 和 p4都被const修饰,所有都不能修改
    // *p4 = number;
    // p4 = &number;
        
    // p5同p4;
    //    *p5 = number;
    //    p5 = &number;
    
}
