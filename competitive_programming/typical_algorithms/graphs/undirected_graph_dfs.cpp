// https://qiita.com/drken/items/4a7869c5e304883f539b#3-3-dfs-%E3%81%AE%E5%86%8D%E5%B8%B0%E9%96%A2%E6%95%B0%E3%82%92%E7%94%A8%E3%81%84%E3%81%9F%E5%AE%9F%E8%A3%85
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v) {
	seen[v] = true; // v を訪問済にする

	// v から行ける各頂点 next_v について
	for (auto next_v : G[v]) {
		if (seen[next_v]) continue; // next_v が探索済だったらスルー
		dfs(G, next_v); // 再帰的に探索
	}
}

int main() {
	// 頂点数と辺数
	int N, M; cin >> N >> M;

	// グラフ入力受取 (ここでは無向グラフを想定)
	Graph G(N);
	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	// 頂点 0 をスタートとした探索
	seen.assign(N, false); // 全頂点を「未訪問」に初期化
	dfs(G, 0);
}
