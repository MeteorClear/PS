// https://www.acmicpc.net/problem/18258

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
