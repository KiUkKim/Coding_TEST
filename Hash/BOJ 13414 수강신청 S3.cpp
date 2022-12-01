#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <limits.h>
using namespace std;

int k, l;
int cnt = 0;

bool compare(pair<string ,int> a, pair<string, int> b)
{
    return a.second < b.second;
}

unordered_map<string, int> hashMap;

int main()
{
    fastio;

    cin >> k >> l;

    for(int i = 0; i < l; i++)
    {
        string str;

        cin >> str;

        if(hashMap.find(str) == hashMap.end())
        {
            hashMap.insert({str, i});
        }

        else{
            hashMap[str] = i;
        }
    }

    vector<pair<string, int>> v(hashMap.begin(), hashMap.end());

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < k; i++)
    {
        if(i==v.size())
        {
            break;
        }
        cout << v[i].first << '\n';
    }

    return 0;
}