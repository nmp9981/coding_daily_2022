#include <cstring>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
map<string,string> userInfo;//아이디, 닉네임
vector<string> userNick;//유저명

vector<string> solution(vector<string> record) {
    vector<string> answer;
    for(auto s:record){
        string command,userID,nick;//명령, 아이디, 닉네임
        stringstream sstream;
        sstream.str(s);
        sstream>>command>>userID>>nick;
        
        if(command=="Enter"){//입장
            userInfo[userID] = nick;
            userNick.push_back(userID);
            answer.push_back("님이 들어왔습니다.");
        }else if(command == "Leave"){//퇴장
            userNick.push_back(userID);
            answer.push_back("님이 나갔습니다.");
        }else if(command == "Change"){//변경
            userInfo[userID] = nick;
        }
        
    }
    //채팅 내용
    for(int i=0;i<answer.size();i++) answer[i] = userInfo[userNick[i]]+answer[i];
    return answer;
}
