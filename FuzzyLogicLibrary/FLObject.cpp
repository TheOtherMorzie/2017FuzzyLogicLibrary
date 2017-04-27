#include "FLObject.h"



FLObject::FLObject()
{
}


FLObject::~FLObject()
{
}

std::weak_ptr<FLSystem> FLObject::getSystem()
{
	return m_system;
}

void FLObject::setSystem(std::weak_ptr<FLSystem> sys)
{
	m_system = sys;
}
