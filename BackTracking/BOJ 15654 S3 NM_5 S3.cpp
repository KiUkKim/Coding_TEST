#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, m;
vector<int> arr;
vector<int> result;
bool visited[8];
int idx = 0;

bool compare(int a, int b)
{
    return a < b;
}

void Solved(int cnt)
{
    if(cnt == m)
    {
        for(int i = 0; i < result.size(); i++)
        {
            cout << result[i] << ' ';
        }
        cout << '\n';
        
        return;
    }

    for(int i = 0; i < arr.size(); i++)
    {
        if(visited[i])
            continue;
        
        visited[i] = true;
        result.push_back(arr[i]);
        Solved(cnt+1);
        result.pop_back();
        visited[i] = false;
    }
}

int main()
{
    fastio;

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end(), compare);

    Solved(0);

    return 0;
}