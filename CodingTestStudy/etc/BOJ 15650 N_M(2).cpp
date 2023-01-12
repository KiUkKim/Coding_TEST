#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, m;
bool visited[9];
vector<int> ans;

void backtracking(int cnt, int idx)
{
    if(cnt == m)
    {
        for(auto v : ans)
        {
            cout << v << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = idx; i < n; i++)
    {
        if(visited[i])
            continue;
        
        ans.push_back(i + 1);
        visited[i] = true;
        backtracking(cnt+1, i);
        ans.pop_back();
        visited[i] = false;
    }
}

int main()
{
    fastio;

    cin >> n >> m;

    backtracking(0, 0);

    return 0;
}