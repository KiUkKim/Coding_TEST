#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<int> arr;
bool visited[8];
int n, m;

void BackTracking(int cnt, int idx)
{
    if(cnt == m)
    {
        for(int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = idx; i < n; i++)
    {
        if(visited[i])
            continue;

        visited[i] = true;
        arr.push_back(i + 1);
        BackTracking(cnt+1, i+1);
        arr.pop_back();
        visited[i] = false;
    }
}


int main()
{
    fastio;

    cin >> n >> m;

    BackTracking(0, 0);

    return 0;
}