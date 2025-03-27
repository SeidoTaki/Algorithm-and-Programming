#include "VectPolynomial.h"
#include <iostream>
#include <vector>
using namespace std;

VectPolynomial::VectPolynomial() {
    this->size = 0;
    this->index = 0;
    this->list = nullptr;
};
VectPolynomial::VectPolynomial(int n) {
    this->size = n;
    this->index = 0;
    this->list = new Polynomial[n];
};
VectPolynomial::VectPolynomial(const VectPolynomial& v) {
    this->size = v.size;
    this->index = v.index;
    this->list = new Polynomial[v.size];

    for (int i = 0; i < v.size; i++) {
        this->list[i] = v.list[i];
    }
};
VectPolynomial::~VectPolynomial() {
    delete[] this->list;
};

int VectPolynomial::getSize() const { return size; }
int VectPolynomial::getCount() const { return index; }

Polynomial& VectPolynomial::operator[](int i) { return list[i]; }
const Polynomial& VectPolynomial::operator[](int i) const { return list[i]; }

int countPolynomials(const vector<VectPolynomial>& vectors) {
    int total = 0;
    for (const auto& v : vectors) {
        total += v.getCount();
    }
    return total;
}