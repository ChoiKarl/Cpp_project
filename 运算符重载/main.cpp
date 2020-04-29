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
};

Point operator+(const Point &l, const Point &r) {
    return Point(l.x + r.x, l.y + r.y);
}

Point operator-(const Point &l, const Point &r) {
    return Point(l.x - r.x, l.y - r.y);
}

void operator+=(Point &l, const Point &r) {
    l.x += r.x;
    l.y += r.y;
}

void operator-=(Point &l, const Point &r) {
    l.x -= r.x;
    l.y -= r.y;
}

bool operator<(const Point &l, const Point &r) {
    return l.x < r.x && l.y < r.y;
}

bool operator>(const Point &l, const Point &r) {
    return l.x > r.x && l.y > r.y;
}

bool operator==(const Point &l, const Point &r) {
    return l.x ==r.x && l.y == r.y;
}

bool operator<=(const Point &l, const Point &r) {
    return l < r || l == r;
}

bool operator>=(const Point &l, const Point &r) {
    return l > r || l == r;
}

Point operator-(const Point &point) {
    return Point(-point.x, -point.y);
}

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
    
    
    return 0;
}
