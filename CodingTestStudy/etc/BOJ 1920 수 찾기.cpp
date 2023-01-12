#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<int> A, M;
int n, m;

// 해당 문제의 접근법은 간단하다.
// 단순히 브루트포스 방식으로 탐색할 수 있나?라는 생각이 들것이다.
// 그리고 O(N^2)으로 접근한다면, 100억이 나오므로 시간초과가 발생한다.
// 그렇다면 먼저 생각해야할 부분은 O(logn) 이분 탐색을 활용하는 것이다.
// 그리고 정수가 존재하는지 알아보기때문에 O(nlogn)이 발생할것이고 적절한 알고리즘이라고 생각이 든다.

int main()
{
    fastio;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int num;

        cin >> num;

        A.push_back(num);
    }

    sort(A.begin(), A.end());

    cin >> m;

    for(int i = 0; i < m; i++)
    {
        int num;

        cin >> num;

        M.push_back(num);
    }

    for(int i = 0; i < m; i++)
    {
        int target = M[i];
        int left = 0;
        int right = n - 1;
        int mid;
        int ans = 0;

        while(left <= right)
        {
            mid = (left + right) / 2;

            if(target == A[mid])
            {
                ans = 1;
                break;
            }

            else if(target > A[mid])
            {
                left = mid + 1;
                continue;
            }

            else{
                right = mid - 1;
                continue;
            }
        }

        cout << ans << '\n';
    }


    return 0;
}