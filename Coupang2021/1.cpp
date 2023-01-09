#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, k, t;

bool visited[100001];
vector<int> ans, tmp, arr;
int cnt = 0;

int dfs(vector<int> arr, int count)
{
    int ans = 1;
    if(ans > t)
    {
        tmp.clear();
        return 0;
    }

    if(ans <= t && tmp.size() >= k)
    {
        cnt++;
        return cnt;
    }

    else if(tmp.size() >= k && ans <= t)
    {
        for(int i = 0; i < arr.size(); i++)
            {
                if(!visited[i])
                {
                    visited[i] = true;
                    ans += dfs(arr[i], );
                    visited[i] = false;
                }
            }
    }

    return ans;

}

int main()
{
    fastio;
    
    cin >> n >> k >> t;

    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    int cnt = 0;

    cnt += dfs(0);

    cout << cnt << '\n';

}