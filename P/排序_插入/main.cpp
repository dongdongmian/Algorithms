#include <iostream>

using namespace std;

void insert_direct(int a[],int num){

    int key;
    for(int i = 1;i<num;i++){
        key = a[i];
        int j = i-1;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;
    }

    cout << "数组排序后为：";
    for(int i = 0;i<num;i++){
        cout << a[i] << ' ';
    }
    cout << endl;
}

int main()
{
    cout << "请输入将要进行排序的数组的长度：";
    int num;
    cin >> num;
    cout << "请输入将要进行排序的数组";
    int A[num];
    for(int i = 0;i<num;i++){
        cin >> A[i];
    }

    insert_direct(A,num);
    return 0;
}
