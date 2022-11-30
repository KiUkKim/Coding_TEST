#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <limits.h>
using namespace std;

int main()
{
    fastio;

    string str;

    getline(cin, str);

    if(str[0] >= 'a' && str[0] <= 'z')
    {
        str[0] -= 32;
    }

    for(int i = 1; i < str.length(); i++)
    {      
        if(str[i] == ' ')
        {
            if(str[i+1] >= 'a' && str[i+1] <= 'z')
            {
                str[i+1] -= 32;
                i+=1;
                continue;
            }

            else{
                i+=1;
                continue;
            }
        }

        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }

    cout << str << '\n';

    return 0;
}