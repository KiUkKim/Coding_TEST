#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <string>
using namespace std;

vector<pair<int, int>> ans;

string BinaryNum(int num)
{
    string bn = "";

    while(num > 0)
    {
        if(num%2 == 1)
        {
            bn = "1" + bn;
        }
        else{
            bn = "0" + bn;
        }
        num >>= 1;
    }

    return bn;
}

int main()
{
    fastio;

    string str;

    cin >> str;

    int zeroCnt = 0;
    int rot = 0;
    string tmp = "";

    while(true)
    {
        if(str.length() == 1)
        {
            rot++;
            break;
        }

        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] != '0')
            {
                tmp += str[i];
            }
            else{
                zeroCnt++;
            }
        }

        int length = tmp.length();

        str = BinaryNum(length);

        if(tmp != str)
        {
            rot++;
        }

        tmp = "";

    }

    ans.push_back({rot, zeroCnt});

    cout << ans[0].first << ' ' << ans[0].second << '\n';

    return 0;
}