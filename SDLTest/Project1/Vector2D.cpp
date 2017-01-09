#include "Vector2D.h"

Vector2D::Vector2D()
{
}

Vector2D::Vector2D(int x, int y) : m_x(x), m_y(y)
{
}

int Vector2D::GetX()
{
	return m_x;
}

int Vector2D::GetY()
{
	return m_y;
}

void Vector2D::SetX(int x)
{
	m_x = x;
}

void Vector2D::SetY(int y)
{
	m_y = y;
}
