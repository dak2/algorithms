// https://drken1215.hatenablog.com/entry/2021/07/25/215000

#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int>> A(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A.at(i).at(j);
    }
  }

  // for (int i = 0; i < H; i++) {
  //   int h_sum = 0; w_sum = 0
  //   for (int j = 0; j < W; j++) {
  //     w_sum += v[i][j]; //行合計
  //     h_sum += v[j][i]; //列合計
  //     v.at(i).at(j) = value;
  //   }
  // }

  // 前処理
  vector<int> yoko(H, 0);  // i 行目の総和
  vector<int> tate(W, 0);  // j 列目の総和
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      yoko[i] += A[i][j];
      tate[j] += A[i][j];
    }
  }

  // 各マス
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cout << yoko[i] + tate[j] - A[i][j] << " ";
    }
    cout << endl;
  }
}
