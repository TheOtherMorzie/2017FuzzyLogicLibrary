#include "FLSystem.h"



FLSystem::FLSystem()
{
	m_objects = std::make_shared<std::vector<std::shared_ptr<FLObject>>>();
}


FLSystem::~FLSystem()
{
}

void FLSystem::addObject(std::shared_ptr<FLObject> obj)
{
	m_objects->push_back(obj);
}

std::shared_ptr<std::vector<std::shared_ptr<FLObject>>> FLSystem::getObjectVector()
{
	return m_objects;
}
