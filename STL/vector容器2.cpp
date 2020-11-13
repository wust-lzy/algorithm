#include<iostream>
#include<vector>
using namespace std;
//构造函数
/*vector<T> v;//默认构造函数
vector (v.begin(),v.end());
vector(n,elem);//n个elem赋值给本身
vector(const vector &vec);//复制构造函数
//赋值函数
vector&operator=(const vector &vec);
assign (beg,end); //将[beg,end)区间中的数据拷贝赋值给本身
assign(n,elem);//将n个elem赋值给本身
//容量和大小
empty(); //判断容器是否为空
capacity();//容器的容量
size();//返回容器中元素的个数
resize(int num);//重新指定长度为num，若变长，则以默认值填充新位置；若变短，则超出长度部分被删除
resize(int num,elem);//以elem填充新位置
//插入和删除
push_back(ele) //尾部插入ele
pop_back();    //删除最后一个元素
insert(const_iterator pos,ele);  //迭代器指向位置pos插入元素ele
insert(const_iterator pos,int count,ele)  //迭代器指向位置pos插入count个元素ele
erase(const_iterator pos); //删除迭代器指向的元素
erase(const_iterator start,const_iterator end);//删除迭代器从start到end的元素
clear();  //删除容器中所有的元素
*/
//数据存取
/*at(int idx)//返回idx所指的数据
operator[idx];//
front();  //返回第一个数据元素
back();//返回容器中最后一个数据元素*/
//容器互换
/*
swap(vec)
vector<int>(v).swap(v);  收缩v的内存  */
//vector 预留空间
/*
减少vector在动态扩展容量时的扩展次数
reserve(int len);容器预留len个元素长度，预留位置不初始化，元素不可访问。
*/
int main()
{
    vector<int> v;
    int num=0,*p=NULL;
    for(int i=0;i<100000;i++)
    {
        v.push_back(i);
        if(p!=&v[0])
        {
            p=&v[0];
            num++;
        }
    }
    cout<<num<<endl;
    return 0;
}
