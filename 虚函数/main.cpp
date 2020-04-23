//
//  main.cpp
//  虚函数
//
//  Created by 蔡浩浩 on 2020/4/23.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 1: 想让父类指针能够指向子类对象,那个子类必须是用public的方式去继承父类才行.
 2: C++中,如果父类指针指向之类对象,那么用父类指针调用方法,其实调用的还是父类自己的方法.\
    在C++中只看指针类型,不看实际类型.你的指针类型是什么就会调用那个类型的方法.
 3: 在C++中想要实现多态需要用到虚函数(virtual),在父类需要多态的方法前面加上virtual关键字,这样这个方法就可以实现多态.而且如果父类的方法写了virtual,子类就可以不用写了.
 */

/*原理:
 1: 虚函数存在虚表里,虚表的地址是存放在对象的前4个字节里.
    调用虚函数时会现在对象的前4个字节里取出虚表的地址,然后在虚表里找到真实的函数地址.虚函数在虚表里是挨着的,通过地址偏移就可以调用到所有的虚函数.
 2: 相同类型的对象指向的是同一张虚表.
 3: 只要父类在函数前声明了`virtual`,就算子类不去重写,也会在子类的虚表里.
 4: 父类的函数前面声明了`virtual`, 父类对象自己调用虚函数,也是从虚表里面调用的.
 5: 有虚函数的类,析构函数也要声明为虚函数,要不然在父类指针指向子类对象的时候,释放只会调用父类的析构,不会调用子类的析构.
 */


class Animal {
public:
    virtual void speak() {
        cout << "Animal::speak()" << endl;
    }
    
    virtual void run() {
        cout << "Animal::run()" << endl;
    }
    
    virtual void eat() {
        cout << "Animal::eat()" << endl;
    }
};

class Dog: public Animal {
public:
    void speak() {
        Animal::speak();
        cout << "Dog::speak()" << endl;
    }
    
    void run() {
        cout << "Dog::run()" << endl;
    }
    
    
};

int main(int argc, const char * argv[]) {
    
    Dog *dog = new Dog();
    Animal *ani = dog;
    ani->speak();
    ani->run();
    ani->eat();
    
    return 0;
}
