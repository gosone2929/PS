#include <iostream>

using namespace std;

struct TrieNode {
    vector<optional<TrieNode*>> next = vector<optional<TrieNode*>>(26, nullopt);
    bool isFinish = false;
    TrieNode(){ }

    void insert(string s, int currentIndex) {
        if (currentIndex == s.size() - 1) {
            isFinish = true;
            return;
        }

        int nextIndexValue = s[currentIndex] - 'a';
        if (not next[nextIndexValue].has_value()) {
            next[nextIndexValue] = new TrieNode();
        }
        next[nextIndexValue].value()->insert(s, currentIndex + 1);
    }
    bool search(string s, int currentIndex) {
        if (currentIndex == s.size() - 1) {
            return isFinish;
        }
        
        int nextIndexValue = s[currentIndex] - 'a';
        if (not next[nextIndexValue].has_value()) {
            return false;
        }
        return next[nextIndexValue].value()->search(s, currentIndex + 1);
    }
    bool startsWith(string s, int currentIndex) {
        if (currentIndex == s.size()) {
            return true and (isFinish == false);
        }

        int nextIndexValue = s[currentIndex] - 'a';
        if (not next[nextIndexValue].has_value()) {
            return false;
        }
        return next[nextIndexValue].value()->startsWith(s, currentIndex + 1);
    }
};

class Trie {
public:
    TrieNode* root = new TrieNode();
    Trie() { }
    
    void insert(string word) {
        root->insert(word, 0);
    }
    
    bool search(string word) {
        return root->search(word, 0);
    }
    
    bool startsWith(string prefix) {
        return root->startsWith(prefix, 0);
    }
};

struct TrieNode {
    TrieNode* next[26];
    bool isFinish = false;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            next[i] = nullptr;
        }
    }

    void insert(const string& s, int currentIndex) {
        if (currentIndex == s.size()) {
            isFinish = true;
            return;
        }

        int nextIndexValue = s[currentIndex] - 'a';
        if (next[nextIndexValue] == nullptr) {
            next[nextIndexValue] = new TrieNode();
        }
        next[nextIndexValue]->insert(s, currentIndex + 1);
    }

    bool search(const string& s, int currentIndex) {
        if (currentIndex == s.size()) {
            return isFinish;
        }

        int nextIndexValue = s[currentIndex] - 'a';
        if (next[nextIndexValue] == nullptr) {
            return false;
        }
        return next[nextIndexValue]->search(s, currentIndex + 1);
    }

    bool startsWith(const string& s, int currentIndex) {
        if (currentIndex == s.size()) {
            return true;
        }

        int nextIndexValue = s[currentIndex] - 'a';
        if (next[nextIndexValue] == nullptr) {
            return false;
        }
        return next[nextIndexValue]->startsWith(s, currentIndex + 1);
    }
};

class Trie {
public:
    TrieNode* root = new TrieNode();

    Trie() = default;

    void insert(const string& word) {
        root->insert(word, 0);
    }

    bool search(const string& word) {
        return root->search(word, 0);
    }

    bool startsWith(const string& prefix) {
        return root->startsWith(prefix, 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */