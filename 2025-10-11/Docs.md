# 代码说明文档

------

**本文档介绍了各个程序的功能 并附有详细的代码注释**

------

### Test-01.c

> 该程序演示了 `sizeof` 运算符的用法 用于获取并打印 C 语言中各种基本数据类型所占用的内存大小 (以字节为单位 )

```
// 包含标准输入输出头文件 用于支持 printf 函数
#include <stdio.h>
// 包含布尔类型头文件 虽然本例未使用 bool 变量 但 sizeof(_Bool) 依赖于此
#include <stdbool.h>

// 主函数 程序执行的入口
int main() 
{
    // sizeof 是一个运算符 它返回一个数据类型或变量所占用的字节数
    // %zd 是一个格式说明符 用于安全地打印 sizeof 返回的 size_t 类型的值

    // 打印 char (字符) 类型的大小C 标准规定它总是 1 字节
    printf("char: %zd byte\n", sizeof(char));

    // 打印 _Bool (布尔) 类型的大小它通常占用 1 字节
    printf("_Bool: %zd byte\n", sizeof(_Bool));

    // 打印 short (短整型) 类型的大小
    printf("short: %zd bytes\n", sizeof(short));

    // 打印 int (整型) 类型的大小在 32 位和 64 位系统上通常是 4 字节
    printf("int: %zd bytes\n", sizeof(int));

    // 打印 long (长整型) 类型的大小其大小可能因系统架构 (32位/64位 )而异
    printf("long: %zd bytes\n", sizeof(long));

    // 打印 long long (更长的整型) 类型的大小通常是 8 字节
    printf("long long: %zd bytes\n", sizeof(long long));

    // 打印 float (单精度浮点型) 类型的大小
    printf("float: %zd bytes\n", sizeof(float));

    // 打印 double (双精度浮点型) 类型的大小
    printf("double: %zd bytes\n", sizeof(double));

    // 打印 long double (长双精度浮点型) 类型的大小其大小依赖于具体的编译器和平台
    printf("long double: %zd bytes\n", sizeof(long double));

    // 程序正常结束
    return 0;
}
```

------

### Test-02.c

> 该程序用于演示 C 语言中其他类型向布尔类型 (`bool`) 的隐式转换规则

```
// 包含标准输入输出头文件
#include <stdio.h>
// 包含布尔类型头文件 用于使用 bool 类型
#include <stdbool.h>

// 主函数 程序入口
int main() 
{
    // 在C语言中 当数值被转换为布尔类型时：
    // 0 会被转换为 false (其整数值为 0)
    bool a = 0; 
    // 任何非零值 (无论是正数还是负数) 都会被转换为 true (其整数值为 1)
    bool b = 100;
    bool c = -50;
    // true 本身就是布尔真值
    bool d = true;

    // 使用 %d 打印布尔变量的底层整数值 (0 或 1)
    printf("a (0) -> %d\n", a);     // 输出 0
    printf("b (100) -> %d\n", b);   // 输出 1
    printf("c (-50) -> %d\n", c);   // 输出 1
    printf("d (true) -> %d\n", d);  // 输出 1

    // 程序正常结束
    return 0;
}
```

------

### Test-03.c

> 该程序演示了 `sizeof` 运算符的两种语法：可以对数据类型使用 也可以对变量或表达式使用

```
// 包含标准输入输出头文件
#include <stdio.h>

// 主函数入口
int main() 
{
    // 定义一个整型变量
    int num = 100;

    // 使用 sizeof 获取 int 数据类型的大小注意 对类型名使用时 括号是必需的
    printf("sizeof(int): %zu\n", sizeof(int));

    // 使用 sizeof 获取变量 num 的大小对变量使用时 括号是可选的
    printf("sizeof(num): %zu\n", sizeof(num));
    
    // 这是对变量使用 sizeof 的另一种形式 省略了括号
    printf("sizeof num: %zu\n", sizeof num);

    // 程序正常结束
    return 0;
}
```

