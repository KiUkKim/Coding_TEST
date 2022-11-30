#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <stack>
using namespace std;

stack<char> st;

int main()
{
    fastio;

    bool answer = true;
    string str;

    cin >> str;

    st.push(str[0]);

    for(int i = 1; i < str.length(); i++)
    {
        if(st.empty())
        {
            st.push(str[i]);
            continue;
        }

        if(st.top() == '(' && str[i] == ')')
        {
            st.pop();
        }

        else
        {
            st.push(str[i]);
        }
    }

    if(!st.empty())
    {
        answer = false;
    }

    cout << answer << '\n';

    return 0;
}