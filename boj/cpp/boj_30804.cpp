// https://www.acmicpc.net/problem/30804

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> S(N);
    for (int i=0; i<N; ++i) {
        cin >> S[i];
    }
    
    unordered_map<int, int> freq;
    int start = 0, end = 0, size = 0;
    
    for (; end<N; ++end) {
        ++freq[S[end]];
        
        while (freq.size() > 2) {
            if (--freq[S[start]] == 0) freq.erase(S[start]);
            ++start;
        }
        size = max(size, end-start+1);
    }
    
    cout << size;

    return 0;
}
