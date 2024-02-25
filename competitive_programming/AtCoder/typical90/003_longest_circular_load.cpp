// https://drken1215.hatenablog.com/entry/2021/06/12/181400

#include <bits/stdc++.h>
using namespace std;

// グラフを表すデータ型
using Graph = vector<vector<int>>;

// 頂点 s から DFS (ここではスタックを使う)
vector<int> dfs(const Graph &G, int s) {
    int N = G.size();

    // 頂点 s からの距離
    // 初期化して{0, -1, -1, -1, -1}
    vector<int> dist(N, -1);
    dist[s] = 0;

    // スタックで DFS
    // stは{0}から開始
    // ---------- while文デバッグ ---------- //
    // 試行1: 都市1から探索開始
    // スタックから都市1（v = 0）を取り出し、都市2（nv = 1）への移動を確認。
    // st = {1}（都市2へ移動）
    // dist = {0, 1, -1, -1, -1}（都市2への距離を更新）

    // 試行2: 都市2から探索
    // スタックから都市2（v = 1）を取り出し、都市1と都市3（nv = 0, 2）への移動を確認。都市1はすでに訪問済みなので、都市3へ移動。
    // st = {2}（都市3へ移動）
    // dist = {0, 1, 2, -1, -1}（都市3への距離を更新）

    // st.push(nv); => 次に移動する都市を格納
    // dist[nv] = dist[v] + 1; => 現在の都市から+1した距離を格納

    // 都市4になった時点で次に移動する都市が存在しないので、スタックが空になりループ終了

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
    // 入力例
    // 5
    // 1 2
    // 2 3
    // 3 4
    // 3 5
    int N;
    cin >> N;
    Graph G(N);

    // 各都市ごとに接続している都市をリストとして保持
    // `G[0] = {1}`、`G[1] = {0, 2}`、`G[2] = {1, 3, 4}`、`G[3] = {2}`、`G[4] = {2}`
    // ex. `G[0] = {1}`: 都市1(index=0)なら都市2(index=1)と接続 / `G[1] = {0, 2}`: 都市2(index=1)なら都市1(index=0)都市3(index=2)と接続
    for (int i = 0; i < N-1; ++i) {
        int a, b; cin >> a >> b; --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 頂点 0 から DFS
    auto dist0 = dfs(G, 0);

    // DFS実行後の結果を利用して、最も遠い頂点を探す
    // 入力例の値を前提とすると、dist = {0, 1, 2, 3, 3}となる
    // distの中で初期値からの差分を求めて、その頂点を割り出す
    // 今回の場合は0から始めて差分が3なので、頂点4
    int mx = -1, mv = -1;
    for (int v = 0; v < N; ++v) {
        if (mx < dist0[v]) {
            mx = dist0[v];
            mv = v;
        }
    }

    // 頂点 mv から 再度DFS
    // * 最初のDFSは、ある特定の起点（例えば頂点0）から他の全ての頂点までの距離を計算します。このとき見つかる「最も遠い点」は、起点から最長の距離にある頂点ですが、これがグラフ全体の中で最も離れた2点間の距離（直径）とは限りません。
    // * 木やグラフの「直径」とは、任意の2点間の最短パスの中で最も長いものの長さです。最初のDFSで見つけた最遠点は、起点に依存します。そのため、この点から最も遠い点を見つけることで、グラフの任意の2点間で最も距離が長い経路（すなわち、直径）が確実に求められます。
    auto distmv = dfs(G, mv);

    // その最大値を求めて、新しく追加する経路の長さ1を足せば良い
    mx = -1;
    for (int v = 0; v < N; ++v) {
        mx = max(mx, distmv[v]);
    }
    cout << mx + 1 << endl;
}