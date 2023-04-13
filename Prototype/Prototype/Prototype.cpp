#include<iostream>
#include<string>
using namespace std;

class Animal
{
public:
	virtual void setName(string* name) {};
	virtual string getName() = 0;
	virtual Animal* clone() const = 0;
};

class Sheep : public Animal
{
public:
	Sheep(){}
	~Sheep()
	{
		delete name;
	}
	void setName(string* name) override
	{
		this->name = name;
	}
	string getName() override
	{
		return *name;
	}

	Sheep* clone()const
	{
		return new Sheep(*this);
	}
private:
	string* name;
	Sheep(const Sheep& donor)
	{
		this->name = donor.name;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");

	Sheep* sheepDonor = new Sheep();
	string name = "Долли";
	sheepDonor->setName(&name);

	Sheep* sheepClone = sheepDonor->clone();

	cout << sheepDonor->getName() << endl;
	cout << sheepClone->getName() << endl;

	return 0;
}