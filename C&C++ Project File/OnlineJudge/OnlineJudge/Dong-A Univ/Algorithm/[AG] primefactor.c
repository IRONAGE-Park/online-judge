#include<stdio.h>
#include<math.h>

int Check_PrimeNumber(int n){ // 소수인지 확인하는 함수
    for(int i = 2; i <= sqrt(n); i++){
        /* i = 2 부터 루트 n까지 비교하면서 수가 한 번이라도 나누어 떨어지면 소수가 아님 */
        if(n % i == 0) return i; // 소수가 아니므로 가장 작은 약수 반환
    }
    return 1; // 소수이므로 true 반환
}

int Calculate_PrimeNumber(int n){ // 소인수들을 모두 더하는 함수
    int check = Check_PrimeNumber(n); // 소수이면 1을 반환하고, 소수가 아니면 1보다 큰 수 중에 제일 작은 약수를 반환.
    if(check == 1) // n이 소수이면
        return n; // n을 그대로 반환함
    else
        return check + Calculate_PrimeNumber(n / check); // 제일 작은 약수 + 그 약수로 나눈 수 n / check를 매개변수로 다시 호출
}
/*
int main(){
    FILE *inp = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    int testcase;
    fscanf(inp, "%d", &testcase);
    while(testcase--){
        int N;
        fscanf(inp, "%d", &N);
        if(Check_PrimeNumber(N) == 1) // N이 그냥 소수이면
            fprintf(out, "PrimeNumber\n"); // PrimeNumber 출력
        else
            fprintf(out, "%d\n", Calculate_PrimeNumber(N)); // 그렇지 않으면 재귀로 소인수분해한 값들 모두 더하여 출력
    }
    fclose(inp);
    fclose(out);
    return 0;
}
*/
