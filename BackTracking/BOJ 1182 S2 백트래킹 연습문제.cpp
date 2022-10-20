#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n, s, cnt;
bool visited[20];
vector <int> arr;

void BackTracking(int k,int tmp)
{
    if(k==n)
    {
        if(tmp == s)
        {
            cnt++;
        }
        return;
    }

    // 원소를 추가하는 경우
    BackTracking(k+1, tmp + arr[k]);
    
    // 원소를 추가하지 않는 경우
    BackTracking(k+1, tmp);
}

int main()
{
    fastio;

    cin >> n >> s;
    
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    BackTracking(0, 0);

    if(s == 0)
    {
        cnt--;
    }

    cout << cnt << '\n';


    return 0;
}