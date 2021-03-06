#include <Flexium/Vector.hpp>

#include <cmath>

namespace flx {

	Vector Vector::fromAngle(double ang, double mag) {
		return Vector(cos(ang) * mag, -sin(ang) * mag);
	}

	Vector Vector::operator +(const Vector& v) const {
		return Vector(x + v.x, y + v.y);
	}

	Vector Vector::operator -(const Vector& v) const {
		return Vector(x - v.x, y - v.y);
	}

	Vector Vector::operator *(double s) const {
		return Vector(x * s, y * s);
	}

	Vector Vector::operator /(double s) const {
		return Vector(x / s, y / s);
	}

	Vector& Vector::operator +=(const Vector& v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	Vector& Vector::operator -=(const Vector& v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}

	Vector& Vector::operator *=(double s) {
		x *= s;
		y *= s;
		return *this;
	}

	Vector& Vector::operator /=(double s) {
		x /= s;
		y /= s;
		return *this;
	}

	bool Vector::operator !=(const Vector& v) const {
		return x != v.x || y != v.y;
	}

	Vector& Vector::operator =(std::initializer_list<double> li) {
		if (li.size() == 2) {
			for (double n : li) {
				x = y;
				y = n;
			}
		}
		return *this;
	}

	double Vector::length() const {
		return sqrt((x * x) + (y * y));
	}

	double Vector::angle() const {
		return atan2(-y, x);
	}

	Vector Vector::rotate(double amount) const {
		return fromAngle(angle() + amount, length());
	}

}