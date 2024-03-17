// https://qiita.com/e869120/items/25cb52ba47be0fd418d6#3-3-%E5%86%8D%E5%B8%B0%E9%96%A2%E6%95%B0%E3%82%92%E7%94%A8%E3%81%84%E3%81%9F%E5%85%A8%E6%8E%A2%E7%B4%A2

#include <iostream>
#include <algorithm>
using namespace std;

void func(string cur, int N, int M) {
  if (cur.size() == N) { cout << cur << endl; return; }
  int last = 1;
  // ASCIIコードから文字列に直すために'0'を引いている
  if (cur.size() >= 1) last = cur[cur.size() - 1] - '0';
  for (int i = last; i <= M; i++) {
    // 文字列同士の足し算となるように`('0' + i)`としている（ASCIIコードからの変換）
    // i = 1の時は '0' + 1 = '1'となる
    string nex = cur; nex += ('0' + i);
    func(nex, N, M);
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  func("", N, M);
}
