// https://www.acmicpc.net/problem/10814

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<pair<int, string>> users;
    
    while (N--) {
        int tempInt;
        string tempStr;
        
        cin >> tempInt >> tempStr;
        users.push_back({tempInt, tempStr});
    }
    
    stable_sort(users.begin(), users.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });
    
    for (auto [key, value] : users) {
        cout << key << ' ' << value << '\n';
    }
    
    return 0;
}
