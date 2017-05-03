#include "FLOutput.h"

#include "ExceptionToolKit\ExceptionC.h"


FLOutput::FLOutput()
{
}


FLOutput::~FLOutput()
{
}

float FLOutput::getResult()
{
	EVALUATECM(m_object.expired() != true, "Output object has invalid object pointer");
	return m_object.lock()->getResult();
}

bool FLOutput::getResultBool()
{
	float r = getResult();
	if (r > 0.5f)
	{
		return true;
	}
	else
	{
		return false;
	}
	return false;
}

void FLOutput::setObject(std::weak_ptr<FLObject> obj)
{
	m_object = obj;
}

std::weak_ptr<FLObject> FLOutput::getObject()
{
	return m_object;
}
