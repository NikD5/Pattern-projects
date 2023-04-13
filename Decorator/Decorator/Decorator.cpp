#include <iostream>
using namespace std;


class Processor {
public:
	virtual ~Processor()
	{
	}

	virtual void process() = 0;
};

class Transmitter : public Processor {
private:
	string data;

public:
	Transmitter(string d) : data(d)
	{
	}

	void process() override
	{
		cout << "Данные " << data << " переданы по каналу связи" << endl;
	}
};

class Shell : public Processor {
protected:
	Processor* processor;

public:
	Shell(Processor* pr) : processor(pr)
	{
	}

	virtual ~Shell()
	{
	}

	void process() override
	{
		processor->process();
	}
};

class HammingCoder : public Shell {
public:
	HammingCoder(Processor* pr) : Shell(pr)
	{
	}

	void process() override
	{
		cout << "Наложен помехоустойчивый код Хамминга->";
		processor->process();
	}
};

class Encryptor : public Shell {
public:
	Encryptor(Processor* pr) : Shell(pr)
	{
	}

	void process() override
	{
		cout << "Шифрование данных->";
		processor->process();
	}
};

int main()
{
	setlocale(LC_ALL, "rus");

	Processor* transmitter = new Transmitter("12345");
	transmitter->process();

	Shell* hammingCoder = new HammingCoder(transmitter);
	hammingCoder->process();

	Shell* encriptor = new Encryptor(hammingCoder);
	encriptor->process();

	delete encriptor;
	delete hammingCoder;
	delete transmitter;

	return 0;
}
