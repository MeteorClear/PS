// https://www.acmicpc.net/problem/10845
// 10845번 큐
// 큐, 구현 문제
// 제시하는 큐 명령 구조를 구현하여 해결 가능

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    queue<int> q;
    
    int N;
    cin >> N;
    
    while (N--) {
        string command;
        cin >> command;
        
        if (command == "push") {
            int data;
            cin >> data;
            q.push(data);
        } else if (command == "pop") {
            if (!q.empty()) {
                cout << q.front() << '\n';
                q.pop();
            } else {
                cout << -1 << '\n';
            }
        } else if (command == "size") {
            cout << q.size() << '\n';
        } else if (command == "empty") {
            cout << q.empty() << '\n';
        } else if (command == "front") {
            cout << (q.empty() ? -1 : q.front()) << '\n';
        } else if (command == "back") {
            cout << (q.empty() ? -1 : q.back()) << '\n';
        } 
    }
    return 0;
}
