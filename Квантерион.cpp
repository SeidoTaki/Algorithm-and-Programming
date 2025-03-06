#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include "Квантерион.h"
using namespace std;



    // ex 2
    Quaternion::Quaternion() : a(1), b(0), c(0), d(0) {}

    Quaternion::Quaternion(double a, double b, double c, double d) :
        a(a), b(b), c(c), d(d) {}

        Quaternion::Quaternion(const Quaternion& q) :
        a(q.a), b(q.b), c(q.c), d(q.d) {}

    // ex 3
    void Quaternion::setA(double va) { a = va; }
    void Quaternion::setB(double vb) { b = vb; }
    void Quaternion::setC(double vc) { c = vc; }
    void Quaternion::setD(double vd) { d = vd; }

    double Quaternion::getA() const { return a; }
    double Quaternion::getB() const { return b; }
    double Quaternion::getC() const { return c; }
    double Quaternion::getD() const { return d; }

    // ex 4
    void Quaternion::printQ() const {
        cout << a << " + " << b << "i + " << c << "j + " << d << "k" << endl;
    }

    // ex 5
    double Quaternion::norm() const {
        return sqrt(a * a + b * b + c * c + d * d);
    }

    // ex 6
    Quaternion Quaternion::sopr() const {
        return Quaternion(a, -b, -c, -d);
    }

    // ex 7
    Quaternion Quaternion::normalize() const {
        double n = norm();
        return Quaternion(a / n, b / n, c / n, d / n);
    }

    // ex 8
    Quaternion Quaternion::inverse() {
        double n = norm();
        return Quaternion (a / (n * n), b*(-1) / (n * n), c*(-1) / (n * n), d*(-1) / (n * n)) ;
    }

    // ex 9
     Quaternion Quaternion::add(const Quaternion& q1, const Quaternion& q2) {
        return Quaternion(q1.a + q2.a, q1.b + q2.b, q1.c + q2.c, q1.d + q2.d);
    }

     Quaternion Quaternion::subtract(const Quaternion& q1, const Quaternion& q2) {
        return Quaternion(q1.a - q2.a, q1.b - q2.b, q1.c - q2.c, q1.d - q2.d);
    }

     Quaternion Quaternion::multiply(const Quaternion& q1, const Quaternion& q2) {
        return Quaternion(
            q1.a * q2.a - q1.b * q2.b - q1.c * q2.c - q1.d * q2.d,
            q1.a * q2.b + q1.b * q2.a + q1.c * q2.d - q1.d * q2.c,
            q1.a * q2.c - q1.b * q2.d + q1.c * q2.a + q1.d * q2.b,
            q1.a * q2.d + q1.b * q2.c - q1.c * q2.b + q1.d * q2.a
        );
    }

     double Quaternion::dotProduct(const Quaternion& q1, const Quaternion& q2) {
        return q1.a * q2.a + q1.b * q2.b + q1.c * q2.c + q1.d * q2.d;
    }

    // ex 10
    double Quaternion::rasst(const Quaternion& q1, const Quaternion& q2) {
        return ((q1.a - q2.a) * (q1.a - q2.a) + (q1.b - q2.b) * (q1.b - q2.b) +
            (q1.c - q2.c) * (q1.c - q2.c) + (q1.d - q2.d) * (q1.d - q2.d));
    }

    // ex 11
    double Quaternion::ChNorm(const Quaternion& q1, const Quaternion& q2) const {
        return max({abs(q1.a - q2.a), abs(q1.b - q2.b), abs(q1.c - q2.c), abs(q1.d - q2.d) });
    }

