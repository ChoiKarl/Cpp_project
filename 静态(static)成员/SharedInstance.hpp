//
//  SharedInstance.hpp
//  静态成员
//
//  Created by 蔡浩浩 on 2020/4/25.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#ifndef SharedInstance_hpp
#define SharedInstance_hpp

#include <stdio.h>
#include <iostream>

class SharedInstance {
    SharedInstance();
    ~SharedInstance();
    static SharedInstance *_shared;
    static std::mutex m_Mutex;
public:
    static SharedInstance *sharedInstance();
    static void deleteSharedInstance();
};

#endif /* SharedInstance_hpp */
