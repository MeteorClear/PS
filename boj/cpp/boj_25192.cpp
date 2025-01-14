// https://www.acmicpc.net/problem/25192

#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    unordered_set<string> first_chat;
    int N, res = 0;
    
    cin >> N;
    
    while (N--) {
        string nickname;
        cin >> nickname;
        
        if (nickname == "ENTER") {
            first_chat = unordered_set<string>();
            continue;
        }
        
        if (first_chat.find(nickname) == first_chat.end()) {
            first_chat.insert(nickname);
            ++res;
        }
    }
    
    cout << res;

    return 0;
}
