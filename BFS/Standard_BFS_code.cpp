#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#define MAX_Y 10
#define MAX_X 10
using namespace std;

// 반드시 외워야하는 BFS 기본 유형 

int visited[MAX_Y][MAX_X];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int n, m;

void bfs(int posy, int posx)
{
    queue<pair<int,int>> q;
    q.push({posy, posx});
    visited[posy][posx] =  1;
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int ny = dy[i] + cur.first;
            int nx = dx[i] + cur.second;
            // 문제 조건 까지 아래쪽에 넣어줘야함!!
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] )
            {
                continue;
            }
            visited[ny][nx] = 1;
            q.push({ny, nx});
            // 해당 문제에 해당하는 것 ;
        }
    }
}

int main()
{
    fastio;


    return 0;
}