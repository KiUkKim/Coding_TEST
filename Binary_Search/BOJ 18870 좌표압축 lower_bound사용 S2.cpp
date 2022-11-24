#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n;

vector<long long> tmp, ans;

int main()
{
    fastio;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        tmp.push_back(num);
    }

    ans = tmp;

    sort(tmp.begin(), tmp.end());

    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

    for(int i = 0; i < n; i++)
    {
        cout << lower_bound(tmp.begin(), tmp.end(), ans[i]) - tmp.begin() << ' ';
    }

    return 0;
}