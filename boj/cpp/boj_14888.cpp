// https://www.acmicpc.net/problem/14888

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void make_permutation(vector<vector<int>>& P, vector<int>& O) {
    do {
        P.push_back(O);
    } while (next_permutation(O.begin(), O.end()));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> A(N), O;
    vector<vector<int>> P;
    
    for (int i=0; i<N; i++)  cin >> A[i];
    for (int i=0; i<4; i++) {
        int temp;
        cin >> temp;
        for (int j=0; j<temp; j++) {
            O.push_back(i);
        }
    }
    
    make_permutation(P, O);
    int max_val=-1000000001, min_val=1000000001;
    
    for (auto p : P) {
        int val = A[0];
        for (int i=1; i<N; i++) {
            int cur_operator = p[i-1];
            int operand = A[i];
            switch (cur_operator) {
                case 0:
                    val += A[i];
                    break;
                case 1:
                    val -= A[i];
                    break;
                case 2:
                    val *= A[i];
                    break;
                case 3:
                    val /= A[i];
                    break;
            }
        }
        max_val = max(max_val, val);
        min_val = min(min_val, val);
    }
    
    cout << max_val << '\n' << min_val;
    
    return 0;
}
