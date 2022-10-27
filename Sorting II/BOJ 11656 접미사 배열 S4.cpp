#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

string s;
vector<string> vc;

int main()
{
    fastio;

    cin >> s;

    for(int i = 0; i < s.length(); i++)
    {
        string tmp = "";
        for(int j = i; j < s.length(); j++)
        {
            tmp += s[j];
        }
        vc.push_back(tmp);
    }

    sort(vc.begin(), vc.end());

    for(auto i : vc)
    {
        cout << i << '\n';
    }

    return 0;
}