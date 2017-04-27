#pragma once

#include <memory>

#include "ExceptionToolKit\ExceptionC.h"

#include "FLLogicObject.h"

namespace FMOFunctions
{
	std::shared_ptr<FLLogicObject> createAndSet(std::shared_ptr<FLObject> flo1, std::shared_ptr<FLObject> flo2, FLLogicObject::FLLogicObjectType type)
	{
		EVALUATECM(flo1->getSystem().expired(), "Fuzzy operation failed! left-hand operand has no valid system object");
		EVALUATECM(flo2->getSystem().expired(), "Fuzzy operation failed! right-hand operand has no valid system object");
		EVALUATECM((flo1->getSystem().lock() != flo2->getSystem().lock()), "Fuzzy operation failed! system object is not the same");

		std::shared_ptr<FLSystem> sys = flo1->getSystem().lock();
		std::shared_ptr<FLLogicObject> lo = std::make_shared<FLLogicObject>();
		lo->setSystem(sys);
		lo->setObject1(flo1);
		lo->setObject2(flo2);
		lo->setType(type);

		sys->addObject(lo);

		return lo;
	}
	std::shared_ptr<FLLogicObject> createAndSet(std::shared_ptr<FLObject> flo1, FLLogicObject::FLLogicObjectType type)
	{
		EVALUATECM(flo1->getSystem().expired(), "Fuzzy operation failed! operand has no valid system object");

		std::shared_ptr<FLSystem> sys = flo1->getSystem().lock();
		std::shared_ptr<FLLogicObject> lo = std::make_shared<FLLogicObject>();
		lo->setSystem(sys);
		lo->setObject1(flo1);
		lo->setType(type);

		sys->addObject(lo);

		return lo;
	}
}


std::shared_ptr<FLLogicObject> operator&&(std::shared_ptr<FLObject> flo1, std::shared_ptr<FLObject> flo2)
{
	/*EVALUATECM(flo1->getSystem().expired(), "Fuzzy operation failed! left-hand operand has no valid system object");
	EVALUATECM(flo2->getSystem().expired(), "Fuzzy operation failed! right-hand operand has no valid system object");
	EVALUATECM((flo1->getSystem().lock() != flo2->getSystem().lock()), "Fuzzy operation failed! system object is not the same");

	std::shared_ptr<FLSystem> sys = flo1->getSystem().lock();
	std::shared_ptr<FLLogicObject> lo = std::make_shared<FLLogicObject>();
	lo->setSystem(sys);
	lo->setObject1(flo1);
	lo->setObject2(flo2);
	lo->setType(FLLogicObject::FLLOT_AND);

	sys->addObject(lo);

	return lo;*/
	return FMOFunctions::createAndSet(flo1, flo2, FLLogicObject::FLLOT_AND);
}

std::shared_ptr<FLLogicObject> operator||(std::shared_ptr<FLObject> flo1, std::shared_ptr<FLObject> flo2)
{
	return FMOFunctions::createAndSet(flo1, flo2, FLLogicObject::FLLOT_OR);
}

std::shared_ptr<FLLogicObject> operator!(std::shared_ptr<FLObject> flo1)
{
	return FMOFunctions::createAndSet(flo1, FLLogicObject::FLLOT_NOT);
}