#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <math.h>
using namespace std;


int num, recur, divn;

// 이 문제에서 주의할점은 A,B,C가 int형 범위이다.
// 따라서 해당 문제가 정상적으로 나오게 하려면 result를 long long형으로 만들어주어야한다.

// 하지만 이렇게 되면 문제점이 있는데
// 브루트포스 형식으로 재귀를 반복을 하게되면 O(N) - > O(2,147,483,647)으로 시간초과가 발생하게 된다.

// 따라서 a^4과 같은 짝수인 경우 = (a^2) * (a^2)형태
// a^5와 같은 홀수인 경우 (a^2) * (a^2) * a의 형태로 구성하며 시간초과를 해결할수있다.

long long recursive(int r)
{
    // recur이 1인경우 그냥 종료
    if(r == 1)
    {
        return num % divn;
    }

    // 먼저 값을 저장해주고, 구하려는 수가 커질 수 있으므로 나눠준다.
    long long result = recursive(r/2);

    // 홀수인 경우
    if(r%2)
    {
        return ((result * result)% divn * num) % divn;
    }
    else{
        return (result * result) % divn;
    }
    
}

int main()
{
    fastio;

    cin >> num >> recur >> divn;

    cout << recursive(recur) << '\n';

    return 0;
}