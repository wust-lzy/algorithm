#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>//标准算法头文件
//vector 容器存放内置数据类型
void myPrint(int val)
{
  cout<<val<<endl;
}
void test01()
{
    vector<int> v;//插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    /*vector <int>::iterator itBegin=v.begin();//起始迭代器 指向容器中第一个元素
    vector <int>::iterator itEnd=v.end();//  结束迭代器  指向容器中最后一个元素的下一个位置
    while(itBegin!=itEnd)//第一种遍历
    {
        cout<<*itBegin<<endl;
        itBegin++;
    }
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)//第二种遍历
    {
        cout<<*it<<endl;
    }*/
    for_each(v.begin(),v.end(),myPrint);//第三种遍历
}
//vector容器中存放自定义数据类型
class Person
{
public:
    string name;
    int age;
    Person(string name,int age)
    {
        this->name=name;
        this->age=age;
    }
};
void test02()
{
    vector<Person> v;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("eee",50);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    //遍历
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<"姓名：  "<<(*it).name<<"年龄:   "<<(*it).age<<endl;
    }
}

//存放自定义数据类型 指针
void test03()
{
    vector<Person*> v;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    Person p5("eee",50);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);
    //遍历容器
    for(vector<Person*>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<(*it)->name<<"  "<<(*it)->age<<endl;
    }
}
//容器嵌套容器
void test04()
{
    vector<vector<int> >v;
    //创建小容器
    vector <int>v1;
    vector <int>v2;
    vector <int>v3;
    vector <int>v4;
    //向小容器中添加数据
    for(int i=0;i<4;i++)
    {
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }
    //将小容器插入到大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    //通过大容器，把所有数据遍历一遍
    for(vector<vector<int>>::iterator it=v.begin();it!=v.end();it++)
    {
        //(*it)----容器vector<int>
        for(vector<int>::iterator vit=(*it).begin();vit!=(*it).end();vit++)
            cout<<*vit<<" ";
        cout<<endl;
    }
}
int main()
{
    test04();
    system("pause");
    return 0;
}

