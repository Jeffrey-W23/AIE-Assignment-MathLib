#pragma once
#include "Vector4.h"
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

class Matrix4
{
public:
	MATH_DLL Matrix4();
	MATH_DLL Matrix4(float Xx, float Xy, float Xz, float Xw, float Yx, float Yy, float Yz, float Yw, float Zx, float Zy, float Zz, float Zw, float Tx, float Ty, float Tz, float Tw);
	MATH_DLL ~Matrix4();

	MATH_DLL Vector4 operator*(const Vector4& rhs);
	MATH_DLL Matrix4 operator*(const Matrix4& rhs);

	// Sub-script operator returning a reference 
	MATH_DLL Vector4& operator[](const int rhs);

	// Cast operator to float pointer
	MATH_DLL operator float*();

	// Set Rotation X
	MATH_DLL void setRotateX(const float a);

	// Set Rotation Y
	MATH_DLL void setRotateY(const float a);

	// Set Rotation Z
	MATH_DLL void setRotateZ(const float a);

	// Set Scale
	MATH_DLL void setScale(const float x, const float y, const float z, const float w);

	// Set postion taking in a vector
	MATH_DLL void setPostionv(const Vector3& rhs);

	// Set postion taking in a float
	MATH_DLL void setPostionf(const float x, const float y, const float z);

	float m[16];
};

