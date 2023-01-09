#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <limits.h>
using namespace std;

vector<string> ans;

int maxN = -987654321;
int minN = 987654321;

int main()
{
    fastio;

    string str;
    
    getline(cin, str);

    string tmp = "";

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] >= '0' && str[i] <= '9' || str[i] == '-')
        {
            tmp += str[i];
        }

        else if(str[i] == ' ')
        {
            ans.push_back(tmp);
            tmp = "";
        }

        if(i == str.length() - 1)
        {
            ans.push_back(tmp);
        }
    }

    for(int i = 0; i <ans.size(); i++)
    {
        minN = min(minN, stoi(ans[i]));
        maxN = max(maxN, stoi(ans[i]));
    }

    string answer = "";

    answer += to_string(minN) + " " + to_string(maxN);

    cout << answer << '\n';
    return 0;
}