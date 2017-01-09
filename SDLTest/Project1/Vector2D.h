#ifndef VECTOR_H
#define VECTOR_H
class Vector2D
{
public:
	Vector2D();
	Vector2D(int x, int y);
	int GetX();
	int GetY();
	void SetX(int);
	void SetY(int);
	int m_x;
	int m_y;
};
#endif
