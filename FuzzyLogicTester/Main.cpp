#include <string>
#include <iostream>

#include <FLSystem.h>
#include <FLInput.h>
#include <FLLogicObject.h>
#include <FLOutput.h>
#include <FLRShoulder.h>

struct Temp
{
	Temp(int num) { i = num; }

	int i;

};


int main()
{

	float ff = 0;
	float * fff = &ff;

	*fff = 22;

	printf("ff = %d\n", *fff);

	std::cout << "ff = " << *fff << "\n";

	std::shared_ptr<Temp> t(new Temp(2));

	printf("t = %i\n", t->i);

	t->i = 4;

	printf("t = %i\n", t->i);

	(*t).i = 6;

	printf("t = %i\n", t->i);

	system("pause");

	std::shared_ptr<float> f(new float);

	float setVal = 0.1f;

	(*f) = setVal;
	std::cout << "f set to " << *f << "\n";

	(*f) = 0.25f;
	std::cout << "f set to " << *f << "\n";

	FLSystem fls;

	std::shared_ptr<FLInput> fli = std::make_shared<FLInput>();
	std::shared_ptr<FLRShoulder> flrs(new FLRShoulder(0.2f, 0.5f, 0.1f, 0.8f));
	std::shared_ptr<FLOutput> flo = std::make_shared<FLOutput>();

	fli->setInput(f);
	flrs->setObject(fli);
	flo->setObject(flrs);

	fls.addObject(fli);
	fls.addObject(flrs);
	fls.addObject(flo);

	std::cout << "f set to  " << *f << " is " << flo->getResultBool() << "\n";
	std::cout << "f set to  " << *f << " is " << flo->getResult() << "\n";

	(*f) = 0.4f;
	std::cout << "f set to  " << *f << " is " << flo->getResultBool() << "\n";
	std::cout << "f set to  " << *f << " is " << flo->getResult() << "\n";

	(*f) = 0.41f;
	std::cout << "f set to  " << *f << " is " << flo->getResultBool() << "\n";
	std::cout << "f set to  " << *f << " is " << flo->getResult() << "\n";
	


	printf("ran\n");

	system("pause");

	return 0; // all good
}