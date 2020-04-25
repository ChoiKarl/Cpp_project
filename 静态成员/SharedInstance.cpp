//
//  SharedInstance.cpp
//  静态成员
//
//  Created by 蔡浩浩 on 2020/4/25.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include "SharedInstance.hpp"
#include <pthread.h>
#include <iostream>


pthread_mutex_t _lock = PTHREAD_MUTEX_INITIALIZER;

SharedInstance::SharedInstance() {}
SharedInstance::~SharedInstance() {}

SharedInstance * SharedInstance::_shared = NULL;
SharedInstance * SharedInstance::sharedInstance() {
    if (_shared == NULL) {
        pthread_mutex_lock(&_lock);
        _shared = new SharedInstance();
        pthread_mutex_unlock(&_lock);
    }
    return _shared;
}

void SharedInstance::deleteSharedInstance() {
    if (_shared != NULL) {
        delete _shared;
        _shared = NULL;
    }
}

