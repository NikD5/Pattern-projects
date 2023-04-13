#include<iostream>
using namespace std;

class DataBaseHelper
{
public:
	
	DataBaseHelper(const DataBaseHelper&) = delete;
	void operator = (const DataBaseHelper&) = delete;
	static DataBaseHelper* getConnection()
	{
		if (dataBaseConnection == nullptr)
		{
			dataBaseConnection = new DataBaseHelper();
		}
		return dataBaseConnection;
		
	}

	string selectData() const
	{
		return data;
	}

	void InsertData(string d)
	{
		cout << "����� ������:" << d << " �������" << endl;
		data = d;
	}

private:
	DataBaseHelper()
	{
		cout << "����������� � ��" << endl;
	};
	static DataBaseHelper* dataBaseConnection;
	string data;
};

DataBaseHelper* DataBaseHelper::dataBaseConnection = nullptr;

int main()
{
	setlocale(LC_ALL, "rus");

	DataBaseHelper::getConnection()->InsertData("123");
	cout << "������� ������ �� �� " << DataBaseHelper::getConnection()->selectData() << endl;

	return 0;
}