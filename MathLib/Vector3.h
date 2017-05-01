// #include, using, etc
#pragma once
#include "math.h"
#include "Vector2.h"
#include "Vector4.h"

#ifdef STATIC_LIB
	#define MATH_DLL
#else
	#ifdef DLL_EXPORT
		#define MATH_DLL __declspec(dllexport)
	#else
		#define MATH_DLL __declspec(dllimport)
	#endif
#endif

// Vector3 object
class Vector3
{
public:

	// Default Constructor
	MATH_DLL Vector3();

	// Constructor passing in 2 floats
	MATH_DLL Vector3(float x, float y, float z);

	// Default Destructor
	MATH_DLL ~Vector3();

	// Addition
	MATH_DLL Vector3 operator+(const Vector3& rhs);

	// Subtraction
	MATH_DLL Vector3 operator-(const Vector3& rhs);

	// Divide
	MATH_DLL Vector3 operator/(const float rhs);

	// Multiply vector by float
	MATH_DLL Vector3 operator*(const float rhs);

	// Dot product
	MATH_DLL float dot(const Vector3& rhs);

	// cross product
	MATH_DLL Vector3 cross(const Vector3& rhs);

	// Magnititude
	MATH_DLL float magnitude();

	// Magnititude Squared
	MATH_DLL float MagnititudeSquared();

	// Normalise
	MATH_DLL void normalise();

	// Normalised
	MATH_DLL static Vector3 Normalised(Vector3 data);

	// Allow negative vector
	MATH_DLL Vector3 operator-();

	// Greater then operator
	MATH_DLL bool operator>(const Vector3 rhs);

	// Less then operator
	MATH_DLL bool operator<(const Vector3 rhs);

	// plus equels
	MATH_DLL Vector3 operator+=(const Vector3& rhs);

	// minus equels
	MATH_DLL Vector3 operator-=(const Vector3& rhs);

	// Multiply equels
	MATH_DLL Vector3 operator*=(const float rhs);

	// Divide equels
	MATH_DLL Vector3 operator/=(const float rhs);

	// Sub-script operator returning a reference 
	MATH_DLL float& operator[](const int rhs);

	// Cast operator to float pointer
	MATH_DLL operator float*();

	// Cast from a Vector2 to Vector3
	MATH_DLL operator Vector2 ();

	// Cast from a Vector4 to Vector3
	MATH_DLL operator Vector4();

	// Returns the smallest components of two vectors.
	MATH_DLL Vector3 Min(Vector3 rhs);

	// Returns the largest components of two vectors.
	MATH_DLL Vector3 Max(Vector3 rhs);

	// Clamping
	MATH_DLL Vector3 Clamp(Vector3 min, Vector3 max);

	// Lerp
	MATH_DLL Vector3 Lerp(Vector3 a, Vector3 b, float t);

	// declare public floats for x and y
	float x;
	float y;
	float z;
};

// Float multiplyed by vector ( out side of class so we can order )
MATH_DLL Vector3 operator*(float lhs, const Vector3& rhs);