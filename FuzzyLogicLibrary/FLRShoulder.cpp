#include "FLRShoulder.h"

#include "ExceptionToolKit\ExceptionC.h"


FLRShoulder::FLRShoulder()
{
}

FLRShoulder::FLRShoulder(float leftX, float rightX, float leftY, float rightY)
{
	if (m_leftX > m_rightX) // backwards
	{
		m_leftX = rightX;
		m_rightX = leftX;
		m_leftY = rightY;
		m_rightY = leftY;
	}
	else
	{
		m_leftX = leftX;
		m_rightX = rightX;
		m_leftY = leftY;
		m_rightY = rightY;
	}
}


FLRShoulder::~FLRShoulder()
{
}

float FLRShoulder::getResult()
{
	EVALUATECM(m_object.expired() != true, "FLRShoulder object has invalid object pointer");
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
		return ((r - m_leftX) / (m_rightX - m_leftX) * (m_rightY - m_leftY)) + m_leftY;
	}

	return 0.0f;
}

void FLRShoulder::setObject(std::weak_ptr<FLObject> obj)
{
	m_object = obj;
}

std::weak_ptr<FLObject> FLRShoulder::getObject()
{
	return m_object;
}
