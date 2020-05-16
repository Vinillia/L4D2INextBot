#pragma once

#define M_PI		3.14159265358979323846f
#define M_RADPI		57.295779513082f
#define M_PI_F		((float)(M_PI))
#define RAD2DEG( x )  ( (float)(x) * (float)(180.f / M_PI_F) )
#define DEG2RAD( x )  ( (float)(x) * (float)(M_PI_F / 180.f) )

class Vector
{
public:

	union 
	{
		float data[3];

		struct 
		{
			float x;
			float y;
			float z;
		};
	};

	Vector() 
	{
		x = 0;
		y = 0;
		z = 0;
	}

	Vector(float ax, float ay, float az) 
	{
		x = ax;
		y = ay;
		z = az;
	}

	Vector(float ax, float ay) 
	{
		x = ax;
		y = ay;
		z = 0;
	}

	Vector(const Vector& o) 
	{
		x = o.x;
		y = o.y;
		z = o.z;
	}

	Vector	operator+(const Vector &) const;

	Vector operator+(const Vector& o)
	{
		return Vector(x + o.x, y + o.y, z + o.z);
	}

	Vector& operator+=(const Vector& o)
	{
		x += o.x;
		y += o.y;
		z += o.z;
		return *this;
	}

	Vector operator-() 
	{
		return Vector(-x, -y, -z);
	}

	Vector operator-(Vector o)
	{
		return Vector(x - o.x, y - o.y, z - o.z);
	}

	inline Vector operator-(const Vector &v) const
	{
		return Vector(x - v.x, y - v.y, z - v.z);
	}

	Vector& operator-=(const Vector o) 
	{
		x -= o.x;
		y -= o.y;
		z -= o.z;
		return *this;
	}

	Vector operator*(const float s) 
	{
		return Vector(x * s, y * s, z * s);
	}

	Vector& operator*=(const float s) 
	{
		x *= s;
		y *= s;
		z *= s;
		return *this;
	}

	Vector	operator*(const float &) const;
	Vector	operator*(const Vector&) const;
	Vector	operator+(float) const;


	Vector	operator/(const Vector &) const;
	
	Vector operator/(const float s) 
	{
		return Vector(x / s, y / s, z / s);
	}

	Vector operator-(float v) const
	{
		return Vector(x - v, y - v, z - v);
	}

	Vector& operator/=(const float s) 
	{
		x /= s;
		y /= s;
		z /= s;
		return *this;
	}

	Vector operator*(const Vector o) 
	{
		return Vector(x * o.x , y * o.y , z * o.z);
	}


	Vector operator^(const Vector o)
	{
		float nx = y * o.z - o.y * z;
		float ny = z * o.x - o.z * x;
		float nz = x * o.y - o.x * y;
		return Vector(nx, ny, nz);
	}

	Vector& operator^=(const Vector o) 
	{
		float nx = y * o.z - o.y * z;
		float ny = z * o.x - o.z * x;
		float nz = x * o.y - o.x * y;

		x = nx;
		y = ny;
		z = nz;

		return *this;
	}

	float magnitude() 
	{
		return sqrt(magnitude_sqr());
	}

	float magnitude_sqr() 
	{
		return (x * x) + (y * y) + (z * z);
	}

	Vector normalised()
	{
		return Vector(*this) / magnitude();
	}

	Vector& normalise()
	{
		(*this) /= magnitude();
		return *this;
	}

	void Init(float ix = 0.0f, float iy = 0.0f, float iz = 0.0f)
	{
		x = ix; y = iy; z = iz;
	}

	void Zero()
	{
		x = y = z = 0.0f;
	}

	inline float Dot(const Vector& v) const
	{
		return (x * v.x + y * v.y + z * v.z);
	}

	float	Length() const;
	float	LengthSquared() const;
	float	Length2D() const;
	float	Length2DSquared() const;
};

inline float Vector::Length() const
{
	return sqrtf((x * x) + (y * y) + (z * z));
}

inline float Vector::LengthSquared() const
{
	return (x * x) + (y * y) + (z * z);
}

inline float Vector::Length2D() const
{
	return sqrtf((x * x) + (y * y));
}

inline float Vector::Length2DSquared() const
{
	return (x * x) + (y * y);
}

inline Vector Vector::operator*(const float &f) const
{
	return Vector(x * f, y * f, z * f);
}

inline Vector Vector::operator*(const Vector &v) const
{
	return Vector(x * v.x, y * v.y, z * v.x);
}

inline Vector Vector::operator+(const Vector &v) const
{
	return Vector(x + v.x, y + v.y, z + v.z);
}

inline Vector Vector::operator+ (float v) const
{
	return Vector(x + v, y + v, z + v);
}

inline Vector Vector::operator/(const Vector &v) const
{
	return Vector(x / (v.x), y / (v.y), z / (v.z));
}

inline Vector operator-(float v, const Vector &vec)
{
	return Vector(vec.x - v, vec.y - v, vec.z - v);
}

inline Vector operator+(float v, const Vector &vec)
{
	return Vector(vec.x + v, vec.y + v, vec.z + v);
}