https://www.acmicpc.net/problem/1655

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<int> left_heap;
    priority_queue<int, vector<int>, greater<int>> right_heap;
    
    int N;
    cin >> N;
    
    while (N--) {
        int n;
        cin >> n;
        
        if (left_heap.empty() || n <= left_heap.top()) left_heap.push(n);
        else right_heap.push(n);
        
        if (left_heap.size() > right_heap.size() + 1) {
            right_heap.push(left_heap.top());
            left_heap.pop();
            
        } else if (right_heap.size() > left_heap.size()) {
            left_heap.push(right_heap.top());
            right_heap.pop();
        }
        
        cout << left_heap.top() << '\n';
    }
    
    return 0;
}
