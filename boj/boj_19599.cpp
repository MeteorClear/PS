// https://www.acmicpc.net/problem/19599

#include <iostream>

using namespace std;

int binary_cost(int n, int idx) {
    int l = 0, r = n-1, cost = 0;
    while (1) {
        int mid = (l + r) / 2;
        
        if (mid == idx) break;
        ++cost;
        
        if (idx < mid) r = mid - 1;
        else l = mid + 1;
    }
    return cost;
}

int ternary_cost(int n, int idx) {
    int l = 0, r = n-1, cost = 0;
    while (1) {
        int lt = l + ((r - l) / 3);
        int rt = r - ((r - l) / 3);
        
        if (idx == lt) return cost;
        ++cost;
        
        if (idx == rt) return cost;
        ++cost;
        
        if (idx < lt) {
            r = lt - 1;
        } else if (idx < rt) {
            l = lt + 1;
            r = rt - 1;
        } else {
            l = rt + 1;
        }
    }
    return cost;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, less = 0, equal = 0, greater = 0;
    cin >> N;
    
    for (int i=0; i<N; ++i) {
        int b = binary_cost(N, i);
        int t = ternary_cost(N, i);
    
        if (b == t) ++equal;
        else if (b > t) ++greater;
        else ++less;
    }
    
    cout << less << '\n' << equal << '\n' << greater;

    return 0;
}
