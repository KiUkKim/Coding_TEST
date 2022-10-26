#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <string>
using namespace std;

int n;
vector<string> vc;
vector<long long> vc1;

int main()
{
    fastio;

    cin >> n;

    for(int i = 0; i < n ; i++)
    {
        string tmp;
        cin >> tmp;

        reverse(tmp.begin(), tmp.end());

        vc.push_back(tmp);
    }

    for(int i = 0; i < n; i++)
    {
        vc1.push_back(stoull(vc[i]));
    }

    sort(vc1.begin(), vc1.end());

    for(auto i : vc1)
    {
        cout << i << '\n';
    }

    return 0;
}