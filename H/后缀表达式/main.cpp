#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int pre(char symbol){
    if(symbol == '(')
        return 3;
    else if(symbol == '+'||symbol == '-')
        return 2;
    else if(symbol == '*'||symbol == '/')
        return 1;
    else
        return 0;
}

int main()
{
    string input;
    stack<char> ope;    //������
    vector<char> ans;   //��׺���ʽ
    vector<char>::iterator start, end;
    cout << "�������������ʽ��" ;
    cin >> input;
    int len = input.length();

    ope.push('=');
    for(int i = 0 ; i < len; ++i)
    {
        if(input[i] >= '0' && input[i] <= '9') //������ֱ�Ӵ���ans
            ans.push_back(input[i]);
        else if(input[i] == '(') //��������ջ
            ope.push(input[i]);
        else if(input[i] == ')') //�����ţ���ƥ������������ݴ���ans,�����ų�ջ
        {
            while (ope.top() != '(')
            {
                ans.push_back(ope.top());
                ope.pop();
            }
            ope.pop(); //�����ų�ջ
        }
        else if(pre(input[i]) == 0){
            cout << "������Ĳ�������ʱ��֧��" <<endl;
            return 0;
        }
        else if(pre(input[i]) < pre(ope.top())) //���ȼ�С��ջ��Ԫ������ջ
            ope.push(input[i]);
        else //����ջ��Ԫ��
        {
            while(pre(input[i]) <= pre(ope.top()))
            {
                ans.push_back(ope.top());
                ope.pop();
            }
            ope.push(input[i]);
        }
    }
    while(ope.top() != '=') //��������������׺���ʽ��
    {
        ans.push_back(ope.top());
        ope.pop();
    }

    for(start = ans.begin(), end = ans.end(); start < end; ++start)
        printf("%c", *start);
    printf("\n");
    return 0;
}
