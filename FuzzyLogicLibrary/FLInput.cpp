#include "FLInput.h"



FLInput::FLInput()
{
}


FLInput::~FLInput()
{
}

float FLInput::getResult()
{
	return (*m_inputFloat - m_min) / (m_max - m_min);
}

void FLInput::setInput(std::shared_ptr<float> f)
{
	m_inputFloat = f;
}

void FLInput::setMin(float min)
{
	m_min = min;
}

void FLInput::setMax(float max)
{
	m_max = max;
}
