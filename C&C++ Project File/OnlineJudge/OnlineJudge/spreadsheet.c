#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100
#define NEW (char *)malloc(sizeof(char) * 100)
#define DECIMAL 10
#define Alpha 26

int toDecimal(char *Alphabet, int start, int end){ // 26진수를 10진수로 변경
    int dec = 0;
    for(int i = end, p = 0; i >= start; i--, p++){
        dec += ((Alphabet[i] - 64) * pow(Alpha, p));
    }
    return dec;
}

int toInt(char *Decimal, int start, int end){ // 문자열을 숫자로 변경!
    int dec = 0;
    for(int i = end, p = 0; i >= start; i--, p++){
        dec += ((Decimal[i] - 48) * pow(DECIMAL, p));
    }
    return dec;
}

char *toAlphabet(int Decimal){ // 10진수를 알파벳으로 변경
    char *alp = NEW;
    int pos = 0, dec = Decimal;
    while(dec != 0) {
        dec = (dec - 1) / Alpha;
        pos++;
    } // 알파벳으로 바뀔 자릿 수 설정
    alp[pos] = '\0';
    while(Decimal != 0){
        alp[--pos] = ((Decimal - 1) % Alpha) + 65;
        Decimal = (Decimal - 1) / Alpha;
    } // 역순으로 자리에 삽입
    return alp;
}

void toSheet(FILE *out, char *str){ // RxCy -> Excel
    int i = 1, ni;
    while(str[i] < 'A') i++;
    ni = i++;
    fprintf(out, "%s", toAlphabet(toInt(str, i, strlen(str) - 1)));
    for(i = 1; i < ni; i++)
        fprintf(out, "%c", str[i]);
}

void toNumbering(FILE *out, char *str){ // Excel -> RxCy
    int i = 0, ni;
    fprintf(out, "R");
    while(str[i] >= 'A') i++;
    ni = i - 1;
    for(;i < strlen(str); i++)
        fprintf(out, "%c", str[i]);
    fprintf(out, "C");
    fprintf(out, "%d", toDecimal(str, 0, ni));
}

int CheckForm(char *str){
    /* return값이 true이면 RxCy형식에서 Excel 형식으로
     false이면 Excel 형식에서 RxCy형식으로 */
    if(str[0] == 'R'){
        int i = 1;
        while(str[i] >= 65) i++;
        while(str[i] < 65) i++;
        if(str[i] == 'C') return 1;
        return 0;
    }
    return 0;
}

int main(){
    FILE *inp = fopen("spreadsheet.inp", "r");
    FILE *out = fopen("spreadsheet.out", "w");
    int testcase;
    
    fscanf(inp, "%d", &testcase);
    while(testcase--){
        char str[MAX];
        fscanf(inp, "%s", &str);
        if(CheckForm(str))
            toSheet(out, str);
        else
            toNumbering(out, str);
        fprintf(out, "\n");
    }
    fclose(inp);
    fclose(out);
    return 0;
}
