#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, cnt = 0, res = 0;
  cin >> N;
  for(int i = 1; i <= N; i++) {
    if(i % 2 != 0) {
      cnt = 0;
      for(int j = 1; j <= i; j++) {
        if(i % j == 0) cnt++;
      }
      if(cnt == 8) res++;
    }
  }
  cout << res << endl;
}
