// ref. https://atcoder.jp/contests/abs/tasks/abc085_c

#include <bits/stdc++.h>
using namespace std;


int main() {
  int N, Y;
  cin >> N >> Y;

  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= N - i; ++j) {
      int k = N - i - j;
      int total = 10000 * i + 5000 * j + 1000 * k;

      if (total == Y) {
        cout << i << " " << j << " " << k << endl;
        return 0;
      }
    }
  }

  cout << "-1 -1 -1" << endl;
  return 0;
}
