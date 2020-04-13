//
//  math.h
//  extern c
//
//  Created by 蔡浩浩 on 2020/4/14.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#ifndef math_h
#define math_h

#include <stdio.h>

// __cplusplus是所有c++代码默认都会带的一个宏.
// 判断只有在c++的环境下才会extern "C", 这样在c和c++环境中就都可以用了.
#ifdef __cplusplus
extern "C" {
#endif

int sum(int num1, int num2);

#ifdef __cplusplus
}
#endif

#endif /* math_h */
