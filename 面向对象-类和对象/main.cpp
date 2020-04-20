//
//  main.cpp
//  面向对象-类和对象
//
//  Created by 蔡浩浩 on 2020/4/19.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace std;

// 1: 在C++中,struct和class都可以定义类,唯一的区别就是struct里的所有变量和属性默认都是`public`的.\
    而class定义的类默认是`private`的
// 2: 用指针定义的对象`Car *car = new Car()`需要用->去访问成员变量和调用方法.\
    直接用`Car car;`这样去定义的对象,可以直接用点语法去访问变量和调用方法.
// 3: new出来的对象是在堆空间,需要手动去释放对象; 非new出来的对象是在栈空间,释放由系统去管理.
// 3: 对象的属性在每一个对象里都会存储一份,但是方法在整个类里只有一份且存放在代码区,调用时是直接用`call 函数地址`这样直接调用的
// 4: 调用一个函数的时候,相当于去申请了一块栈空间,但是这块空间可能是之前用过的,里面存在垃圾数据,所有在用之前,会将栈空间全部用`cc`去填充满.

struct Car {
    int price;
    void run() {
        cout << price << endl;
    }
};

class Person {
public:
    int age;
    int id;
    int height;
    
    void test() {
        cout << "age: " << age << ", id: " << id << ", height: " << height << endl;
    }
};

void test() {
    /*
     -0x10(%rbp)就是per的内存地址,直接将10赋值给内存,相当于赋值给了第一个变量,per.age = 10;
     0x1000010f8 <+8>:  movl   $0xa, -0x10(%rbp)
     // 偏移4个字节,赋值给id
     0x1000010ff <+15>: movl   $0x14, -0xc(%rbp)
     // 偏移8个字节,赋值给height
     0x100001106 <+22>: movl   $0x1e, -0x8(%rbp)
     // 将per这个变量的地址赋值给rdi
     0x10000110d <+29>: leaq   -0x10(%rbp), %rdi
     // 调用test函数
     0x100001111 <+33>: callq  0x100001130               ; Person::test at main.cpp:33
     // 将per这个变量的地址赋值给rax
     0x100001116 <+38>: leaq   -0x10(%rbp), %rax
     // 将rax赋值给-0x18(%rbp),由于rax现在存放的是一个地址,能接收地址的是一个指针,所以-0x18(%rbp)就是指针变量p
     0x10000111a <+42>: movq   %rax, -0x18(%rbp)
     // 将指针的值赋值给rax,也就是将per的内存地址赋值给rax
     0x10000111e <+46>: movq   -0x18(%rbp), %rax
     // 将18赋值到内存中.
     0x100001122 <+50>: movl   $0x12, (%rax)
     */
    Person per;
    per.age = 10;
    per.id = 20;
    per.height = 30;
    per.test();
    
    Person *p = &per;
    p->age = 18;
}

int main(int argc, const char * argv[]) {
    /*
     // 初始化一个对象
     0x100001144 <+20>:  callq  0x100001dfa               ; symbol stub for: operator new(unsigned long)
     0x100001149 <+25>:  xorl   %esi, %esi
     0x10000114b <+27>:  movq   %rax, %rcx
     0x10000114e <+30>:  movq   %rcx, %rdi
     0x100001151 <+33>:  movl   $0xc, %edx
     0x100001156 <+38>:  movq   %rax, -0x20(%rbp)
     0x10000115a <+42>:  callq  0x100001e0c               ; symbol stub for: memset
     
     // -0x20(%rbp)所对应的应该是Person()申请的内存, 赋值给rax
     0x10000115f <+47>:  movq   -0x20(%rbp), %rax
     // 将rax赋值给-0x18(%rbp), 因为rax现在对应的是一个地址了,能接收地址的肯定是一个指针,所有-0x18(%rbp)就是per这个指针变量的地址
     0x100001163 <+51>:  movq   %rax, -0x18(%rbp)
     // 将per指针所指向的内存地址赋值给rcx
     0x100001167 <+55>:  movq   -0x18(%rbp), %rcx
     // (%rcx)取出地址,将10放进去,也就相当于给第一个变量赋值,也就是age
     0x10000116b <+59>:  movl   $0xa, (%rcx)
     // 再将per指向的内存地址赋值给rcx
     0x100001171 <+65>:  movq   -0x18(%rbp), %rcx
     // (%rcx)是取出地址,+0x4,就是在地址上偏移4个字节,也就是id变量,将6赋值给id.
     0x100001175 <+69>:  movl   $0x6, 0x4(%rcx)
     // 再将per指向的内存地址赋值给rcx
     0x10000117c <+76>:  movq   -0x18(%rbp), %rcx
     // 将20赋值给偏移8个字节的那块内存,也就是给height赋值20.
     0x100001180 <+80>:  movl   $0x14, 0x8(%rcx)
     // 将per指针指向的内存赋值给rdi, 传入到test函数中
     0x100001187 <+87>:  movq   -0x18(%rbp), %rdi
     // 调用test
     0x10000118b <+91>:  callq  0x1000011a0               ; Person::test at main.cpp:33
     */
    Person *per = new Person();
    per -> age = 10;
    per -> id = 6;
    per -> height = 20;
    per -> test();
    
    delete per;
}
