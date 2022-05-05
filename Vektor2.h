#pragma once
#define DIM 3
#define DIM2 4


class Vektor2
{
public:
	double vek[DIM];
	Vektor2();
	Vektor2(double x, double y);

};

class Matrix2
{
	double mat[DIM][DIM];
public:
	Matrix2();
	void setTrans(double dx, double dy);
	void setRotation(double winkel);
	Vektor2 operator * (const Vektor2& v);
};

class Matrix3 {
	double mat[DIM][DIM][DIM];
public:
	Matrix3();

};

class Vektor3 {
public:
	double vek[DIM2];
	Vektor3();
	Vektor3(double x, double y, double z);
};
