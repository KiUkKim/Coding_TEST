#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, m;

int map[9] = {1, 2, 3, 4, 5, 6, 7, 8};
bool visited[8];
vector <int> result;
int cnt;


void print_()
{
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ' ';
    }
    cout << '\n';
}

void DFS(int cnt)
{
    if(cnt == m)
    {
        print_();
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(visited[i])
            continue;
        visited[i] = true;
        result.push_back(map[i]);
        DFS(cnt+1);
        result.pop_back();
        visited[i] = false;
    }
}

int main()
{
    fastio;

    cin >> n >> m;

    DFS(0);

    return 0;
}