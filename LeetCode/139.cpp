#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<string> ws = {};
    unordered_set<string> memo = {};

    bool dfs(string s) {
        if (s.empty()) {
            return true;
        }else if (memo.count(s)) {
            return false;
        }

        for (int distance = 1; distance <= s.size(); distance += 1) {
            string curStr = s.substr(0, distance);

            if (ws.count(curStr)) {
                auto nextStr = s.substr(distance, s.size() - distance);
                auto dfsVal = dfs(nextStr);
                if (dfsVal) {
                    return true;
                }
            }
        }
        memo.insert(s);
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for (string word: wordDict) {
            ws.insert(word);
        }
        return dfs(s);

        return true;
    }
};
class Solution2 {
public:
    // to determin prev visited;
    unordered_set<string> memo = {};
    struct Trie{
        unordered_map<char, Trie*> next = {};
        bool isLeaf = false;

        vector<string> getVal() {
            vector<string> ans;
            if (next.empty()) {
                ans.push_back("");
                return ans;
            }

            for (auto& [ch, nxt] : next) {
                vector<string> sub = nxt->getVal();
                for (auto& s : sub) {
                    ans.push_back(ch + s);   // 앞에 문자 추가
                }
            }
            
            return ans;
        }
    };

    bool go(const string& s) {
        if (s.empty()) return true;
        if (memo.count(s)) return false;

        Trie* ptr = &root;
        for (size_t i = 0; i < s.size(); ++i) {
            char curChar = s[i];

            if (!ptr->next.count(curChar)) {
                memo.insert(s);
                return false;
            }

            ptr = ptr->next[curChar];
            if (ptr->isLeaf) {
                string rem = s.substr(i + 1); 
                if (go(rem)) return true;
            }
        }
        bool result = ptr->isLeaf;
        if (!result) memo.insert(s);
        return result;
    }
    Trie root;
    bool wordBreak(string s, vector<string>& wordDict) {
        root = Trie();
        for (auto word: wordDict) {
            Trie* prev = &root;
            for (char curChar: word) {
                if (not prev->next.count(curChar)) {
                    Trie* newNode = new Trie();
                    prev->next[curChar] = newNode;
                }
                prev = prev->next[curChar];
            }
            prev->isLeaf = true;
        }
        for(auto p: memo) cout << p << endl;
        return go(s);
    }
};

int main() {
    vector<string> v = {"cats","dog","sand","and","cat"};
    bool x = Solution2().wordBreak("applepenapple", v);
    cout << (x ? "true" : "false") << endl;
}