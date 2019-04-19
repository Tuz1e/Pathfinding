#pragma once

#include <cmath>

namespace tz
{
	template <class T>
	class Vector2
	{
	public:
		Vector2();
		Vector2(T x, T y);

		template <typename U>
		Vector2(const Vector2<U>& vec);

		void Normalize() 
		{
			float length = sqrt((X*X) + (Y*Y));
			if (length != 0.0f)
			{
				X *= (1.0f / length);
				Y *= (1.0f / length);
			}
		}

		//	float tempV0 = a.X - b.X;
//	float tempV1 = a.Y - b.Y;
//	return sqrt((tempV0*tempV0) + (tempV1*tempV1));

		T X, Y;
	};

	template<typename T>
	float DisBetweenVec(Vector2<T>& a, Vector2<T>& b)
	{
		float x = a.X - b.X;
		float y = a.Y - b.Y;

		return sqrt((x*x) + (y*y));
	}

#include "Vector2.inl"

	template<typename T>
	bool operator ==(const Vector2<T>& leftVec, const Vector2<T>& rightVec);

	template<typename T>
	bool operator !=(const Vector2<T>& leftVec, const Vector2<T>& rightVec);

	template<typename T>
	Vector2<T> operator -(const tz::Vector2<T>& leftVec, const tz::Vector2<T>& rightVec);

	template<typename T>
	Vector2<T> operator +(const tz::Vector2<T>& leftVec, const tz::Vector2<T> rightVec);

	template<typename T>
	Vector2<T> operator *(const tz::Vector2<T>& leftVec, const tz::Vector2<T>& rightVec);

	template<typename T>
	Vector2<T> operator *(const T& left, const tz::Vector2<T>& rightVec);

	template<typename T>
	Vector2<T> operator *(const tz::Vector2<T>& leftVec, const T& right);

	template<typename T>
	Vector2<T> operator *=(const tz::Vector2<T>& leftVec, const T& right);

	template<typename T>
	Vector2<T> operator /(const tz::Vector2<T>& leftVec, const tz::Vector2<T>& rightVec);

	template<typename T>
	Vector2<T> operator /(const tz::Vector2<T>& leftVec, T& right);

	template<typename T>
	Vector2<T> operator /=(const tz::Vector2<T>& leftVec, const tz::Vector2<T>& rightVec);

	template<typename T>
	Vector2<T> operator /=(const tz::Vector2<T>& leftVec, T& right);

	template<typename T>
	Vector2<T> operator +=(const tz::Vector2<T>& leftVec, T& right);

	template<typename T>
	Vector2<T> operator -=(const tz::Vector2<T>& leftVec, T& right);

	typedef Vector2<int> Vector2i;
	typedef Vector2<unsigned int> Vector2u;
	typedef Vector2<float> Vector2f;
	typedef Vector2<double> Vector2d;
}