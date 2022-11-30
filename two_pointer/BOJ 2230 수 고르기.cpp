#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n;
long long m;
long long minN = 2000000001;
vector<long long> vc;

int main()
{
    fastio;

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        vc.push_back(tmp);
    }
    sort(vc.begin(), vc.end());

    int left = 0;
    int right = 0;

    long long diff_now = 0;

    while(left <= right  && right < n)
    {
        if(diff_now >= m)
        {
            minN = min(minN, diff_now);

            if(left==right)
            {
                right++;

                if(right == n)
                    break;
                
                diff_now = vc[right] - vc[left];
            }

            else{
                left ++;

                diff_now = vc[right] - vc[left];
            }
        }

        else{
            right++;
            if(right == n)
                break;
            diff_now = vc[right] - vc[left];
        }
    }

    cout << minN << '\n';

    return 0;
}