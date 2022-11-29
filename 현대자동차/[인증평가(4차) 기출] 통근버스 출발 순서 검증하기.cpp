#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n;
vector<int> bus;
int st[5001][5001];
long long result = 0;

int main()
{
    fastio;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        bus.push_back(tmp);
    }


    // 1부터 N까지 증가시키면서 해당 값 보다 작은 구간 개수 설정
    for(int i = 1; i <= n; i++)
    {
        
        // 마지막은 무조건 0
        // 뒤의 n-1구간은 해당 idx 기준. 기존의 값 입력부분과 헷갈리는 것을 방지하기 위해 n-1이 끝.
        st[i][n-1] = 0;

        // 맨 뒤의 앞 부분은 그 값 기준으로 따지면 된다.
        if(bus[n-1] < i)
        {
            st[i][n-2] = 1;
        }
        else{
            st[i][n-2] = 0;
        }

        // 증가하는 값을 기준으로 구간합으로 뒤에서부터 오는 방법을 채택.
        for(int j = n - 3; j >= 0; j--)
        {
            if(bus[j+1] < i)
            {
                st[i][j] += st[i][j+1] + 1; 
            }

            else{
                st[i][j] = st[i][j+1];
            }
        }
    }

    for(int i = 0; i < n-2; i++)
    {
        for(int j = i+1; j < n-1; j++)
        {
            if(bus[i] < bus[j])
            {
                result += st[bus[i]][j];
            }
        }
    }


    cout << result << '\n';

    return 0;
}