//
// Created by connor on 9/19/19.
//
class Box {
    double len;
    double width;
    double height;
public:
    Box(double lenIn, double widthIn, double heightIn);
    double volume();
    Box operator+(Box in);
    bool operator==(Box in);
    void print();
};
