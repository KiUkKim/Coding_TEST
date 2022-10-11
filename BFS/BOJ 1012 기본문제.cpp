#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <queue>
#define maxY 52
#define maxX 52
using namespace std;

int n, m, k, t;
int board[maxY][maxX];
bool visited[maxY][maxX];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {-1, 1, 0, 0};

void clearArray()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            board[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

void BFS(int startY, int startX)
{
    queue<pair<int,int>> q;
    q.push({startY, startX});
    
    while(!q.empty())
    {
        pair<int, int> cur = q.front();

        int cury = cur.first;
        int curx = cur.second;

        visited[cury][curx] = true;

        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = cury + dy[i];
            int nx = curx + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || !board[ny][nx])
                continue;
            
            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }
}

int main()
{
    fastio;
    
    cin >> t; 

    while(t--)
    {
        cin >> m >> n >> k;

        for(int i = 0; i < k; i++)
        {
            int y, x;

            cin >> x >> y;

            board[y][x] = 1;
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

        cout << cnt << '\n';

        clearArray();
    }
    


    return 0;
}