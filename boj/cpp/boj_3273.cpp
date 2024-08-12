// https://www.acmicpc.net/problem/3273

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
	  cin.tie(0);
	
    int n, x, count = 0;
    
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    cin >> x;
    vector<bool> visit(x, false);
    
    sort(arr.begin(), arr.end());
    
    for (int i : arr) {
        if (x-i < 0) continue;
        if (visit[x-i]) count++;
        else visit[i] = true;
    }
    cout << count;

    return 0;
}
