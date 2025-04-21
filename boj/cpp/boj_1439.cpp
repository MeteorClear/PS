// https://www.acmicpc.net/problem/1439

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string S;
    cin >> S;
    
    int count_1 = 0, count_0 = 0;
    
    char now = S[0];
    if (now == '0') ++count_0;
    else ++count_1;
    
    for (int i=1; i<S.size(); ++i) {
        if (S[i] != now) {
            now = S[i];
            if (now == '0') ++count_0;
            else ++count_1;
        }
    }
    
    if (count_1 && count_0) cout << min(count_1, count_0);
    else cout << 0;

    return 0;
}
