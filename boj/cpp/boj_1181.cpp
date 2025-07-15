// https://www.acmicpc.net/problem/1181
// 1181번 단어 정렬
// 문자열, 정렬 문제
// 주어진 문자열을 중복을 제거하고 길이가 짧은 것부터, 길이가 같으면 사전 순으로 정렬하여 해결 가능

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<string> v;
    set<string> s;
    
    for (int i=0; i<N; ++i) {
        string temp;
        cin >> temp;
        s.insert(temp);
    }
    
    for (auto e : s) {
        v.push_back(e);
    }
    
    sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        if (a.size() == b.size()) {
            return a < b;
        }
        return a.size() < b.size();
    });
    
    for (auto& e : v) {
        cout << e << '\n';
    }

    return 0;
}
