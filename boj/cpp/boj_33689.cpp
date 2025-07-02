// https://www.acmicpc.net/problem/33689

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, ans = 0;
    cin >> N;
    
    while (N--) {
        string s;
        cin >> s;
        if (s.front() == 'C') ++ans;
    }
    
    cout << ans;
    
    return 0;
}
