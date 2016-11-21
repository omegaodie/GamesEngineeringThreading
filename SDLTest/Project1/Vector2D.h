#ifndef VECTOR_H
#define VECTOR_H
class Vector2D
{
public:
	Vector2D(float x, float y);
	float GetX();
	float GetY();
	void SetX(float);
	void SetY(float);
protected:
	float m_x;
	float m_y;
};
#endif
