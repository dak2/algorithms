// https://qiita.com/e869120/items/25cb52ba47be0fd418d6#3-2-%E9%A0%86%E5%88%97%E5%85%A8%E6%8E%A2%E7%B4%A2

#include <iostream>
#include <algorithm>
using namespace std;

int N, A[11][11], ans = 1000000000;
int P[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) cin >> A[i][j];
    }
    // N!の組み合わせを全て生成するまでイテレーションする
    // ex
    // N = 3の場合
    // `while(next_permutation(P, P + N))` の行はPの配列から先頭3つを3!だけ組み合わせを生成する
    // (1, 2, 3), (1, 3, 2), (2, 1, 3), (2, 3, 1), (3, 1, 2), (3, 2, 1)
    // (1, 2, 3)の場合
    // A[1][2]で都市1と都市2の運賃。A[2][3]で都市2と都市3の運賃を足し込む
    // (1, 3, 2)の場合
    // A[1][3]で都市1と都市2の運賃。A[3][2]で都市2と都市3の運賃を足し込む
    // この最小値を求める
    do {
        int ret = 0;
        for (int i = 0; i < N - 1; i++) ret += A[P[i]][P[i + 1]];
        ans = min(ans, ret);
    } while(next_permutation(P, P + N));

    cout << ans << endl;
    return 0;
}
