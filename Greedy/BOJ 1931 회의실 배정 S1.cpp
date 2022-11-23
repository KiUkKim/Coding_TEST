#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <utility>
using namespace std;

int n;
vector<pair<int, int>> rooms;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second)
        return a.first < b.first;

    return a.second < b.second;
}

int main()
{
    fastio;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int start, end;

        cin >> start >> end;

        rooms.push_back({start, end});
    }

    sort(rooms.begin(), rooms.end(), compare);
    
    int endtime = rooms[0].second;

    int cnt = 1;

    for(int i = 1; i < rooms.size(); i++)
    {
        if(endtime <= rooms[i].first)
        {
            endtime = rooms[i].second;
            cnt++;
        }
    }

    cout << cnt << '\n';


    return 0;
}