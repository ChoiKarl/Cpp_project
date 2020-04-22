//
//  Car.hpp
//  命名空间
//
//  Created by 蔡浩浩 on 2020/4/21.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#ifndef Car_hpp
#define Car_hpp

#include <stdio.h>
// C++类的函数声明与实现分开写
class Car {
public:
    
    Car(int price);
    ~Car();
    
    int price;
    void run();
};

#endif /* Car_hpp */
