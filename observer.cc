#include <iostream>
#include <string>
#include <vector>

using namespace std;

class YoutubeSubscriber {
public:
    virtual void sendNotification(const string& channel, const string& event) = 0;
};

class YoutubeUser : public YoutubeSubscriber { 
    string name;
public:

    YoutubeUser(const string& name) {
        this->name  = name;
    }

    void sendNotification(const string& channel, const string& event) override {
        cout << "User " << name << " received notification from channel [" 
            << channel << "], event:{" << event << "}" << endl;
    }
};

class YoutubeChannel {
    string name;
    vector<YoutubeSubscriber*> subscribers;
public:
    YoutubeChannel(const string& name) {
        this->name = name;
    }

    void addSubscriber(YoutubeSubscriber* subscriber) {
        subscribers.push_back(subscriber);
    }

    void uploadVideo(const string& subject) {
        for (auto subscriber : subscribers) {
            subscriber->sendNotification(name, "uploaded vedio: " + subject);
        }
    }
};


int main() {
    YoutubeChannel channel("haifeng geek");
    YoutubeUser* sub = new YoutubeUser("Lily");
    channel.addSubscriber((YoutubeSubscriber*)sub);
    channel.uploadVideo("artemis");
}
