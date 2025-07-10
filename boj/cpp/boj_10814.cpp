// https://www.acmicpc.net/problem/10814
// 10814번 나이순 정렬
// 정렬 문제
// 나이 순, 나이가 같으면 가입한 순(입력 순)으로 정렬하여 해결 가능

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
