#include<iostream>
#include<fstream>
#define MAX 601 // 최대 문자열의 길이(%s입력의 경우 마지막 '\0'이 입력되기 위해서 갯수 그만큼의 공간 1 추가
#define LEN 6 // 한 암호의 길이

using namespace std;

const char *code[] = {
    "000000", // A
    "001111", // B
    "010011", // C
    "011100", // D
    "100110", // E
    "101001", // F
    "110101", // G
    "111010"  // H
};

char str[MAX]; // Input으로 들어오는 문자열 저장
int str_Compare(const char *s, int start_index){ // 문자열을 비교하는 함수 (다른 문자의 갯수만큼 return)
    int dif_cnt = 0;
    for(int i = 0; i < LEN; i++)
        if(*(s + i) != *(str + i + start_index)) dif_cnt++; // code[s][i]번째 숫자 0 혹은 1과 str[i + start_index]가 다르면 다른 갯수 카운팅
    return dif_cnt; // 다른 갯수 만큼 return
}

char decodeMessage(int start_index){
    if(str_Compare(code[0], start_index) <= 1) return 'A';
    else if(str_Compare(code[1], start_index) <= 1) return 'B';
    else if(str_Compare(code[2], start_index) <= 1) return 'C';
    else if(str_Compare(code[3], start_index) <= 1) return 'D';
    else if(str_Compare(code[4], start_index) <= 1) return 'E';
    else if(str_Compare(code[5], start_index) <= 1) return 'F';
    else if(str_Compare(code[6], start_index) <= 1) return 'G';
    else if(str_Compare(code[7], start_index) <= 1) return 'H';
    else return 'X';
    /* 모든 문자열에 대하여 1이하로 차이날 경우에는 해당 문자를 return하고
     그렇지 않은 경우에는 마지막에 X return */
}

int main(){
    ifstream inp("mail.inp");
    ofstream out("mail.out");
    int testcase;
    inp >> testcase;
    while(testcase--){ // 테스트 케이스 수 만큼 반복
        int N;
        inp >> N;
        inp >> str;
        for(int i = 0; i < N; i++)
            out << decodeMessage(i * LEN);
        out << '\n';
    }
    inp.close();
    out.close();
    return 0;
}
