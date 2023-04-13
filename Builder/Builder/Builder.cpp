#include<iostream>
using namespace std;

class Phone
{
	string data;
public:
	Phone() 
	{
		data = "";
	}
	string aboutPhone()
	{
		return data;
	}
	void appendData(string str)
	{
		data += str;
	}
};

class IDeveloper
{
public:
	virtual void createDisplay() = 0;
	virtual void createBox() = 0;
	virtual void systemInstall() = 0;

	virtual Phone* getPhone() = 0;
};

class AndroidDeveloper: public IDeveloper
{
public:
	AndroidDeveloper()
	{
		phone = new Phone();
	};
	~AndroidDeveloper() {
		delete phone;
	};

	void createDisplay() override
	{
		phone->appendData(" Произведен дисплей Samsung ");
	}
	void createBox() override
	{
		phone->appendData(" Произведен корпус Samsung ");
	}
	void systemInstall() override
	{
		phone->appendData(" Установлена система Android ");
	}
	Phone* getPhone() override
	{
		return phone;
	}
private:
	Phone* phone;
};

class IPhoneDeveloper:public IDeveloper
{
public:
	IPhoneDeveloper()
	{
		phone = new Phone();
	};
	~IPhoneDeveloper() {
		delete phone;
	};
	void createDisplay() override
	{
		phone->appendData(" Произведен дисплей Apple ");
	}
	void createBox() override
	{
		phone->appendData(" Произведен корпус Apple ");
	}
	void systemInstall() override
	{
		phone->appendData(" Установлена система IOS ");
	}
	Phone* getPhone() override
	{
		return phone;
	}

private:
	Phone* phone;
};

class Director
{
public:
	Director(IDeveloper* dev):developer(dev) {};

	void setDeveloper(IDeveloper* dev)
	{
		developer = dev;
	}

	Phone* MountOnlyPhone()
	{
		developer->createBox();
		developer->createDisplay();
		return developer->getPhone();
	}
	Phone* MountFullPhone()
	{
		developer->createBox();
		developer->createDisplay();
		developer->systemInstall();
		return developer->getPhone();
	}

private:
	IDeveloper* developer;
};


int main()
{
	setlocale(LC_ALL, "rus");

	IDeveloper* andrDeveloper = new AndroidDeveloper();
	Director director(andrDeveloper);

	Phone* samsung = director.MountFullPhone();
	cout << samsung->aboutPhone() << endl;

	IDeveloper* iphoneDeveloper = new IPhoneDeveloper();
	director.setDeveloper(iphoneDeveloper);

	Phone* iphone = director.MountOnlyPhone();
	cout << iphone->aboutPhone() << endl;


	return 0;
}