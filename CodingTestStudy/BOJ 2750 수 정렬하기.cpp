#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int t;

vector<int> ans;

int main()
{
    fastio;

    cin >> t;

    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        ans.push_back(n);
    }

    sort(ans.begin(), ans.end());

    for(auto v : ans)
    {
        cout << v << '\n';
    }

    return 0;
}