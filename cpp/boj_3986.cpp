// https://www.acmicpc.net/problem/3986

#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, count = 0;
    cin >> N;
    while (N--) {
        string str;
        stack<char> s;
        
        cin >> str;
        for (char c : str) {
            if (!s.empty() && s.top() == c) {
                s.pop();
            } else {
                s.push(c);
            }
        }
        
        if (s.empty()) count++;
    }
    
    cout << count;

    return 0;
}
