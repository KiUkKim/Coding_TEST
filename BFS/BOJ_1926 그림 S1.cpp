#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

// 문제 접근
// DFS BFS 둘 다 접근을 할 수 있는 문제이다.
// 해당 문제는 BFS카테고리로, BFS 접근
// 1번이 해당되는 부분을 탐색한 후, 더 이상 탐색할 경우가 없을 경우 탈출하고 이 개수를 반환한다.
// 해당 개수를 반환해주면서 가장 큰 값을 정답으로 반환

// main 문에서 탈출했을 경우 1개씩 늘리면서 개수를 찾는다.

// 주의할 점은 그림이 하나도 없는 경우 제일 큰 넓이는 0이므로 area 초기값을 0으로 지정

// 상하좌우
bool visited[501][501];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int map[501][501];
int n, m;
int maxArea = 0;

void BFS(int posy, int posx)
{
    // 시작점을 기준으로 queue에 담는다
    int tmpArea = 0;
    queue<pair<int, int>> q;
    q.push({posy, posx});

    while(!q.empty())
    {
        // queue가 빌때까지 반복해서 탐색 -- 즉, 1을 찾을수없는 탐색이면 종료
        pair<int, int> cur = q.front();
        visited[cur.first][cur.second] = true;
        q.pop();
        tmpArea++;
        for(int i = 0; i < 4; i++)
        {
            int ny = dy[i] + cur.first;
            int nx = dx[i] + cur.second;

            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || !map[ny][nx])
            {
                continue;
            }

            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }
    maxArea = max(maxArea, tmpArea);
}

int main()
{
    fastio;

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    int cnt = 0;

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

    cout << cnt << '\n' << maxArea << '\n';

    return 0;
}