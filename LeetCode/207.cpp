//
// Created by MaraMincho on 2025. 12. 22..
//
#include <iostream>

using namespace std;


class Solution {
public:
    const int NOW_VISIT = 1, NOT_VISITED = 0, END_VISITED = 2;

    vector<int> visited;
    vector<vector<int>> graph;

    bool dfs(const int current) {
        visited[current] = NOW_VISIT;
        for (auto next: graph[current]) {
            if (visited[next] == END_VISITED) {
                continue;
            }else if (visited[next] == NOW_VISIT) {
                return false;
            }
            if (not dfs(next)) {
                return false;
            }
        }
        visited[current] = END_VISITED;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        visited.resize(numCourses);
        for (auto ele: prerequisites) {
            graph[ele[1]].push_back(ele[0]);
        }
        for (int i = 0; i < numCourses; i += 1) {
            if (visited[i] == END_VISITED) {
                continue;
            }
            if (not dfs(i)) {
                return false;
            }
        }
        return true;
    }
};
