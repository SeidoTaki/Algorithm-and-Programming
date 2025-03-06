#pragma once
#include <utility>

class Ellipse {
    char BigAxis; // расположение большой оси (X или Y)
    double h; // координата цента по х
    double k; // координата цента по у
    double a; // длина большой полуоси
    double b; // длина малой полуоси
    double c; // эллипсис

    public:
    Ellipse(char vBigAxis, double vh, double vk, double va, double vb);
    Ellipse(double va = 0, double vb = 0);
    Ellipse(const Ellipse& other);

    double getC();

    void giveV();
    void giveF();

    double giveLR();
    double giveE();

    void setH(double vh);
    void setK(double vk); 
    void setA(double va);
    void setB(double vb);

    double getH() const; 
    double getK() const; 
    double getA() const; 
    double getB() const;

    void TheEllipseEquation();
    void printALL();

    bool inside(double x, double y) const;

    double getPerimeter();

    double getArea();

    std::pair<double, double> calculateY(double x) const;
    std::pair<double, double>  calculateX(double y) const;
};