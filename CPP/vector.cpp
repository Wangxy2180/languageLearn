#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int m = 3, n = 2;
    // 1.还可以这样去创建一个固定大小的二维vector
    vector<vector<int>> t(n, vector<int>(m));
    t[1][1] = 999;
    cout << t[1][1] << endl;
    cout << t.size() << endl;
    cout << t[0].size() << endl;
    cout << "----------------------" << endl;
    // 其实这个用法是这样的，第一个是个数，第二个是初始值
    // 2.这里的初始值就是int类型，上边的初始值就是vector<int>类型
    vector<int> t1(n, m);
    for (auto k : t1)
        cout << k << endl;
    cout << "----------------------" << endl;
    // 3.或者可以这样resize,一个是带初值的resize，一个不带初值（默认为0），
    vector<vector<int>> sums;
    sums.resize(10, vector<int>(10 + 1));
    // sums.resize(10,vector<int>(10+1,111));
    cout << sums[1][2] << endl;
    cout << sums.size() << endl;
    cout << sums[0].size() << endl;

    // 4.assign，赋值操作，适合批量赋值使用,同样是第一个参数是个数，第二个是数值
    vector<int> ass;
    ass.assign(5, 77);
    cout << "ass.size()" << ass.size() << endl;
    cout << "ass[4]    " << ass[4] << endl;

    // 5.交换位置
    cout << "swap:";
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    swap(vec[1], vec[6]);
    for (auto k : vec)
        cout << k << ",";

    // 6.清除操作
    cout << endl
         << "erase: ";
    vec.erase(vec.begin() + 3);
    for (auto k : vec)
        cout << k << ",";
    cout << endl;

    // 7.插入操作，在开头插入
    vector<int> vec7(3, 1);
    vec7.insert(vec7.begin(), 999);
    cout << "front insert: ";
    for (int i = 0; i < vec7.size(); ++i)
    {
        cout << vec7[i] << ", ";
    }
    cout << endl;

    // 8.翻转
    vector<int> la({1, 2, 3, 4, 5});
    reverse(la.begin(), la.end());
    cout << "reverse: ";
    for (auto k : la)
        cout << k << ", ";
    cout << endl;

    // 9 排序
    vector<int> srt({4, 3, 5, 1, 6, 1, 6, 26});
    sort(srt.begin(), srt.end());
    cout << "sort: ";
    for (auto k : srt)
        cout << k << ", ";
    cout << endl;
}