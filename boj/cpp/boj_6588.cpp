// https://www.acmicpc.net/problem/6588

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<bool> prime(1000001, false);
    vector<int> prime_list;
    
    for (int i=2; i<1000001; ++i) {
        if (!prime[i]) {
            prime_list.push_back(i);
            for (int j=i*2; j<1000001; j+=i) {
                prime[j] = true;
            }
        }
    }
    
    while (1) {
        int n;
        cin >> n;
        if (!n) break;
        
        for (auto& prime_num : prime_list) {
            if (prime_num >= n) {
                cout << "Goldbach's conjecture is wrong.\n";
                break;
            } 
            
            if (!prime[n-prime_num]) {
                cout << n << " = " << prime_num << " + " << n-prime_num << '\n';
                break;
            }
        }
    }

    return 0;
}
