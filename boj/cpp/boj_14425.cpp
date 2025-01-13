// https://www.acmicpc.net/problem/14425

#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    unordered_set<string> s;
    
    while (N--) {
        string S;
        cin >> S;
        s.insert(S);
    }
    
    int res = 0;
    
    while (M--) {
        string check;
        cin >> check;
        
        if (s.find(check) == s.end()) continue;
        ++res;
    }
    
    cout << res;

    return 0;
}
