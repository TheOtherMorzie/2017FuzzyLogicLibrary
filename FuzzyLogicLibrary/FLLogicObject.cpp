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
	return 0.0f;
}
