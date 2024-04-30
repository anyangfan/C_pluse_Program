#include <iostream>
#include <string>
#include <map>
#include <list>

int main()
{
    using namespace std;
    // typedef pair<const Key, T> value_type;
    std::map<std::string, int> mymap = {
        {"alpha", 0},
        {"beta", 0},
        {"gamma", 0}};

    mymap.at("alpha") = 10;
    mymap.at("beta") = 20;
    mymap.at("gamma") = 30;

    for (auto &x : mymap)
    {
        std::cout << x.first << ": " << x.second << '\n';
    }
    cout<<"\n"<<endl;
    /*
    这段代码使用了C++11中的范围（range-based）for循环语法。
    这种循环语法允许直接对容器（比如std::map、std::vector等）进行迭代，而不需要显式地使用迭代器。

    具体来说，for (auto &x : mymap) 中的部分解释如下：
    auto &x：使用auto关键字可以让编译器根据右侧的表达式自动推导出x的类型，这里的&表示x是一个引用类型，
    这样做可以避免在循环中进行元素的拷贝，提高效率。
    mymap：被遍历的容器，这里是一个std::map<std::string, int>类型的mymap。
    因此，这行代码的意思是对mymap中的每一对键值对进行遍历，将键值对中的键赋值给x.first，值赋值给x.second，然后执行循环体中的代码。
    在循环体中，通过x.first和x.second分别访问map中的键和值，并将它们输出到标准输出流中。
    */
    
    /* -------------------------- map::begin map::end ------------------------- */
    for(map<string,int>::iterator it = mymap.begin();it != mymap.end();it++)
    {
        cout << "key: " << it->first << " | value: " << it->second << endl;
    }

    cout<<"\n"<<endl;

    /* --------- map::clear map::erase map::emplace map::find map::count -------- */
    mymap.erase("alpha");
    for(map<string,int>::iterator it = mymap.begin();it != mymap.end();it++)
    {
        cout << "key: " << it->first << " | value: " << it->second << endl;
    }

    cout<<"\n"<<endl;

    mymap.emplace("alpha",10);
    for(map<string,int>::iterator it = mymap.begin();it != mymap.end();it++)
    {
        cout << "key: " << it->first << " | value: " << it->second << endl;
    }
    cout<<"\n"<<endl;

    map<string,int>::iterator it = mymap.find("alpha");
    if(it != mymap.end())
    {
        cout << "key found" << endl;
        cout << "key: " << it->first << " | value: " << it->second << endl;
    }
    else
    {
        cout << "key not found" << endl;
    }
    cout<<"\n"<<endl;

    /* ------------------------------- map::count ------------------------------- */
    //创建一个string list列表
    list <string> mylist = {"alpha","beta","gamma","delta","Andy"};
    for(auto it = mylist.begin(); it != mylist.end(); it++)
    {
        if(mymap.count(*it)>0)
        {
            std::cout << *it <<" is an element of mymap.\n";
            cout << "key: " << *it << " | value: " << mymap[*it] << endl;
        }
       else
       {
           std::cout << *it <<" is not an element of mymap.\n";
       }
    }
    

    return 0;
}