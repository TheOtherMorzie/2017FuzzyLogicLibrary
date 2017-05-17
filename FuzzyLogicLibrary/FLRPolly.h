#pragma once
#include "FLRule.h"
class FLRPolly :
	public FLRule
{
public:
	FLRPolly();
	FLRPolly(const std::vector<std::pair<float, float>> & pairVectorXY, bool truncateLeft = true, bool truncateRight = true); // truncate will set all return values outside of the vector to 0
	~FLRPolly();

	virtual float getResult();

	void setObject(std::weak_ptr<FLObject> obj);
	std::weak_ptr<FLObject> getObject();

protected:

	std::weak_ptr<FLObject> m_object;

	std::vector<std::pair<float, float>> m_pairVectorXY;
	bool m_trunLeft = true;
	bool m_trunRight = true;
};

