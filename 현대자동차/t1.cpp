#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;


int main()
{
    fastio;

    string input;

    cin >> input;

    string key;
    cin >> key;


    int idx = 0;
    int left = 0;
    int right = 0;    
    int point = 0;
    
    while(idx < key.length())
    {
        for(int i = 0; i < input.length(); i++)
        {
            if(key[idx] == input[i] && i > point)
            {
                if(input.length() - i + 1  > abs(i - point))
                {
                    right += abs(i-point);
                }
                else
                {
                    left += input.length() - i + 1;
                }

                point = i;
            }

            else if(key[idx] == input[i] && i < point)
            {
                if(input.length() - i + 1 > abs(i - point))
                {
                    left += abs(i-point);
                }

                else
                {
                    right += input.length() - i + 1;
                }

                point = i;
            }
        }
        idx++;
    }

    cout << left + right + key.length() << ' '<< left << ' ' << right << '\n';

    return 0;
}