#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

int n;
map<string, bool, greater<string>> hashMap;

int main()
{
    fastio;

    cin >> n;

    for(int i = 0; i <= n; i++)
    {
        string str;
        getline(cin, str);

        string key = "";
        string value = "";

        for(int j = 0; j < str.length(); j++)
        {
            if(str[j] == ' ')
            {
                key = str.substr(0, j);

                value = str.substr(j+1, str.length());
                
                break;
            }
        }

        // 찾는 값이 현재 없다면
        if(value == "enter")
        {
            hashMap.insert({key, true});
        }

        else{
            hashMap.erase(key);
        }
    }

    for(auto i : hashMap)
    {
        cout << i.first << '\n';
    }

    return 0;
}