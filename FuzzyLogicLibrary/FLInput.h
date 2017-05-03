#pragma once
#include "FLObject.h"
class FLInput :
	public FLObject
{
public:
	FLInput();
	virtual ~FLInput();

	virtual float getResult();

	void setInput(std::shared_ptr<float> f);

	void setMin(float min);
	void setMax(float max);


protected:

	std::shared_ptr<float> m_inputFloat;

	float m_min = 0;
	float m_max = 1;

};

