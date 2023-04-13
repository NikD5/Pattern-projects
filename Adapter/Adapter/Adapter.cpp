#include<iostream>
using namespace std;

class Scales
{
public:
	virtual float* getWeight() = 0;
	virtual ~Scales(){}

};

class RussianScales: public Scales
{
public:
	RussianScales(float* cw):currentWeight(cw){};
	float* getWeight() override
	{
		return currentWeight;
	}
	~RussianScales()
	{
		delete currentWeight;
	};

private:
	float* currentWeight;
};

class BritishScales
{
public:
	BritishScales(float* cw) :currentWeight(cw) {};
	float* getWeight() 
	{
		return currentWeight;
	}
	~BritishScales()
	{
		delete currentWeight;
	};

private:
	float* currentWeight;
};

class AdapterBritishScales:public Scales
{
public:
	AdapterBritishScales(BritishScales* bs) :britishScales(bs), cw(0) {

	};
	~AdapterBritishScales()
	{
		delete britishScales;
		delete cw;
	};

	float* getWeight() override
	{
		cw = britishScales->getWeight();
		*cw = *cw * 0.453;
		return cw;
	}
private:
	BritishScales* britishScales;
	float* cw;
};


int main()
{
	setlocale(LC_ALL, "rus");

	float kg = 55.0;
	float lb = 55.0;

	Scales* rScales = new RussianScales(&kg);
	Scales* bScales = new AdapterBritishScales(new BritishScales(&lb));

	cout << *rScales->getWeight() << endl;
	cout << *bScales->getWeight() << endl;

	return 0;
}