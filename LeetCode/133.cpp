#include <iostream>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    vector<int> visited = vector(101, 0);
    unordered_map<int, Node*> hash = {};
    Node* dfs(Node* node) {
        if (hash.count(node->val)) 
            return hash[node->val];
        
        Node* clone = new Node(node->val);
        hash[clone->val] = clone;

        for (auto next: node->neighbors) {
            clone->neighbors.push_back(dfs(next));
        }
        return clone;
    }
    // input is root node
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        return dfs(node);
    }
    

    void printNode(Node* node) {
        if (visited[node->val]) return;
        visited[node->val] = 1;

        vector<int> ne = {};
        for (auto next: node->neighbors) {
            ne.push_back(next->val);
        }
        cout << node->val << ": ";
        for(auto t: ne) cout << t << ", "; cout << endl;

        for(auto next: node->neighbors) {
            printNode(next);
        }
    }
};

Node* test1Node() {
     // 노드 생성
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    // 이웃 연결 (undirected graph)
    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};
    return n1;
}

int main() {
    Node* test1 = test1Node();

    auto p = Solution().cloneGraph(test1);
    Solution().printNode(p);

    // Solution().printNode(test1);
}