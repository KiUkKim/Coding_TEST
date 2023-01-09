#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

vector< pair<int, int> > houseInfoPair;

int main() {
	string publickey;

	int n;	
	
    cin >> publickey;
    cin >> n;

    int cnt = 0;
    while(cnt <= n)
    {
        string houseInfo;
        
        getline(cin, houseInfo);

        string houseNum = "";
        string housePassword = "";
        for(int i = 0; i < houseInfo.length(); i++)
        {
            if(houseInfo[i] == ' ')
            {
                houseNum += houseInfo.substr(0, i);
                housePassword += houseInfo.substr(i+1 , houseInfo.length() -1 );

                houseInfoPair.push_back({stoi(houseNum), stoi(housePassword)});
                break;
            }
        }
        cnt++;
    }

    string tmp;
    cin >> tmp;

    
    string password = "";
    string InputHouseNum = "";

    for(int i = 0; i < tmp.size(); i++)
    {
        if(tmp[i] == '*' && i != tmp.size() - 1 && tmp[tmp.size()- 1] == '*')
        {
            InputHouseNum = tmp.substr(0, i);
            cout << InputHouseNum << '\n';
            password = tmp.substr(i+1, tmp.length() - 5);

            break;
        }

        else if(tmp[i] == '*' && i == tmp.size() - 1)
        {
            password = tmp.substr(0, tmp.size() - 1);

            break;
        }

        if(i == tmp.size() - 1)
        {
            InputHouseNum = tmp;
            break;
        }
    }


    if(password == publickey)
    {
        cout << password.substr(password.size() - 4, password.size() - 1) << " OPEN";
    }
    else if(password != ""){
        for(int i = 0; i < houseInfoPair.size(); i++)
        {
            if(stoi(InputHouseNum) == houseInfoPair[i].first && stoi(password) == houseInfoPair[i].second)
            {
                cout << password.substr(password.size()- 4, password.size() - 1) << " OPEN";
            }
            
        }
    }

    else if(password == "")
    {
        if(InputHouseNum == "0000")
        {
            cout << InputHouseNum << " SECURITY";
        }
        else{
            cout << InputHouseNum << " CALL";
        }
    }


}