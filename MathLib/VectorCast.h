#pragma once
#include "Vector2.h"
#include "Vector3.h"

template <class D, class S>
D CastTo(S source) {};

template <>
Vector3 CastTo(Vector2 source) 
{
	Vector3 result;

	result.x = source.x;
	result.y = source.y;

	return result;
};

template <>
Vector2 CastTo(Vector3 source)
{
	return Vector2(source.x, source.y);
};