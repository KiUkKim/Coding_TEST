#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <unordered_set>
using namespace std;

unordered_set<string> people;

int n;

int main()
{
    fastio;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string name,cmd;

        cin >> name >> cmd;

        if(cmd == "enter")
        {
            people.insert(name);
        }

        else if(cmd == "leave" && people.count(name) != 0)
        {
            people.erase(name);
        }
    }

    vector<string> ans(people.begin(), people.end());

    sort(ans.begin(), ans.end(), greater<string>());

    for(auto i : ans)
    {
        cout << i << '\n';
    }

    return 0;
}