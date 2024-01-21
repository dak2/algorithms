// ref. https://atcoder.jp/contests/abs/tasks/abc088_b

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
  int N, sumA = 0, sumB = 0;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];
  // 降順のソート
  sort(A.begin(), A.end(), greater<int>());

  // 偶数番目と奇数番目の総和
  for (int k = 0; k < N; ++k) {
    if(k % 2 == 0) {
      sumA += A[k];
    } else {
      sumB += A[k];
    }
  }

  cout << (sumA - sumB) << endl;
}
