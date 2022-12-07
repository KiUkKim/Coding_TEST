#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, m;
bool visited[100][100];
vector<vector<int>> vc(100);
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int ans[100][100];

void bfs(int y, int x)
{
    queue<pair<int,int>> q;
    q.push({y, x});
    visited[y][x] = true;
    ans[y][x] = 1;

    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = dy[i] + cur.first;
            int nx = dx[i] + cur.second;

            if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || vc[ny][nx] == 0) 
                continue;

            visited[ny][nx] = true;
            ans[ny][nx] = ans[cur.first][cur.second] + 1;
            q.push({ny, nx});
        }
    }
}

int main()
{
    fastio;

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            char tmp;
            cin >> tmp;
            vc[i].push_back(tmp - '0');
        }
    }

    bfs(0,0);

    cout << ans[n-1][m-1] << '\n';

    return 0;
}