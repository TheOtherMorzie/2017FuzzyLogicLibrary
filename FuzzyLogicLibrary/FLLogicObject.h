#pragma once
#include "FLObject.h"

class FLLogicObject : public FLObject
{
public:

	enum FLLogicObjectType
	{
		FLLOT_UNKNOW,
		FLLOT_AND,
		FLLOT_OR,
		FLLOT_XOR,
		FLLOT_NOR,
		FLLOT_NOT
	};


	FLLogicObject();
	~FLLogicObject();

	virtual float getResult(); // do this ###########

	void setObject1(std::weak_ptr<FLObject> obj);
	void setObject2(std::weak_ptr<FLObject> obj);
	
	std::weak_ptr<FLObject> getObject1();
	std::weak_ptr<FLObject> getObject2();

	void setType(FLLogicObjectType type);

	FLLogicObject::FLLogicObjectType getType();

protected:

	FLLogicObjectType m_type = FLLOT_UNKNOW;

	std::weak_ptr<FLObject> m_object1;
	std::weak_ptr<FLObject> m_object2;

};

