#include <iostream>
#include <string>

using namespace std;

class TrieFacade {
private:
    struct Trie {
        Trie* next[26];
        Trie() {for (int i=0; i<26; i++) next[i] = nullptr;}
    };

    Trie* root;

public:
    TrieFacade() {
        root = new Trie();
    }

    void add(const string& s) {
        Trie* p = root;
        for (auto c : s) {
            if (p->next[c-'a'] == nullptr) p->next[c-'a'] = new Trie();
            p = p->next[c-'a'];
        }
    }

    bool query(const string& s) {
        Trie* p = root;
        for (auto c : s) {
            if (p->next[c-'a'] == nullptr) return false;
            p = p->next[c-'a'];
        }
        return true;
    }
};

int main() {
    TrieFacade t;
    t.add("abcd");
    t.add("hello");
    t.add("world");
    t.add("anything");
    t.add("great");

    cout << "1=" << t.query("abc") << endl;
    cout << "0=" << t.query("abd") << endl;
    cout << "0=" << t.query("hello,world") << endl;
    cout << "1=" << t.query("any") << endl;
    cout << "0=" << t.query("greeting") << endl;
    cout << "0=" << t.query("bcd") << endl;
}
