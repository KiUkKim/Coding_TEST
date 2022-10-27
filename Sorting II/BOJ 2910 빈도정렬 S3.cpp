#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <unordered_map>
using namespace std;

int N, C;

unordered_map <int, int> num;
unordered_map <int, int> order;

bool compare(pair<int, int> p, pair<int, int> q)
{
    if(p.second == q.second)
    {
        return order[p.first] < order[q.first];
    }
    else
    {
        return p.second > q.second;
    }
}

int main()
{
    fastio;

    cin >> N >> C;

    for(int i = 0; i < N; i++)
    {
        int tmp;

        cin >> tmp;

        if(num.count(tmp) != 0 )
        {
            num[tmp] += 1;
        }

        else{
            num.insert({tmp, 1});
        }

        if(order.count(tmp) == 0)
        {
            order.insert({tmp, i+1});
        }
    }

    vector<pair<int, int>> numV(num.begin(), num.end());

    sort(numV.begin(), numV.end(), compare);

    for(int i = 0; i < numV.size(); i++)
    {
        for(int j = 0; j < numV[i].second; j++)
        {
            cout << numV[i].first << ' ';
        }
    }

    return 0;
}