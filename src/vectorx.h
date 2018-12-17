/**
* @file vectorx.h
*
* @brief The VectorX_t header file
*/

#ifndef VECTORX_H
#define VECTORX_H

#include <iostream>


/**
* @brief pi (180 deg)
* @var PI
*/
#define PI			3.1415926535897932384626433832795
/**
* @brief pi/2 (90 deg)
* @var HALF_PI
*/
#define HALF_PI		1.5707963267948966192313216916398
/**
* @brief pi*2 (360 deg)
* @var TWO_PI
*/
#define TWO_PI		6.283185307179586476925286766559
/**
* @brief convert degrees to radians
* @var DEG_TO_RAD
*/
#define DEG_TO_RAD	0.017453292519943295769236907684886
/**
* @brief convert radians to degrees
* @var RAD_TO_DEG
*/
#define RAD_TO_DEG	57.295779513082320876798154814105


/**
 * @brief Template Class for different Vectors
 *
 * current vector typedefs: Vector2 and Vector3
 *
 * int's: Vector2i, Vector3i
 *
 * float's: Vector2f, Vector3f
 *
 * doubles: Vector2d, Vector3d
 */
template <class T>
class VectorX_t
{
private:
	T x; //!< VectorX_t<T> x value
	T y; //!< VectorX_t<T> y value
	T z; //!< VectorX_t<T> z value

public:
	// ---------- Constructors ----------

	/**
	 * @brief Default VectorX_t<T> constructor.
	 *
	 * Creates a VectorX_t<T> with endpoint 0,0,0
	 * Length = 0
	 */
	VectorX_t<T>() { x = 0; y = 0; z = 0; };
	/**
	 * @brief Creates a Vector3 with endpoint xx,yy,zz
	 *
	 * @param xx
	 * The x position of the Vector3
	 * @param yy
	 * The y position of the Vector3
	 * @param zz
	 * The z position of the Vector3
	 */
	VectorX_t<T>(T xx, T yy, T zz) { x = xx; y = yy; z = zz; };
	/**
	 * @brief Creates a Vector2 with endpoint xx,yy
	 *
	 * @param xx
	 * The x position of the Vector2
	 * @param yy
	 * The y position of the Vector2
	 */
	VectorX_t<T>(T xx, T yy) { x = xx; y = yy; };
	


	


	// ---------- Getters and Setters ----------

	/**
	* @brief Set values of VectorX_t<T> to input values
	*/
	void Set(const T &xx, const T &yy, const T &zz) 
	{
		x = xx;
		y = yy;
		z = zz;
	}
	/**
	* @brief Set x value of VectorX_t<T> to input value
	*/
	void SetX(const T &xx) { x = xx; }
	/**
	* @brief Set y value of VectorX_t<T> to input value
	*/
	void SetY(const T &yy) { y = yy; }
	/**
	* @brief Set z value of VectorX_t<T> to input value
	*/
	void SetZ(const T &zz) { z = zz; }

	/**
	* @brief Get x value from VectorX_t<T>
	*
	* @return x
	* returns the x value of VectorX_t<T>
	*/
	T GetX() const { return x }

	/**
	* @brief Get y value from VectorX_t<T>
	*
	* @return y
	* returns the y value of VectorX_t<T>
	*/
	T GetY() const { return y }

	/**
	* @brief Get z value from VectorX_t<T>
	*
	* @return z
	* returns the z value of VectorX_t<T>
	*/
	T GetZ() const { return z }


	// ---------- Calculations ----------

	/**
	* @brief Add other VectorX_t<T> to this VectorX_t<T>
	*/
	void Add(const VectorX_t otherVec) 
	{
		x += otherVec.x;
		y += otherVec.y;
		z += otherVec.z;
	}

	/**
	* @brief Add VectorX_t<T> A to VectorX_t<T> B
	*
	* @return VectorX_t(newX, newY, newZ)
	* returns the two VectorX_t<T> as one new VectorX_t<T>
	*/
	T Add(const VectorX_t vec1, const VectorX_t vec2) 
	{
		T newX = vec1.x + vec2.x;
		T newY = vec1.y + vec2.y;
		T newZ = vec1.z + vec2.z;

		return VectorX_t(newX, newY, newZ);
	}

