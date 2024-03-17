#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MOD = 1e9 + 7; // 答えを求める際のモジュール

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        --A; --B; // 配列のインデックスに合わせて0から始める
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    // ex
    // N = 4, M = 5
    // 1 2
    // 1 3
    // 2 3
    // 2 4
    // 3 4
    // graph: [[1, 2], [0, 2, 3], [0, 1, 3], [1, 2]]

    vector<int> distance(N, -1); // 各都市までの距離
    vector<int> ways(N, 0); // 各都市への最短経路の数
    queue<int> que;

    distance[0] = 0;
    // [0, -1, -1, -1]
    ways[0] = 1;
    // [1, 0, 0, 0]
    que.push(0);
    // [0]

    // que = [0]
    //   current = 0
    //     graph[0]の時、next 1,2
    //       next = 1
    //         distance[1]は-1
    //         distance[1] = distance[0](=0) + 1 = 1 都市2は都市1から1離れている
    //         ways[1] = ways[0] = 1 都市1から都市2への最短経路数
    //         que = [1]
    //         distance[0, 1, -1, -1]
    //         ways[1, 1, 0, 0]
    //       next = 2
    //         distance[2]は-1
    //         distance[2] = distance[0](=0) + 1 = 1 都市3は都市1から1離れている
    //         ways[2] = ways[0] = 1 都市1から都市3への最短経路数
    //         que = [1,2]
    //         distance = [0, 1, 1, -1]
    //         ways = [1, 1, 1, 0]
    //         都市2,3(index上では-1)を積む理由は、次の都市を出発点として探索するため。都市1を出発点として次は隣接都市2,3を出発点として探索を行う
    // que = [1,2]
    //   current = 1
    //     graph[1]の時、next 0, 2, 3
    //       next = 0
    //         distance[0] == -1ではない
    //         distance[0] == distance[1] + 1ではない
    //         よって次
    //       next = 2
    //         distance[2] == -1ではない
    //         distance[2] == distance[1] + 1である。つまり、現在の都市2の時点から1つ離れている
    //           ways[2] += ways[1] = 2 都市1から都市3は2つ離れている
    //           ways[2] %= MOD = 2
    //         distance = [0, 1, 2, -1]
    //         ways = [1,1,2,0]
    //       next = 3
    //         distance[3] == -1である
    //         distance[3] = distance[1] + 1 = 2 つまり、現在の都市2の時点から2つ離れている
    //         ways[3] = ways[1] = 1
    //         que = [2,3]
    //         distance = [0, 1, 2, 2]
    //         ways = [1,1,2,1]
    //   current = 2
    //     graph[2]の時、next 0, 1, 3
    //       next = 0
    //         distance[0] == -1ではない
    //         distance[0] == distance[2] + 1ではない
    //         => 0はすでに探索ずみ
    //         よって次
    //       next = 1
    //         distance[1] == -1ではない
    //         distance[1] == distance[2] + 1ではない
    //         => 1はすでに探索済み
    //         よって次
    //       next = 3
    //         distance[3] == -1ではない
    //         distance[3] == distance[2] + 1ではない
    //         => すでに探索済み
    // que = [3]
    //   current = 3
    //     distance = [0, 1, 2, 2]
    //     ways = [1,1,2,1]
    //     graph[3]の時、next = [1,2]
    //       next = 1
    //         distance[1] == -1ではない
    //         distance[1] == distance[3] + 1ではない
    //         よって次
    //       next = 2
    //         distance[2] == -1ではない
    //         distance[2] == distance[3] + 1ではない
    //         終了

    while (!que.empty()) {
        int current = que.front();
        que.pop();
        for (int next : graph[current]) {
            if (distance[next] == -1) {
                distance[next] = distance[current] + 1;
                ways[next] = ways[current];
                que.push(next);
            // 既に探索されたnext都市が現在の都市currentから1ステップ離れた（すなわち、最短経路で直接つながっている）場合に真
            } else if (distance[next] == distance[current] + 1) {
                ways[next] += ways[current];
                ways[next] %= MOD;
            }
        }
    }

    cout << ways[N - 1] << endl; // 最後の都市までの最短経路の数
    return 0;
}