------

### Test-04.c

> 该程序揭示了 `sizeof` 运算符的一个重要特性：其内部的表达式在编译时求值 并不会在运行时执行

```
// 包含标准输入输出头文件
#include <stdio.h>

// 主函数入口
int main() 
{
    // 定义一个整型变量并初始化为 10
    int x = 10;

    // sizeof(x++)：sizeof 在编译阶段就已经确定了表达式 x++ 的结果类型 (这里是 int ) 
    // 并返回该类型的大小表达式本身 (即 x++ 的自增操作 )不会被执行
    printf("%zd\n", sizeof(x++));

    // 因为上一行的 x++ 没有被执行 所以 x 的值仍然是 10
    printf("%d\n", x);

    // 程序正常结束
    return 0;
}
```

------

### Test-05.c

> 该程序与 `Test-04.c` 类似 进一步证明 `sizeof` 内部的表达式 (包括赋值操作 )不会在运行时执行

```
// 包含标准输入输出头文件
#include <stdio.h>

// 主函数入口
int main() 
{
    // 定义短整型和整型变量
    short s = 10;
    int num = 100;

    // sizeof(s = num + 2)：编译器仅分析表达式 `s = num + 2` 的结果类型
    // 这个表达式的结果类型是赋值运算符左侧变量 `s` 的类型 即 short
    // 因此 sizeof 返回 short 类型的大小赋值操作 `s = num + 2` 本身不会被执行
    printf("%zd\n", sizeof(s = num + 2));

    // 由于上一行的赋值操作没有执行 变量 s 的值仍然是其初始值 10
    printf("%hd\n", s); // 使用 %hd 打印 short 类型

    // 程序正常结束
    return 0;
}
```

------

### Test-06.c

> 该程序演示了对字面量 (literal )使用 `sizeof` 运算符 并揭示了 C 语言中不同字面量的默认类型

```
// 包含标准输入输出头文件
#include <stdio.h>

// 主函数入口
int main() 
{
    // sizeof(100)：100 是一个整数字面量 其默认类型是 int
    // 所以 这里打印的是 int 类型的大小
    printf("sizeof(100): %zd\n", sizeof(100));

    // sizeof(3.14)：3.14 是一个浮点数字面量 其默认类型是 double 而不是 float
    // 所以 这里打印的是 double 类型的大小
    printf("sizeof(3.14): %zd\n", sizeof(3.14));

    // sizeof('A')：'A' 是一个字符字面量 在C语言中 其类型被视为 int
    // 这与 C++ 不同 (在C++中是 char 类型 )所以 这里打印的是 int 类型的大小
    printf("sizeof('A'): %zd\n", sizeof('A'));
    
    // 作为对比 直接打印 char 类型的大小
    printf("sizeof(char): %zd\n", sizeof(char));

    // 程序正常结束
    return 0;
}
```

------

### Test-07.c

> 该程序演示了无符号整数 (`unsigned int`) 的溢出行为 也称为“回绕” (wrap-around )现象

```
// 包含标准输入输出头文件
#include <stdio.h>
// 包含 limits.h 头文件 用于访问 UINT_MAX 等表示数据类型范围的宏
#include <limits.h>

// 主函数入口
int main() 
{
    // 获取 unsigned int 类型的最大值和最小值
    unsigned int max = UINT_MAX;
    unsigned int min = 0;

    printf("UINT_MAX: %u\n", max);

    // 当无符号整数达到最大值后再加 1 它会“回绕”到最小值 0
    // 这种行为是定义良好的 符合模运算规则
    unsigned int a = max + 1;
    printf("max + 1 = %u\n", a); // 输出 0

    // 当无符号整数为最小值 0 时再减 1 它会“回绕”到最大值 UINT_MAX
    unsigned int b = min - 1;
    printf("min - 1 = %u\n", b); // 输出 UINT_MAX 的值

    // 程序正常结束
    return 0;
}
```

------

### Test-08.c

