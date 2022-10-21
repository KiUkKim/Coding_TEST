#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, m;
vector<int> num;
vector<int> result;
bool visited[8];

bool compare(int a, int b)
{
    return a < b;
}

void Solved(int cnt, int idx)
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

    for(int i = idx; i < num.size(); i++)
    {
        if(visited[i])
            continue;

        visited[i] = true;
        result.push_back(num[i]);
        Solved(cnt+1, i+1);
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
        num.push_back(tmp);
    }

    sort(num.begin(), num.end(), compare);

    Solved(0, 0);

    return 0;
}