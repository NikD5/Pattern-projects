#include <iostream>
#include <string>

using namespace std;


class TrafficLight;

class State {
protected:
	TrafficLight* trafficLight_;

public:
	virtual ~State()
	{
	}

	void setTrafficLight(TrafficLight* tr)
	{
		trafficLight_ = tr;
	}

	virtual void nextState() = 0;

	virtual void previousState() = 0;
};

class TrafficLight {
private:
	State* state_;

public:
	TrafficLight(State* st) : state_(nullptr)
	{
		setState(st);
	}

	~TrafficLight()
	{
		if (state_)
			delete state_;
	}

	void setState(State* st)
	{
		if (state_)
			delete state_;

		state_ = st;
		state_->setTrafficLight(this);
	}

	void nextState()
	{
		state_->nextState();
	}

	void previousState()
	{
		state_->previousState();
	}
};

class GreenState : public State {
public:
	void nextState() override;

	void previousState() override
	{
		cout << "������ ����" << endl;
	}
};

class YellowState : public State {
public:
	void nextState() override;

	void previousState() override
	{
		cout << "�� ������ � ������ ����" << endl;
		trafficLight_->setState(new GreenState());
	}
};

void GreenState::nextState()
{
	cout << "�� ������� � ����� ����" << endl;
	trafficLight_->setState(new YellowState());
}

class RedState : public State {
public:
	void nextState() override
	{
		cout << "������� ����" << endl;
	}

	void previousState() override
	{
		cout << "�� �������� � ����� ����" << endl;
		trafficLight_->setState(new YellowState());
	}
};

int main()
{
	setlocale(LC_ALL, "rus");

	TrafficLight* trafficLight = new TrafficLight(new YellowState());

	trafficLight->nextState();
	trafficLight->nextState();
	trafficLight->previousState();
	trafficLight->previousState();
	trafficLight->previousState();

	delete trafficLight;

	return 0;
}

void YellowState::nextState()
{
	cout << "�� ������ � ������� ����" << endl;
	trafficLight_->setState(new RedState());
}
