#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n;

int prime[4000001];
vector<int> decimal;

int main()
{
    fastio;

    cin >> n;

    if(n == 1)
    {
        cout << 0 << '\n';
        return 0;
    }

    if(n == 2)
    {
        cout << 1 << '\n';
        return 0;
    }

    // 에라토스테네스의 체로 소수 판별
    for(int i = 2; i <= n; i++)
    {
        prime[i] = true;
    }

    for(int i = 2; i * i <= n; i++)
    {
        if(prime[i])
        {
            for(int k = i * i; k <= n; k += i)
            {
                prime[k] = false;
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(prime[i])
            decimal.push_back(i);
    }

    int left = 0;
    int right = 1;

    int sum = decimal[left] + decimal[right];
    
    int ans = 0;

    while(left <= right && right < decimal.size())
    {
        // sum과 같은 경우 증가
        if(sum == n)
        {
            ans++;

            right++;

            if(right == decimal.size())
                break;

            sum += decimal[right];
        }

        // n보다 작을 경우 늘려줌
        if(sum < n)
        {
            right++;

            if(right == decimal.size())
                break;
            
            sum += decimal[right];
        }

        // n보다 클 경우 빼줘야함
        else
        {
            if(left == right)
            {
                right++;

                if(right == decimal.size())
                    break;

                sum += decimal[right];
            }

            else{
                sum -= decimal[left++];
            }

        }
    }

    cout << ans << '\n';


    return 0;
}

