#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <math.h>
using namespace std;

int board[15]; // 보드판
int n;
int cnt = 0;

bool isCheck(int level)
{
    for(int i  = 0; i < level; i++)
    {
        if(board[i] == board[level] || abs(board[level] - board[i]) == abs(level - i) )
            return false;
    }
    return true;
}

// tmp는 현재 행을 의미함
void nQueen(int tmp)
{
    // 현재 탐색하는 행이 끝까지온다면
    if(tmp == n)
    {
        cnt += 1;
        return;
    }

    // 0행부터 시작
    for(int i = 0; i < n; i++)
    {
        board[tmp] = i;
        if(isCheck(tmp))
        {
            nQueen(tmp+1);
        }
    }


}

int main()
{
    fastio;

    cin >> n;

    nQueen(0);

    cout << cnt << '\n';

    return 0;
}