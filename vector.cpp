#include<iostream>
using namespace std;
#include<vector>

void printf_num(int num)
{
    cout<<num<<" ";
}

int main()
{
    vector<int>vec = {1,2,5,4,3};
    vector<int>::iterator iter_begin = vec.begin();
    vector<int>::iterator iter_end = vec.end();
    // 1.1 for_each的遍历数组的使用：要声明迭代器、回调函数printf_num
    for_each(iter_begin,iter_end,printf_num);
    cout<<endl;
    // 1.2使用for循环遍历
    for(vector<int>::iterator it = vec.begin();it != vec.end();++it)
    {
        //*it - 取值
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<"初始化"<<endl;
    // 2.1 初始化-使用另外一个数组
    vector<int>temp1(vec.begin(),vec.end());
    vector<int>::iterator t1 = temp1.begin();
    vector<int>::iterator t2 = temp1.end();
    for_each(t1,t2,printf_num);
    cout<<endl;
    // 2.2 初始化-数组数值相等
    vector<int>temp2(10,1);
    vector<int>::iterator t3 = temp2.begin();
    vector<int>::iterator t4 = temp2.end();
    for_each(t3,t4,printf_num);
    cout<<endl;
    // 2.3初始化-拷贝构造函数
    vector<int>temp3(temp2);
    vector<int>::iterator t5 = temp3.begin();
    vector<int>::iterator t6 = temp3.end();
    for_each(t5,t6,printf_num);
    cout<<endl;
    // 2.4初始化-交换数组来初始化
    vector<int>temp4(temp3);
    temp4.swap(temp1); //此时temp1不变
    vector<int>::iterator t7 = temp4.begin();
    vector<int>::iterator t8 = temp4.end();
    for_each(t7,t8,printf_num);
    cout<<endl;

    cout<<"插入操作"<<endl;
    //3.1插入操作 - loc位置之前插入element
    vec.insert(iter_begin + 1,10);
    vector<int>::iterator l = vec.begin();
    vector<int>::iterator r = vec.end();
    for_each(l,r,printf_num);
    cout<<endl;
    //3.2插入操作 - loc位置之前插入num个element
    vec.insert(l + 1,5,10);
    vector<int>::iterator l1 = vec.begin();
    vector<int>::iterator r1 = vec.end();
    for_each(l1,r1,printf_num);
    cout<<endl;

    //3.3插入操作 - loc之前插入【iteartor start，iterator end)迭代器之间的元素
    vec.insert(l1 + 1,l1,l1 + 1);
    vector<int>::iterator l2 = vec.begin();
    vector<int>::iterator r2 = vec.end();
    for_each(l2,r2,printf_num);
    cout<<endl;

    cout<<"删除元素"<<endl;
    //4.1 删除元素 - erase(iterator loc)
    vec.erase(vec.end() - 1);
    vector<int>::iterator d1 = vec.begin();
    vector<int>::iterator d2 = vec.end();
    for_each(d1,d2,printf_num);
    cout<<endl;
    // 4.2 删除元素 - erase(iterator start，iterator end)
    vec.erase(vec.begin(),vec.end() - 1);
    vector<int>::iterator d3 = vec.begin();
    vector<int>::iterator d4 = vec.end();
    for_each(d3,d4,printf_num);
    // 4.3 clear(),删除全部元素
    cout<<endl;


    cout<<"改变数组大小"<<endl;
    //5.1 resize(len) - 将数组空间调整为len大小
    vec.resize(2);
    // vec.resize(20,1);
    vector<int>::iterator l3 = vec.begin();
    vector<int>::iterator r3 = vec.end();
    for_each(l3,r3,printf_num);
    cout<<endl;
    // 5.2 reserve(len)提前申请足够的空间，可减少动态申请空间的次数
    vector<int>re;
    //re.reserve(1000);   // 预留空间-减少申请空间次数、数据拷贝，提高性能
    int* address = NULL;
    int num = 0; //需要动态增长的次数
    for(int i = 0;i < 1000;++i)
    {
        re.push_back(i);
        if(address != &(re[0]))
        {
            address = &(re[0]);
            num++;
        }
    }
    cout<<num<<endl;
    return 0;
}