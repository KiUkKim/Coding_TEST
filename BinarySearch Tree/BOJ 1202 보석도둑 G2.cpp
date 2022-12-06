#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <math.h>
using namespace std;

int n, k;

vector<pair<int, int>> jwInfo;

vector<int> bag;

priority_queue<int> pq;

int main()
{
    fastio;

    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        int m, v;

        cin >> m >> v;

        jwInfo.push_back({m, v});
    }

    sort(jwInfo.begin(), jwInfo.end());

    for(int i = 0; i < k; i++)
    {
        int c;

        cin >> c;

        bag.push_back(c);
    }

    sort(bag.begin(), bag.end());

    long long ans = 0;
    int idx = 0;

    for(int i = 0; i < k; i++)
    {
        while(idx < n && jwInfo[idx].first <= bag[i])
            pq.push(jwInfo[idx++].second);

        if(!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << '\n';

    return 0;
}