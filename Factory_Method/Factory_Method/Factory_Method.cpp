#include <iostream>
using namespace std;

//��������� �����/FACTORY METHOD
class IProduction
{
public:
	virtual void release() = 0;
	virtual ~IProduction() {};
};
class Car : public IProduction
{
public:
	void release() override
	{
		cout << "������� �������� ����������" << endl;
	}
};
class Truck : public IProduction
{
public:
	void release() override
	{
		cout << "������� �������� ����������" << endl;
	}
};
class IWorkShop
{
public:
	virtual IProduction* create() = 0;
};
class CarWorkShop :public IWorkShop
{
public:
	IProduction* create() override
	{
		return new Car();
	}

};
class TruckWorkShop :public IWorkShop
{
public:
	IProduction* create() override
	{
		return new Truck();
	}

};


int main()
{
	setlocale(LC_ALL, "rus");

	//������ ������ ���������� ������
	IWorkShop* creator = new CarWorkShop();
	IProduction* car = creator->create();
	creator = new TruckWorkShop();
	IProduction* truck = creator->create();

	car->release();
	truck->release();

	delete car;
	delete truck;

	return 0;
}