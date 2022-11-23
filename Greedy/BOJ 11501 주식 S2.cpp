#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int t;

int main()
{
    fastio;

    cin >> t;

    int loop = 0;

    while(loop < t)
    {
        int n ;
        vector<int> arr;
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            arr.push_back(tmp);
        }

        int maxV = -1;
        long long ans = 0;

        for(int i = arr.size() -1; i >= 0; i--)
        {
            if(maxV < arr[i])
                maxV = arr[i];

            else if(maxV > arr[i])
            {
                ans += maxV - arr[i];
            }
        }

        cout << ans << '\n';
        loop++;
    }
    

    return 0;
}