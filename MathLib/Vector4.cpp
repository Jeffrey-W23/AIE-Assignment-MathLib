// #include, using, etc
#include "Vector4.h"

// Default Constructor
Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 1;
}

// Constructor passing in 2 floats
Vector4::Vector4(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

// Default Destructor
Vector4::~Vector4()
{
}

// Addition
Vector4 Vector4::operator+(const Vector4& rhs)
{
	Vector4 result;
	result.x = x + rhs.x;
	result.y = y + rhs.y;
	result.z = z + rhs.z;
	result.w = w + rhs.w;

	return result;
}

// Subtraction
Vector4 Vector4::operator-(const Vector4& rhs)
{
	Vector4 result;
	result.x = x - rhs.x;
	result.y = y - rhs.y;
	result.z = z - rhs.z;
	result.w = w - rhs.w;

	return result;
}

// Divide
Vector4 Vector4::operator/(const float rhs)
{
	Vector4 result;
	result.x = x / rhs;
	result.y = y / rhs;
	result.z = z / rhs;
	result.w = w / rhs;

	return result;
}

// Multiply vector by float
Vector4 Vector4::operator*(const float rhs)
{
	Vector4 result;
	result.x = x * rhs;
	result.y = y * rhs;
	result.z = z * rhs;
	result.w = w * rhs;

	return result;
}

// Multiply float by vector ( out side of class so we can order )
Vector4 operator*(float lhs, const Vector4& rhs)
{
	Vector4 result;
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;
	result.w = lhs * rhs.w;

	return result;
}

// Dot product
float Vector4::dot(const Vector4& rhs)
{
	float result;
	result = x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
	return result;
}

// Cross product
Vector4 Vector4::cross(const Vector4& rhs)
{
	Vector4 result;
	result.x = y * rhs.z - z * rhs.y;
	result.y = z * rhs.x - x * rhs.z;
	result.z = x * rhs.y - y * rhs.x;
	result.w = 0;

	return result;
}

// Magnititude
float Vector4::magnitude()
{
	float result;
	result = sqrtf(x*x + y*y + z*z + w*w);
	return result;
}

// Magnititude Squared
float Vector4::MagnititudeSquared()
{
	float result;
	result = x*x + y*y + z*z + w*w;
	return result;
}

// Normalise
void Vector4::normalise()
{
	float mag = magnitude();

	if (mag != 0)
	{
		x = x / mag;
		y = y / mag;
		z = z / mag;
		w = w / mag;
	}
}

// Normalised
Vector4 Vector4::Normalised(Vector4 data)
{
	float mag = data.magnitude();

	Vector4 result;

	if (mag != 0)
	{
		result.x = data.x / mag;
		result.y = data.y / mag;
		result.z = data.z / mag;
		result.w = data.w / mag;

		return result;
	}

	return Vector4();
}

// Allow negative vector
Vector4 Vector4::operator-()
{
	Vector4 result;
	result.x = -x;
	result.y = -y;
	result.z = -z;
	result.w = -w;

	return result;
}

// Greater then operator
bool Vector4::operator>(const Vector4 rhs)
{
	return (x > rhs.x && y > rhs.y && z > rhs.z && w > rhs.w);
}

// Less then operator
bool Vector4::operator<(const Vector4 rhs)
{
	return (x < rhs.x && y < rhs.y && z < rhs.z && w < rhs.w);

}

// Override plus equels
Vector4 Vector4::operator+=(const Vector4& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	w += rhs.w;

	return *this;
}

// Override minus equels
Vector4 Vector4::operator-=(const Vector4& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	w -= rhs.w;

	return *this;
}

// Override multiply equels
Vector4 Vector4::operator*=(const float rhs)
{
	Vector4 result;
	result.x = x *= rhs;
	result.y = y *= rhs;
	result.z = z *= rhs;
	result.w = w *= rhs;

	return result;
}

// Override divide equels
Vector4 Vector4::operator/=(const float rhs)
{
	Vector4 result;
	result.x = x /= rhs;
	result.y = y /= rhs;
	result.z = z /= rhs;
	result.w = w /= rhs;

	return result;
}

// Sub-script operator returning a reference 
float& Vector4::operator[](const int rhs)
{
	if (rhs == 0)
		return x;
	else if (rhs == 1)
		return y;
	else if (rhs == 2)
		return z;
	else if (rhs == 3)
		return w;
	else
		return x;
}

// Cast operator to float pointer
Vector4::operator float*()
{
	return &x;
}

// Calculate the normal of a face
Vector4 Vector4::CalcNormal(Vector4 pos1, Vector4 pos2)
{
	Vector4 vec1;
	Vector4 vec2;

	vec1.x = pos1.x - x;
	vec1.y = pos1.y - y;
	vec1.z = pos1.z - z;

	vec2.x = pos2.x - x;
	vec2.y = pos2.y - y;
	vec2.z = pos2.z - z;

	Vector4 res = vec1.cross(vec2);
	res.normalise();

	return res;
}

// Returns the smallest components of two vectors.
Vector4 Vector4::Min(Vector4 rhs)
{
	Vector4 result;

	if (x < rhs.x)
		result.x = x;
	else
		result.x = rhs.x;

	if (y < rhs.y)
		result.y = y;
	else
		result.y = rhs.y;

	if (z < rhs.z)
		result.z = z;
	else
		result.z = rhs.z;

	if (w < rhs.w)
		result.w = w;
	else
		result.w = rhs.w;

	return result;
}

// Returns the largest components of two vectors.
Vector4 Vector4::Max(Vector4 rhs)
{
	Vector4 result;

	if (x > rhs.x)
		result.x = x;
	else
		result.x = rhs.x;

	if (y > rhs.y)
		result.y = y;
	else
		result.y = rhs.y;

	if (z > rhs.z)
		result.z = z;
	else
		result.z = rhs.z;

	if (w > rhs.w)
		result.w = w;
	else
		result.w = rhs.w;

	return result;
}

// Clamping
Vector4 Vector4::Clamp(Vector4 min, Vector4 max)
{
	Vector4 result;

	result = this->Min(min);
	result = result.Max(max);

	return result;
}

// Lerp
Vector4 Vector4::Lerp(Vector4 a, Vector4 b, float t)
{
	return (a + b) * t;
}

// Get distance between 2 vectors.
float Vector4::Distance(Vector4 pos1, Vector4 pos2)
{
	Vector4 diff = pos1 - pos2;
	return diff.magnitude();
}

// Equel to operator
bool Vector4::operator==(const Vector4 rhs)
{
	return (x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w);
}

// Not equel to operator
bool Vector4::operator!=(const Vector4 rhs)
{
	return (x != rhs.x && y != rhs.y && z != rhs.z && w != rhs.w);
}

// Greater then or equel or operator
bool Vector4::operator>=(const Vector4 rhs)
{
	return (x >= rhs.x && y >= rhs.y && z >= rhs.z && w >= rhs.w);
}

// Greater then or equel or operator
bool Vector4::operator<=(const Vector4 rhs)
{
	return (x <= rhs.x && y <= rhs.y && z <= rhs.z && w <= rhs.w);
}

// Bezier
Vector4 Vector4::Bezier(float t, Vector4 a, Vector4 b, Vector4 c)
{
	Vector4 result;
	Vector4 ab = Lerp(a, b, t);
	Vector4 bc = Lerp(b, c, t);
	result = Lerp(ab, bc, t);

	return result;
}

// Hermite Curve
Vector4 Vector4::hermiteCurve(Vector4 point0, Vector4 tangent0, Vector4 point1, Vector4 tangent1, float t)
{
	// calculate t-squared and t-cubed
	float tsq = t * t;
	float tcub = tsq * t;

	// calculate the 4 basis functions
	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + t;
	float h11 = tcub - tsq;

	// return the combined result
	return h00 * point0 + h10 * tangent0 + h01 * point1 + h11 * tangent1;
}