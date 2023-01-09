#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int recur;

// 재귀 함수의 가장 큰 핵심은 어디에서 반복이 되는지 규칙을 찾는 것이다.
// 처음 줄은 공통적으로 나와있어서 main문에 작성하는 형식으로 구성
// 그리고 2번째 재귀부터 - 이 출력되는 부분은 함수로 만들어서 사용하였다.

void hypen(int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << ("____");
    }
}

void hypen2(int n)
{
    if(n == 0)
    {
        cout << "라고 답변하였지." << '\n';
        return;
    }

    for(int i = n; i > 0; i--)
    {
        cout << ("____");
    }
    cout << "라고 답변하였지." << '\n';

    hypen2(n - 1);
}

void recurF(int cnt)
{
    hypen(cnt);
    cout << "\"재귀함수가 뭔가요?\"" << '\n';
    
    if(cnt == recur)
    {
        hypen(cnt);
        cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << '\n';

        hypen2(cnt);

        return;
    }
    
    else{
        hypen(cnt);
        cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << '\n';

        hypen(cnt);
        cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << '\n';

        hypen(cnt);
        cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << '\n';
    }

    recurF(cnt+1);
}

int main()
{
    fastio;

    cin >> recur;

    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << '\n';

    recurF(0);

    return 0;
}