#ifndef VECTORX_H
#define VECTORX_H


template <class T>
class VectorX_t
{
private:
	T x, y, z;

public:
	// ---------- Constructors ----------

	// Default constructor
	VectorX_t<T>() { x = 0; y = 0; z = 0; };
	// Three parameter constructor for Vector3
	VectorX_t<T>(T xx, T yy, T zz) { x = xx; y = yy; z = zz; };
	// Two parameter constructor for Vector2
	VectorX_t<T>(T xx, T yy) { x = xx; y = yy; };
	


	


	// ---------- Getters and Setters ----------

	// Set Vector3
	void Set(const T &xx, const T &yy, const T &zz) 
	{
		x = xx;
		y = yy;
		z = zz;
	}
	void SetX(const T &xx) { x = xx; } // Set X
	void SetY(const T &yy) { y = yy; } // Set Y
	void SetZ(const T &zz) { z = zz; } // Set Z

	T GetX() const { return x } // Get X
	T GetY() const { return y } // Get Y
	T GetZ() const { return z } // Get Z


	// ---------- Calculations ----------

	// Add other Vector to current Vector
	void Add(const VectorX_t otherVec) 
	{
		x += otherVec.x;
		y += otherVec.y;
		z += otherVec.z;
	}

	// Add Vector A to Vector B
	T Add(const VectorX_t vec1, const VectorX_t vec2) 
	{
		T newX = vec1.x + vec2.x;
		T newY = vec1.y + vec2.y;
		T newZ = vec1.z + vec2.z;

		return VectorX_t(newX, newY, newZ);
	}

	// Substract other Vector from current Vector
	void Sub(const VectorX_t otherVec)
	{
		x -= otherVec.x;
		y -= otherVec.y;
		z -= otherVec.z;
	}

	// Substract Vector A form Vector B
	T Sub(const VectorX_t vec1, const VectorX_t vec2)
	{
		T newX = vec1.x - vec2.x;
		T newY = vec1.y - vec2.y;
		T newZ = vec1.z - vec2.z;

		return VectorX_t(newX, newY, newZ);
	}

	// Multiply current Vector with other Vector
	void Multiply(const VectorX_t otherVec)
	{
		x *= otherVec.x;
		y *= otherVec.y;
		z *= otherVec.z;
	}

	// Multipy Vector A with Vector B
	T Multiply(const VectorX_t vec1, const VectorX_t vec2)
	{
		T newX = vec1.x * vec2.x;
		T newY = vec1.y * vec2.y;
		T newZ = vec1.z * vec2.z;

		return VectorX_t(newX, newY, newZ);
	}



	// ------------ Overloaded operators ------------

	// Overloaded addition operator to add VectorX_ts together
	VectorX_t operator+(const VectorX_t &vector) const
	{
		return VectorX_t<T>(x + vector.x, y + vector.y, z + vector.z);
	}

	// Overloaded add and asssign operator to add VectorX_ts together
	void operator+=(const VectorX_t &vector)
	{
		x += vector.x;
		y += vector.y;
		z += vector.z;
	}

	// Overloaded subtraction operator to subtract a VectorX_t from another VectorX_t
	VectorX_t operator-(const VectorX_t &vector) const
	{
		return VectorX_t<T>(x - vector.x, y - vector.y, z - vector.z);
	}

	// Overloaded subtract and asssign operator to subtract a VectorX_t from another VectorX_t
	void operator-=(const VectorX_t &vector)
	{
		x -= vector.x;
		y -= vector.y;
		z -= vector.z;
	}

	// Overloaded multiplication operator to multiply two VectorX_ts together
	VectorX_t operator*(const VectorX_t &vector) const
	{
		return VectorX_t<T>(x * vector.x, y * vector.y, z * vector.z);
	}

	// Overloaded multiply operator to multiply a vector by a scalar
	VectorX_t operator*(const T &value) const
	{
		return VectorX_t<T>(x * value, y * value, z * value);
	}

	// Overloaded multiply and assign operator to multiply a vector by a scalar
	void operator*=(const T &value)
	{
		x *= value;
		y *= value;
		z *= value;
	}

	// Overloaded multiply operator to multiply a vector by a scalar
	VectorX_t operator/(const T &value) const
	{
		return VectorX_t<T>(x / value, y / value, z / value);
	}

	// Overloaded multiply and assign operator to multiply a vector by a scalar
	void operator/=(const T &value)
	{
		x /= value;
		y /= value;
		z /= value;
	}

	void display()
	{
		std::cout << "X: " << x << "\t Y: " << y << "\t Z: " << z << std::endl;
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