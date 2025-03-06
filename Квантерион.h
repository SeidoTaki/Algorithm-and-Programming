#pragma once



class Quaternion {
private:
    double a; // действительная часть
    double b; // коэффициент для i
    double c; // коэффициент для j
    double d; // коэффициент для k

public:

    // ex 2
    Quaternion();

    Quaternion(double a, double b, double c, double d);
    Quaternion(const Quaternion& q);

    // ex 3
    void setA(double va);
    void setB(double vb);
    void setC(double vc);
    void setD(double vd);

    double getA() const;
    double getB() const;
    double getC() const;
    double getD() const;

    // ex 4
    void printQ() const;

    // ex 5
    double norm() const;
    // ex 6
    Quaternion sopr() const;

    // ex 7
    Quaternion normalize() const;
    // ex 8
    Quaternion inverse();

    // ex 9
    static Quaternion add(const Quaternion& q1, const Quaternion& q2);

    static Quaternion subtract(const Quaternion& q1, const Quaternion& q2);

    static Quaternion multiply(const Quaternion& q1, const Quaternion& q2);

    static double dotProduct(const Quaternion& q1, const Quaternion& q2);

    // ex 10
    double rasst(const Quaternion& q1, const Quaternion& q2);

    // ex 11
   double ChNorm(const Quaternion& q1, const Quaternion& q2) const;
};
