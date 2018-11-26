#ifndef VECTORX_H
#define VECTORX_H

#include <iostream>


#define PI			3.1415926535897932384626433832795	// value of pi
#define HALF_PI		1.5707963267948966192313216916398	// value of pi/2
#define TWO_PI		6.283185307179586476925286766559	// value of pi * 2
#define DEG_TO_RAD	0.017453292519943295769236907684886	// factor from degrees to radians
#define RAD_TO_DEG	57.295779513082320876798154814105	// factor from radians to degrees


template <class T>
class VectorX_t
{
private:
	T x, y, z;

public:
	// ---------- Constructors ----------

	// Default constructor
	VectorX_t<T>() { this->x = 0; this->y = 0; this->z = 0; };
	// Three parameter constructor for Vector3
	VectorX_t<T>(T xx, T yy, T zz) { this->x = xx; this->y = yy; this->z = zz; };
	// Two parameter constructor for Vector2
	VectorX_t<T>(T xx, T yy) { this->x = xx; this->y = yy; };
	


	


	// ---------- Getters and Setters ----------

	// Set VectorX_t
	void Set(const T &xx, const T &yy, const T &zz) 
	{
		this->x = xx;
		this->y = yy;
		this->z = zz;
	}
	void SetX(const T &xx) { this->x = xx; } // Set X
	void SetY(const T &yy) { this->y = yy; } // Set Y
	void SetZ(const T &zz) { this->z = zz; } // Set Z

	T GetX() const { return this->x } // Get X
	T GetY() const { return this->y } // Get Y
	T GetZ() const { return this->z } // Get Z


	// ---------- Calculations ----------

	// Add other VectorX_t to current VectorX_t
	void Add(const VectorX_t otherVec) 
	{
		this->x += otherVec.x;
		this->y += otherVec.y;
		this->z += otherVec.z;
	}

	// Add VectorX_t A to VectorX_t B
	T Add(const VectorX_t vec1, const VectorX_t vec2) 
	{
		T newX = vec1.x + vec2.x;
		T newY = vec1.y + vec2.y;
		T newZ = vec1.z + vec2.z;

		return VectorX_t(newX, newY, newZ);
	}

	// Substract other VectorX_t from current VectorX_t
	void Sub(const VectorX_t otherVec)
	{
		this->x -= otherVec.x;
		this->y -= otherVec.y;
		this->z -= otherVec.z;
	}

	// Substract VectorX_t A form VectorX_t B
	T Sub(const VectorX_t vec1, const VectorX_t vec2)
	{
		T newX = vec1.x - vec2.x;
		T newY = vec1.y - vec2.y;
		T newZ = vec1.z - vec2.z;

		return VectorX_t(newX, newY, newZ);
	}

	// Multiply current VectorX_t with other VectorX_t
	void Multiply(const VectorX_t otherVec)
	{
		this->x *= otherVec.x;
		this->y *= otherVec.y;
		this->z *= otherVec.z;
	}

	// Multipy VectorX_t A with VectorX_t B
	T Multiply(const VectorX_t vec1, const VectorX_t vec2)
	{
		T newX = vec1.x * vec2.x;
		T newY = vec1.y * vec2.y;
		T newZ = vec1.z * vec2.z;

		return VectorX_t(newX, newY, newZ);
	}

	// Get lenght of this VectorX_t
	T GetLength()
	{
		T xx = this->x;
		T yy = this->y;
		T zz = this->z;

		return sqrtf((xx*xx) + (yy*yy) + (zz*zz));
	}

	// Get angle from 2D VectorX_t in RADIANS
	T GetAngle()
	{
		return atan2(this->y, this->x);
	}
	// Get angle from 2D VectorX_t in DEGREES
	T GetAngleDeg()
	{
		return (GetAngle() * RAD_TO_DEG)
	}

