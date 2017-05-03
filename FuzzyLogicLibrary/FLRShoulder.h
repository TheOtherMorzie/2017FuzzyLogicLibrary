#pragma once
#include "FLRule.h"
class FLRShoulder :
	public FLRule
{
public:
	FLRShoulder();
	FLRShoulder(float leftX, float rightX, float leftY, float rightY); // lowX: shoulder start, highX: shoulder end
	virtual ~FLRShoulder();

	virtual float getResult();

	void setObject(std::weak_ptr<FLObject> obj);
	std::weak_ptr<FLObject> getObject();

protected:

	std::weak_ptr<FLObject> m_object;

	float m_leftX = 0;
	float m_leftY = 0;
	float m_rightX = 1;
	float m_rightY = 1;



};

