#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, m;
vector<int> ans, num;
bool visited[8];

void Solved(int cnt, int idx)
{
    if(cnt == m)
    {
        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int tmp = 0;
    for(int i = idx; i < num.size(); i++)
    {
        if(tmp != num[i] && !visited[i])
        {
            visited[i] = true;
            ans.push_back(num[i]);
            Solved(cnt+1, i + 1);
            tmp = ans.back();
            ans.pop_back();
            visited[i] = false;
        }
    }


}


int main()
{
    fastio;

    cin >> n >> m;

    for(int i = 0; i < n ; i++)
    {
        int tmp;
        cin >> tmp;
        num.push_back(tmp);
    }    

    sort(num.begin(), num.end());

    Solved(0, 0);

    return 0;
}