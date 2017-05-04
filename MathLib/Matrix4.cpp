#include "Matrix4.h"
#include "VectorCast.h"

Matrix4::Matrix4()
{
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = 0;
	m[5] = 1;
	m[6] = 0;
	m[7] = 0;
	m[8] = 0;
	m[9] = 0;
	m[10] = 1;
	m[11] = 0;
	m[12] = 0;
	m[13] = 0;
	m[14] = 0;
	m[15] = 1;
}

Matrix4::Matrix4(float Xx, float Xy, float Xz, float Xw, float Yx, float Yy, float Yz, float Yw, float Zx, float Zy, float Zz, float Zw, float Tx, float Ty, float Tz, float Tw)
{
	m[0] = Xx;
	m[1] = Xy;
	m[2] = Xz;
	m[3] = Xw;

	m[4] = Yx;
	m[5] = Yy;
	m[6] = Yz;
	m[7] = Yw;

	m[8] = Zx;
	m[9] = Zy;
	m[10] = Zz;
	m[11] = Zw;

	m[12] = Tx;
	m[13] = Ty;
	m[14] = Tz;
	m[15] = Tw;
}

Matrix4::~Matrix4()
{

}

Vector4 Matrix4::operator*(const Vector4& rhs)
{
	Vector4 result;

	result.x = m[0] * rhs.x + m[4] * rhs.y + m[8] * rhs.z + m[12] * rhs.w;
	result.y = m[1] * rhs.x + m[5] * rhs.y + m[9] * rhs.z + m[13] * rhs.w;
	result.z = m[2] * rhs.x + m[6] * rhs.y + m[10] * rhs.z + m[14] * rhs.w;
	result.w = m[3] * rhs.x + m[7] * rhs.y + m[11] * rhs.z + m[15] * rhs.w;

	return result;
}

Matrix4 Matrix4::operator*(const Matrix4& rhs)
{
	Matrix4 result;

	result.m[0] = m[0] * rhs.m[0] + m[4] * rhs.m[1] + m[8] * rhs.m[2] + m[12] * rhs.m[3];
	result.m[1] = m[1] * rhs.m[0] + m[5] * rhs.m[1] + m[9] * rhs.m[2] + m[13] * rhs.m[3];
	result.m[2] = m[2] * rhs.m[0] + m[6] * rhs.m[1] + m[10] * rhs.m[2] + m[14] * rhs.m[3];
	result.m[3] = m[3] * rhs.m[0] + m[7] * rhs.m[1] + m[11] * rhs.m[2] + m[15] * rhs.m[3];

	result.m[4] = m[0] * rhs.m[4] + m[4] * rhs.m[5] + m[8] * rhs.m[6] + m[12] * rhs.m[7];
	result.m[5] = m[1] * rhs.m[4] + m[5] * rhs.m[5] + m[9] * rhs.m[6] + m[13] * rhs.m[7];
	result.m[6] = m[2] * rhs.m[4] + m[6] * rhs.m[5] + m[10] * rhs.m[6] + m[14] * rhs.m[7];
	result.m[7] = m[3] * rhs.m[4] + m[7] * rhs.m[5] + m[11] * rhs.m[6] + m[15] * rhs.m[7];

	result.m[8] = m[0] * rhs.m[8] + m[4] * rhs.m[9] + m[8] * rhs.m[10] + m[12] * rhs.m[11]; // put wrong thing here but said was right
	result.m[9] = m[1] * rhs.m[8] + m[5] * rhs.m[9] + m[9] * rhs.m[10] + m[13] * rhs.m[11];
	result.m[10] = m[2] * rhs.m[8] + m[6] * rhs.m[9] + m[10] * rhs.m[10] + m[14] * rhs.m[11];
	result.m[11] = m[3] * rhs.m[8] + m[7] * rhs.m[9] + m[11] * rhs.m[10] + m[15] * rhs.m[11];

	result.m[12] = m[0] * rhs.m[12] + m[4] * rhs.m[13] + m[8] * rhs.m[14] + m[12] * rhs.m[15];
	result.m[13] = m[1] * rhs.m[12] + m[5] * rhs.m[13] + m[9] * rhs.m[14] + m[13] * rhs.m[15];
	result.m[14] = m[2] * rhs.m[12] + m[6] * rhs.m[13] + m[10] * rhs.m[14] + m[14] * rhs.m[15];
	result.m[15] = m[3] * rhs.m[12] + m[7] * rhs.m[13] + m[11] * rhs.m[14] + m[15] * rhs.m[15];

	return result;
}

// Sub-script operator returning a reference 
Vector4& Matrix4::operator[](const int rhs)
{
	return *(Vector4*)(m + 4 * rhs);
}

// Cast operator to float pointer
Matrix4::operator float*()
{
	return &m[0];
}

// Set Rotation X
void Matrix4::setRotateX(const float a)
{
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = 0;
	m[5] = cosf(a);
	m[6] = sinf(a);
	m[7] = 0;
	m[8] = 0;
	m[9] = -sinf(a);
	m[10] = cosf(a);
	m[11] = 0;
	m[12] = 0;
	m[13] = 0;
	m[14] = 0;
	m[15] = 1;
}

