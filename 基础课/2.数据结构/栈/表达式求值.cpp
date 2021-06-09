#include<iostream>
#include<stack>
#include<unordered_map>
#include<algorithm>
using namespace std;
stack<int> num;
stack<char> op;
void eval()
{
    int b = num.top();
    num.pop();
    int a = num.top();
    num.pop();
    char c = op.top();
    op.pop();
    int x;
    if(c=='+')
        x = a + b;
    else if (c == '-')
        x = a - b;
    else if (c == '*')
        x = a * b;
    else
        x = a / b;
    num.push(x);
}
int main()
{
    //定义操作符的优先级
    unordered_map<char, int> book{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    string s;
    cin >> s;
    for (int i = 0; i < s.size();i++)
    {
        if(isdigit(s[i])){
            int x = 0, j = i;
            while(j<s.size()&&isdigit(s[j]))
                x = x * 10 + s[j++] - '0';
            i = j - 1;
            num.push(x);
        }else if(s[i]=='(')
            op.push(s[i]);
        else if(s[i]==')'){
            while(op.top()!='(')
                eval();
            op.pop();//删除左括号
        }else{  //+ - * /
            while(!op.empty()&&book[op.top()]>=book[s[i]])
                eval();
            op.push(s[i]);
        }
    }
    while(!op.empty()){
        eval();
    }
    cout << num.top();
    return 0;
}