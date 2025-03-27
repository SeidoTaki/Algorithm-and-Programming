#include "Polynomial.h"
#include <iostream>
using namespace std;

Polynomial::Polynomial() {
	st = 0;
	ValueX = 0;
	VectKoef = nullptr; 
	VectExp = nullptr;
};
Polynomial::Polynomial(int st1, int ValueX1) {
	st = st1;
	ValueX = ValueX1;
	VectKoef = new int[st1 + 1];
	VectExp = new int[st1 + 1];
	for (int i = 0; i < st; ++i) {
		VectExp[i] = i;
	}
};
Polynomial::Polynomial(const Polynomial& other) {
	st = other.st;
	ValueX = other.ValueX;
	VectKoef = new int[other.st + 1];
	for (int i = 0; i < (other.st + 1); i++) {
		VectKoef[i] = other.VectKoef[i];
	}
	VectExp = new int[other.st + 1];
	for (int i = 0; i < (other.st + 1); i++) {
		VectExp[i] = other.VectExp[i];
	}
};
Polynomial::~Polynomial() {
	delete[] VectKoef;
	delete[] VectExp;
};

void Polynomial::setSt(int st1) { st = st1; };
void Polynomial::setValueX(int ValueX1) { ValueX = ValueX1; };
void Polynomial::setVectKoef(int n, int zn) { 
	if (n < 0 || n > st) {
		cerr << "Ошибка: индекс выходит за границы!" << endl; 
	}
	else { VectKoef[n] = zn; }
};
void Polynomial::setVectExp(int n, int zn) { 
	if (n < 0 || n > st) {
		cerr << "Ошибка: индекс выходит за границы!" << endl;
	}
	else { VectExp[n] = zn; }
};

int Polynomial::getSt() { return st; };
int Polynomial::getValueX() { return ValueX; };
int Polynomial::getVectKoef(int n) { 
	if (n < 0 || n > st) {
		cerr << "Ошибка: индекс выходит за границы!" << endl;
	}
	else { return VectKoef[n]; }
};
int Polynomial::getVectExp(int n) { 
	if (n < 0 || n > st) {
		cerr << "Ошибка: индекс выходит за границы!" << endl;
	}
	else { return VectExp[n]; }
};

void Polynomial::printPolynomial() {
	cout << "P(x) = ";
	for (int i = 0; i <= st; ++i) {
		if (i != 0) cout << " + ";
		cout << VectKoef[i] << "*x^" << VectExp[i];
	}
	cout << endl;
	cout << "При x = " << ValueX << endl;
}

int Polynomial::getDegree() const {
	int maxExp = 0;
	for (int i = 0; i < (st + 1); ++i) {
		if (VectExp[i] > maxExp) {
			maxExp = VectExp[i];
		}
	}
	return maxExp;
}

int Polynomial::calculateValue() const {
	int result = 0;
	for (int i = 0; i <= st; ++i) {
		int term = VectKoef[i];
		if (VectExp[i] > 0) {
			int power = 1;
			for (int j = 0; j < VectExp[i]; ++j) {
				power *= ValueX;
			}
			term *= power;
		}
		result += term;
	}
	return result;
}

Polynomial Polynomial::add(const Polynomial& other) const {
	int maxDegree = max(this->getDegree(), other.getDegree());
	Polynomial result(maxDegree, this->ValueX); 
	for (int i = 0; i <= maxDegree; ++i) {
		result.setVectKoef(i, 0);
		result.setVectExp(i, i);
	}
	for (int i = 0; i <= this->st; ++i) {
		int exp = this->VectExp[i];
		if (exp <= maxDegree) {
			result.setVectKoef(exp, result.getVectKoef(exp) + this->VectKoef[i]);
		}
	}
	for (int i = 0; i <= other.st; ++i) {
		int exp = other.VectExp[i];
		if (exp <= maxDegree) {
			result.setVectKoef(exp, result.getVectKoef(exp) + other.VectKoef[i]);
		}
	}

	return result;
}

Polynomial Polynomial::subtract(const Polynomial& other) const {
	int maxDegree = max(this->getDegree(), other.getDegree());
	Polynomial result(maxDegree, this->ValueX); 
	for (int i = 0; i <= maxDegree; ++i) {
		result.setVectKoef(i, 0);
		result.setVectExp(i, i);
	}
	for (int i = 0; i <= this->st; ++i) {
		int exp = this->VectExp[i];
		if (exp <= maxDegree) {
			result.setVectKoef(exp, result.getVectKoef(exp) + this->VectKoef[i]);
		}
	}
	for (int i = 0; i <= other.st; ++i) {
		int exp = other.VectExp[i];
		if (exp <= maxDegree) {
			result.setVectKoef(exp, result.getVectKoef(exp) - other.VectKoef[i]);
		}
	}
	return result;
}