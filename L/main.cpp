#include <iostream>

#define UP 1
#define INCLINED 2
#define LEFT 3

#define MAX 50

using namespace std;

void Print_LCS(int Sym[][MAX],string a,int m,int n){
    if(m == 0 || n ==0)
        return;

    if(Sym[m][n] == INCLINED){
        Print_LCS(Sym,a,m-1,n-1);
        cout << a[m-1] << ' ';
    }

    else if(Sym[m][n] == UP)
        Print_LCS(Sym,a,m-1,n);

    else
        Print_LCS(Sym,a,m,n-1);
}

void LCS_CreateTable(string a,string b){
    int m = a.length();
    int n = b.length();

    /*for(int i = 0;i<=m;i++){
        cout << a[i] << ' ' << i <<endl;
    }*/

    int Num[MAX][MAX],Sym[MAX][MAX];

    //initial
    for(int i = 0;i<=m;i++){
        for(int j = 0;j<=n;j++){
            Num[i][j] = 0;
            Sym[i][j] = 0;  //1 is represent up,2 is represent tilted,3 is represent LEFT
        }
    }

    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            if(a[i-1] == b[j-1]){
                Num[i][j] = Num[i-1][j-1]+1;
                Sym[i][j] = INCLINED;
            }

            else if(Num[i-1][j] >= Num[i][j-1]){
                Num[i][j] = Num[i-1][j];
                Sym[i][j] = UP;
            }

            else{
                Num[i][j] = Num[i][j-1];
                Sym[i][j] = LEFT;
            }
        }
    }
    cout << "The table is:" << endl;
    for(int i = 0;i<=m;i++){
        for(int j = 0;j<=n;j++){
            cout << Num[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "The strings' LCS length is " << Num[m][n] << endl;

    cout << "The LCS is :" << endl;
    Print_LCS(Sym,a,m,n);
}

int main()
{
    cout << "Please input two String to find their longest-common-subsequece:" << endl;

    string a,b;
    cin >> a >> b;
    LCS_CreateTable(a,b);

    return 0;
}
