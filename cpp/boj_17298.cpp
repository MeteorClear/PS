// https://www.acmicpc.net/problem/17298

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct E {
    int idx;
    int element;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> res(N, -1);
    stack<E> A;
    
    for (int i=0; i<N; i++) {
        int data;
        cin >> data;
        
        while (!A.empty() && A.top().element < data) {
            res[A.top().idx] = data;
            A.pop();
        }
        
        A.push({i, data});
    }
    
    for (int i : res) cout << i << ' ';
    
    return 0;
}
