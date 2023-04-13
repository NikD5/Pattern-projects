#include<iostream>
using namespace std;

class DataReader
{
public:
	virtual void read() = 0;
};

class DataBaseReader :public DataReader
{
public:
	void read() override
	{
		cout << "������ �� �� " ;
	}
};

class FileReader :public DataReader
{
public:
	void read() override
	{
		cout << "������ �� ����� " ;
	}
};

class Sender
{
protected:
	DataReader* reader;
public:
	Sender(DataReader* dr) :reader(dr){};
	void setDataReader(DataReader* dr)
	{
		reader = dr;
	}
	virtual void send() = 0;
};


class EmailSender :public Sender
{
public:
	EmailSender(DataReader* dr) :Sender(dr) {};
	void send() override
	{
		reader->read();
		cout << " ���������� ��� ������ Email" << endl;
	}
};

class TelegramBotSender :public Sender
{
public:
	TelegramBotSender(DataReader* dr) :Sender(dr) {};
	void send() override
	{
		reader->read();
		cout << " ���������� ��� ������ Telegram ����" << endl;
	}
};
int main()
{
	setlocale(LC_ALL, "rus");

	Sender* sender = new EmailSender(new DataBaseReader());
	sender->send();

	sender->setDataReader(new FileReader());
	sender->send();

	sender = new TelegramBotSender(new DataBaseReader());
	sender->send();

	return 0;

}