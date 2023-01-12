#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, total;
vector<int> money;

int main()
{
    fastio;

    cin >> n >> total;

    for(int i = 0; i < n; i++)
    {
        int num;

        cin >> num;

        money.push_back(num);
    }

    sort(money.begin(), money.end(), greater<int>());

    int cnt = 0;

    for(int i = 0; i < n; i++)
    {
        if(money[i] > total)
            continue;
        
        int tmp_cnt = (total / money[i]);

        total -= money[i] * tmp_cnt;
        cnt += tmp_cnt;
    }

    cout << cnt << '\n';

    return 0;
}