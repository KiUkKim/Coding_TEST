#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

char team[5][5];
bool visited[25];
int result = 0;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {-1, 1, 0, 0};

// 처음 생각 정리 -> 각좌표마다 갈 수 있는 경로를 다 따진다. 이렇게 되면 모두 4가지 경우의 수 에 25번이니깐 4^25로 말도안되는 수치가 나오게 된다.
// 따라서 다른 생각. 
// 먼저 백트래킹으로 7명을 고르는 경우의 수
// BFS 나 DFS로 이 7명이 인접하는지 확인한다.
// 이다솜파가 4명이상 존재하는지 확인한다.

// 다솜이파 4명인지 확인
bool isSom()
{
    int sum = 0;
    for(int i = 0; i < 25; i++)
    {
        if(visited[i] && team[i / 5][i % 5] == 'S')
        {
            sum++;
        }
    }
    if(sum >= 4)
        return true;
    
    return false;
}

// 인정한지 확인
bool isConnect()
{
    queue<pair<int, int>> q;

    
}

void DFS(int cnt, int cntS, int cntY, int y, int x)
{
    if(cntY >= 4)
        return;
    
    if(cnt == 7)
    {
        result++;
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
            continue;
        
        if(team[ny][nx] == "S")
        {
            DFS(cnt+1, cntS + 1, cntY, ny, nx);
        }

        else if(team[ny][nx] == "Y")
        {
            DFS(cnt+1, cntS, cntY + 1, ny, nx);
        }
    }
}

int main()
{
    fastio;

    for(int i = 0; i < 5; i++)
    {
        string a;
        cin >> a;
        for(int j = 0; j < 5; j++)
        {
            team[i][j] = a[j];
        }
    }

    // for(int i = 0; i < 5; i++)
    // {
    //     for(int j = 0; j < 5; j++)
    //     {
    //         cout << team[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }



    DFS(0, 0, 0, 0, 0);

    cout << result << '\n';

    return 0;
}