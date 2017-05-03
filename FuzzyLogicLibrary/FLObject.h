#pragma once

#include <memory>

#include "FLSystem.h"

class FLObject
{
public:
	FLObject();
	virtual ~FLObject();

	virtual float getResult() = 0; // returns a result between 0 - 1

	std::weak_ptr<FLSystem> getSystem();
	void setSystem(std::weak_ptr<FLSystem> sys);

protected:

	std::weak_ptr<FLSystem> m_system;

};