// Set Rotation Y
void Matrix4::setRotateY(const float a)
{
	m[0] = cosf(a);
	m[1] = 0;
	m[2] = -sinf(a);
	m[3] = 0;
	m[4] = 0;
	m[5] = 1;
	m[6] = 0;
	m[7] = 0;
	m[8] = sinf(a);
	m[9] = 0;
	m[10] = cosf(a);
	m[11] = 0;
	m[12] = 0;
	m[13] = 0;
	m[14] = 0;
	m[15] = 1;
}

// Set Rotation Z
void Matrix4::setRotateZ(const float a)
{
	m[0] = cosf(a);
	m[1] = sinf(a);
	m[2] = 0;
	m[3] = 0;
	m[4] = -sinf(a);
	m[5] = cosf(a);
	m[6] = 0;
	m[7] = 0;
	m[8] = 0;
	m[9] = 0;
	m[10] = 1;
	m[11] = 0;
	m[12] = 0;
	m[13] = 0;
	m[14] = 0;
	m[15] = 1;
}

// Set Scale
void Matrix4::setScale(const float x, const float y, const float z, const float w)
{
	m[0] = x;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = 0;
	m[5] = y;
	m[6] = 0;
	m[7] = 0;
	m[8] = 0;
	m[9] = 0;
	m[10] = z;
	m[11] = 0;
	m[12] = 0;
	m[13] = 0;
	m[14] = 0;
	m[15] = 1;
}

// Set postion taking in a vector
void Matrix4::setPostionv(const Vector3& rhs)
{
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = 0;
	m[5] = 1;
	m[6] = 0;
	m[7] = 0;
	m[8] = 0;
	m[9] = 0;
	m[10] = 1;
	m[11] = 0;
	m[12] = rhs.x;
	m[13] = rhs.y;
	m[14] = rhs.z;
	m[15] = 1;
}

// Set postion taking in a float
void Matrix4::setPostionf(const float x, const float y, const float z)
{
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = 0;
	m[5] = 1;
	m[6] = 0;
	m[7] = 0;
	m[8] = 0;
	m[9] = 0;
	m[10] = 1;
	m[11] = 0;
	m[12] = x;
	m[13] = y;
	m[14] = z;
	m[15] = 1;
}


void Matrix4::LookAt(Vector3 from, const Vector3 target, const Vector3 up)
{
	Vector3 zaxis = from - target;
	zaxis.normalise();

	Vector3 xaxis = zaxis.cross(up);
	xaxis.normalise();

	Vector3 yaxis = xaxis.cross(zaxis);
	yaxis.normalise();

	(*this)[0] = CastTo<Vector4>(xaxis);
	(*this)[1] = CastTo<Vector4>(yaxis);
	(*this)[2] = CastTo<Vector4>(zaxis);
	(*this)[3] = CastTo<Vector4>(from);

	m[15] = 1;
}

// Get Scale
Vector4 Matrix4::getScale()
{
	Vector4 res;

	Vector4 xcol(m[0], m[1], m[2], m[3]);
	Vector4 ycol(m[4], m[5], m[6], m[7]);
	Vector4 zcol(m[8], m[9], m[10], m[11]);

	res.x = xcol.magnitude();
	res.y = ycol.magnitude();
	res.z = zcol.magnitude();

	return res;
}

// Get position
Vector4 Matrix4::getPos()
{
	Vector4 result;
	result.x = m[12];
	result.y = m[13];
	result.z = m[14];

	return result;
}

// Determinant
float Matrix4::Determinant()
{
	float res1 = m[0] * (m[5] * m[10] * m[15] - m[5] * m[11] * m[14] - m[6] * m[9] * m[15] + m[6] * m[11] * m[13] + m[7] * m[9] * m[14] - m[7] * m[10] * m[13]);
	float res2 = m[1] * (m[4] * m[10] * m[15] - m[4] * m[11] * m[14] - m[6] * m[8] * m[15] + m[6] * m[11] * m[12] + m[7] * m[8] * m[14] - m[7] * m[10] * m[12]);
	float res3 = m[2] * (m[4] * m[9] * m[15] - m[4] * m[11] * m[13] - m[5] * m[8] * m[15] + m[5] * m[11] * m[12] + m[7] * m[8] * m[13] - m[7] * m[9] * m[12]);
	float res4 = m[3] * (m[4] * m[9] * m[14] - m[4] * m[10] * m[13] - m[5] * m[8] * m[14] + m[5] * m[10] * m[12] + m[6] * m[8] * m[13] - m[6] * m[9] * m[12]);

	return res1 - res2 + res3 - res4;
}

// isIdentity
bool Matrix4::isIdentity()
{
	int count = 0;

	for (int i = 0; i < 16; i++)
	{
		if (m[i] == 1 && i%5 == 0)
		{
			++count;
		}
		else if (m[i] == 0)
		{
			++count;
		}
	}

	if (count == 16)
		return true;

	return false;
}

// Transpose  //TEST
void Matrix4::Transpose()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			a[i][j] = a[j][i];
		}
	}
}
