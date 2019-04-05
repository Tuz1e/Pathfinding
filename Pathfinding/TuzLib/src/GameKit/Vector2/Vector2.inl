#include "Vector2.hpp"

template <typename T>
inline tz::Vector2<T>::Vector2() : X(0), Y(0) {}

template <typename T>
inline tz::Vector2<T>::Vector2(T x, T y) : X(x), Y(y) {}

template <typename T>
template <typename U>
inline tz::Vector2<T>::Vector2(const tz::Vector2<U>& vec) :
	X(static_cast<T>(vec.X)),
	Y(static_cast<T>(vec.Y)) {}

template<typename T>
inline bool operator ==(const tz::Vector2<T>& leftVec, const tz::Vector2<T>& rightVec)
{
	return ((leftVec.X == rightVec.X) && (leftVec.Y == rightVec.Y));
}

template<typename T>
inline bool operator !=(const tz::Vector2<T>& leftVec, const tz::Vector2<T>& rightVec)
{
	return ((leftVec.X != rightVec.X) && (leftVec.Y != rightVec.Y));
}

template<typename T>
inline tz::Vector2<T> operator -(const tz::Vector2<T>& leftVec, const tz::Vector2<T>& rightVec)
{
	return tz::Vector2<T>(leftVec.X - rightVec.X, leftVec.Y - rightVec.Y);
}

template<typename T>
inline tz::Vector2<T> operator +(const tz::Vector2<T>& leftVec, const tz::Vector2<T> rightVec)
{
	return tz::Vector2<T>(leftVec.X + rightVec.X, leftVec.Y + rightVec.Y);
}

template<typename T>
inline tz::Vector2<T> operator *(const tz::Vector2<T>& leftVec, const tz::Vector2<T>& rightVec)
{
	return tz::Vector2<T>(leftVec.X * rightVec.X, leftVec.Y * rightVec.Y);
}

template<typename T>
inline tz::Vector2<T> operator *(const T& left, const tz::Vector2<T>& rightVec)
{
	return tz::Vector2<T>(rightVec.X * left, rightVec.Y * left);
}

template<typename T>
inline tz::Vector2<T> operator *(const tz::Vector2<T>& leftVec, const T& right)
{
	return tz::Vector2<T>(leftVec.X * right, leftVec.Y * right);
}

template<typename T>
inline tz::Vector2<T> operator *=(const tz::Vector2<T>& leftVec, const T& right)
{
	leftVec.X *= right;
	leftVec.Y *= right;

	return leftVec;
}

template<typename T>
inline tz::Vector2<T> operator /(const tz::Vector2<T>& leftVec, const tz::Vector2<T>& rightVec)
{
	return tz::Vector2<T>(leftVec.X / rightVec.X, leftVec.Y / rightVec.Y);
}

template<typename T>
inline tz::Vector2<T> operator /(const tz::Vector2<T>& leftVec, T& right)
{
	return tz::Vector2<T>(leftVec.X / right, leftVec.Y / right);
}

template<typename T>
inline tz::Vector2<T> operator /=(const tz::Vector2<T>& leftVec, const tz::Vector2<T>& rightVec)
{
	leftVec.X /= rightVec.X;
	leftVec.Y /= rightVec.Y;

	return leftVec;
}

template<typename T>
inline tz::Vector2<T> operator /=(const tz::Vector2<T>& leftVec, T& right)
{
	leftVec.X /= right;
	leftVec.Y /= right;

	return leftVec;
}