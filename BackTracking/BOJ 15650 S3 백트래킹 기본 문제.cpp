#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, m;
int num[8] = {1, 2, 3, 4, 5, 6, 7, 8};
bool visited[8];
vector <int> arr;

void DFS(int cnt)
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

    for(int i = 0; i < n; i++)
    {
        if(visited[i])
            continue;
        visited[i] = true;
        
        if(arr.empty())
        {
            arr.push_back(num[i]);
        }

        else if(arr[cnt-1] < num[i])
        {
            arr.push_back(num[i]);
        }

        else if(arr[cnt-1] > num[i])
        {
            visited[i] = false;
            continue;
        }
        DFS(cnt+1);
        arr.pop_back();    
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