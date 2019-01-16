#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#define MAX 100
#define DECIMAL 10
#define Alpha 26

using namespace std;

int toDecimal(string Alphabet){
    int dec = 0;
    for(int i = Alphabet.length() - 1, p = 0; i >= 0; i--, p++){
        dec += ((Alphabet[i] - 64) * pow(Alpha, p));
    }
    return dec;
}

int toInt(string Decimal){
    int dec = 0;
    for(int i = Decimal.length() - 1, p = 0; i >= 0; i--, p++){
        dec += ((Decimal[i] - 48) * pow(DECIMAL, p));
    }
    return dec;
}

string toString(int Decimal){
    string str = "";
    int pos = 0, dec = Decimal;
    while(dec != 0){
        dec /= DECIMAL;
        str += '0';
        pos++;
    }
    while(Decimal != 0){
        str[--pos] = (Decimal % DECIMAL) + 48;
        Decimal /= DECIMAL;
    }
    return str;
}

string toAlphabet(int Decimal){
    string alp = "";
    int pos = 0, dec = Decimal;
    while(dec != 0) {
        dec = (dec - 1) / Alpha;
        alp += '0';
        pos++;
    }
    while(Decimal != 0){
        alp[--pos] = ((Decimal - 1) % Alpha) + 65;
        Decimal = (Decimal - 1) / Alpha;
    }
    return alp;
}

string toSheet(string str){
    string answer = "";
    int i = 1, ni;
    while(str[i] < 'A') i++;
    ni = i++;
    answer += toAlphabet(toInt(str.substr(i, str.length() - i))) + str.substr(1, ni - 1);
    return answer;
}

string toNumbering(string str){
    string answer = "";
    int i = 0, ni;
    answer += 'R';
    while(str[i] >= 'A') i++;
    ni = i;
    answer += str.substr(i) + 'C' + toString(toDecimal(str.substr(0, ni)));
    return answer;
}

bool CheckForm(string str){
    if(str[0] == 'R'){
        int i = 1;
        while(str[i] >= 65) i++;
        while(str[i] < 65) i++;
        if(str[i] == 'C') return true;
        return false;
    }
    return false;
}

int main(){
    ifstream inp("spreadsheet.inp");
    ofstream out("spreadsheet.out");
    int testcase;
    inp >> testcase;
    while(testcase--){
        string str;
        inp >> str;
        if(CheckForm(str))
            str = toSheet(str);
        else
            str = toNumbering(str);
        out << str + '\n';
    }
    inp.close();
    out.close();
    return 0;
}
