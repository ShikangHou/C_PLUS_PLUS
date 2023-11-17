#include <iostream>
#include <list>

using namespace std;

class YouTubeChannel
{
public:
    string name_;
    int subscribersCount_;

public:
    YouTubeChannel(string name, int subscribersCount)
    {
        this->name_ = name;
        this->subscribersCount_ = subscribersCount;
    }

    bool operator ==(const YouTubeChannel channel)
    {
        if(channel.name_ == this->name_) return true;
        else return false;
    }
};

class MyCollection
{
public:
    list<YouTubeChannel> channels;

public:
    void operator+=(const YouTubeChannel &channel)
    {
        this->channels.push_back(channel);
    }

    void operator-=(const YouTubeChannel &channel)
    {
        this->channels.remove(channel); // remove 中使用了 == ,因此还要实现 == 的重载
    }
};

ostream &operator<<(ostream &COUT, const YouTubeChannel &channel)
{
    COUT << "name: " << channel.name_;
    COUT << " subscriberCount: " << channel.subscribersCount_ << endl;
    return COUT;
}

ostream &operator<<(ostream &COUT, const MyCollection &collection)
{
    for (auto &channel : collection.channels)
    {
        COUT << channel.name_ << endl;
        COUT << channel.subscribersCount_ << endl;
    }
    return COUT;
}

int main(int argc, char const *argv[])
{
    YouTubeChannel channel1 = YouTubeChannel("music", 10000);
    YouTubeChannel channel2 = YouTubeChannel("art", 3000);
    cout << channel1 << channel2;

    MyCollection collection;
    collection += channel1;
    collection += channel2;
    collection -= channel1;
    cout << collection;


    return 0;
}
