// https://www.acmicpc.net/problem/24511

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> A(N);
    for (int i=0; i<N; ++i) {
        cin >> A[i];
    }
    
    deque<int> qs;
    
    for (auto e : A) {
        int temp;
        cin >> temp;
        if (!e) qs.push_back(temp);
    }
    
    int M;
    cin >> M;
    
    while (M--) {
        int temp;
        cin >> temp;
        qs.push_front(temp);
        cout << qs.back() << ' ';
        qs.pop_back();
    }

    return 0;
}
