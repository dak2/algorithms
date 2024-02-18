// https://drken1215.hatenablog.com/entry/2021/06/12/181400

#include <bits/stdc++.h>
using namespace std;

// グラフを表すデータ型
using Graph = vector<vector<int>>;

// 頂点 s から DFS (ここではスタックを使う)
vector<int> dfs(const Graph &G, int s) {
    int N = G.size();

    // 頂点 s からの距離
    vector<int> dist(N, -1);
    dist[s] = 0;

    // スタックで DFS
    stack<int> st({s});
    while (!st.empty()) {
        int v = st.top();
        st.pop();
        for (auto nv: G[v]) {
            if (dist[nv] == -1) {
                st.push(nv);
                dist[nv] = dist[v] + 1;
            }
        }
    }

    // リターン
    return dist;
}

int main() {
    // 入力
    int N;
    cin >> N;
    Graph G(N);
    for (int i = 0; i < N-1; ++i) {
        int a, b; cin >> a >> b; --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 頂点 0 から DFS
    auto dist0 = dfs(G, 0);

    // 距離最大の点を求める
    int mx = -1, mv = -1;
    for (int v = 0; v < N; ++v) {
        if (mx < dist0[v]) {
            mx = dist0[v];
            mv = v;
        }
    }

    // 頂点 mv から DFS
    auto distmv = dfs(G, mv);

    // その最大値を求める
    mx = -1;
    for (int v = 0; v < N; ++v) {
        mx = max(mx, distmv[v]);
    }
    cout << mx + 1 << endl;
}
