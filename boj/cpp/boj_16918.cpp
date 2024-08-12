// https://www.acmicpc.net/problem/16918

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int R, C, N;
    cin >> R >> C >> N;
    char map[R][C]={};
    
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            scanf(" %c ", &map[i][j]);
        }
    }
    
    if (N == 1) {
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                printf("%c", map[i][j]);
            }
            printf("\n");
        }
    } else if (N>1 && N%4 == 3) {
        int temp[R][C];
        for (int i=0; i<R; i++) {
            fill(temp[i], temp[i]+C, 0);
        }
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if (map[i][j] == 'O') {
                    temp[i][j] = 1;
                    temp[min(i+1, R-1)][j] = 1;
                    temp[i][min(j+1, C-1)] = 1;
                    temp[max(i-1, 0)][j] = 1;
                    temp[i][max(j-1, 0)] = 1;
                }
            }
        }
        
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                printf("%c", (temp[i][j] == 1 ? '.' : 'O'));
            }
            printf("\n");
        }
    } else if (N>1 && N%4 == 1) {
        int temp[R][C];
        for (int i=0; i<R; i++) {
            fill(temp[i], temp[i]+C, 0);
        }
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if (map[i][j] == 'O') {
                    temp[i][j] = 1;
                    temp[min(i+1, R-1)][j] = 1;
                    temp[i][min(j+1, C-1)] = 1;
                    temp[max(i-1, 0)][j] = 1;
                    temp[i][max(j-1, 0)] = 1;
                }
            }
        }
        
        int temp2[R][C];
        for (int i=0; i<R; i++) {
            fill(temp2[i], temp2[i]+C, 0);
        }
        
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if (temp[i][j] == 0) {
                    temp2[i][j] = 1;
                    temp2[min(i+1, R-1)][j] = 1;
                    temp2[i][min(j+1, C-1)] = 1;
                    temp2[max(i-1, 0)][j] = 1;
                    temp2[i][max(j-1, 0)] = 1;
                }
            }
        }
        
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                printf("%c", (temp2[i][j] == 1 ? '.' : 'O'));
            }
            printf("\n");
        }
    } else {
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                printf("O");
            }
            printf("\n");
        }
    }
    return 0;
}
