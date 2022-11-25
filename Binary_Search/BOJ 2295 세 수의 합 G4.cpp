#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n;
vector<int> arr, sum;

int main()
{
    fastio;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            sum.push_back(arr[i] + arr[j]);
        }
    }

    sort(sum.begin(), sum.end());

    for(auto i : sum)
    {
        cout << i << ' ';
    }

    int result = -987654321;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(binary_search(sum.begin(), sum.end(), arr[j] - arr[i])){
                result = max(result, arr[j]);
            }
        }
    }

    cout << result << '\n';


    return 0;
}