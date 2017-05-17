#include "FLRPolly.h"

#include "ExceptionToolKit\ExceptionC.h"



FLRPolly::FLRPolly()
{
}

FLRPolly::FLRPolly(const std::vector<std::pair<float, float>> & pairVectorXY, bool truncateLeft, bool truncateRight)
{
	m_pairVectorXY = pairVectorXY;
	m_trunLeft = truncateLeft;
	m_trunRight = truncateRight;
}


FLRPolly::~FLRPolly()
{
}

float FLRPolly::getResult()
{
	EVALUATECM(m_object.expired() != true, "FLRPolly object has invalid object pointer");
	float r = m_object.lock()->getResult();

	int vecSize = m_pairVectorXY.size();

	// check if point is outside of vector
	if (r < m_pairVectorXY[0].first)
	{
		if (m_trunLeft)
		{
			return 0;
		}
		else
		{
			return m_pairVectorXY[0].second;
		}
	}
	else if (r > m_pairVectorXY[vecSize].first)
	{
		if (m_trunRight)
		{
			return 0;
		}
		else
		{
			return m_pairVectorXY[vecSize].second;
		}
	}

	// check for which points it lies between
	for (size_t i = 1; i < vecSize; i++) // start at one because we are check to our left and the first point has been checked when we checked if it was lying outside the vector
	{
		if (r <= m_pairVectorXY[i].first) // point is to the left of i
		{
			return ((r - m_pairVectorXY[i - 1].first) / (m_pairVectorXY[i].first - m_pairVectorXY[i - 1].first) * (m_pairVectorXY[i].second - m_pairVectorXY[i - 1].second)) + m_pairVectorXY[i - 1].second;
		}
	}

	return 0.0f;
}

void FLRPolly::setObject(std::weak_ptr<FLObject> obj)
{
	m_object = obj;
}

std::weak_ptr<FLObject> FLRPolly::getObject()
{
	return m_object;
}
