#pragma once
#include <cmath>
class Vec2
{
public:
	float x;
	float y;

public:
	Vec2() :
		x(0.0f),
		y(0.0f)
	{
	}

	Vec2(float posX, float posY) :
		x(posX),
		y(posY)
	{
	}

	//�P�ʉ��Z�q+
	Vec2 operator +() const
	{
		//this�|�C���^ : �������g�̃A�h���X���w��
		return *this;
	}

	//�P�ʉ��Z�q-�@�t�x�N�g��
	Vec2 operator - () const
	{
		return Vec2{ -x,-y };
	}


	/// �����Z
	Vec2 operator +(Vec2 vec) const
	{
		return Vec2{ x + vec.x, y + vec.y };
	}
	Vec2 operator +=(Vec2 vec)
	{
		x += vec.x;
		y += vec.y;
		return *this;
	}

	/// �����Z
	Vec2 operator -(Vec2 vec) const
	{
		return Vec2{ x - vec.x, y - vec.y };
	}
	Vec2 operator -=(Vec2 vec)
	{
		x -= vec.x;
		y -= vec.y;
		return *this;
	}

	/// �|���Z
	Vec2 operator *(float scale) const
	{
		return Vec2{ x * scale, y * scale };
	}
	Vec2 operator *=(float scale)
	{
		x *= scale;
		y *= scale;
		return *this;
	}

	/// ����Z
	Vec2 operator /(float scale) const
	{
		return Vec2{ x / scale, y / scale };
	}
	Vec2 operator /=(float scale)
	{
		x /= scale;
		y /= scale;
		return *this;
	}

	/// <summary>
	/// �x�N�g���̒�����2������߂�
	/// </summary>
	/// <returns>������2��</returns>
	float SqLength() const
	{
		return x * x + y * y;
	}

	/// <summary>
	/// �x�N�g���̒��������߂�
	/// </summary>
	/// <returns>����</returns>
	float Length() const
	{
		return sqrtf(SqLength());
	}

	/// <summary>
	/// ���g�̐��K�����s��
	/// </summary>
	void Normalize()
	{
		float len = Length();

		// ����0�ȉ��Ȃ珈�����s��Ȃ�
		if (len <= 0.0f) return;

		x /= len;
		y /= len;
	}

	/// <summary>
	/// ���g�𐳋K�������x�N�g�����擾����
	/// </summary>
	/// <returns>���K�������x�N�g��</returns>
	Vec2 GetNormalized() const
	{
		float len = Length();

		// ����0�ȉ��Ȃ�(0, 0)��Ԃ�
		/* ��������ɂ��Ă��闝�R */
		// �����Ȃ��R���X�g���N�^�̏C���ɋ������邽��
		if (len <= 0.0f) return Vec2{ 0.0f, 0.0f };

		return Vec2{ x / len, y / len };
	}
};
