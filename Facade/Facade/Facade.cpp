#include <iostream>
using namespace std;

class ProviderCommunication {
public:
	void receive()
	{
		cout << "��������� ���������" << endl;
	}

	void payment()
	{
		cout << "������ ���������� � ���������� �������� �� ������� ���������" << endl;
	}
};

class Site {
public:
	void placement()
	{
		cout << "���������� �� �����" << endl;
	}

	void del()
	{
		cout << "�������� � �����" << endl;
	}
};

class Database {
public:
	void insert()
	{
		cout << "������ � ���� ������" << endl;
	}

	void del()
	{
		cout << "�������� �� ���� ������" << endl;
	}
};

class MarketPlace {
private:
	ProviderCommunication providerCom;
	Site site;
	Database database;

public:
	void productReceipt()
	{
		providerCom.receive();
		site.placement();
		database.insert();
	}

	void productRelease()
	{
		providerCom.payment();
		site.del();
		database.del();
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	MarketPlace marketPlace;
	marketPlace.productReceipt();

	cout << "--------------------------" << endl;

	marketPlace.productRelease();
	return 0;
}
