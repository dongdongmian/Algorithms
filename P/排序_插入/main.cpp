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

    cout << "���������Ϊ��";
    for(int i = 0;i<num;i++){
        cout << a[i] << ' ';
    }
    cout << endl;
}

int main()
{
    cout << "�����뽫Ҫ�������������ĳ��ȣ�";
    int num;
    cin >> num;
    cout << "�����뽫Ҫ�������������";
    int A[num];
    for(int i = 0;i<num;i++){
        cin >> A[i];
    }

    insert_direct(A,num);
    return 0;
}
