#include <string>
#include <iostream>

using namespace std;

class Burger {
    string buns;
    string patty;
    string cheese;
public:
    Burger() {
        buns = "";
        patty = "";
        cheese = "";
    }

    void setBuns(const string& buns) {
        this->buns = buns;
    }

    void setPatty(const string& patty) {
        this->patty = patty;
    }

    void setCheese(const string& cheese) {
        this->cheese = cheese;
    }

    void print() {
        cout << "a burger with buns:" << buns << ", patty:"
            << patty << ", cheese:" << cheese << endl;
    }
};


class BurgerBuilder {
    Burger burger;
public:
    BurgerBuilder() {}

    BurgerBuilder& addBuns(const string& buns) {
        burger.setBuns(buns);
        return *this;
    }

    BurgerBuilder& addPatty(const string& patty) {
        burger.setPatty(patty);
        return *this;
    }

    BurgerBuilder& addCheese(const string& cheese) {
        burger.setCheese(cheese);
        return *this;
    }

    Burger build() {
        return burger;
    }
};

int main() {
    BurgerBuilder builder;
    Burger burger1 = builder.addBuns("sesame")
        .addPatty("fish-patty")
        .addCheese("swiss cheese")
        .build();
    burger1.print();

    Burger burger2 = builder.addBuns("peanut")
        .addPatty("beaf-patty")
        .addCheese("union cheese")
        .build();
    burger2.print();
}



