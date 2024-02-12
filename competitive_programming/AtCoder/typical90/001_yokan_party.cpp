// https://drken1215.hatenablog.com/entry/2021/06/12/020300

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, L, K;
    cin >> N >> L >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    auto check = [&](long long x) -> bool {
        long long num = 0;
        long long pre = 0;
        for (int i = 0; i < N; ++i) {
            if (A[i] - pre >= x) {
                ++num;
                pre = A[i];
            }
        }
        if (L - pre >= x) ++num;

        return (num >= K + 1);
    };

    long long left = -1, right = L + 1;
    while (right - left > 1) {
        long long mid = (left + right) / 2;
        if (check(mid)) left = mid;
        else right = mid;
    }
    cout << left << endl;
}
