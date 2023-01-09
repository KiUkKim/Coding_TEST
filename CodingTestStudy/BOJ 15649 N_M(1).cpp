#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, m;
vector<int> ans;
bool visited[9];

void backtracking(int cnt)
{
    if(cnt == m)
    {
        for(auto v: ans)
        {
            cout << v << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(visited[i])
            continue;

        visited[i] = true;
        ans.push_back(i+1);
        backtracking(cnt+1);
        ans.pop_back();
        visited[i] = false;
    }
}

int main()
{
    fastio;

    cin >> n >> m;

    backtracking(0);

    return 0;
}