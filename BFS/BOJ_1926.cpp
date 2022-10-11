#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <queue>
#define max_y 501
#define max_x 501
using namespace std;

int n, m;
int board[max_y][max_x];
bool visited[max_y][max_x];
int dy[4] = {0,0, 1, -1};
int dx[4] = {-1, 1, 0, 0};
int MaxAreaV = 0;

void BFS(int start_y, int start_x)
{
    int cnt = 0;
    queue<pair<int,int>> q;
    q.push({start_y, start_x});
    
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        visited[cur.first][cur.second] = true;
        q.pop();
        cnt++; 
        for(int i = 0; i < 4; i++)
        {
            int ny = dy[i] + cur.first;
            int nx = dx[i] + cur.second;

            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || !board[ny][nx])
                continue;
            
            visited[ny][nx] = true;
            q.push({ny, nx});

        }
    }
    MaxAreaV = max(MaxAreaV, cnt);

}

int main()
{
    fastio;

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    int cnt = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j] && board[i][j])
            {
                BFS(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << '\n' << MaxAreaV;

    return 0;
}