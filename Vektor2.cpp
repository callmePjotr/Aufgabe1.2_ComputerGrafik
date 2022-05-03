#include "pch.h"
#include "Vektor2.h"

Vektor2::Vektor2() {
	vek[0] = 0;
	vek[1] = 0;
	vek[2] = 0;

}

Vektor2::Vektor2(double x, double y) {
	vek[0] = x;
	vek[1] = y;
	vek[2] = 1;
}




Matrix2::Matrix2() {
	for (int i = 0; i < DIM; i++) {
		for (int j = 0; j < DIM; j++) {
			if (i == j) {
				mat[i][j] = 1;
			}
			else {
				mat[i][j] = 0;
			}
		}
	}
}

Vektor2 Matrix2::operator * (const Vektor2& v){
	Vektor2 temp;
	for (int j = 0; j < DIM; j++) {
		for (int i = 0; i < DIM; i++) {
			temp.vek[j] = temp.vek[j] + mat[i][j] * v.vek[i];
		}
	}
	return temp;
}

void Matrix2::setTrans(double dx, double dy) {
	mat[DIM - 1][0] = dx;
	mat[DIM - 1][1] = dy;

}


void Matrix2::setRotation(double w) {
	mat[0][0] = mat[1][1] = cos(w);
	mat[0][1] = sin(w);
	mat[1][0] = -sin(w);

}









//hier weiter


Matrix3::Matrix3() {
	for (int i = 0; i < DIM; i++) {
		for (int j = 0; j < DIM; j++) {
			for (int k = 0; k < DIM; k++) {
				if (i == j) {
					mat[i][j][k] = 1;
				}
				else {
					mat[i][j][k] = 0;
				}
			}
		}
	}
}

Vektor3::Vektor3() {
	vek[0] = 0;
	vek[1] = 0;
	vek[2] = 0;
	vek[3] = 0;
}

Vektor3::Vektor3(double x, double y, double z) {
	vek[0] = x;
	vek[1] = y;
	vek[2] = z;
	vek[3] = 1;
}