// https://www.acmicpc.net/problem/4949

#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while (1) {
        string str;
        getline(cin, str);
        
        if (str[0] == '.') break;
        
        string res = "yes";
        stack<char> s;
        for (char c : str) {
            if (c == '(' || c == '[') {
                s.push(c);
            } else if (c == ')') {
                if (s.empty()) {
                    res = "no";
                } else if (s.top() == '(') {
                    s.pop();
                } else {
                    res = "no";
                }
            } else if (c == ']') {
                if (s.empty()) {
                    res = "no";
                } else if (s.top() == '[') {
                    s.pop();
                } else {
                    res = "no";
                }
            }
        }
        if (!s.empty()) res = "no";
        
        cout << res << '\n';
    }

    return 0;
}
