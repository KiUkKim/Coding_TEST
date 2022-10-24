#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <unordered_map>
using namespace std;

int n;
long long maxN = 0;
long long maxIdx = 0;

bool compare(pair<long long, int> a, pair<long long, int> b)
{
    return a.first < b.first;
}


int main()
{
    fastio;

    cin >> n;

    unordered_map<long long, int> card;

    for(int i = 0; i < n; i++)
    {
        long long tmp;
        cin >> tmp;

        if(card.count(tmp) != 0)
        {
            card[tmp] += 1;
        }

        else{
            card.insert({tmp, 1});
        }
    }

    vector <pair<long long, int>> cardV(card.begin(), card.end());

    sort(cardV.begin(), cardV.end(), compare);

    for(auto i : cardV)
    {
        if(i.second > maxN)
        {
            maxN = i.second;
            maxIdx = i.first;
        }
    }

    cout << maxIdx << '\n';

    return 0;
}