#pragma once
class Polynomial
{
public:
	int st;
	int ValueX;
	int* VectKoef; // DINAMIC 
	int* VectExp; // DINAMIC 

	Polynomial();
	Polynomial(int st1, int ValueX1);
	Polynomial(const Polynomial& other);
	~Polynomial();

	void setSt(int st1);
	void setValueX(int ValueX1);
	void setVectKoef(int n, int zn);
	void setVectExp(int n, int zn);

	int getSt();
	int getValueX();
	int getVectKoef(int n);
	int getVectExp(int n);

	void printPolynomial();

	int getDegree() const;

	int calculateValue() const;
	Polynomial add(const Polynomial& other) const;
	Polynomial subtract(const Polynomial& other) const;
};