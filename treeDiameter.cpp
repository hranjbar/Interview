/*
https://app.codesignal.com/interview-practice/question/Sby2j4SHqDncwyQjh/description
*/

int maxD, maxNode;
vector<int> visited;
void dfs(vector<vector<int>> & graph, int node, int dist){
    visited[node] = 1;
    if (dist > maxD){ maxD = dist; maxNode = node;}
    for (auto m : graph[node]) if (visited[m] == 0) dfs(graph, m, dist+1);
}
int solution(int n, vector<vector<int>> tree) {
    vector<vector<int>> graph(n);
    for (auto e : tree){
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    visited.assign(n, 0);
    maxD = -1; maxNode = -1;
    dfs(graph, 0, 0);
    visited.assign(n, 0);
    maxD = -1;
    dfs(graph, maxNode, 0);
    return maxD;
}
