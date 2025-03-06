#include <iostream>
#include <cmath>
#include "Эллипс.h"
#define PI 3,1415
using namespace std;


 Ellipse::Ellipse(char vBigAxis, double vh, double vk, double va, double vb) :
     BigAxis(vBigAxis), h(vh), k(vk), a(va), b(vb) {
     while (va <= vb) { 
         cout << "Значение большой полуоси всегда должно быть больше значения малой полуоси."; 
         cout << "Введите значения повторно.";
         cin >> va >> vb;
     }
     a = va; b = vb;          
 }
 Ellipse::Ellipse(double va, double vb) : BigAxis('X'), h(0), k(0), a(0), b(0) {
     while (va <= vb) {
         cout << "Значение большой полуоси всегда должно быть больше значения малой полуоси.";
         cout << "Введите значения повторно.";
         cin >> va >> vb;
     }
     a = va; b = vb;
 }
 Ellipse::Ellipse(const Ellipse& other) : 
         BigAxis(other.BigAxis), h(other.h), k(other.k), a(other.a), b(other.b) {}
     
     // ex 3
 double Ellipse::getC() {
     c = sqrt(a * a - b * b);
 }
 
 // ex 4
 void Ellipse::giveV() {
     if (BigAxis == 'X') {
         cout << "Вершины" << endl;
         cout << "V1(" << h - a << "," << k << ")" << endl;
         cout << "V2(" << h + a << "," << k << ")" << endl;
     } 
     else {
         cout << "Вершины" << endl;
         cout << "V1(" << h << "," << k - a << ")" << endl;
         cout << "V2(" << h << "," << k + a << ")" << endl;
     }
 }
 void Ellipse::giveF() {
     if (BigAxis == 'X') {
         cout << "Фокусы" << endl;
         cout << "F1(" << h - c << "," << k << ")" << endl;
             cout << "F2(" << h + c << "," << k << ")" << endl;
     }
         else {
             cout << "Фокусы" << endl;
             cout << "F1(" << h << "," << k - c << ")" << endl;
             cout << "F2(" << h << "," << k + c << ")" << endl;
         }
 }
 // ex 5
 double Ellipse::giveLR() {
     return (2 * b * b) / a;
 }
 double Ellipse::giveE() {
     return c / a;
 }
 // ex 6
 void Ellipse::setH(double vh) { h = vh; }
 void Ellipse::setK(double vk) { k = vk; }
 void Ellipse::setA(double va) {
     if (va <= b) {
         cout << "Значение большой полуоси всегда должно быть больше значения малой полуоси.";
     }
     a = va;
 }
 void Ellipse::setB(double vb) { 
     if (a <= vb) {
         cout << "Значение большой полуоси всегда должно быть больше значения малой полуоси.";
     }
     b = vb;
 }
 double Ellipse::getH() const { return h; }
 double Ellipse::getK() const { return k; }
 double Ellipse::getA() const { return a; }
 double Ellipse::getB() const { return b; }
 // ex 7
 void Ellipse::TheEllipseEquation() {
     if (BigAxis == 'X') {
         cout << "(x - " << h << ")^2 / " << a * a << " + (y - " << k << ")^2 / " << b * b;
     }
     else {
         cout << "(x - " << h << ")^2 / " << b * b << " + (y - " << k << ")^2 / " << a * a;
     }
 }
 void Ellipse::printALL() {
     TheEllipseEquation();
     cout << 'C(' << h << "," << k << ')' << endl;
     giveV();
     giveF();
 }
 // ex 8
 bool Ellipse::inside(double x, double y) const {
     if (((pow(x - h, 2))/ (a * a) + (pow(y - k, 2))/ (b * b)) < 1)  {
         cout << "Точка внутри";
     }
     else if (((pow(x - h, 2))/ (a * a) + (pow(y - k, 2))/ (b * b)) == 1)  {
         cout << "Точка на эллипсе";
     }
     else { cout << "Точка снаружи"; }    
 }
 // ex 9
 double Ellipse::getPerimeter() {
     return PI * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
 }
 // ex 10
 double Ellipse::getArea() {
     return a * b * PI;
 }
 // ex 11
 pair<double, double> Ellipse::calculateY(double x) const {
     if (BigAxis == 'X'){
         double znY1 = b * sqrt(1-((pow(x - h, 2)) / (a * a))) + k ;
         double znY2 = k - b * sqrt(1-((pow(x - h, 2)) / (a * a))) ;
         return make_pair(znY1, znY2);
     }
     else {
         double znY1 = a * sqrt(1-((pow(x - h, 2)) / (b * b))) + k;
         double znY2 = k - a * sqrt(1-((pow(x - h, 2)) / (b * b)));
         return make_pair(znY1, znY2);
     }
 
 }
 pair<double, double> Ellipse::calculateX(double y) const {
     if (BigAxis == 'X'){
         double znX1 = a * sqrt(1-((pow(y - k, 2)) / (b * b))) + h ;
         double znX2 = h - a * sqrt(1-((pow(y - k, 2)) / (b * b))) ;
         return make_pair(znX1, znX2);
     }
     else {
         double znX1 = b * sqrt(1-((pow(y - k, 2)) / (a * a))) + h;
         double znX2 = h - b * sqrt(1-((pow(y - k, 2)) / (a * a)));
         return make_pair(znX1, znX2);
     }
};