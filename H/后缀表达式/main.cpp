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
    stack<char> ope;    //操作符
    vector<char> ans;   //后缀表达式
    vector<char>::iterator start, end;
    cout << "请输入算数表达式：" ;
    cin >> input;
    int len = input.length();

    ope.push('=');
    for(int i = 0 ; i < len; ++i)
    {
        if(input[i] >= '0' && input[i] <= '9') //操作数直接存入ans
            ans.push_back(input[i]);
        else if(input[i] == '(') //左括号入栈
            ope.push(input[i]);
        else if(input[i] == ')') //右括号，将匹配的左括号内容存入ans,左括号出栈
        {
            while (ope.top() != '(')
            {
                ans.push_back(ope.top());
                ope.pop();
            }
            ope.pop(); //左括号出栈
        }
        else if(pre(input[i]) == 0){
            cout << "你输入的操作符暂时不支持" <<endl;
            return 0;
        }
        else if(pre(input[i]) < pre(ope.top())) //优先级小于栈顶元素则入栈
            ope.push(input[i]);
        else //大于栈顶元素
        {
            while(pre(input[i]) <= pre(ope.top()))
            {
                ans.push_back(ope.top());
                ope.pop();
            }
            ope.push(input[i]);
        }
    }
    while(ope.top() != '=') //其余操作符存入后缀表达式中
    {
        ans.push_back(ope.top());
        ope.pop();
    }

    for(start = ans.begin(), end = ans.end(); start < end; ++start)
        printf("%c", *start);
    printf("\n");
    return 0;
}
