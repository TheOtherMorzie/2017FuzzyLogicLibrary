#pragma once
#include "FLObject.h"

#include <memory>

class FLLogicObject : public FLObject
{

	enum FLLogicObjectType
	{
		FLLOT_UNKNOW,
		FLLOT_AND,
		FLLOT_OR,
		FLLOT_XOR,
		FLLOT_NOR
	};

public:
	FLLogicObject();
	~FLLogicObject();

	virtual float getResult(); // do this ###########

protected:

	FLLogicObjectType m_type = FLLOT_UNKNOW;

	std::shared_ptr<FLObject> object1;
	std::shared_ptr<FLObject> object2;

};

