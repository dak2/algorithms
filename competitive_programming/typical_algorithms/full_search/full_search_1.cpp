#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, A[50];
  int cnt;
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < N; i++) {
    for(int j = i+1; i < N; j++) {
      for(int k = j+1; i < N; k++) {
        if (A[i] + A[j] + A[k] == K) cnt += 1;
      }
    }
  }
  cout << cnt << endl;
}
