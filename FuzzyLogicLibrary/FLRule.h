#pragma once
#include "FLObject.h"

#include "FLLogicObject.h"

class FLRule : public FLObject
{
public:
	FLRule();
	~FLRule();

	virtual float getResult() = 0;

	virtual FLLogicObject operator&&(const FLObject& other);

};

