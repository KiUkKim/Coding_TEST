#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, now;
bool checked[10];
string str;
vector<string> ans;

bool compare(string s1, string s2)
{
    if(s1.length() == s2.length())
    {
        for(int i = 0; i < s1.size(); i++)
        {
            if(s1[i] == s2[i])
                continue;
            
            return s1[i] < s2[i];
        }       
    }
    return (s1.length() < s2.length());
}

void Solved(bool visited[10], int num)
{
    string aa = "";
    // 앞자리에 0이 들어가는 것을 방지하기 위해 9부터 시작
    for(int i = 9; i >= 0; i--)
    {
        if(visited[i])
        {
            aa += ('0' + i);
        }

    }
    ans.push_back(aa);

    for(int i = num; i < 10; i++)
    {
        if(visited[i] == false)
        {
            visited[i] = true;
            Solved(visited , num + 1);
            visited[i] = false;
        }
    }

    return;
}

int main()
{
    fastio;

    cin >> n;

    if(n > 1022)
        cout << -1 << '\n';


    else{
        Solved(checked, 0);

        sort(ans.begin(), ans.end());

        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        sort(ans.begin(), ans.end(), compare);

        cout << ans[n+1] << '\n';
    }


    return 0;
}