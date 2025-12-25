#pragma once

namespace dwiVec
{
	constexpr double PI = 3.14159265358979323846f;
	constexpr double DEG2RAD = PI / 180.0f;
	constexpr double RAD2DEG = 180.0f / PI;

	struct Vec2
	{
		double x, y;
		Vec2()
		{
			x = 0.0;
			y = 0.0;
		}
		Vec2(double value)
		{
			x = value;
			y = value;
		}
		Vec2(double x, double y)
		{
			this->x = x;
			this->y = y;
		}
		inline double toRadians(double degrees)
		{
			return degrees * DEG2RAD;
		}

		inline double toDegrees(double radians)
		{
			return radians * RAD2DEG;
		}
	};
}