	/**
	* @brief Substract other VectorX_t<T> from this VectorX_t<T>
	*/
	void Sub(const VectorX_t otherVec)
	{
		x -= otherVec.x;
		y -= otherVec.y;
		z -= otherVec.z;
	}

	/**
	* @brief Substract VectorX_t<T> B from VectorX_t<T> A
	*
	* @return VectorX_t(newX, newY, newZ)
	* returns the two VectorX_t<T> substracted as one new VectorX_t<T>
	*/
	T Sub(const VectorX_t vec1, const VectorX_t vec2)
	{
		T newX = vec1.x - vec2.x;
		T newY = vec1.y - vec2.y;
		T newZ = vec1.z - vec2.z;

		return VectorX_t(newX, newY, newZ);
	}

	/**
	* @brief Multiply this VectorX_t<T> with other VectorX_t<T>
	*/
	void Multiply(const VectorX_t otherVec)
	{
		x *= otherVec.x;
		y *= otherVec.y;
		z *= otherVec.z;
	}

	/**
	* @brief Multiply VectorX_t<T> A by VectorX_t<T> B
	*
	* @return VectorX_t(newX, newY, newZ)
	* returns the two VectorX_t<T> multiplied as one new VectorX_t<T>
	*/
	T Multiply(const VectorX_t vec1, const VectorX_t vec2)
	{
		T newX = vec1.x * vec2.x;
		T newY = vec1.y * vec2.y;
		T newZ = vec1.z * vec2.z;

		return VectorX_t(newX, newY, newZ);
	}

	/**
	* @brief Get the lenght or magnitude of this VectorX_t<T>
	*
	* @return sqrtf((xx*xx)+(yy*yy)+(zz*zz))
	* returns the lenght of this VectorX_t<T>
	*/
	T GetLength()
	{
		T xx = x;
		T yy = y;
		T zz = z;

		return sqrtf((xx*xx)+(yy*yy)+(zz*zz));
	}

	/**
	* @brief Get the angle of this VectorX_t<T>
	*
	* @return atan2(y, x)
	* returns the angle of this VectorX_t<T> in RADIANS
	*/
	T GetAngle()
	{
		return atan2(y, x);
	}

	/**
	* @brief Get the angle of this VectorX_t<T> and convert to DEGREES
	*
	* @return (GetAngle() * RAD_TO_DEG)
	* returns the angle of this VectorX_t<T> in DEGREES
	*/
	T GetAngleDeg()
	{
		return (GetAngle() * RAD_TO_DEG)
	}

	/**
	* @brief Get the angle between this VectorX_t<T> and other VectorX_t<T>
	*
	* @return atan2(y, x)
	* returns the angle between this VectorX_t<T> and other VectorX_t<T> in RADIANS
	*/
	T GetAngle(VectorX_t other)
	{
		VectorX_t copy = *this;
		T dot = copy.Dot(other);
		T l1 = copy.GetLength();
		T l2 = other.GetLength();

		return acos(dot/(l1*l2));
	}

	/**
	* @brief Get the angle between this VectorX_t<T> and other VectorX_t<T> and convert to DEGREES 
	*
	* @return atan2(y, x)
	* returns the angle between this VectorX_t<T> and other VectorX_t<T> in DEGREES
	*/
	T GetAngleDeg(const VectorX_t other)
	{

		return (GetAngle(other) * RAD_TO_DEG);
	}

	/**
	* @brief Get dot value
	*/
	T Dot(const VectorX_t other)
	{
		T xx = x * other.x;
		T yy = y * other.y;
		T zz = z * other.z;

		return (xx + yy + zz);
	}

	/**
	* @brief Get cross value
	*/
	T Cross(const VectorX_t other)
	{
		T xx = (y * other.z) - (z * other.y);
		T yy = (z * other.x) - (x * other.z);
		T zz = (x * other.y) - (y * other.x);

		return VectorX_t(xx, yy, zz);
	}

	/**
	* @brief Get normalized VectorX_t<T>
	*
	* @return copy
	* returns normalized value of this VectorX_t<T>
	*/
	T getNormalized()
	{
		VectorX_t copy = *this;
		copy.Normalize();

		return copy;
	}

	/**
	* @brief Normalize this VectorX_t<T>
	*/
	void VectorX_t::Normalize()
	{
		T l = GetLength();
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