> 该程序演示了将一个负数赋值给无符号整型变量时会发生什么

```
// 包含标准输入输出头文件
#include <stdio.h>

// 主函数入口
int main() 
{
    // 定义一个有符号整型变量并赋值为 -100
    int a = -100;
    // 使用 %d 正常打印有符号整数
    printf("%d\n", a);

    // 将 -100 赋值给一个无符号整型变量 b
    // 编译器会根据内存中的二进制补码表示来解释这个值
    // -100 的补码在一个 32 位系统上是一个非常大的正数
    unsigned int b = -100;
    // 使用 %u 以无符号十进制形式打印 b 的值 会看到这个很大的正数
    printf("%u\n", b);

    // 程序正常结束
    return 0;
}
```

------

### Test-09.c

> 该程序展示了使用 `printf` 时 格式说明符 (`%d` 或 `%u`) 与变量实际类型不匹配可能导致的输出结果

```
// 包含标准输入输出头文件
#include <stdio.h>

// 主函数入口
int main() 
{
    int a = 100;
    int b = -100;
    unsigned int c = 100;
    unsigned int d = -100; // d 存储的是 -100 对应的二进制补码的大正数

    // %d 匹配有符号 int 正常输出 100
    printf("%d\n", a);

    // %u 要求以无符号形式解释 b 的内存
    // -100 的二进制补码被当作一个大正数来打印
    printf("%u\n", b);
    
    // %d 要求以有符号形式解释 c 的内存
    // 因为 100 在 int 的正数范围内 所以可以正常输出 100
    printf("%d\n", c);

    // %u 匹配无符号 int 正常输出 d 的值 (那个由 -100 转换来的大正数 )
    printf("%u\n", d);

    // 程序正常结束
    return 0;
}
```

------

### Test-10.c

> 该程序通过包含 `<limits.h>` 头文件 打印出 C 语言中所有标准整型数据类型的最小值和最大值

```
// 包含标准输入输出头文件
#include <stdio.h>
// 包含 limits.h 头文件 其中定义了各种整型范围的宏
#include <limits.h>

// 主函数入口
int main() 
{
    // 打印 char 类型的范围
    printf("SCHAR_MIN: %d\n", SCHAR_MIN);   // 有符号 char 最小值
    printf("SCHAR_MAX: %d\n", SCHAR_MAX);   // 有符号 char 最大值
    printf("UCHAR_MAX: %u\n\n", UCHAR_MAX); // 无符号 char 最大值

    // 打印 short 类型的范围
    printf("SHRT_MIN: %d\n", SHRT_MIN);     // 有符号 short 最小值
    printf("SHRT_MAX: %d\n", SHRT_MAX);     // 有符号 short 最大值
    printf("USHRT_MAX: %u\n\n", USHRT_MAX); // 无符号 short 最大值

    // 打印 int 类型的范围
    printf("INT_MIN: %d\n", INT_MIN);       // 有符号 int 最小值
    printf("INT_MAX: %d\n", INT_MAX);       // 有符号 int 最大值
    printf("UINT_MAX: %u\n\n", UINT_MAX);   // 无符号 int 最大值

    // 打印 long 类型的范围 (使用 %ld 和 %lu)
    printf("LONG_MIN: %ld\n", LONG_MIN);     // 有符号 long 最小值
    printf("LONG_MAX: %ld\n", LONG_MAX);     // 有符号 long 最大值
    printf("ULONG_MAX: %lu\n\n", ULONG_MAX); // 无符号 long 最大值
    
    // 打印 long long 类型的范围 (使用 %lld 和 %llu)
    printf("LLONG_MIN: %lld\n", LLONG_MIN);   // 有符号 long long 最小值
    printf("LLONG_MAX: %lld\n", LLONG_MAX);   // 有符号 long long 最大值
    printf("ULLONG_MAX: %llu\n\n", ULLONG_MAX);// 无符号 long long 最大值

    // 程序正常结束
    return 0;
}
```

------

