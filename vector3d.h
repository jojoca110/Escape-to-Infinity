#pragma once
#include <iostream>
#include <cmath>

using namespace std;

template <class S> class Vector3Dx;

typedef Vector3Dx<double> Vector3D;

typedef Vector3Dx<float>  Vector3Df;
typedef Vector3Dx<double> Vector3Dd;
typedef Vector3Dx<int>    Vector3Di;

template<class S>
class Vector3Dx {
	S x, y, z;
public:
	Vector3Dx() :x(0), y(0), z(0) {}

	Vector3Dx(S x, S y, S z = 0) :x(x), y(y), z(z) {}

	inline S GetX() const { return x; }
	inline S GetY() const { return y; }
	inline S GetZ() const { return z; }

	inline void SetX(S d) { x = d; }
	inline void SetY(S d) { y = d; }
	inline void SetZ(S d) { z = d; }

	Vector3Dx<S> operator+(Vector3Dx<S> v);
	Vector3Dx<S> operator-(Vector3Dx<S> v);
	Vector3Dx<S> operator-();
	Vector3Dx<S> operator*(S s);
	Vector3Dx<S> operator/(S s);
	S operator*(Vector3Dx<S> v);

	//Vector product
	Vector3Dx<S> X(Vector3Dx<S> v);
	S norm2();
	S norm();
	S length();
	S distance(Vector3Dx<S> v);
	Vector3Dx<S> normalized();
	Vector3Dx<S> project(Vector3Dx<S> v);
	Vector3Dx<S> coproject(Vector3Dx<S> a);
	void imprime();
	
};
template <class S = double>
ostream& operator<<(ostream& os, const Vector3Dx<S>& v) {
	os << v.GetX() << "," << v.GetY() << "," << v.GetZ();
	return os;
}
template <class S>
Vector3Dx<S> Vector3Dx<S>::operator+(Vector3Dx<S> v) {
	Vector3Dx<S> r(this->GetX() + v.GetX(),
		this->GetY() + v.GetY(),
		this->GetZ() + v.GetZ());
	return r;
}
template <class S>
Vector3Dx<S> Vector3Dx<S>::operator-(Vector3Dx<S> v) {
	return Vector3Dx<S>(x - v.x, y - v.y, z - v.z);
}
template <class S>
Vector3Dx<S> Vector3Dx<S>::operator-() { return Vector3Dx<S>(-x, -y, -z); }
template <class S>
Vector3Dx<S> Vector3Dx<S>::operator*(S s) {
	Vector3Dx<S> r;
	r.SetX(this->GetX() * s);
	r.SetY(this->GetY() * s);
	r.SetZ(this->GetZ() * s);
	return r;
}
template <class S>
Vector3Dx<S> Vector3Dx<S>::operator/(S s) {
	Vector3Dx<S> r;
	r.x = this->GetX() / s;
	r.y = this->GetY() / s;
	r.z = this->GetZ() / s;
	return r;
}
template <class S>
S Vector3Dx<S>::operator*(Vector3Dx<S> v) {
	S s;
	s = this->GetX() * v.GetX() + this->GetY() * v.GetY() + this->GetZ() * v.GetZ();
	return s;
}
template <class S>
Vector3Dx<S> Vector3Dx<S>::X(Vector3Dx<S> v1) {
	Vector3Dx<S>& v2 = *this;
	Vector3Dx<S> r(
		v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x);
	return r;
}
template <class S>
S Vector3Dx<S>::norm2() {
	S s;
	Vector3Dx<S>& este = *this;
	//s= x*x + y*y + z*z;
	s = este * este;//(*this)*(*this) <=> this->operator*(*this)
	return s;
}
template <class S>
S Vector3Dx<S>::norm() {
	Vector3Dx<S>& este = *this;
	S s;
	s = sqrt(este.norm2());
	return s;
}
template <class S>
S Vector3Dx<S>::length() {
	return norm();
}
template <class S>
S Vector3Dx<S>::distance(Vector3Dx<S> v) {
	Vector3Dx<S> dif;
	dif.SetX(v.GetX() - (*this).GetX());
	dif.SetY(v.GetY() - this->GetY());
	dif.SetZ(v.GetZ() - this->GetZ());
	S d;
	d = dif.norm();
	return d;
}
template <class S>
Vector3Dx<S> Vector3Dx<S>::normalized() {
	Vector3Dx<S> r;
	S l;
	Vector3Dx<S>& este = *this;
	l = norm();
	r = este / l;
	return r;
}
template <class S>
Vector3Dx<S> Vector3Dx<S>::project(Vector3Dx<S> v) {
	Vector3Dx<S> n;
	Vector3Dx<S> r;
	n = this->normalized();
	S prjL;
	prjL = n * v;
	r = n * prjL;
	return r;
}
template <class S>
Vector3Dx<S> Vector3Dx<S>::coproject(Vector3Dx<S> a) {
	Vector3Dx<S> a1;
	Vector3Dx<S> a2;
	a1 = this->project(a);
	a2 = a - a1;
	return a2;
}
template <class S>
void Vector3Dx<S>::imprime() {
	cout << this->GetX() << "," << this->GetY() << "," << this->GetZ() << endl;
}
