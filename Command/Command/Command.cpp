#include <iostream>
#include <stack>
#include <vector>

using namespace std;


class ICommand {
public:
	virtual ~ICommand()
	{
	}

	virtual void positive() = 0;

	virtual void negative() = 0;
};

class Conveyor {
public:
	void on()
	{
		cout << "�������� �������" << endl;
	}

	void off()
	{
		cout << "�������� ����������" << endl;
	}

	void speedIncrease()
	{
		cout << "��������� �������� ���������" << endl;
	}

	void speedDecrease()
	{
		cout << "������� �������� ���������" << endl;
	}
};

class ConveyorWorkCommand : public ICommand {
	Conveyor* conveyor_;

public:
	ConveyorWorkCommand(Conveyor* conveyor) : conveyor_(conveyor)
	{
	}

	void positive() override
	{
		conveyor_->on();
	}

	void negative() override
	{
		conveyor_->off();
	}
	};

class ConveyorAdjustCommand : public ICommand {
	Conveyor* conveyor_;

public:
	ConveyorAdjustCommand(Conveyor* conveyor) : conveyor_(conveyor)
	{
	}

	void positive() override
	{
		conveyor_->speedIncrease();
	}

	void negative() override
	{
		conveyor_->speedDecrease();
	}
};

class Multipult {
	vector<ICommand*> commands_;
	stack<ICommand*> history_;

public:
	Multipult()
	{
		commands_.resize(2);
	}

	~Multipult()
	{
		for (auto command : commands_) 
		{
			if (command)
				delete command;
		}
	}

	void setCommand(int button, ICommand* command)
	{
		commands_[button] = command;
	}

		void pressOn(int button)
	{
		commands_[button]->positive();
		history_.push(commands_[button]);
	}

	void pressCancel()
	{
		if (!history_.empty()) {
			history_.top()->negative();
			history_.pop();
		}
	}
};

int main()
{
	setlocale(LC_ALL, "rus");

	Conveyor* conveyor = new Conveyor();

	Multipult* multipult = new Multipult();
	multipult->setCommand(0, new ConveyorWorkCommand(conveyor));
	multipult->setCommand(1, new ConveyorAdjustCommand(conveyor));

	multipult->pressOn(0);
	multipult->pressOn(1);
	multipult->pressCancel();
	multipult->pressCancel();

	delete multipult;
	delete conveyor;


	return 0;

}