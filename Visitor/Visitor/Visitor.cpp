#include <iostream>
#include <string>

using namespace std;


class Zoo;
class Cinema;
class Circus;

class IVizitor {
public:
	virtual ~IVizitor() = default;

	virtual void vizit(Zoo& ref) = 0;

	virtual void vizit(Cinema& ref) = 0;

	virtual void vizit(Circus& ref) = 0;
};

class Place {
public:
	virtual ~Place() = default;

	virtual void accept(IVizitor& v) = 0;
};

class Zoo : public Place {
public:
	void accept(IVizitor& v) override
	{
		v.vizit(*this);
	}
};

class Cinema : public Place {
public:
	void accept(IVizitor& v) override
	{
		v.vizit(*this);
	}
};

class Circus : public Place {
public:
	void accept(IVizitor& v) override
	{
		v.vizit(*this);
	}
};

class HolidayMaker : public IVizitor {
public:
	string value;

public:
	void vizit(Zoo& ref) override
	{
		value = "���� � ��������";
	}

	void vizit(Cinema& ref) override
	{
		value = "���� - ��������� �����";
	}

	void vizit(Circus& ref) override
	{
		value = "����� � �����";
	}
};


int main()
{

	setlocale(LC_ALL, "rus");

	Zoo zoo;
	Cinema cinema;
	Circus circus;

	Place* places[] = { &zoo, &cinema, &circus };

	for (auto place : places) {
		HolidayMaker vizitor;
		place->accept(vizitor);
		cout << vizitor.value << endl;
	}


	return 0;
}