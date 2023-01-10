###  0003. 无重复字符的最长子串
string中find及find_first_of的使用：
```c++
size_t find ( const string& str, size_t pos = 0 ) const;
size_t find ( const char* s, size_t pos, size_t n ) const;
size_t find ( const char* s, size_t pos = 0 ) const;
size_t find ( char c, size_t pos = 0 ) const;
size_t find_first_of ( const string& str, size_t pos = 0 ) const;
size_t find_first_of ( const char* s, size_t pos, size_t n ) const;
size_t find_first_of ( const char* s, size_t pos = 0 ) const;
size_t find_first_of ( char c, size_t pos = 0 ) const;
```
pos为string中的位置，是一个整数，返回值是一个整数，不是迭代器，n为查找字符的前n个字符

### 0005. 最长回文子串
若已知对角线的值，想要得到上三角和下三角的值，可以使用循环：
```c++
for (int L = 2; L <= n; L++) {
    for (int i = 0; i < n; i++) {
        int j = i + L - 1;
        dp[i][j];
    }
}
```

### 0007. 整数反转
负数模之后还是负数，如：-11 % 10 = -1，-11 % 3 = -2。

### 0031. 下一个排列
reverse是C++下的库函数，可用于翻转字符串，翻转链表等
reverse()会将区间[begin,end)内的元素全部逆序
```c++
reverse(str.begin(),str.end()) 反转字符串	 
reverse(vector.begin(),vector.end()) 反转向量
reverse(a,a+strlen(a)) 反转数组
```

iter_swap()可以交换两个迭代器的元素，如：
```c++
iter_swap(a,b);
```
其中a,b均为迭代器。

### 0036. 有效的数独
可以使用memset来初始化数组中的所有元素：
```c++
int rows[9][9];
memset(rows,0,sizeof(rows));
```

### 0060. 排列序列
计算序列全排列的函数：next_permutation(start, end)和prev_permutation(start,end)。
这两个函数作用是一样的，若存在下个一排序或前一个排序，则返回true，否则返回false。
```c++
    string s = "1234";
    while (next_permutation(s.begin(), s.end())) {
        cout << s << endl;
    }

    string s = "4321";
    while (prev_permutation(s.begin(), s.end())) {
        cout << s << endl;
    }
```
此时分别输出“1234”的下一个组合以及“4321”的前一个组合。

