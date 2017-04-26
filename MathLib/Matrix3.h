#pragma once
#include "Vector3.h"
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

class Matrix3
{
public:
	MATH_DLL Matrix3();
	MATH_DLL Matrix3(float Xx, float Xy, float Xz, float Yx, float Yy, float Yz, float Zx, float Zy, float Zz);
	MATH_DLL ~Matrix3();

	MATH_DLL Vector3 operator*(const Vector3& rhs);
	MATH_DLL Matrix3 operator*(const Matrix3& rhs);

	// Sub-script operator returning a reference 
	MATH_DLL Vector3& operator[](const int rhs);

	// Cast operator to float pointer
	MATH_DLL operator float*();

	// Set Rotation X
	MATH_DLL void setRotateX(const float a);

	// Set Rotation Y
	MATH_DLL void setRotateY(const float a);

	// Set Rotation Z
	MATH_DLL void setRotateZ(const float a);

	// Set Scale
	MATH_DLL void setScale(const float x, const float y, const float z);

	// Set postion taking in a vector
	MATH_DLL void setPostionv(const Vector2& rhs);

	// Set postion taking in a float
	MATH_DLL void setPostionf(const float x, const float y);

	float m[9];
};

