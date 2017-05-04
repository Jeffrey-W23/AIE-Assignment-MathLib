// #include, using, etc
#include "Vector3.h"

// Default Constructor
Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

// Constructor passing in 2 floats
Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

// Default Destructor
Vector3::~Vector3()
{
}

// Addition
Vector3 Vector3::operator+(const Vector3& rhs)
{
	Vector3 result;
	result.x = x + rhs.x;
	result.y = y + rhs.y;
	result.z = z + rhs.z;

	return result;
}

// Subtraction
Vector3 Vector3::operator-(const Vector3& rhs)
{
	Vector3 result;
	result.x = x - rhs.x;
	result.y = y - rhs.y;
	result.z = z - rhs.z;

	return result;
}

// Divide
Vector3 Vector3::operator/(const float rhs)
{
	Vector3 result;
	result.x = x / rhs;
	result.y = y / rhs;
	result.z = z / rhs;

	return result;
}

// Multiply vector by float
Vector3 Vector3::operator*(const float rhs)
{
	Vector3 result;
	result.x = x * rhs;
	result.y = y * rhs;
	result.z = z * rhs;

	return result;
}

// Multiply float by vector ( out side of class so we can order )
Vector3 operator*(float lhs, const Vector3& rhs)
{
	Vector3 result;
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;

	return result;
}

// Dot product
float Vector3::dot(const Vector3& rhs)
{
	float result;
	result = x * rhs.x + y * rhs.y + z * rhs.z;
	return result;
}

// Cross product
Vector3 Vector3::cross(const Vector3& rhs)
{
	Vector3 result;
	result.x = y * rhs.z - z * rhs.y;
	result.y = z * rhs.x - x * rhs.z;
	result.z = x * rhs.y - y * rhs.x;

	return result;
}

// Magnititude
float Vector3::magnitude()
{
	float result;
	result = sqrtf(x*x + y*y + z*z);
	return result;
}

// Magnititude Squared
float Vector3::MagnititudeSquared()
{
	float result;
	result = x*x + y*y + z*z;
	return result;
}

// Normalise
void Vector3::normalise()
{
	float mag = magnitude();

	if (mag != 0)
	{
		x = x / mag;
		y = y / mag;
		z = z / mag;
	}
}

// Normalised
Vector3 Vector3::Normalised(Vector3 data)
{
	float mag = data.magnitude();

	Vector3 result;

	if (mag != 0)
	{
		result.x = data.x / mag;
		result.y = data.y / mag;
		result.z = data.z / mag;

		return result;
	}

	return Vector3();
}

// Allow negative vector
Vector3 Vector3::operator-()
{
	Vector3 result;
	result.x = -x;
	result.y = -y;
	result.z = -z;

	return result;
}

// Greater then operator
bool Vector3::operator>(const Vector3 rhs)
{
	return (x > rhs.x && y > rhs.y && z > rhs.z);
}

// Less then operator
bool Vector3::operator<(const Vector3 rhs)
{
	return (x < rhs.x && y < rhs.y && z < rhs.z);

}

// Override plus equels
Vector3 Vector3::operator+=(const Vector3& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;

	return *this;
}

// Override minus equels
Vector3 Vector3::operator-=(const Vector3& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;

	return *this;
}

// Override multiply equels
Vector3 Vector3::operator*=(const float rhs)
{
	Vector3 result;
	result.x = x *= rhs;
	result.y = y *= rhs;
	result.z = z *= rhs;

	return result;
}

// Override divide equels
Vector3 Vector3::operator/=(const float rhs)
{
	Vector3 result;
	result.x = x /= rhs;
	result.y = y /= rhs;
	result.z = z /= rhs;

	return result;
}

// Sub-script operator returning a reference 
float& Vector3::operator[](const int rhs)
{
	if (rhs == 0)
		return x;
	else if (rhs == 1)
		return y;
	else if (rhs == 2)
		return z;
	else
		return x;
}

// Cast operator to float pointer
Vector3::operator float*()
{
	return &x;
}

// Calculate the normal of a face
Vector3 Vector3::CalcNormal(Vector3 pos1, Vector3 pos2)
{
	Vector3 vec1;
	Vector3 vec2;

	vec1.x = pos1.x - x;
	vec1.y = pos1.y - y;
	vec1.z = pos1.z - z;
	
	vec2.x = pos2.x - x;
	vec2.y = pos2.y - y;
	vec2.z = pos2.z - z;

	Vector3 res = vec1.cross(vec2);
	res.normalise();

	return res;
}

// Returns the smallest components of two vectors.
Vector3 Vector3::Min(Vector3 rhs)
{
	Vector3 result;

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

	return result;
}

// Returns the largest components of two vectors.
Vector3 Vector3::Max(Vector3 rhs)
{
	Vector3 result;

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

	return result;
}

// Clamping
Vector3 Vector3::Clamp(Vector3 min, Vector3 max)
{
	Vector3 result;

	result = this->Min(min);
	result = result.Max(max);

	return result;
}

// Lerp
Vector3 Vector3::Lerp(Vector3 a, Vector3 b, float t)
{
	return (a + b) * t;
}

// Get distance between 2 vectors.
float Vector3::Distance(Vector3 pos1, Vector3 pos2)
{
	Vector3 diff = pos1 - pos2;
	return diff.magnitude();
}

// Equel to operator
bool Vector3::operator==(const Vector3 rhs)
{
	return (x == rhs.x && y == rhs.y && z == rhs.z);
}

// Not equel to operator
bool Vector3::operator!=(const Vector3 rhs)
{
	return (x != rhs.x && y != rhs.y && z != rhs.z);
}

// Greater then or equel or operator
bool Vector3::operator>=(const Vector3 rhs)
{
	return (x >= rhs.x && y >= rhs.y && z >= rhs.z);
}

// Greater then or equel or operator
bool Vector3::operator<=(const Vector3 rhs)
{
	return (x <= rhs.x && y <= rhs.y && z <= rhs.z);
}

// Bezier
Vector3 Vector3::Bezier(float t, Vector3 a, Vector3 b, Vector3 c)
{
	Vector3 result;
	Vector3 ab = Lerp(a, b, t);
	Vector3 bc = Lerp(b, c, t);
	result = Lerp(ab, bc, t);

	return result;
}

// Hermite Curve
Vector3 Vector3::hermiteCurve(Vector3 point0, Vector3 tangent0, Vector3 point1, Vector3 tangent1, float t)
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