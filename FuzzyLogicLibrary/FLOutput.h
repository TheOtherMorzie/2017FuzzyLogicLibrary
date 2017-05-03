#pragma once
#include "FLObject.h"
class FLOutput :
	public FLObject
{
public:
	FLOutput();
	virtual ~FLOutput();

	virtual float getResult(); // returns a result between 0 - 1

	bool getResultBool();

	void setObject(std::weak_ptr<FLObject> obj);
	std::weak_ptr<FLObject> getObject();

protected:

	std::weak_ptr<FLObject> m_object;

};

