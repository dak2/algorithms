// ref. https://atcoder.jp/contests/abs/tasks/abc088_b

#include<iostream>
#include<algorithm>
#include<vector>
#include <set>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];

  // build set to eliminate duplicate 
  set<int> s;
  for(int num : A) {
    s.insert(num);
  };

  cout << s.size() << endl;
}
