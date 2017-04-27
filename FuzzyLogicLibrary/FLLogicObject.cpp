#include "FLLogicObject.h"

#include <math.h>

#include "ExceptionToolKit\ExceptionC.h"


FLLogicObject::FLLogicObject()
{
}


FLLogicObject::~FLLogicObject()
{
}

float FLLogicObject::getResult()
{
	if (m_type == FLLOT_NOT)
	{
		EVALUATEC(m_object1.expired() != true);
		std::shared_ptr<FLObject> object1 = m_object1.lock();
		return 1 - object1->getResult();
	}
	else
	{
		EVALUATEC(m_object1.expired() != true);
		EVALUATEC(m_object2.expired() != true);
		std::shared_ptr<FLObject> object1 = m_object1.lock();
		std::shared_ptr<FLObject> object2 = m_object2.lock();
		switch (m_type)
		{
		case FLLogicObject::FLLOT_AND:
			return fmin(object1->getResult(), object2->getResult());
			break;
		case FLLogicObject::FLLOT_OR:
			return fmax(object1->getResult(), object2->getResult());
			break;
		case FLLogicObject::FLLOT_XOR:
			return fmax(object1->getResult(), object2->getResult()) - fmin(object1->getResult(), object2->getResult());
			break;
		case FLLogicObject::FLLOT_NOR:
			return 1 - fmax(object1->getResult(), object2->getResult()) - fmin(object1->getResult(), object2->getResult());
			break;
		default:
			THROWC("Unknown FFLOT type");
			break;
		}
	}
	return 0.0f;
}

void FLLogicObject::setObject1(std::weak_ptr<FLObject> obj)
{
	m_object1 = obj;
}

void FLLogicObject::setObject2(std::weak_ptr<FLObject> obj)
{
	m_object2 = obj;
}

std::weak_ptr<FLObject> FLLogicObject::getObject1()
{
	return m_object1;
}

std::weak_ptr<FLObject> FLLogicObject::getObject2()
{
	return m_object2;
}

void FLLogicObject::setType(FLLogicObjectType type)
{
	m_type = type;
}

FLLogicObject::FLLogicObjectType FLLogicObject::getType()
{
	return m_type;
}
