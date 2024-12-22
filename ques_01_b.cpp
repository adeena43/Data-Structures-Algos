#include<iostream>
#include<utility>
#include<vector>
#include<string>
using namespace std;

int main()
{
    vector<pair<string, string>> smsMessages = 
    {
        {"1234567890", "Hey, this is a test message from Mom"},
        {"5555555555", "Meeting at 5 PM, don't be late!"},
        {"0987654321", "Family lunch at 1 PM. Dad"}
    };

    vector<string> familyNumbers = {
        "1234567890", "0987654321", "1122334455", "6677889900", "5544332211"
    };

    for(auto sms:smsMessages)
    {
        for(auto famNum:familyNumbers)
        {
            if(sms.first == famNum)
            {
                cout<<"Alert: Family member's message detected\nMessage: "<<sms.second<<endl;
                break;
            }
        }
    }
    return 0;
}