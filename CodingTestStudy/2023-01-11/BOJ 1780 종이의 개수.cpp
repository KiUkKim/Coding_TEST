#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

// 해당 문제는 먼저 그래프 탐색으로 접근할 수 있다.
// 단순하게 DFS, BFS 이용해서 구현할 수 있다고 가정한다.
// 방문조건에서 해당 그래프의 크기를 n/3으로 쪼개서 탐색을 시작한다.
// 이런식으로 접근하게 된다면, 해당 문제는 O(n * m * log3N)으로 추정된다.

// 가장 좋은 방법은 DFS || BFS & backtracking을 활용하는 방법이다.
// 단순하게 재귀로 해당 구간을 따져주면 되기때문이다.
// 해당 문제에서는 backtracking에서 효율적인 DFS를 사용해서 구현하는 것이 적합하다고 생각한다.

// DFS, BFS를 진행할 때 문제점은 해당 문제에서 종이를 9로 나누어준 것을 반복해주어야하는데 이렇게 될 경우 BFS, DF에 대한 처리를 해줘야한다.
// 따라서 재귀를 통해서 해당 범위를 체크하는것이 적합하다고 생각하였다.

int n;

int ans[3];

int map[2188][2188];
bool visited[2188][2188];

// 해당 맵을 추적해서 cnt == size와 같으면 반환시킨다.
void DFS(int y, int x, int m[2188][2188], int cnt)
{
    if(cnt == n)
    {
        if(m[y][x] == -1)
        {
            ans[0]++;
        }

        else if(m[y][x] == 0)
        {
            ans[1]++;
        }

        else{
            ans[2]++;
        }
        return;
    }

    for(int i = 0; i < n; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= n || nx < 0 || nx >= n)
            continue;
        
        visited[ny][nx] = true;
        DFS(ny, nx, m, cnt+1);
        visited[ny][nx] = false;
    }
}


int main()
{
    fastio;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> mpa[i][j];
        }
    }



    return 0;
}