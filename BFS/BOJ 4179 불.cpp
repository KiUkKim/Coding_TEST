#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, m;
char map[1002][1002];

queue<pair<int, int>> Jihun;
queue<pair<int, int>> Fire;

int visitedF[1002][1002];

int visitedJ[1002][1002];

int dy[4] = {-1, 1, 0, 0};
int cnt = 0;
int dx[4] = {0, 0, -1, 1};

// 아이디어는 BFS를 두게 사용한다는 점이다.
// 지훈이를 먼저 옮기고, 그리고 불을 사용할것이다.

// 삽질 많이 한 문제이다.
// for문으로 계속해서 체크를 하다보니 불이 이동하지 못하는 경우가 있었다.
// 이 문제는 먼저 F나 J으로 관리할 필요가 없다.
// 처음에 입력을 받을 떄 큐에 불과 지훈이의 위치를 저장해두고 시작해주는 것이 깔끔한 코드이다.

void FireBFS()
{
    while(!Fire.empty())
    {
        pair<int, int> cur = Fire.front();

        if(!visitedF[cur.first][cur.second])
        {
            visitedF[cur.first][cur.second] = true;
        }

        Fire.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            // 벽을 만났으면 다음 노드를 탐색
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == '#')
                continue;
            
            // 벽을 만나지 않고, 해당 위치가 0이 아닐 경우(0은 불이 아직 퍼지지 않은 것을 나타낸다.)
            if(!visitedF[ny][nx])
            {
                Fire.push({ny, nx});
                visitedF[ny][nx] = visitedF[cur.first][cur.second] + 1; // 이동하는 곳의 1단계를 증가시켜준다.
            }
        }

    }

}

// 지훈이가 이동하는 구간이다.
void JihunBFS()
{
    // 초기 값 true로 변환 (하지 않으면 돌아가지 않는다.)
    visitedJ[Jihun.front().first][Jihun.front().second] = true;

    while(!Jihun.empty())
    {
        pair<int, int> cur = Jihun.front();

        Jihun.pop();

        if(cur.first == 0 || cur.second == 0 || cur.first == n - 1 || cur.second == m - 1)
        {
            cout << visitedJ[cur.first][cur.second] << '\n';
            return;
        }

        for(int i = 0; i < 4; i++)
        {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];

            // 이 구간에 지훈이가 온다면 탈출을 할 수 있다는 의미이다.
            if(ny < 0 || nx < 0 || ny >= n || nx >= m)
            {
                continue;
            }

            // 이동할 수 있는 구간이라고 가정 (불은 여기서 생각 x)
            if(map[ny][nx] == '.' && !visitedJ[ny][nx])
            {
                // 해당 부분에서 불의 단계를 따져서 계산한다
                // J이가 이동한 곳의 + 1단계 (즉 이미 진행되었는 걸 의미한다.)에서 불이 번지지않았다면 지나갈 수 있음을 의미한다.
                // 주의 해야 할 점은 불이 하나도 없는 경우도 존재한다는 것을 기억해줘야한다.
                if(visitedF[ny][nx] > visitedJ[cur.first][cur.second] + 1 || visitedF[ny][nx] == 0)
                {
                    Jihun.push({ny, nx});
                    visitedJ[ny][nx] = visitedJ[cur.first][cur.second] + 1;
                }
            }
        }
    }
    // 탈출을 여기서 했다는 것은 지훈이가 이동할 수 없음을 의미한다.
    cout << "IMPOSSIBLE" << '\n';
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

            // 지훈이라면 큐에 넣어둔다.
            if(map[i][j] == 'J')
                Jihun.push({i, j});
            
            else if(map[i][j] == 'F')
                Fire.push({i, j});
        }
    }

    FireBFS();

    JihunBFS();

    return 0;
}