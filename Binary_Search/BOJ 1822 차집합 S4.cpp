#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int a_n, b_n;
vector<int> a, b, ans;

int main()
{
    fastio;

    cin >> a_n >> b_n;

    for(int i = 0; i < a_n; i++)
    {
        int tmp;
        cin >> tmp;

        a.push_back(tmp);
    }

    for(int i = 0; i < b_n; i++)
    {
        int tmp;
        cin >> tmp;

        b.push_back(tmp);
    }

    sort(a.begin(), a.end());

    sort(b.begin(), b.end());

    int cnt = 0;

    int left = 0;
    int right = b.size();

    int mid = (left + right) / 2;

    
    for(int i = 0; i < a.size(); i++)
    {
        int left = 0;
        int right = b.size() - 1;
        int mid = (left + right ) / 2;

        while(true)
        {
            mid = (left + right) / 2;

            if(left > right)
            {
                ans.push_back(a[i]);
                break;
            }

            if(a[i] < b[mid])
            {
                right = mid - 1;
            }
            else if(a[i] > b[mid])
            {
                left = mid + 1;
            }
            else{
                break;
            }
        }
    }

    cout << ans.size() << '\n';

    for(auto i : ans)
    {
        cout << i << ' ';
    }

    return 0;
}