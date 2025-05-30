#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int start, vector<int> graph[], bool visited[]) {
    visited[start] = true;
    cout << start << " ";
    for (int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];
        if (!visited[next]) {
            dfs(next, graph, visited);
        }
    }
}

int main() {
    int n = 4; // 정점 개수
    vector<int> graph[5];
    bool visited[5] = {false};

    // 그래프 구성
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(1);
    graph[2].push_back(4);
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[4].push_back(2);
    graph[4].push_back(3);

    // 번호가 작은 순서대로 방문하기 위해 정렬
    for (int i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end());

    cout << "DFS: ";
    dfs(1, graph, visited);
    cout << endl;
    return 0;
}
