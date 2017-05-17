#include "FLRTriangle.h"

#include "ExceptionToolKit\ExceptionC.h"


FLRTriangle::FLRTriangle()
{
}

FLRTriangle::FLRTriangle(float leftX, float middleX, float rightX, float leftY, float middleY, float rightY)
{
	m_leftX = leftX;
	m_middleX = middleX;
	m_rightX = rightX;
	m_leftY = leftY;
	m_middleY = middleY;
	m_rightY = rightY;
}


FLRTriangle::~FLRTriangle()
{
}

float FLRTriangle::getResult()
{
	EVALUATECM(m_object.expired() != true, "FLRTriangle object has invalid object pointer");
	float r = m_object.lock()->getResult();

	if (r <= m_leftX) // low plateau
	{
		return m_leftY;
	}
	else if (r >= m_rightX) // top plateau
	{
		return m_rightY;
	}
	else // inbetween
	{
		if (r == m_middleX)
		{
			return m_middleY;
		}
		else if (r < m_middleX) // towards left
		{
			return ((r - m_leftX) / (m_middleX - m_leftX) * (m_middleY - m_leftY)) + m_leftY;
		}
		else // towards right
		{
			return ((r - m_middleX) / (m_rightX - m_middleX) * (m_rightY - m_middleY)) + m_middleY;
		}
	}

	return 0.0f;
}

void FLRTriangle::setObject(std::weak_ptr<FLObject> obj)
{
	m_object = obj;
}

std::weak_ptr<FLObject> FLRTriangle::getObject()
{
	return m_object;
}
