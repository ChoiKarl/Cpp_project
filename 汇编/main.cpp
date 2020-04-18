//
//  main.cpp
//  汇编
//
//  Created by 蔡浩浩 on 2020/4/18.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {

    
}

void pointerTest() {
    /*
     // 10赋值给-0x14(%rbp), 也就是赋值给a
     0x100000e8f <+15>: movl   $0xa, -0x14(%rbp)
     // 将a的地址值给rax
     0x100000e96 <+22>: leaq   -0x14(%rbp), %rax
     // 将rax(也就是a的地址值)赋值给-0x20(%rbp),-0x20(%rbp)其实就是指针变量p
     0x100000e9a <+26>: movq   %rax, -0x20(%rbp)
     // 将-0x20(%rbp)赋值给rax,这个时候rax存储的就是指针变量p
     0x100000e9e <+30>: movq   -0x20(%rbp), %rax
     // 将20赋值给rax的地址里,因为rax这个时候是指针变量p,指针变量p又是指向a的地址的,所有相当于把20放进到了a对应的地址了,相当于修改了a的值.
     0x100000ea2 <+34>: movl   $0x14, (%rax)
     */
    int a = 10;
    int *p = &a;
    *p = 20;
}

// jump test
void test() {}
void jump() {
    /*
     jmp 0x000000000
     * 跳转到某个内存地址执行代码
     * J开头的一般都是跳转，大多数待条件的跳转，需要配合test、cmp等指令配合使用
     * je: jump equal // 相等时跳转
     * jnp: jump not equal //不相等时跳转
     * jle: jump less equal //小于等于时跳转
     * jge: jump greater equal //大于等于时跳转
     * jg: jump greater //大于时跳转
     * jl: jump less //小于时跳转
     */
    
    /*
     // 将4赋值给-0x14(%rbp),也就是a
     0x100000ee6 <+22>:  movl   $0x4, -0x14(%rbp)
     // 将10赋值给-0x18(%rbp),也就是b
     0x100000eed <+29>:  movl   $0xa, -0x18(%rbp)
     // 将a赋值eax
     0x100000ef4 <+36>:  movl   -0x14(%rbp), %eax
     // 比较b和eax
     0x100000ef7 <+39>:  cmpl   -0x18(%rbp), %eax
     // jne:jumo not equal(不等于), 比较结果不相等的话就跳转到0x100000f13,相等的话就接着往下执行
     0x100000efa <+42>:  jne    0x100000f13               ; <+67> at main.cpp:23:16
     // printf("a == b")
     0x100000f00 <+48>:  leaq   0x93(%rip), %rdi          ; "a == b"
     0x100000f07 <+55>:  movb   $0x0, %al
     0x100000f09 <+57>:  callq  0x100000f78               ; symbol stub for: printf
     // 跳转到0x100000f69,走到这个条件里,相当于其他的if条件都不需要走了,直接跳转出去
     0x100000f0e <+62>:  jmp    0x100000f69               ; <+153> at main.cpp:31:5
     // 走到这里相当于上一个条件没成立,将a赋值给eax
     0x100000f13 <+67>:  movl   -0x14(%rbp), %eax
     // 比较b和eax
     0x100000f16 <+70>:  cmpl   -0x18(%rbp), %eax
     // jge:jump greater equal(大于等于), 比较结果是大于等于的话,这个条件不成立,就跳转到0x100000f32, 成立就接着往下走
     0x100000f19 <+73>:  jge    0x100000f32               ; <+98> at main.cpp:25:16
     // printf("a < b")
     0x100000f1f <+79>:  leaq   0x7b(%rip), %rdi          ; "a < b"
     0x100000f26 <+86>:  movb   $0x0, %al
     0x100000f28 <+88>:  callq  0x100000f78               ; symbol stub for: printf
     // 跳转到 0x100000f64
     0x100000f2d <+93>:  jmp    0x100000f64               ; <+148> at main.cpp
     // 将a赋值给eax
     0x100000f32 <+98>:  movl   -0x14(%rbp), %eax
     // 比较b和eax
     0x100000f35 <+101>: cmpl   -0x18(%rbp), %eax
     // jle:jump less equal(小于等于),比较结果是小于等于的话,这个条件就不成立,就跳转到0x100000f51,成立就接着往下走
     0x100000f38 <+104>: jle    0x100000f51               ; <+129> at main.cpp:28:9
     // printf("a > b")
     0x100000f3e <+110>: leaq   0x62(%rip), %rdi          ; "a > b"
     0x100000f45 <+117>: movb   $0x0, %al
     0x100000f47 <+119>: callq  0x100000f78               ; symbol stub for: printf
     // 跳转到 0x100000f5f
     0x100000f4c <+124>: jmp    0x100000f5f               ; <+143> at main.cpp
     // printf("other")
     0x100000f51 <+129>: leaq   0x55(%rip), %rdi          ; "other"
     0x100000f58 <+136>: movb   $0x0, %al
     0x100000f5a <+138>: callq  0x100000f78               ; symbol stub for: printf
     // 跳转到 0x100000f64
     0x100000f5f <+143>: jmp    0x100000f64               ; <+148> at main.cpp
     // 跳转到 0x100000f69
     0x100000f64 <+148>: jmp    0x100000f69               ; <+153> at main.cpp:31:5
     // 调用test函数
     0x100000f69 <+153>: callq  0x100000ec0               ; test at main.cpp:12
     */
    int a = 4;
    int b = 10;
    
    if (a == b) {
        printf("a == b");
    } else if (a <= b) {
        printf("a < b");
    } else if (a > b) {
        printf("a > b");
    } else {
        printf("other");
    }
    
    test();
}
