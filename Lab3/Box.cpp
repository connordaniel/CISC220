#include "Box.h"
#include <iostream>
using namespace std;

Box::Box(double lenIn, double widthIn, double heightIn) {
    length = lenIn;
    width = widthIn;
    height = heightIn;
}

double Box::volume() {
    return length * width * height;
}

Box Box Box::operator+(Box in){
    Box b(0,0,0);
    b.length = length + in.length;
    b.width = width + in.width;
    b.height = height + in.height;
    return b;
}

bool Box::operator==(Box in){
    bool ret = ((length == in.length) && (width == in.width) && (height == in.height));
    return ret;
}

void Box::print() {
    cout << "Length: " << length << "\n Width: " << width << "\n Height : " << height << endl;
}