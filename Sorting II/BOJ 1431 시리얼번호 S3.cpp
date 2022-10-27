#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <string>
using namespace std;

vector<string> ans;
int n;

bool compare(string s1, string s2)
{
    if(s1.length() != s2.length())
        return s1.length() < s2.length();
    
    else{
        int tmp = 0;
        int tmp2 = 0;
        for(int i = 0; i < s1.length(); i++)
        {
            if(s1[i] >= '0' && s1[i] <= '9')
            {
                tmp += s1[i] - '0';
            }

            if(s2[i] >= '0' && s2[i] <= '9')
            {
                tmp2 += s2[i] - '0';
            }
        }

        if(tmp != tmp2)
        {
            return tmp < tmp2;
        }

        else if(tmp == tmp2)
        {
            for(int i = 0; i < s1.length(); i++)
            {
                if(s1[i] == s2[i])
                    continue;
                return s1[i] < s2[i];
            }
        }
    }
}

int main()
{
    fastio;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        ans.push_back(tmp);
    }
    
    sort(ans.begin(), ans.end(), compare);

    for(auto i : ans)
    {
        cout << i << '\n';
    }

    return 0;
}