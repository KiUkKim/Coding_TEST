#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n;

vector<long long> ans;

int main()
{
    fastio;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string tmp;

        cin >> tmp;

        reverse(tmp.begin(), tmp.end());

        ans.push_back(stoll(tmp));
    }

    sort(ans.begin(), ans.end());

    for(auto v: ans)
    {
        cout << v << '\n';
    }

    return 0;
}