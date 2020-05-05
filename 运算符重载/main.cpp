//
//  main.cpp
//  运算符重载
//
//  Created by 蔡浩浩 on 2020/4/30.
//  Copyright © 2020 蔡浩浩. All rights reserved.
//

#include <iostream>
using namespace std;

class Point {
public:
    int x = 0;
    int y = 0;
    Point(int x, int y): x(x), y(y) {}
    
    void log() {
        cout << "(" << x << "," << y << ")" << endl;
    }
    
    
    const Point operator+(const Point &r) const {
        return Point(x + r.x, y + r.y);
    }

    const Point operator-(const Point &r) const {
        return Point(x - r.x, y - r.y);
    }

    Point& operator+=(const Point &r) {
        x += r.x;
        y += r.y;
        return *this;
    }

    Point& operator-=(const Point &r) {
        x -= r.x;
        y -= r.y;
        return *this;
    }

    bool operator<(const Point &r) const {
        return x < r.x && y < r.y;
    }

    bool operator>(const Point &r) const {
        return x > r.x && y > r.y;
    }

    bool operator==(const Point &r) const {
        return x == r.x && y == r.y;
    }

    bool operator<=(const Point &r) const {
        return *this < r || *this == r;
    }

    bool operator>=(const Point &r) const {
        return *this > r || *this == r;
    }

    const Point operator-() const {
        return Point(-x, -y);
    }
    
    // 前置++
    // ++p
    Point& operator++() {
        ++x;
        ++y;
        return *this;
    }
    
    // 后置++
    // p++
    const Point operator++(int) {
        Point old(x, y);
        x++;
        y++;
        return old;
    }
};


int main(int argc, const char * argv[]) {
    
    Point p1(1, 1);
    Point p2(2, 2);
    Point p3 = p1 + p2;
    p3.log();
    
    p3 += p1;
    p3.log();
    
    p3 -= p2;
    p3.log();
    
    Point p4 = -p3;
    p4.log();
    
    p4++;
    p4.log();
    
    (++p4) += p2;
    p4.log();
    
    return 0;
}
