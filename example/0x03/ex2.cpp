#include <iostream>
using namespace std;

int list[100];
int func2(int arr[], int N);
int main() {
    int arr[] = {4, 13, 63, 87};
    cout << func2(arr, 4);
}

int func2(int arr[], int N) {
    for(int i = 0; i < N; i++) {
        if(list[100-arr[i]]) return 1;
        list[arr[i]]++;
    }
    return 0;
}