#include <iostream>
#include <vector>

using namespace std;

class FilterStrategy {
public:
    virtual bool removeItem(int val) {
        return true;
    }
};

class RemoveNegativeValueStrategy : public FilterStrategy {
public:
    RemoveNegativeValueStrategy() {}

    bool removeItem(int val) override {
        return val < 0;
    }
};

class RemoveOddValueStrategy : public FilterStrategy {
public:
    RemoveOddValueStrategy() {} 

    bool removeItem(int val) override {
        return val % 2 != 0;
    }
};

class Values {
private:
    vector<int> v;
public:
    Values(const vector<int>& v) {
        this->v = v;
    }

    vector<int> filter(FilterStrategy* strategy) {
        if (strategy == nullptr) return v;
        vector<int> ans;
        for (auto i : v) {
            if (!strategy->removeItem(i)) ans.push_back(i);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {-4,-1,3,4,5,6,7};
    Values v(nums);
    auto v0 = v.filter(nullptr);
    for (auto i : v0) cout << i << ","; cout << endl;
    auto v1 = v.filter(new RemoveNegativeValueStrategy());
    for (auto i : v1) cout << i << ","; cout << endl;
    auto v2 = v.filter(new RemoveOddValueStrategy());
    for (auto i : v2) cout << i << ","; cout << endl;
    auto v3 = v.filter(new FilterStrategy());
    for (auto i : v3) cout << i << ","; cout << endl;
}


