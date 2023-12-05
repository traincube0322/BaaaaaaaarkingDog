#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<int> DQ;
    int T;
    string oper;
    int len;
    string str;
    bool error;
    cin >> T;

    while(T--) {
        DQ.clear();
        cin >> oper;
        cin >> len;
        cin >> str;
        
        // 대괄호 [ ] 삭제.
        str.erase(str.begin());
        str.erase(str.end());
        istringstream iss(str);
        string buffer;
        // ,로 숫자를 구분하고, 문자열을 int로 바꿔서 DQ에 저장.
        while(getline(iss, buffer, ',')) {
            DQ.push_back(stoi(buffer));
        }


        // flag = 0 일 때, it가 앞을 가리킴.
        // flag = 1 일 때, it가 뒤를 가리킴.
        int flag = 0, error = 0;
        for(char s : oper) {
            if(s == 'R') {
                flag = 1 - flag;
            }
            if(s == 'D') {
                if(DQ.empty()) {
                    error = 1;
                    break;
                }
                if(flag) DQ.pop_back();
                else DQ.pop_front();
            }
        }
        if(error) {
            cout << "error";
        }
        else {
            cout << "[";
            if(flag) {
                for(auto it = DQ.rbegin(); it != DQ.rend(); it++) {
                    cout << *it << ",";
                }
            }
            else {
                for(auto it = DQ.begin(); it != DQ.end(); it++) {
                    cout << *it << ",";
                }
            }

            cout << "]";
        }
        cout << "\n";

    }
}