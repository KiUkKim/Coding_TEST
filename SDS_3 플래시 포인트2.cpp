#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, m, k;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int result = 987654321;

bool visited[100][100];
char Firemap[100][100];
int dist[100][100];

int BFS(int y, int x)
{
    queue<pair<int,int>> qu;
    qu.push({y, x});
    dist[y][x] = 1;
    int ans = 987654321;
    int cnt = 0;

    visited[y][x] = true;

    while(!qu.empty())
    {
        pair<int, int> cur = qu.front();
        qu.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = dy[i] + cur.first;
            int nx = dx[i] + cur.second;

            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])
                continue;

            if(Firemap[ny][nx] == '#')
                continue;
            
            else if(Firemap[ny][nx] == 'X')
            {
                cnt++;
                ans = min(ans, dist[ny][nx]);
                
                if(cnt == k)
                {
                    return ans;
                }
                continue;
            }

            visited[ny][nx] = true;
            qu.push({ny, nx});
            dist[ny][nx] = dist[cur.first][cur.second] + 1; 
        }
    }
}

int main()
{
    fastio;

    cin >> n >> m >> k;

    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> Firemap[i][j];
        }
    }

    for(int i = 0; i < k; i++)
    {
        int y, x;

        cin >> y >> x;

        Firemap[y-1][x-1] = 'X';
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(Firemap[i][j] != '#' || Firemap[i][j] != 'X')
            {
                result = min(result, BFS(i,j));
            }
        }
    }

    cout << result << '\n';


    return 0;
}