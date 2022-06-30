#include<iostream>
using namespace std;
#include<string>

int main()
{
    string str = "Hello World!";
    cout<<"索引数据"<<endl;
    // 1.1 string类重载了[],和at(int loc)一样能够索引数据，但是at函数出错能够抛出异常
    try
    {
        // 不执行catch
        // cout<<str[100]<<endl;
        // 执行catch
        cout<<str.at(100)<<endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "数组越界" << '\n';
    }
    cout<<endl;

    cout<<"拼接数据"<<endl;
    string str1 = "This is world of C++";
    //2.1 string类重载了 +=
    string temp1 = str;
    temp1 += str1;
    cout<<temp1<<endl;
    //2.2 使用append(string)
    string temp2 = str;
    temp2.append(str1);
    cout<<temp2<<endl;
    //2.3 append(stirng,loc)把string从下标loc开始的字符  添加到 字符的尾部。
    string temp3 = str;
    temp3.append(str1,0);
    cout<<temp3<<endl;
    //2.4 append(stirng,loc,n)把string从下表loc开始的n个字符  添加到 字符的尾部。n大于实际长度，不报错
    string temp4 = str;
    temp4.append(str1,2,str1.size());
    cout<<temp4<<endl;
    // 2.5append(n,c)追加n个相同的字符c
    string temp5 = str;
    temp5.append(10,'q');
    cout<<temp5<<endl;
    cout<<endl;

    cout<<"查找"<<endl;
    //3.1 int find(string,loc) 从loc开始的字符串中查找string在字符串中的位置
    int loc1 = str.find("World",6);
    cout<<loc1<<endl;
    // 3.2 int find(string,loc,n) 从loc开始的字符串中查找string的前n个字符串在字符串中的位置
    int loc2 = str.find("Worlde",6,5);
    cout<<loc2<<endl;
    cout<<endl;

    cout<<"替换/修改"<<endl;
    //4.1 replace(pos,n,string)  替换pos开始的n个字符为string
    string temp6 = str;
    temp6.replace(0,5,"Hi");
    cout<<temp6<<endl;
    cout<<endl;

    cout<<"比较字符串大小"<<endl;
    // 5.1compare(string),返回值为ASCII超过的数值
    string temp7 = "a";
    string temp8 = "B";
    cout<<temp7.compare(temp8)<<endl;
    cout<<endl;

    cout<<"获取子串"<<endl;
    // 6.1 substr(loc,len)
    cout<<str.substr(0,10)<<endl;
    cout<<endl;

    cout<<"插入子串"<<endl;
    //7.1 insert(loc,str)
    string temp9 = str;
    string temp10 = str;
    cout<<temp9.insert(temp9.size()," Come On")<<endl;
    //7.2insert(loc,n,c)
    cout<<temp10.insert(temp10.size(),10,'m')<<endl;
    cout<<endl;

    cout<<"删除"<<endl;
    // 8.1erase(loc,n),删除从loc开始的n个字符
    string temp11 = str;
    cout<<temp11.erase(6,5)<<endl;
    return 0;
}