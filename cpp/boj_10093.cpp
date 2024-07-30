// https://www.acmicpc.net/problem/10093

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    long long A, B;
    
    scanf("%lld %lld", &A, &B);

    if (A > B) swap(A, B);
    
    printf("%lld\n", max((long long)0, B-A-1));
    while (++A < B) printf("%lld ", A);

    return 0;
}
