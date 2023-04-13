#include <iostream>
#include <map>
#include <string>

using namespace std;


class ISite {
public:
	virtual string getPage(int num) = 0;

	virtual ~ISite()
	{
	}
};

class Site : public ISite {
public:
	string getPage(int num) override
	{
		return "Это страница сайта " + to_string(num);
	}
};

class SiteProxy : public ISite {
	ISite* site_;
	map<int, string> cache_;

public:
	SiteProxy(ISite* site) : site_(site)
	{
	}

	~SiteProxy()
	{
		delete site_;
	}

	string getPage(int num) override
	{
		string page;

		if (cache_.find(num) == cache_.end()) {
			page = site_->getPage(num);
			cache_[num] = page;
		}
		else {
			page = cache_[num];
			page.insert(0, "из кэша: ");
		}

		return page;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");

	ISite* mySite = new SiteProxy(new Site());

	cout << mySite->getPage(1) << endl;
	cout << mySite->getPage(2) << endl;
	cout << mySite->getPage(3) << endl;

	cout << mySite->getPage(2) << endl;

	delete mySite;

	return 0;
}