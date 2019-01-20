#include<iostream>
#define TT 10000
using namespace std;

int cont1(int rank){
    if(rank == 0 || rank >= 21) return 0;
    else if(rank == 1) return 500 * TT;
    else if(rank <= 3) return 300 * TT;
    else if(rank <= 6) return 200 * TT;
    else if(rank <= 10) return 50 * TT;
    else if(rank <= 15) return 30 * TT;
    else return 10 * TT;
}

int cont2(int rank){
    if(rank == 0 || rank >= 32) return 0;
    else if(rank == 1) return 512 * TT;
    else if(rank <= 3) return 256 * TT;
    else if(rank <= 7) return 128 * TT;
    else if(rank <= 15) return 64 * TT;
    else return 32 * TT;
}

int main(){
    int testcase;
    cin >> testcase;
    while(testcase--){
        int c1, c2;
        cin >> c1 >> c2;
        cout << cont1(c1) + cont2(c2) << '\n';
    }
    return 0;
}
