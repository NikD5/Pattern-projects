#include <iostream>
using namespace std;

//ПРИМЕР РАБОТЫ АБСТРАКТНОЙ ФАБРИКИ/ABSTRACT FACTORY
class IEngine
{
public:
	virtual void releaseEngine() = 0;
	virtual ~IEngine() {};
};
class JapaneseEngine :public IEngine
{
public:
	void releaseEngine() override
	{
		cout << "Японский двигатель" << endl;
	}
};
class RussianEngine :public IEngine
{
public:
	void releaseEngine() override
	{
		cout << "Российский двигатель" << endl;
	}
};
class ICar
{
public:
	virtual void releaseCar(IEngine* engine) = 0;
	virtual ~ICar() {};
};
class JapaneseCar : public ICar
{
public:
	void releaseCar(IEngine* engine) override
	{
		cout << "Собрали японский автомобиль" << endl;
		engine->releaseEngine();
	}
};
class RussianCar : public ICar
{
public:
	void releaseCar(IEngine* engine) override
	{
		cout << "Собрали российский автомобиль" << endl;
		engine->releaseEngine();
	}
};
class IFactory
{
public:
	virtual IEngine* createEngine() = 0;
	virtual ICar* createCar() = 0;
	virtual ~IFactory() {};
};
class JapaneseFactory :public IFactory
{
public:
	IEngine* createEngine() override
	{
		return new JapaneseEngine();
	}
	ICar* createCar() override
	{
		return new JapaneseCar();
	}
};
class RussianFactory :public IFactory
{
public:
	IEngine* createEngine() override
	{
		return new RussianEngine();
	}
	ICar* createCar() override
	{
		return new RussianCar();
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	IFactory* jfactory = new JapaneseFactory();
	IEngine* jEngine = jfactory->createEngine();
	ICar* jCar = jfactory->createCar();
	jCar->releaseCar(jEngine);
	delete jfactory;
	delete jEngine;
	delete jCar;

	IFactory* rFactory = new RussianFactory();
	IEngine* rEngine = rFactory->createEngine();
	ICar* rCar = rFactory->createCar();
	rCar->releaseCar(rEngine);
	delete rFactory;
	delete rEngine;
	delete rCar;
	return 0;
}