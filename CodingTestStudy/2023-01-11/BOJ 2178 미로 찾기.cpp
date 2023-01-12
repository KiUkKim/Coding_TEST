#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <math.h>
using namespace std;

// 해당 문제는 단순하게 그래프 탐색으로 예상할 수 있다.
// DFS, BFS문제로 나누어지겠지만, BFS로 탐색을 시도한다.
// 이유는 N,M의 위치로 최소의 이동을 해야하기 때문에, 가장 빠른 길을 탐색하는 BFS가 적합하다.
// 물론 해당 문제에서는 DFS에서는 시간초과가 발생한다.
// 이유는 DFS는 방문을 한 노드 기준, 모든 경로를 다 탐색하고 그 다음 경로를 탐색하게 된다.
// DFS는 O(V+E)의 형태를 띈다. 모든 정점을 4방향으로 봐야하기떄문에 약 4^n이 소요된다고 판단한다. (더 많이 소요될 수도 있다)
// 따라서 DFS BFS 둘다 접근하는 형식으로 진행하였다.

int map[101][101];
bool visited[101][101];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int ans[101][101];
int minH = 987654321;
int n, m;

// void DFS(int y, int x, int height)
// {
//     if(y == n - 1 && x == m - 1)
//     {
//         minH = min(minH, height);
//         return;
//     }
//     // 모든 경로를 다 파악한다.
//     for(int i = 0; i < 4; i++)
//     {
//         int ny = dy[i] + y;
//         int nx = dx[i] + x;

//         if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || map[ny][nx] == 0)
//         {
//             continue;
//         }

//         visited[ny][nx] = true;
//         DFS(ny, nx, height+1);
//         visited[ny][nx] = false;
//     }

// }

void BFS(int y, int x)
{
    // 먼저 출발 지점을 queue에 넣어준다.
    queue<pair<int, int>> q;

    q.push({y, x});

    visited[y][x] = true;

    // 해당 문제의 구현은 여기가 중요하다.
    // 기본적인 전역변수로 지정할 시, n,m 도착지를 갈때까지 넣어본 노드에서 또 판단을 해야하는 어려움이 있다.
    ans[y][x] = 1;

    // 큐가 목표 지점을 탐새할 때 까지 반복한다.
    while(!q.empty())
    {
        // queue의 젤 앞의 노드를 꺼내준다.
        pair<int, int> cur = q.front();

        q.pop();

        for(int i = 0; i < 4; i++)
        {
            // 다음위치로 옮겨준다.
            int ny = dy[i] + cur.first;
            int nx = dx[i] + cur.second;

            // 탐색하려는 곳을 넘어섰다면 다음 노드로
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || map[ny][nx] == 0)
            {
                continue;
            }

            q.push({ny,nx});
            visited[ny][nx] = true;
            ans[ny][nx] = ans[cur.first][cur.second] + 1;
        }
    }    
}

int main()
{
    fastio;

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        // 해당 문제는 붙어서 입력이 되기 때문에, string으로 받아서 나누어준다.
        string tmp;
        cin >> tmp;
        for(int j = 0; j < m; j++)
        {
            map[i][j] = tmp[j] - '0';
        }
    }

    BFS(0, 0);

    cout << ans[n-1][m-1] << '\n';

    // DFS(0, 0, 1);

    // cout << minH << '\n';

    return 0;
}