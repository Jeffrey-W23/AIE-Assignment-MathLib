// #include, using, etc
#pragma once
#include "math.h"
#include "Vector2.h"
#include "Vector3.h"

#ifdef STATIC_LIB
	#define MATH_DLL
#else
	#ifdef DLL_EXPORT
		#define MATH_DLL __declspec(dllexport)
	#else
		#define MATH_DLL __declspec(dllimport)
	#endif
#endif

// Vector2 object
class Vector4
{
public:

	// Default Constructor
	MATH_DLL Vector4();

	// Constructor passing in 2 floats
	MATH_DLL Vector4(float x, float y, float z, float w);

	// Default Destructor
	MATH_DLL ~Vector4();

	// Addition
	MATH_DLL Vector4 operator+(const Vector4& rhs);

	// Subtraction
	MATH_DLL Vector4 operator-(const Vector4& rhs);

	// Divide
	MATH_DLL Vector4 operator/(const float rhs);

	// Multiply vector by float
	MATH_DLL Vector4 operator*(const float rhs);

	// Dot product
	MATH_DLL float dot(const Vector4& rhs);

	// cross product
	MATH_DLL Vector4 cross(const Vector4& rhs);

	// Magnititude
	MATH_DLL float magnitude();

	// Magnititude Squared
	MATH_DLL float MagnititudeSquared();

	// Normalise
	MATH_DLL void normalise();

	// Normalised
	MATH_DLL static Vector4 Normalised(Vector4 data);

	// Allow negative vector
	MATH_DLL Vector4 operator-();

	// Greater then operator
	MATH_DLL bool operator>(const Vector4 rhs);

	// Less then operator
	MATH_DLL bool operator<(const Vector4 rhs);

	// plus equels
	MATH_DLL Vector4 operator+=(const Vector4& rhs);

	// minus equels
	MATH_DLL Vector4 operator-=(const Vector4& rhs);

	// Multiply equels
	MATH_DLL Vector4 operator*=(const float rhs);

	// Divide equels
	MATH_DLL Vector4 operator/=(const float rhs);

	// Sub-script operator returning a reference 
	MATH_DLL float& operator[](const int rhs);

	// Cast operator to float pointer
	MATH_DLL operator float*();

	// Cast from a Vector3 to Vector4
	MATH_DLL operator Vector2 ();

	// Cast from a Vector2 to Vector4
	MATH_DLL operator Vector3 ();

	// Returns the smallest components of two vectors.
	MATH_DLL Vector4 Min(Vector4 rhs);

	// Returns the largest components of two vectors.
	MATH_DLL Vector4 Max(Vector4 rhs);

	// Clamping
	MATH_DLL Vector4 Clamp(Vector4 min, Vector4 max);

	// Lerp
	Vector4 Lerp(Vector4 a, Vector4 b, float t);

	// declare public floats for x and y
	float x;
	float y;
	float z;
	float w;
};

// Float multiplyed by vector ( out side of class so we can order )
MATH_DLL Vector4 operator*(float lhs, const Vector4& rhs);