#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n;
vector<long long> tmp, ans;

int main()
{
    fastio;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        tmp.push_back(num);
    }

    ans = tmp;

    sort(tmp.begin(), tmp.end());

    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

    int arr_size = tmp.size() - 1;

    for(int i = 0; i < n; i++)
    {
        int left = 0;
        int right = arr_size;
        int mid = (left + right )/2;

        while(true)
        {
            mid = (left + right ) / 2;

            if(tmp[mid] > ans[i])
            {
                right = mid - 1;
            }
            else if(tmp[mid] < ans[i])
            {
                left = mid + 1;
            }
            else{
                break;
            }
        }
        cout << mid << ' ';
    }


    return 0;
}