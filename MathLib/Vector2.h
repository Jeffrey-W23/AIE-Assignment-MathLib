// #include, using, etc
#pragma once
#include "math.h"
#include "Vector3.h"
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

// Vector2 object
class Vector2
{
public:

	// Default Constructor
	MATH_DLL Vector2();

	// Constructor passing in 2 floats
	MATH_DLL Vector2(float x, float y);
	
	// Default Destructor
	MATH_DLL ~Vector2();

	// Addition
	MATH_DLL Vector2 operator+(const Vector2& rhs);

	// Subtraction
	MATH_DLL Vector2 operator-(const Vector2& rhs);

	// Divide
	MATH_DLL Vector2 operator/(const float rhs);

	// Multiply vector by float
	MATH_DLL Vector2 operator*(const float rhs);
	
	// Dot product
	MATH_DLL float dot(const Vector2& rhs);

	// Magnititude
	MATH_DLL float magnitude();

	// Magnititude Squared
	MATH_DLL float MagnititudeSquared();

	// Normalise
	MATH_DLL void normalise();

	// Normalised
	MATH_DLL static Vector2 Normalised(Vector2 data);

	// Allow negative vector
	MATH_DLL Vector2 operator-();

	// Greater then operator
	MATH_DLL bool operator>(const Vector2 rhs);

	// Less then operator
	MATH_DLL bool operator<(const Vector2 rhs);

	// plus equels
	MATH_DLL Vector2 operator+=(const Vector2& rhs);
	
	// minus equels
	MATH_DLL Vector2 operator-=(const Vector2& rhs);
	
	// Multiply equels
	MATH_DLL Vector2 operator*=(const float rhs);
	
	// Divide equels
	MATH_DLL Vector2 operator/=(const float rhs);

	// Sub-script operator returning a reference 
	MATH_DLL float& operator[](const int rhs);

	// Cast operator to float pointer
	MATH_DLL operator float*();

	// Calculate the normal of a face
	MATH_DLL Vector2 CalcNormal(Vector2 pos);

	// Returns the smallest components of two vectors.
	MATH_DLL Vector2 Min(Vector2 rhs);

	// Returns the largest components of two vectors.
	MATH_DLL Vector2 Max(Vector2 rhs);

	// Clamping
	MATH_DLL Vector2 Clamp(Vector2 min, Vector2 max);

	// Lerp
	MATH_DLL Vector2 Lerp(Vector2 a, Vector2 b, float t);

	// Get distance between 2 vectors.
	MATH_DLL float Distance(Vector2 pos1, Vector2 pos2);

	// Equel to operator
	MATH_DLL bool operator==(const Vector2 rhs);

	// Not equel to operator
	MATH_DLL bool operator!=(const Vector2 rhs);

	// Greater then or equel or operator
	MATH_DLL bool operator>=(const Vector2 rhs);

	// Greater then or equel or operator
	MATH_DLL bool operator<=(const Vector2 rhs);

	// Bezier
	MATH_DLL Vector2 Bezier(float t, Vector2 a, Vector2 b, Vector2 c);

	// Hermite Curve
	MATH_DLL Vector2 hermiteCurve(Vector2 point0, Vector2 tangent0, Vector2 point1, Vector2 tangent1, float t);

	// declare public floats for x and y. Union so we can use both an array and floats.
	union
	{
		struct
		{
			float x;
			float y;
		};

		float vec[2];
	};
};

// Float multiplyed by vector ( out side of class so we can order )
MATH_DLL Vector2 operator*(float lhs, const Vector2& rhs);