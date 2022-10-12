#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int n;
string a = "____";
string b = "\"재귀함수가 뭔가요?\"";
string c = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.";
string d = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.";
string e = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"";
string f = "라고 답변하였지.";
string g = "\"재귀함수는 자기 자신을 호출하는 함수라네\"";

void print_(int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "____";
    }
}

void Recursive(int t)
{
    print_(t);
    cout << b << '\n';

    if(t == n)
    {
        print_(t);
        cout << g << '\n';

        for(int i = t; i >= 0; i--)
        {
            print_(i);
            cout << f << '\n';
        }

        return;
    }

    print_(t);
    cout << c << '\n';

    print_(t);
    cout << d << '\n';

    print_(t);
    cout << e << '\n';

    Recursive(t + 1);
}

int main()
{
    fastio;

    cin >> n;

    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << '\n';

    Recursive(0);

    return 0;
}