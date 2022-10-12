#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#define maxY 1001
#define maxX 1001
using namespace std;

int board[maxY][maxX];
bool visited[maxY][maxX][2];
int n, m;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {-1, 1, 0, 0};

int BFS(int startY, int startX, int wallCnt, int Cnt)
{
    // first pair에는 해당 y좌표와 x좌표가 담겨있다.
    // second pair에는 벽을 부순 횟수와 결과가 담겨있다.
    queue<pair<pair<int,int>, pair<int, int>>> q;
    q.push({{startY, startX}, {wallCnt, Cnt}});
    
    while(!q.empty())
    {
        pair<int , int> cur = q.front().first;
        pair<int, int> curI = q.front().second;

        int curY = cur.first;
        int curX = cur.second;

        int wallCnt = curI.first;
        int cnt = curI.second;

        q.pop();

        if(curY == n-1 && curX == m-1)
        {
            return cnt;
        }

        for(int i = 0; i < 4; i++)
        {
            int ny = curY + dy[i];
            int nx = curX + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            
            if(wallCnt == 0 && board[ny][nx])
            {
                visited[ny][nx][wallCnt]= 1;
                q.push({{ny, nx}, {wallCnt + 1, cnt+1}});
            }

            if(board[ny][nx] == 0 && visited[ny][nx][wallCnt] == false)
            {
                visited[ny][nx][wallCnt] = true;
                q.push({{ny, nx}, {wallCnt, cnt+1}});
            }
        }
    }
    return -1;
    
}

int main()
{
    fastio;

    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
    {
        string wall;
        cin >> wall;
        for(int j = 0; j < m; j++)
        {
            board[i][j] = wall[j] - '0';
        }
    }

    int result = BFS(0, 0, 0, 1);

    cout << result << '\n';


    return 0;
}