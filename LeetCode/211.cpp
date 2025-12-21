#include <iostream>
using namespace std;


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

    bool searchDot(const string& s, int currentIndex) {
        for (int i = 0; i < 26 ; i += 1) {
            if (next[i] != nullptr and next[i]->search(s, currentIndex + 1)) {
                return true;
            }
        }
        return false;
    }

    bool search(const string& s, int currentIndex) {
        if (currentIndex == s.size()) {
            return isFinish;
        }

        if (s[currentIndex] == '.') {
            return searchDot(s, currentIndex);
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

class WordDictionary {
public:
    Trie* trie = new Trie();
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        trie->insert(word);
    }
    
    bool search(string word) {
        return trie->search(word);
    }
};