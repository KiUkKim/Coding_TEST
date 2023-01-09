#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

// 해당 문제 접근 아이디어
// 해당문제는 기본적인 BFS 문제이다.
// BFS 탐색을 하면서, 탈출하게되면 하나씩 증가하면 되는 문제이다.
// 주의할 점은, 해당 게임판을 test case가 종료되면 초기화 시켜주어야한다.

int map[52][52];
bool visited[52][52];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int n, m, k, t;

void clearMap()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            map[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

void BFS(int posy, int posx)
{
    queue<pair<int, int>> q;

    q.push({posy, posx});

    while(!q.empty())
    {
        pair<int, int> cur = q.front();

        // visited[cur.first][cur.second] = true;
        
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = dy[i] + cur.first;
            int nx = dx[i] + cur.second;

            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || !map[ny][nx])
            {
                continue;
            }
            q.push({ny, nx});
            visited[ny][nx] = true;
        }
    }
}


int main()
{
    fastio;

    cin >> t;

    while(t--)
    {
        int cnt = 0;
        cin >> m >> n >> k;

        for(int i = 0; i < k; i++)
        {
            int k_m, k_n;

            cin >> k_m >> k_n;

            map[k_n][k_m] = 1;
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!visited[i][j] && map[i][j])
                {
                    BFS(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';

        clearMap();
    }
    return 0;
}