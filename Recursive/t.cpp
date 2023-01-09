#include <iostream>
#include <math.h>
using namespace std;

int n , m;
int map[501][501];
bool visited[501][501];
int move_x[4] = {1,-1,0,0};
int move_y[4] = {0,0,1,-1};
int cnt = 0;
int Max;
int maxn = 0;

void dfs(int x, int y){
    
    Max++;
    visited[x][y] = true;

    for(int i = 0 ; i < 4; i++){
        int next_x = x + move_x[i];
        int next_y = y + move_y[i];

        if(next_x < 0 || next_y < 0 || next_x >= n || next_y >= m || visited[next_x][next_y] || !map[next_x][next_y])
            continue;

        dfs(next_x,next_y);
    }
}

int main(){

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m; j++){
            if(map[i][j] && !visited[i][j]){
                Max = 0;
                dfs(i,j);
                maxn = max(maxn, Max);
                cnt++;
            }
        }
    }
    cout << cnt << "\n" << maxn << '\n';
}