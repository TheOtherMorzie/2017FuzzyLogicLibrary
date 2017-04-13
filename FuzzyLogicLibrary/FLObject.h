#pragma once
class FLObject
{
public:
	FLObject();
	~FLObject();

	virtual float getResult() = 0; // returns a result between 0 - 1

};

