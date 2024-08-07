// https://www.acmicpc.net/problem/9012

#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        string PS, res = "YES";
        stack<char> s;
        
        cin >> PS;
        for (char P : PS) {
            if (!s.empty() && P == ')') {
                s.pop();
            } else if (P == '(') {
                s.push(P);
            } else {
                res = "NO";
            }
        }
        
        if (!s.empty()) res = "NO";
        cout << res << '\n';
    }
    
    return 0;
}
