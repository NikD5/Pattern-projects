#include <iostream>

using namespace std;


class Transmitter {
protected:
	virtual void voiceRecord()
	{
		cout << "������ ��������� ����" << endl;
	}

	virtual void sampling()
	{
	}

	virtual void digitization()
	{
	}

	virtual void modulation() = 0;

	virtual void transmission()
	{
		cout << "�������� ������� �� �����������" << endl;
	}

public:
	virtual ~Transmitter()
	{
	}

	void processStart()
	{
		voiceRecord();
		sampling();
		digitization();
		modulation();
		transmission();
	}
};

class AnalogTransmitter : public Transmitter {
public:
	void modulation() override
	{
		cout << "��������� ����������� �������" << endl;
	}
};

class DigitalTransmitter : public Transmitter {
public:
	void sampling() override
	{
		cout << "������������� ����������� ���������" << endl;
	}

	void digitization() override
	{
		cout << "���������" << endl;
	}

	void modulation() override
	{
		cout << "��������� ��������� �������" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");

	Transmitter* analogTransmitter = new AnalogTransmitter();

	analogTransmitter->processStart();

	cout << endl;

	Transmitter* digitalTransmitter = new DigitalTransmitter();

	digitalTransmitter->processStart();

	delete analogTransmitter;
	delete digitalTransmitter;

	return 0;
}
