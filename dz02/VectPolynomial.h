#pragma once
#include "Polynomial.h"

class VectPolynomial
{
public:
	Polynomial* list;
	int size;
	int index;

	VectPolynomial();
	VectPolynomial(int n);
	VectPolynomial(const VectPolynomial& v);
	~VectPolynomial();

	int getSize() const;
	int getCount() const;

	Polynomial& operator[](int i);
	const Polynomial& operator[](int i) const;

};