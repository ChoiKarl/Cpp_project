//
//  Person.hpp
//  静态成员
//
//  Created by 蔡浩浩 on 2020/4/25.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>

/*
 静态变量必须需要初始化.在Person.cpp文件里.
 */
class Person {
    
public:
    static int age;
    static void run();
};

#endif /* Person_hpp */
