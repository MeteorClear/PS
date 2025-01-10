// https://www.acmicpc.net/problem/16916

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string S, P;
    cin >> S >> P;
    
    vector<int> lps_array(P.size(), 0);
    
    for (int i=1, j=0; i<P.size(); ++i) {
        while (j > 0 && P[i] != P[j]) j = lps_array[j-1];
        if (P[i] == P[j]) lps_array[i] = ++j;
    }
    
    bool is_find = false;
    for (int i=0, j=0; i<S.size(); ++i) {
        while (j > 0 && S[i] != P[j]) j = lps_array[j-1];
        if (S[i] == P[j]) ++j;
        
        if (j == P.size()) {
            is_find = true;
            break;
        }
    }
    
    cout << (int)is_find;

    return 0;
}
