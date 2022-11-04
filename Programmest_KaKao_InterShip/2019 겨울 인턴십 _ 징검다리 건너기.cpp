#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int k, result, idx;
vector<int> stones;
bool check = true;

int main()
{
    fastio;

    cin >> k;

    for(int i = 0; i < 10; i++)
    {
        int tmp;
        cin >> tmp;
        stones.push_back(tmp);
    }

    while(check)
    {
        for(int i = 0; i < stones.size(); i++)
        {   
            if(idx == k)
            {
                check = false;
                break;
            }
            
            if(stones[i] == 0)
            {
                idx ++;
                continue;
            }
            
            else if(stones[i] != 0)
            {
                stones[i] --;
                idx = 0;
            }
            
        }
        
        if(check)
        {
            result++;
        }
    }

    for(auto i : stones)
    {
        cout << i << ' ';
    }

    cout << result << '\n';

    return 0;
}