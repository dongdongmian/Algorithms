#include <iostream>

#define INFINITY -10000

using namespace std;

//自顶向下  备忘
int MEMOIZED_CUT_ROD_AUX(int r[],int p[],int n){
    int q;
    if(r[n] >= 0)
        return r[n];
    if(n == 0)
        q = 0;
    else{
        q = INFINITY;
        for(int i = 1;i<=n;i++)
            q = max(q,(p[i]+MEMOIZED_CUT_ROD_AUX(r,p,n-i)));
    }
    r[n] = q;
    //cout << n << ": " << r[n] << endl;
    return q;
}

int MEMOIZED_CUT_ROD(int p[],int n){
    int r[n];
    for(int i = 0;i<=n;i++)
        r[i] = INFINITY;
    return MEMOIZED_CUT_ROD_AUX(r,p,n);
}

int main()
{
    cout << "Input the steel bar length:" ;
    int n;
    cin >> n;
    cout << "The number of choices :";
    int num;
    cin >> num;

    int p[num];
    cout << "Input the profit of every length bar:";
    for(int i = 1;i<=num;i++){
      cin >> p[i];
    }

    int Max_pro;
    Max_pro = MEMOIZED_CUT_ROD(p,n);
    cout << "The max profit of " << n << " steel bar is:" << Max_pro << endl;
    return 0;
}
