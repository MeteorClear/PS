// https://www.acmicpc.net/problem/10866

#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    deque<int> dq;
    int N;
    cin >> N;
    
    while (N--) {
        string command;
        cin >> command;
        
        if (command == "push_front") {
            int data;
            cin >> data;
            dq.push_front(data);
        } else if (command == "push_back") {
            int data;
            cin >> data;
            dq.push_back(data);
        } else if (command == "pop_front") {
            cout << (dq.empty() ? -1 : dq.front()) << '\n';
            if (!dq.empty()) {
                dq.pop_front();
            }
        } else if (command == "pop_back") {
            cout << (dq.empty() ? -1 : dq.back()) << '\n';
            if (!dq.empty()) {
                dq.pop_back();
            }
        } else if (command == "size") {
            cout << dq.size() << '\n';
        } else if (command == "empty") {
            cout << dq.empty() << '\n';
        } else if (command == "front") {
            cout << (dq.empty() ? -1 : dq.front()) << '\n';
        } else if (command == "back") {
            cout << (dq.empty() ? -1 : dq.back()) << '\n';
        }
    } 

    return 0;
}
