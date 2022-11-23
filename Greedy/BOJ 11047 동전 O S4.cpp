#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, money;

vector<int> haveMoney;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    fastio;

    cin >> n >> money;

    int cnt = 0;

    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        haveMoney.push_back(tmp);
    }

    sort(haveMoney.begin(), haveMoney.end(), compare);

    for(int i = 0; i < haveMoney.size(); i++)
    {
        if(haveMoney[i] <= money)
        {
            int tmp = haveMoney[i];
            int count = money / tmp;
            
            money -= tmp * count;

            cnt += count;
        }

        if(money == 0)
            break;
    }

    cout << cnt << '\n';

    return 0;
}