#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Burger {
    vector<string> ingredients;
public:
    Burger(vector<string>& ingredients) {
        this->ingredients = ingredients;
    }

    void print() {
        cout << "ingredients:" << endl;
        for (auto s : ingredients) cout << s << ","; cout << endl;
    }
};

class BurgerFactory {
public:

    Burger createCheeseBurger() {
        vector<string> ingredients = {"bun", "cheese", "beef-patty"};
        return Burger(ingredients);
    }
        
    Burger createDeluxCheeseBurger() {
        vector<string> ingredients = {"bun", "tomato", "lettuce", "cheese", "beef-patty"};
        return Burger(ingredients);
    }

    Burger createVeganBurger() {
        vector<string> ingredients = {"bun", "special-sauce", "veggie-patty"};
        return Burger(ingredients);
    }
        
};

int main() {
    BurgerFactory bf;
    bf.createCheeseBurger().print();
    bf.createDeluxCheeseBurger().print();
    bf.createVeganBurger().print();
}
