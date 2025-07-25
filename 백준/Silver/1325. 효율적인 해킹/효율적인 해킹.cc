#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> graph(10001);
int max_count = 0;
int hack_count[10005]; 

int bfs(int start) {
    vector<bool> visited(N + 1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    int count = 1;

    while (!q.empty()) {
        int current = q.front(); q.pop();

        for (int next : graph[current]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                count++;
            }
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        graph[B].push_back(A);
    }

    for (int i = 1; i <= N; i++) {
        hack_count[i] = bfs(i);
        max_count = max(max_count, hack_count[i]);
    }

    for (int i = 1; i <= N; i++) {
        if (hack_count[i] == max_count) {
            cout << i << " ";
        }
    }

    return 0;
}