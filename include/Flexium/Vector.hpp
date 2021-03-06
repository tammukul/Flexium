#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <initializer_list>

namespace flx {

	class Vector {

		public:

			double x, y;

			static Vector fromAngle(double ang, double mag);

			Vector(): x(0), y(0) {};
			Vector(double a, double b): x(a), y(b) {};

			Vector operator +(const Vector& v) const;
			Vector operator -(const Vector& v) const;
			Vector operator *(double s) const;
			Vector operator /(double s) const;
			Vector& operator +=(const Vector& v);
			Vector& operator -=(const Vector& v);
			Vector& operator *=(double s);
			Vector& operator /=(double s);
			Vector& operator =(std::initializer_list<double>);
			bool operator !=(const Vector& v) const;
			double length() const;
			double angle() const;
			Vector rotate(double ang) const;

	};

}

#endif