#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n;
int sum;
vector<int> atm;

// 다음 문제는 최소의 합을 구하는 문제이다.
// 명제를 시간이 가장 적게드는 사람부터 처리하게 한다입니다.
// 귀류법으로 증명해본다면, 시간이 가장 많이드는 사람부터 처리한다입니다.
// 이를 예시의 P1 = 3, P2 = 1, P3 = 4 , P4 = 3, P5 = 2로 생각합니다.
// 그렇다면 4 + (4 + 3) + (4 + 3 + 3) + (4 + 3 + 3 + 2) + (4 + 3 + 3 + 2+ 1) = 4 + 7 + 10 + 12 + 13  => 46으로  가장 많이 시간이 듭니다.

int main()
{
    fastio;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int num;

        cin >> num;

        atm.push_back(num);
    }

    sort(atm.begin(), atm.end());

    int total = 0;
    for(auto i : atm)
    {
        sum += i;

        total += sum;
    }
    
    cout << total << '\n';

    return 0;
}