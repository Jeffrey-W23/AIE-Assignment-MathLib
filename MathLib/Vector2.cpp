// #include, using, etc
#include "Vector2.h"

// Default Constructor
Vector2::Vector2()
{
	x = 0;
	y = 0;
}

// Constructor passing in 2 floats
Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

// Default Destructor
Vector2::~Vector2()
{
}

// Addition
Vector2 Vector2::operator+(const Vector2& rhs)
{
	Vector2 result;
	result.x = x + rhs.x;
	result.y = y + rhs.y;

	return result;
}

// Subtraction
Vector2 Vector2::operator-(const Vector2& rhs)
{
	Vector2 result;
	result.x = x - rhs.x;
	result.y = y - rhs.y;

	return result;
}

// Divide
Vector2 Vector2::operator/(const float rhs)
{
	Vector2 result;
	result.x = x / rhs;
	result.y = y / rhs;

	return result;
}

// Multiply vector by float
Vector2 Vector2::operator*(const float rhs)
{
	Vector2 result;
	result.x = x * rhs;
	result.y = y * rhs;

	return result;
}

// Multiply float by vector ( out side of class so we can order )
Vector2 operator*(float lhs, const Vector2& rhs)
{
	Vector2 result;
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;

	return result;
}

// Dot product
float Vector2::dot(const Vector2& rhs)
{
	float result;
	result = x * rhs.x + y * rhs.y;
	return result;
}

// Magnititude
float Vector2::magnitude()
{
	float result;
	result = sqrtf(x*x + y*y);
	return result;
}

// Magnititude Squared
float Vector2::MagnititudeSquared()
{
	float result;
	result = x*x + y*y;
	return result;
}

// Normalise
void Vector2::normalise()
{
	float mag = magnitude();

	if (mag != 0)
	{
		x = x / mag;
		y = y / mag;
	}
}

// Normalised
Vector2 Vector2::Normalised(Vector2 data)
{
	float mag = data.magnitude();

	Vector2 result;

	if (mag != 0)
	{
		result.x = data.x / mag;
		result.y = data.y / mag;
		
		return result;
	}

	return Vector2();
}

// Allow negative vector
Vector2 Vector2::operator-()
{
	Vector2 result;
	result.x = -x;
	result.y = -y;

	return result;
}

// Greater then operator
bool Vector2::operator>(const Vector2 rhs)
{
	return (x > rhs.x && y > rhs.y);
}

// Less then operator
bool Vector2::operator<(const Vector2 rhs)
{
	return (x < rhs.x && y < rhs.y);

}

// Override plus equels
Vector2 Vector2::operator+=(const Vector2& rhs)
{
	x += rhs.x;
	y += rhs.y;

	return *this;
}

// Override minus equels
Vector2 Vector2::operator-=(const Vector2& rhs)
{
	x -= rhs.x;
	y -= rhs.y;

	return *this;
}

// Override multiply equels
Vector2 Vector2::operator*=(const float rhs)
{
	Vector2 result;
	result.x = x *= rhs;
	result.y = y *= rhs;

	return result;
}

// Override divide equels
Vector2 Vector2::operator/=(const float rhs)
{
	Vector2 result;
	result.x = x /= rhs;
	result.y = y /= rhs;

	return result;
}

// Sub-script operator returning a reference 
float& Vector2::operator[](const int rhs)
{
	if (rhs == 0)
		return x;
	else if (rhs == 1)
		return y;
	else
		return x;
}

// Cast operator to float pointer
Vector2::operator float*()
{
	return &x;
}

// Calculate the normal of a face
Vector2 Vector2::CalcNormal(Vector2 pos)
{
	Vector2 vec;
	Vector2 res;

	vec.x = pos.x - x;
	vec.y = pos.y - y;
	vec.normalise();

	res.x = vec.y;
	res.y = -vec.x;

	return res;
}

// Returns the smallest components of two vectors.
Vector2 Vector2::Min(Vector2 rhs)
{
	Vector2 result;

	if (x > rhs.x)
		result.x = x;
	else
		result.x = rhs.x;

	if (y > rhs.y)
		result.y = y;
	else
		result.y = rhs.y;

	return result;
}

// Returns the largest components of two vectors.
Vector2 Vector2::Max(Vector2 rhs)
{
	Vector2 result;

	if (x < rhs.x)
		result.x = x;
	else
		result.x = rhs.x;

	if (y < rhs.y)
		result.y = y;
	else
		result.y = rhs.y;

	return result;
}

// Clamping
Vector2 Vector2::Clamp(Vector2 min, Vector2 max)
{
	Vector2 result;

	result = this->Min(min);
	result = result.Max(max);

	return result;
}

// Lerp
Vector2 Vector2::Lerp(Vector2 a, Vector2 b, float t)
{
	return (a + b) * t;
}

// Get distance between 2 vectors.
float Vector2::Distance(Vector2 pos1, Vector2 pos2)
{
	Vector2 diff =  pos1 - pos2;
	return diff.magnitude(); // change for vector 3 and 4
}