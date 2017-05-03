#pragma once

#include <vector>
#include <memory>

//#include "FLObject.h"
class FLObject;

class FLSystem
{
public:
	FLSystem();
	~FLSystem();

	void addObject(std::shared_ptr<FLObject> obj);

	std::shared_ptr<std::vector<std::shared_ptr<FLObject>>> getObjectVector();

protected:

	std::shared_ptr<std::vector<std::shared_ptr<FLObject>>> m_objects;

};

