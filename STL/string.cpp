#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>//标准算法头文件
/*string ();                    //创建一个空的字符串
string(const char *s);        //使用字符串初始化
string (const string &str);   //使用str对象初始化
string (int n,char c);   //使用n个字符c初始化

string &operator=(const string &s);//赋值
string &operator=(char c);  //用字符c赋值
string &assign(const char *s,int n);  //字符串s前n个字符赋值
string &assign(const string &s);
string &assign(int n,char c);

string &operator+=(const string &s);
string &operator+=(const char c);
string &operator+=(const string &str);
string &append(const char *s);
string &append(const char *s,int n);
string &append(const string &s);
string &append(const string &s,int pos,int n);//字符串s中从pos开始的n个字符连接到字符串结束*/
//1.查找
void test1()
{
    string str1="111abcdefg";
    int pos=str1.find("de");
    if(pos==-1)
        cout<<"未找到"<<endl;
    else
    cout<<"pos="<<pos<<endl;

    //rfind
    pos=str1.rfind("de");
    cout<<"pos="<<pos<<endl;
    //rfind和find区别
    //rfind从右往左查找  find从左往右查找
}
//2.替换
void test2()
{
    string str1="111abcdefg";
    str1.replace(1,3,"1111");
    cout<<"str1="<<str1<<endl;
}
//3.比较
/*
int compare(const string &s)const;
int compare(const char *s) const; 小于返回负数，等于返回0，大于返回正数
*/
//4.字符存取
/*
char &operator[](int n);
char &at(int n);
*/
//5.插入和删除
string &insert(int pos,const char *s);
string &insert(int pos,const string &str);
string &insert(int pos,int n, char c);
//string &erase(int pos,int n=npos);
//6.子串
//string substr(int pos=0,int n=npos)const;//返回由pos开始的n个字符组成的字符串
void test3()
{
    string email="zhangsan@sina.com";
    //从邮箱地址中获取用户名
    int pos=email.find("@");
    string usrName=email.substr(0,pos);
    cout<<usrName<<endl;
}
int main()
{


    //test2();
    //string s="afaf";
    //s.erase(1);
    //cout<<s;
    test3();
    system("pause");
    return 0;
}
