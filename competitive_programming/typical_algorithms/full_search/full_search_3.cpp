#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, sum = 0, cnt = 0;
  cin >> N >> sum;
  for(int i = 1; i <= N; i++) {
    for(int j = i + 1; j <= N; j++) {
      for(int k = j + 1; k <= N; k++) {
        if((i + j + k) == sum) cnt++;
      }
    }
  }
  cout << cnt << endl;
}
