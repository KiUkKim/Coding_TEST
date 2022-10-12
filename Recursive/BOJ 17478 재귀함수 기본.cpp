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
string b = "\"����Լ��� ������?\"";
string c = "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.";
string d = "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.";
string e = "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"";
string f = "��� �亯�Ͽ���.";
string g = "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"";

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

    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << '\n';

    Recursive(0);

    return 0;
}