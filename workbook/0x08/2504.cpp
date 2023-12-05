#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    stack<char> S;
    //총 합계 sum, tmp는 중간 저장용
    int sum = 0, tmp = 1;
    cin >> str;
    for(int i = 0; i < str.size(); i++) {
        char s = str[i];
        if(s == '(') {
            S.push('(');
            tmp *= 2;
        }
        if(s == '[') {
            S.push('[');
            tmp *= 3;
        }

        if(s == ')') {
            if(!S.empty() && S.top() == '(') {
                if(str[i-1] == '(') {
                    S.pop();
                    sum += tmp;
                    tmp /= 2;
                }
                else {
                    S.pop();
                    tmp /= 2;
                }
            }
            else {
                sum = 0;
                break;
            }
        }

        if(s == ']') {
            if(!S.empty() && S.top() == '[') {
                if(str[i-1] == '[') {
                    S.pop();
                    sum += tmp;
                    tmp /= 3;
                }
                else {
                    S.pop();
                    tmp /= 3;
                }
                
            }
            else {
                sum = 0;
                break;
            }
        }
    }


    if(!S.empty()) sum = 0;

    cout << sum;
}