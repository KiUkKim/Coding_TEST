#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<int> num;
int n;

int main()
{
    fastio;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        num.push_back(tmp);
    }

    sort(num.begin(), num.end());

    for(auto i : num)
    {
        cout << i << '\n';
    }

    return 0;
}