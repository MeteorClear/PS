// https://www.acmicpc.net/problem/11652
// 11652번 카드
// 맵 문제
// 맵과 같은 키-값 쌍 구조를 이용해 빈도를 세어 해결 가능

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    map<long long, int> deck;
    
    while (N--) {
        long long temp;
        cin >> temp;
        if (deck.find(temp) == deck.end()) {
            deck[temp] = 1;
        } else {
            ++deck[temp];
        }
    }
    
    long long maxKey = 0, maxValue = -1;
    
    for (auto [key, value] : deck) {
        if (value > maxValue) {
            maxKey = key;
            maxValue = value;
        }
    }
    
    cout << maxKey;

    return 0;
}
