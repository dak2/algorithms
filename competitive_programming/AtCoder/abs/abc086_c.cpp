#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {
  int N, pt = 0, px = 0, py = 0;
  cin >> N;
  vector<vector<int>> vec(N);
  for (int i = 0; i < N; ++i) {
    int t, x, y;
    cin >> t >> x >> y;
    int d = abs(px - x) + abs(py - y);
    int dt = (t - pt);
    if(dt < d) {
      cout << "No" << endl;
      return 0;
    }
    if((dt - d) % 2 == 1) {
      cout << "No" << endl;
      return 0;
    }
    pt = t;
    px = x;
    py = y;
  }

  cout << "Yes" << endl;
}
