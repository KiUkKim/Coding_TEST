#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n,m;
vector<int> card, check;

// 수 찾기 문제와 같은 형식이다.

int main()
{
    fastio;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        card.push_back(num);
    }
    
    sort(card.begin(), card.end());

    cin >> m;

    for(int i = 0; i < m; i++)
    {
        int num;
        cin >> num;

        check.push_back(num);
    }

    for(int i = 0; i < m; i++)
    {
        int left = 0;
        int right = n - 1;
        int target = check[i];
        int ans = 0;
        int mid;

        while(left <= right)
        {
            mid = (left + right) / 2;

            if(target == card[mid])
            {
                ans = 1;
                break;   
            }

            else if(target > card[mid])
            {
                left = mid+1;
            }

            else{
                right = mid - 1;
            }
        }

        cout << ans << ' ';
    }



    return 0;
}