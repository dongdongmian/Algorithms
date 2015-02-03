#include <iostream>

using namespace std;

//A[] is the array   p is the start index   r is the end index
int Partition(int A[],int p,int r){
    int x = A[r];
    int i = p-1;
    int temp;
    for(int j = p;j <= r-1;j++){
        if(A[j] <= x){
            i = i+1;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[r];
    A[r] = A[i+1];
    A[i+1] = temp;

    return i+1;
}

void QuickSort(int A[],int p,int r){
    int q;
    if(p<r){
        q = Partition(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
}

int main()
{
    cout << "Please input the array's lengh:" ;
    int num;
    cin >> num;

    cout << "Please input the array:" ;
    int A[num];
    for(int i = 1;i<=num;i++){
        cin >> A[i];
    }

    QuickSort(A,1,num);

    for(int i = 1;i<=num;i++){
        cout << A[i] << ' ';
    }
    cout << endl;
    return 0;
}
