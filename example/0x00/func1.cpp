// N이하의 자연수 중에서 3의 배수이거나 5의 배수인 수를 모두 합한 값을 반환하는 함수
// func1(int N)을 작성하라. N은 50000 미만의 자연수이다.

#include <iostream>
using namespace std;

int func1(int);
int main() {
    cout << func1(27639);
}

int func1(int N) {
    int sum = 0;
    for(int i = 0; i < N; i++) {
        if(i % 3 ==0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}