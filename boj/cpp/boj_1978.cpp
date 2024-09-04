// https://www.acmicpc.net/problem/1978

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<bool> v(1001, false);
    v[1] = true;
    for (int i=2; i<998; i++) {
        if (v[i]) continue;
        for (int j=i*2; j<1001; j+=i) {
            v[j] = true;
        }
    }
    
    int N, res = 0;
    cin >> N;
    
    while (N--) {
        int P;
        cin >> P;
        if (!v[P]) ++res;
    }
    
    cout << res;

    return 0;
}
