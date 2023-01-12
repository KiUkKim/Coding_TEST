#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace std;

// 해당 문제는 미로찾기와 다르게 DFS, BFS 구현이 가능하다.
// 이유는 앞의 문제에서는 목표지점까지가야 return을 하기 때문에 갈 수 있는 경로를 다 체크해야만한다.
// 해당 문제는 목표지점과 다르게 더 이상 갈 수 없는 지점에 도달하게 되면 탐색을 끝낼 수 있다.

// 해당 아이디어는 정상인 사람 기준 BFS, 적록색약 사람 기준 BFS 돌리기
// 그렇게되면 O(n * m * 2) 정도 소요될 것으로 예상되어진다.

// BFS 두개 만들필요없이 -> 기본 테이블을 받아와서 빨강 초록을 하나로 합쳐준다.

int dy[4] = {-1, 1, 0 , 0};
int dx[4] = {0, 0, -1, 1};
int visited[101][101];
char map[101][101];
char RGB_map[101][101];
int n;

// 해당 bfs 함수에서 같은 색깔인지 판단하기 위해서 color로 받아왔고
// 해당 arr를 따지기 위해서 parameter로 배열을 받아왔다
void stPerson(int y, int x, char Color, char arr[101][101])
{
    queue<pair<int, int>> q;

    q.push({y, x});

    while(!q.empty())
    {
        pair<int, int> cur = q.front();

        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = dy[i] + cur.first;
            int nx = dx[i] + cur.second;

            if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] || arr[ny][nx] != Color)
            {
                continue;
            }
            
            q.push({ny, nx});
            visited[ny][nx] = true;
        }
    }
}

void init()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }
}

int main()
{
    fastio;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;

        for(int j = 0; j < n; j++)
        {
            map[i][j] = tmp[j];

            if(tmp[j] == 'G')
                RGB_map[i][j] = 'R';
            else{
                RGB_map[i][j] = tmp[j];
            }
        }
    }
    
    int st_cnt = 0;

    // 먼저 정상인을 판단해준다.
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j])
            {
                stPerson(i, j, map[i][j], map);
                st_cnt++;
            }
        }
    }

    init(); // 방문처리 초기화

    int rgb_cnt = 0;

    // 다음 적록색약인 사람을 판단해준다.
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j])
            {
                stPerson(i, j, RGB_map[i][j], RGB_map);
                rgb_cnt++;
            }
        }
    }

    cout << st_cnt << ' ' << rgb_cnt << '\n';

    return 0;
}