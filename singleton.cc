#include <string>
#include <iostream>

using namespace std;


class ApplicationState {
private:
    bool loggedIn;
    ApplicationState() {
        loggedIn = false;
    }
    static ApplicationState* instance;
public:
    static ApplicationState* getInstance() {
        if (instance == nullptr) instance = new ApplicationState();
        return instance;
    }

    void login() {
        loggedIn = true;
    }

    void logout() {
        loggedIn = false;
    }

    string getState() {
        string ans = "";
        if (!loggedIn) ans = "not ";
        ans += "logged in";
        return ans;
    }

    ~ApplicationState() {delete instance;}
};

ApplicationState* ApplicationState::instance = nullptr;

int main() {
    ApplicationState* state1 = ApplicationState::getInstance();
    cout << "current state is: " << state1->getState() << endl;
    state1->login();
    cout << "current state is: " << state1->getState() << endl;

    ApplicationState* state2 = ApplicationState::getInstance();
    cout << "current state is: " << state2->getState() << endl;
}
