#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

bool visited[11][11] = {false, };
// 상, 하, 좌, 우
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int map[11][11];
int M,N,K;
int x1, y1, x2, y2;
vector<int> cnt2;

int dfs(int x, int y)
{
    int cnt = 1;

    map[x][y] = 0;

    for(int i = 0; i < 4; i++)
    {
        int nx = dx[i] + x;
        int ny = dy[i] + y;

        if(nx < 0 || ny < 0 || nx >= N || ny >= N)
        {
            continue;
        }

        if(map[nx][ny])
        {
            cnt += dfs(nx,ny);
        }
    }
    return cnt;
}

int main()
{
    fastio;

    cin >>N;
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    for(int i = 0;  i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(map[i][j])
            {
                cnt2.push_back(dfs(i,j));
            }
        }
    }

    cout << cnt2.size() << '\n';

    sort(cnt2.begin(), cnt2.end());

    for(auto &v : cnt2)
    {
        cout << v << ' ';
    }

    return 0;
}