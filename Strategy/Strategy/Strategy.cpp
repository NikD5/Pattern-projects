#include <iostream>
#include <string>

using namespace std;


class Reader {
public:
	virtual ~Reader()
	{
	}

	virtual void parse(string& url) = 0;
};

class ResourceReader {
	Reader* reader_;

public:
	ResourceReader(Reader* r) : reader_(r)
	{
	}

	~ResourceReader()
	{
		delete reader_;
	}

	void setStrategy(Reader* r)
	{
		if (reader_)
			delete reader_;

		reader_ = r;
	}

	void read(string& url)
	{
		reader_->parse(url);
	}
};

class NewsSiteReader : public Reader {
public:
	void parse(string& url) override
	{
		cout << "Парсинг с новостного сайта: " << url << endl;
	}
};

class SocialNetworkReader : public Reader {
public:
	void parse(string& url) override
	{
		cout << "Парсинг ленты новостей социальной сети: " << url << endl;
	}
};

class TelegramChannelReader : public Reader {
public:
	void parse(string& url) override
	{
		cout << "Парсинг канала мессенджера Telegram: " << url << endl;
	}
};


int main()
{
	setlocale(LC_ALL, "rus");

	ResourceReader* resourceReader = new ResourceReader(new NewsSiteReader());

	string url = "https://www.engadget.com/";
	resourceReader->read(url);

	url = "https://linkedin.com";
	resourceReader->setStrategy(new SocialNetworkReader());
	resourceReader->read(url);

	url = "@news_channel_telegram";
	resourceReader->setStrategy(new TelegramChannelReader());
	resourceReader->read(url);

	delete resourceReader;


	return 0;
}
