// https://www.acmicpc.net/problem/13414

#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int K, L;
    cin >> K >> L;
    
    unordered_map<string, int> registration;
    
    for (int i=0; i<L; ++i) {
        string studentNum;
        cin >> studentNum;
        registration[studentNum] = i;
    }
    
    map<int, string> queue;
    
    for (auto [key, value] : registration) {
        queue[value] = key;
    }
    
    int now = 0;
    for (auto [key, value] : queue) {
        cout << value << '\n';
        ++now;
        if (now == K) break;
    }

    return 0;
}
