// https://www.acmicpc.net/problem/10989

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> v(10001, 0);
    
    while (N--) {
        int temp;
        cin >> temp;
        ++v[temp];
    }
    
    for (int i=1; i<10001; ++i) {
        for (int j=0; j<v[i]; ++j) {
            cout << i << '\n';
        }
    }
    
    return 0;
}
