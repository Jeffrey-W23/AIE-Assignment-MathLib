#pragma once
#include "Vector2.h"

#ifdef STATIC_LIB
	#define MATH_DLL
#else
	#ifdef DLL_EXPORT
		#define MATH_DLL __declspec(dllexport)
	#else
		#define MATH_DLL __declspec(dllimport)
	#endif
#endif

class Matrix2
{
public:
	MATH_DLL Matrix2();
	MATH_DLL Matrix2(float Xx, float Xy, float Yx, float Yy);
	MATH_DLL ~Matrix2();

	MATH_DLL Vector2 operator*(const Vector2& rhs);
	MATH_DLL Matrix2 operator*(const Matrix2& rhs);

	// Sub-script operator returning a reference 
	MATH_DLL Vector2& operator[](const int rhs);

	// Cast operator to float pointer
	MATH_DLL operator float*();

	// Set Rotation
	MATH_DLL void setRotate(const float a);

	// Set Scale
	MATH_DLL void setScale(const float x, const float y);

	// Get Scale
	MATH_DLL Vector2 getScale();

	// Determinant
	MATH_DLL float Determinant(const Matrix2& rhs);

	// declare public floats for x and y. Union so we can use both a double array and single.
	union
	{
		float m[4];
		float a[2][2];
	};
};