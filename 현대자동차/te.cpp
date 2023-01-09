#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

vector<int> vc, ans;

int main() {
	string input;
	
    getline(cin, input);
	
	string tmp = "";

	for(int i = 0; i < input.length(); i++)
	{
		if(input[i] >= '0' && input[i] <= '9')
		{
			tmp += input[i];
		}
		
		else if(input[i] == ' ')
		{
			vc.push_back(stoi(tmp));
			tmp = "";
    }

    if(i == input.length() - 1)
    {
        vc.push_back(stoi(tmp));
    }
	}

	int minDis = 987654321;
	int minSum = 987654321;
	
	int idx = 0;
	while(idx < vc.size())
	{
		for(int i = idx+1; i < vc.size() - 1; i++)
		{
			if(abs(vc[idx] - vc[i] ) < minDis && vc[idx] + vc[i] < minSum)
			{
					minDis = min(abs(vc[idx] - vc[i]), minDis);
					minSum = min(vc[idx] + vc[i], minSum);
                    ans.clear();
                    ans.push_back(vc[idx]);
                    ans.push_back(vc[i]);
			}
		}
        idx++;
	}

    for(auto i : ans)
    {
        cout << i << ' ';
    }

	return 0;
}