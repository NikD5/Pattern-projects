#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Item 
{
protected:
	string itemName;
	string ownerName;

public:
	Item(string name) : itemName(name)
	{
	}

	virtual ~Item()
	{
	}

	void setOwner(string o)
	{
		ownerName = o;
	}

	virtual void add(Item* subItem) = 0;

	virtual void remove(Item* subItem) = 0;

	virtual void display() = 0;
	};

class ClickableItem : public Item {
public:
	ClickableItem(string name) : Item(name)
	{
	}

	void add(Item* subItem) override
	{
		throw exception();
	}

	void remove(Item* subItem) override
	{
		throw exception();
	}

	void display() override
	{
		cout << itemName << endl;
	}
};

class DropDownItem : public Item {
private:
	vector<Item*> children;

public:
	DropDownItem(string name) : Item(name)
	{
	}

	void add(Item* subItem) override
	{
		subItem->setOwner(this->itemName);
		children.push_back(subItem);
	}

	void remove(Item* subItem) override
	{
		std::remove(children.begin(), children.end(), subItem);
	}

	void display() override
	{
		for (const auto& child : children) 
		{
			if (ownerName != "")
				cout << ownerName << itemName;
			child->display();
		}
	}
};

int main()
{
	setlocale(LC_ALL, "rus");

	Item* file = new DropDownItem("Файл - ");

	Item* create = new DropDownItem("Создать - ");
	Item* open = new DropDownItem("Открыть - ");
	Item* exit = new ClickableItem("Выход");

	file->add(create);
	file->add(open);
	file->add(exit);

	Item* project = new ClickableItem("Проект -");
	Item* repository = new ClickableItem("Репозиторий -");

	create->add(project);
	create->add(repository);

	Item* solution = new ClickableItem("Решение -");
	Item* folder = new ClickableItem("Папка -" );

	open->add(solution);
	open->add(folder);

	file->display();
	cout << endl;

	file->remove(create);

	file->display();

	return 0;
}
