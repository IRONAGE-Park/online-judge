#include<iostream>
#define MAX 41

using namespace std;

typedef struct { int zero, one; }Fibo;

Fibo fibo[MAX];

void Sol(){
    fibo[0].one = 0; fibo[0].zero = 1; fibo[1].one = 1; fibo[1].zero = 0;
    for(int i = 2; i < MAX; i++){
        fibo[i].one = fibo[i - 1].one + fibo[i - 2].one;
        fibo[i].zero = fibo[i - 1].zero + fibo[i - 2].zero;
    }
}

int main(){
    int testcase;
    cin >> testcase;
    Sol();
    while(testcase--){
        int N;
        cin >> N;
        cout << fibo[N].zero << ' ' << fibo[N].one << '\n';
    }
    return 0;
}
