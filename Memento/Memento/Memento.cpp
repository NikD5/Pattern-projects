#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Memento {
public:
	virtual ~Memento()
	{
	}

	virtual int getDollars() = 0;

	virtual int getEuro() = 0;
};

class ExchangeMemento : public Memento {
	int dollars_;
	int euro_;

public:
	ExchangeMemento(int d, int e) : dollars_(d), euro_(e)
	{
	}

	int getDollars() override
	{
		return dollars_;
	}

	int getEuro() override
	{
		return euro_;
	}
};

class Exchange {
	int dollars_;
	int euro_;

public:
	Exchange(int d, int e) : dollars_(d), euro_(e)
	{
	}

	void getDollars()
	{
		cout << "��������: " << dollars_ << endl;
	}

	void getEuro()
	{
		cout << "����: " << euro_ << endl;
	}

	void sell()
	{
		dollars_ ? --dollars_ : 0;
	}

	void buy()
	{
		++euro_;
	}

	ExchangeMemento* save()
	{
		return new ExchangeMemento(dollars_, euro_);
	}

	void restore(Memento* exchangeMemento)
	{
		dollars_ = exchangeMemento->getDollars();
		euro_ = exchangeMemento->getEuro();

		delete exchangeMemento;
	}
};

class Memory {
	stack<Memento*> history_;
	Exchange* exchange_;

public:
	Memory(Exchange* ex) : exchange_(ex)
	{
	}

	void backup()
	{
		history_.push(exchange_->save());
	}

	void undo()
	{
		if (history_.empty())
			return;
		exchange_->restore(history_.top());
		history_.pop();
	}
};

int main()
{
	setlocale(LC_ALL, "rus");

	Exchange* exchange = new Exchange(10, 10);

	Memory* memory = new Memory(exchange);

	exchange->getDollars();
	exchange->getEuro();

	cout << "---- ������� �������, ������� ���� ----" << endl;
	exchange->sell();
	exchange->buy();

	exchange->getDollars();
	exchange->getEuro();

	cout << "---- ���������� ��������� -------------" << endl;
	memory->backup();

	cout << "---- ������� �������, ������� ���� ----" << endl;
	exchange->sell();
	exchange->buy();

	exchange->getDollars();
	exchange->getEuro();

	cout << "---- �������������� ��������� ---------" << endl;
	memory->undo();

	exchange->getDollars();
	exchange->getEuro();

	delete memory;
	delete exchange;

	return 0;
}