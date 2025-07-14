// https://www.acmicpc.net/problem/11478
// 11478번 서로 다른 부분 문자열의 개수
// 문자열, 집합 문제
// 부분 문자열을 집합에 넣어 중복을 제거하여 세어 해결 가능

#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string S;
    cin >> S;
    
    unordered_set<string> C;
    
    for (int i=1; i<=S.size(); ++i) {
        for (int j=0; j+i<=S.size(); ++j) {
            C.insert(S.substr(j, i));
        }
    }
    
    cout << C.size();
    
    return 0;
}
