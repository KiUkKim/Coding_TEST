#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <math.h>
using namespace std;

int n;
int ans;
vector<int> rope;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    fastio;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        rope.push_back(tmp);
    }

    sort(rope.begin(), rope.end(), compare);

    int ans = 1;

    for(int i = 0; i < n; i++)
    {
        ans = max(ans, rope[i] * (i + 1));
    }

    cout << ans << '\n';


    return 0;
}   