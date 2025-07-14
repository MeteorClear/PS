// https://www.acmicpc.net/problem/11656
// 11656번 접미사 배열
// 문자열, 정렬 문제
// 주어진 문자열의 부분 문자열을 정렬해 해결 가능

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    vector<string> v;
    
    for (int i=0; i<s.size(); ++i) {
        v.push_back(s.substr(i));
    }
    
    sort(v.begin(), v.end());
    
    for (auto e : v) {
        cout << e << '\n';
    }

    return 0;
}
