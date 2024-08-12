// https://www.acmicpc.net/problem/1406

#include <iostream>
#include <list>
#include <cstdio>

using namespace std;

int main() {
    char N[100010];
    list<char> l;
    
    scanf("%s", N);
    
    for (int i=0; N[i]!='\0'; i++) {
        l.push_back(N[i]);
    }
    
    int M;
    scanf("%d", &M);
    
    auto cursor = l.end();
    
    for (int i=0; i<M; i++) {
        char command;
        scanf(" %c", &command);
        
        if (command == 'P') {
            char data;
            scanf(" %c", &data);
            
            l.insert(cursor, data);
            
        } else if (command == 'L') {
            if (cursor != l.begin()) {
                cursor--;
            }
            
        } else if (command == 'D') {
            if (cursor != l.end()) {
                cursor++;
            }
            
        } else if (command == 'B') {
            if (cursor != l.begin()) {
                cursor--;
                cursor = l.erase(cursor);
            }
            
        }
    }
    
    for (char ch : l) printf("%c", ch);

    return 0;
}
