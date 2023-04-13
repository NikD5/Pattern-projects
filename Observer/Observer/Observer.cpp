#include <iostream>
#include <string>
#include <vector>

using namespace std;

class IObserver {
public:
	virtual ~IObserver()
	{
	}

	virtual void update(double p) = 0;
};
class IObservable {
public:
	virtual ~IObservable()
	{
	}

	virtual void addObserver(IObserver* o) = 0;

	virtual void removeObserver(IObserver* o) = 0;

	virtual void notify() = 0;
};

class Product : public IObservable {
	vector<IObserver*> observers_;
	double price_;

public:
	Product(double p) : price_(p)
	{
	}

	void changePrice(double p)
	{
		price_ = p;
		notify();
	}

	void addObserver(IObserver* o) override
	{
		observers_.push_back(o);
	}

	void removeObserver(IObserver* o) override
	{
		observers_.erase(remove(observers_.begin(),observers_.end(),o),observers_.end());
	}

	void notify() override
	{
		for (auto o : observers_) {
			o->update(price_);
		}
	}
};

class Wholesaler : public IObserver {
	IObservable* product_;

public:
	Wholesaler(IObservable* obj) : product_(obj)
	{
		obj->addObserver(this);
	}

	void update(double p) override
	{
		if (p < 300) {
			cout << "������� ������� ����� �� ���� " << p << endl;
			product_->removeObserver(this);
		}
	}
};

class Buyer : public IObserver {
	IObservable* product_;

public:
	Buyer(IObservable* obj) : product_(obj)
	{
		obj->addObserver(this);
	}

	void update(double p) override
	{
		if (p < 350) {
			cout << "���������� ������� ����� �� ���� " << p << endl;
			product_->removeObserver(this);
		}
	}
};

int main()
{
	setlocale(LC_ALL, "rus");

	Product* product = new Product(400);

	Wholesaler* wholesaler = new Wholesaler(product);
	Buyer* buyer = new Buyer(product);

	product->changePrice(320);
	product->changePrice(280);

	delete wholesaler;
	delete buyer;
	delete product;
	return 0;
}
