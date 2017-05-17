#pragma once
#include "FLRule.h"
class FLRTriangle :
	public FLRule
{
public:
	FLRTriangle();
	FLRTriangle(float leftX, float middleX, float rightX, float leftY, float middleY, float rightY);
	~FLRTriangle();

	virtual float getResult();

	void setObject(std::weak_ptr<FLObject> obj);
	std::weak_ptr<FLObject> getObject();

protected:

	std::weak_ptr<FLObject> m_object;

	float m_leftX = 0;
	float m_leftY = 0;
	float m_middleX = 0.5f;
	float m_middleY = 0.5f;
	float m_rightX = 1;
	float m_rightY = 1;
};

