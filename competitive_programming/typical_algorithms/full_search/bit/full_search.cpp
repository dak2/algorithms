// https://qiita.com/e869120/items/25cb52ba47be0fd418d6#3-1-bit-%E5%85%A8%E6%8E%A2%E7%B4%A2

#include <iostream>
using namespace std;

int N, X, A[22];
bool flag = false;

int main() {
    cin >> N >> X;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 0; i < (1 << N); i++) {
        int bit[30], sum = 0;
        for (int j = 0; j < N; j++) {
            // 1を左jビットシフトする = 2のj乗
            // ex
            // j = 0の場合、1 = 2^0 = 1
            // j = 1の場合、10 = 2^1 = 2
            // j = 2の場合、100 = 2^2 = 4
            // j = 3の場合、1000 = 2^3 = 8
            int Div = (1 << j);
            // 10進数のiを2進数に変換する
            // ex
            // N = 3の場合は0,1の2通りを3回組み合わせられるので2^3 = 8通り
            // (0,0,0),(0,0,1),(0,1,0),(0,1,1),(1,0,0),(1,0,1),(1,1,0),(1,1,1)
            // i = 0の場合、0(j=0),0(j=1),0(j=2)
            // i = 1の場合、1(j=0),0(j=1),0(j=2)
            // i = 2の場合、0(j=0),0(j=1),1(j=2)
            // i = 3の場合、1(j=0),1(j=1),0(j=2)
            bit[j] = (i / Div) % 2;
        }
        // bit列と掛け算して足し込む
        // ex
        // i = 3の場合、bit[1,1,0]
        // 0以外をかけて和をとる
        for (int j = 0; j < N; j++) sum += A[j] * bit[j];
        if (sum == X) flag = true;
    }
    if (flag == true) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
