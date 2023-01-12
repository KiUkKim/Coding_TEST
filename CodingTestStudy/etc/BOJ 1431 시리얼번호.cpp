#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <string.h>
using namespace std;

vector<string> guitar;
int n;

// 문제 아이디어를 그대로 수행하면 되는 문제.
// custom sort로 구현
// 3번의 조건은 단순히 아스키 코드 상으로, 숫자가 알파벳보다 작으므로 오름차순으로 정렬
// quick sort , heap sort 여러가지 형식이 있지만 해당 문제에서 시간 줄일 구간은 2번 조건 부분인데 이 부분에서 필요없다고 판단하였고 N이 50으로 작기때문에
// O(n)의 형식으로 구현된다.
bool compare(string a, string b)
{
    // 1번 조건 구현
    // a,b 길이를 비교하여서 다를 경우 오름차순으로 정렬시킨다.
    if(a.length() != b.length())
    {
        return a.length() < b.length();
    }

    // 2번 조건 구현
    // 서로 길이가 같을 경우 모든 자리의 합을 더한다.(숫자만)
    else{
        int a_sum = 0;
        int b_sum = 0;

        for(int i = 0; i < a.length(); i++)
        {
            if(a[i] >= '0' && a[i] <= '9')
            {
                // 일반적으로 stoi를 많이 사용하지만 해당 문제는 char형으로 하나의 숫자를 받아주어야한다.
                a_sum += a[i] - '0';
            }
        }

        for(int i = 0; i < b.length(); i++)
        {
            if(b[i] >= '0' && b[i] <= '9')
            {
                // 일반적으로 stoi를 많이 사용하지만 해당 문제는 char형으로 하나의 숫자를 받아주어야한다.
                b_sum += b[i] - '0';
            }
        }

        // 2번 조건 구현
        // if-else로 구현할 시, 반환할 때 sum으로 구성
        if(a_sum != b_sum)
        {
            return a_sum < b_sum;
        }

        else{
            return a < b;
        }

    }
}

int main()
{
    fastio;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string tmp;

        cin >> tmp;

        guitar.push_back(tmp);
    }

    sort(guitar.begin(), guitar.end(), compare);

    for(auto g : guitar)
    {
        cout << g << '\n';
    }



    return 0;
}