	// Get angle between this Vector and other Vector in RADIANS
	T GetAngle(const VectorX_t<T> other)
	{
		VectorX_t<T> copy = *this;
		T dot = copy.Dot(other);
		T l1 = copy.GetLength();
		T l2 = other.GetLenght();

		return acos(dot/(l1*l2));
	}
	// Get angle between this Vector and other Vector in DEGREES
	T GetAngleDeg(const VectorX_t<T> other)
	{

		return (GetAngle(other) * RAD_TO_DEG);
	}

	T Dot(const VectorX_t<T> other)
	{
		T x = this->x * other.x;
		T y = this->y * other.y;
		T z = this->z * other.z;

		return (x + y + z);
	}

	T Cross(const VectorX_t<T> other)
	{
		T x = (this->y * other.z) - (this->z * other.y);
		T y = (this->z * other.x) - (this->x * other.z);
		T z = (this->x * other.y) - (this->y * other.x);

		return VectorX_t<T>(x, y, z);
	}

	T getNormalized()
	{
		VectorX_t<T> copy = *this;
		copy.normalize();

		return copy;
	}

	void VectorX_t<T>::Normalize()
	{
		T l = this->getLength();
		if (l != 0)
		{
			*this /= l;
		}
	}


	// ============================================================================================
	// --------------------------------------------------------------------------------------------
	// ============================================================================================




	// ------------ Overloaded operators ------------

	// Overloaded addition operator to add VectorX_ts together
	VectorX_t operator+(const VectorX_t &vector) const
	{
		return VectorX_t<T>(this->x + vector.x, this->y + vector.y, this->z + vector.z);
	}

	// Overloaded add and asssign operator to add VectorX_ts together
	void operator+=(const VectorX_t &vector)
	{
		this->x += vector.x;
		this->y += vector.y;
		this->z += vector.z;
	}

	// Overloaded subtraction operator to subtract a VectorX_t from another VectorX_t
	VectorX_t operator-(const VectorX_t &vector) const
	{
		return VectorX_t<T>(this->x - vector.x, this->y - vector.y, this->z - vector.z);
	}

	// Overloaded subtract and asssign operator to subtract a VectorX_t from another VectorX_t
	void operator-=(const VectorX_t &vector)
	{
		this->x -= vector.x;
		this->y -= vector.y;
		this->z -= vector.z;
	}

	// Overloaded multiplication operator to multiply two VectorX_ts together
	VectorX_t operator*(const VectorX_t &vector) const
	{
		return VectorX_t<T>(this->x * vector.x, this->y * vector.y, this->z * vector.z);
	}

	// Overloaded multiply operator to multiply a vector by a scalar
	VectorX_t operator*(const T &value) const
	{
		return VectorX_t<T>(this->x * value, this->y * value, this->z * value);
	}

	// Overloaded multiply and assign operator to multiply a vector by a scalar
	void operator*=(const T &value)
	{
		this->x *= value;
		this->y *= value;
		this->z *= value;
	}

	// Overloaded multiply operator to multiply a vector by a scalar
	VectorX_t operator/(const T &value) const
	{
		return VectorX_t<T>(this->x / value, this->y / value, this->z / value);
	}

	// Overloaded multiply and assign operator to multiply a vector by a scalar
	void operator/=(const T &value)
	{
		this->x /= value;
		this->y /= value;
		this->z /= value;
	}

	void display()
	{
		std::cout << "X: " << this->x << "\t Y: " << this->y << "\t Z: " << this->z << std::endl;
	}

};
// ---------- Typedefs ----------

typedef VectorX_t<int> Vector2i; // --------------------------- ||
typedef VectorX_t<float> Vector2f; // -------- Vector2 -------- ||
typedef VectorX_t<double> Vector2d;// ------------------------- ||
typedef Vector2f Vector2;// ----------------------------------- ||


typedef VectorX_t<int> Vector3i; // --------------------------- ||
typedef VectorX_t<float> Vector3f; // -------- Vector3 -------- ||
typedef VectorX_t<double> Vector3d;// ------------------------- ||
typedef Vector3f Vector3;// ----------------------------------- ||


#endif