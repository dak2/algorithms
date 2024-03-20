// https://qiita.com/e869120/items/25cb52ba47be0fd418d6#4-1-%E4%BA%8C%E5%88%86%E6%8E%A2%E7%B4%A2%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, V, a[100009];;
    cin >> N >> V;
    for (int i = 0; i < N; i++) cin >> a[i];

    // a[i] < x となるような i が何個あるのかを O(log N) で計算
    cout << lower_bound(a, a + N, V) - a << endl;

    return 0;
}
