# ArrayManager · 一维数组综合管理器 · V0.04

# 包含AIGC内容，请谨慎辨别！

> 个人 C 语言学习项目：一个一维数组管理器。
> 版本定位：**多文件工程化**——把单文件拆成 `main.c` + `prearr.c` + `prearr.h`，按编码分目录存放；同时用 `qsort` 重写排序、用双循环重写去重。

---

## 一、目录结构

```
project/ArrayManager/
├── README.md                  本说明文档
├── GBK/                       GBK 编码工程（三个文件）
│   ├── main.c                 主函数：状态声明 + 主循环 + switch 分派
│   ├── prearr.c               全部功能函数的实现
│   └── prearr.h               宏定义 + 函数声明
├── UTF-8/                     UTF-8 编码工程（与 GBK/ 内容完全相同，仅编码不同）
│   ├── main.c
│   ├── prearr.c
│   └── prearr.h
└── ArrayManager.old/          历史版本存档
    ├── V0.01/                 初版：单文件、main 里堆满算法
    ├── V0.02/                 第一次重构：功能函数化、消除 goto
    └── V0.03/                 第二次重构：状态去全局化、指针传递长度
```

- `GBK/` 与 `UTF-8/` 下同名文件**逐行内容一致**，只有中文注释/字符串的字节编码不同（`main.c`、`prearr.h` 两个文件连字节都完全一致，只有含中文字符串的 `prearr.c` 不同）。
- `ArrayManager.old/` 是历史快照，**最新存档仍是 V0.03**；V0.04 的源码就是上面的 `GBK/` 与 `UTF-8/`。

---

## 二、功能一览

菜单功能与 V0.03 相同，未增删；但功能 4/5 与 10 的**实现方式**变了（见第六节）。

| 序号 | 功能 | 说明 |
| :--: | --- | --- |
| 1 | 显示当前数组 | 按位置逐个输出全部元素 |
| 2 | 重新输入数组 | 重新指定长度并录入元素，结束后立即回显数组 |
| 3 | 统计信息 | 总和、平均值、最大值、最小值 |
| 4 | 升序排序并输出新数组 | 把数组**复制**到临时数组后用 `qsort` 升序，只输出副本，原数组不变 |
| 5 | 降序排序并输出新数组 | 同上，改为降序 |
| 6 | 查找某个值 | 出现次数 + 所有出现位置 |
| 7 | 删除指定位置的元素 | 后续元素前移，长度减一，被空出的位置清零 |
| 8 | 在指定位置插入一个元素 | 指定位置及之后元素后移，长度加一 |
| 9 | 删除所有等于指定值的元素 | 删除全部匹配项并报告删除个数 |
| 10 | 数组去重 | 重复元素只保留第一次出现的位置 |
| 0 | 退出程序 | 结束运行 |

> 菜单里功能 4/5 写的「排序原数组并输出新数组」，这一版**真的**是排副本再输出，文案与实现终于一致了。

---

## 三、编译与运行

本版本是多文件工程，**必须把 `main.c` 和 `prearr.c` 一起编译**，只编 `main.c` 会报链接错误（找不到 `initialize`、`print_menu` 等）。

1. 用 IDE（Dev-C++ / VS Code / Code::Blocks 等）新建工程，把 `main.c` 与 `prearr.c` 一起加入；
2. 编译器标准选 **C11**（代码里用了 C99 起的变长数组，见第八节第 1 条）；
3. 编译后运行 `.exe`；请根据自己控制台的编码选择 `GBK/` 或 `UTF-8/` 目录下的源码。

命令行方式（GCC）：

```bash
# UTF-8 版
cd UTF-8
gcc -std=c11 -Wall -Wextra -Wshadow main.c prearr.c -o ArrayManager.exe

# GBK 版：源文件是 GBK 编码，必须告诉编译器输入编码
cd GBK
gcc -std=c11 -finput-charset=GBK -fexec-charset=UTF-8 main.c prearr.c -o ArrayManager.exe
```

> - 系统：Win10 / Win11（更旧的 Windows 版本应该也能跑）。
> - 程序启动后**先完成初始化**（输入数组长度 → 依次输入各元素），之后才进入功能菜单。
> - `system("cls")` / `system("pause")` 是 Windows 命令，在 Linux / macOS 下会有报错提示，但程序仍可继续使用。
> - 用 MSVC（Visual Studio）编译会卡在变长数组上，见第八节。

---

## 四、输入约束

与 V0.03 相同。

| 项目 | 约束 |
| --- | --- |
| 数组长度 | 整数，1 ~ 100 |
| 数组元素 | 双精度浮点数，-10000 ~ 10000 |
| 菜单选项 | 整数，0 ~ 10 |
| 位置索引 | 对用户从 1 开始计数 |

所有输入统一走 `get_user_input()`，以下情况都会提示并要求重新输入，不会崩溃也不会污染缓冲区：

- 非数字内容（`abc`、空输入等）；
- 数字后跟随多余字符（`3.5abc`、`5 5`）；
- 要求整数的场合输入小数（`5.5`）；
- 超出范围的数值、`nan`；
- 输入流意外结束（EOF）：提示后退出程序。

---

## 五、源码结构（V0.04）

### 1. 三个文件的分工

| 文件 | 职责 | 内容 |
| --- | --- | --- |
| `prearr.h` | 接口：宏 + 函数原型 | 9 个宏、21 个函数声明，用 `#ifndef PREARR_H` 做头文件保护 |
| `prearr.c` | 实现：所有功能函数 | `#include <stdio.h> <stdlib.h> <math.h> "prearr.h"`，21 个函数定义 |
| `main.c` | 入口：状态与流程 | 只 `#include "prearr.h"`，声明变量、调 `initialize()`、跑主循环 |

拆分后 `main.c` 只有 80 行，读代码时可以先看 `main.c` 抓住流程，需要细节再跳 `prearr.c`。

### 2. 宏定义（`prearr.h`）

| 宏 | 当前值 | 含义 |
| --- | --- | --- |
| `MAX_LENGTH` | 100 | 数组最大长度 |
| `MIN_LENGTH` | 1 | 数组最小长度 |
| `MIN_VALUE` | -10000 | 元素允许的最小值 |
| `MAX_VALUE` | 10000 | 元素允许的最大值 |
| `MIN_NUM_FUNCTION` | 0 | 菜单选项最小值 |
| `MAX_NUM_FUNCTION` | 10 | 菜单选项最大值 |
| `NUM_TAG` | 100000 | 仅作为「尚未赋值」的初始值占位，**不再是删除标记** |
| `INT_CHOICE` | 1 | 输入校验：要求整数 |
| `FLOAT_CHOICE` | 2 | 输入校验：允许浮点数 |

**与 V0.03 的差别**：`NORMAL_ORDER` / `REVERSE_ORDER` 两个排序方向宏被删掉了——排序改成两个独立函数（`sort_NormalOrder` / `sort_ReverseOrder`），不需要再用参数区分方向。

### 3. 函数框架

按「长度参数怎么传」分成两类，这是读代码时最容易混的地方：

- **`int *p_length`**：函数会**改变**长度，必须回写调用方。
- **`int arr_length`**：函数只**读**长度，按值传即可。

| 函数 | 所在文件 | 长度参数 | 作用 |
| --- | --- | --- | --- |
| `main()` | `main.c` | — | 声明局部数组与长度，取指针后调 `initialize()`，再进主循环 |
| `clear_buffer()` | `prearr.c` | — | 清空键盘缓冲区，丢弃当前行剩余字符 |
| `get_user_input(max, min, function_selection)` | `prearr.c` | — | 统一的输入读取与校验 |
| `get_user_int_input(max, min)` | `prearr.c` | — | 在 `get_user_input` 基础上要求整数 |
| `print_menu()` | `prearr.c` | — | 只负责打印主菜单 |
| `get_user_choice(int *p)` | `prearr.c` | 指针 | 读取用户选择并写入指针所指变量 |
| `function_start(int user_function_chose)` | `prearr.c` | — | 打印「你选择了功能 N」，**按值**接收 |
| `function_over()` | `prearr.c` | — | 统一收尾：暂停 + 清屏 |
| `compar_NormalOrder(a, b)` | `prearr.c` | — | `qsort` 升序比较函数 |
| `compar_ReverseOrder(a, b)` | `prearr.c` | — | `qsort` 降序比较函数 |
| `sort_NormalOrder(arr, arr_length)` | `prearr.c` | 按值 | 功能 4：复制后升序排序并输出副本 |
| `sort_ReverseOrder(arr, arr_length)` | `prearr.c` | 按值 | 功能 5：复制后降序排序并输出副本 |
| `array_print(arr, arr_length)` | `prearr.c` | 按值 | 按位置输出数组 |
| `pre_initialize(int *p_length, double arr[])` | `prearr.c` | 指针 | 输入数组长度与各元素 |
| `initialize(int *p_length, double arr[])` | `prearr.c` | 指针 | 欢迎信息 + `pre_initialize()` + 清屏 |
| `program_exit()` | `prearr.c` | — | 打印告别语并 `exit(0)` |
| `statistics(array, arr_length)` | `prearr.c` | 按值 | 功能 3：总和、平均值、最大值、最小值 |
| `search_num(arr_length, array)` | `prearr.c` | 按值 | 功能 6：查找指定值并输出次数与位置 |
| `delete_element_by_location(int *p_length, double array[])` | `prearr.c` | 指针 | 功能 7：按位置删除 |
| `insert_element(int *p_length, double array[])` | `prearr.c` | 指针 | 功能 8：按位置插入 |
| `delete_elements_by_value(int *p_length, double array[])` | `prearr.c` | 指针 | 功能 9：按值删除全部匹配项 |
| `array_unique(int *p_length, double array[])` | `prearr.c` | 指针 | 功能 10：去重 |

### 4. 主流程

```
main()
 ├── int array_length = 0;
 ├── int user_function_choice = 0;
 ├── double array[MAX_LENGTH] = {0};
 ├── int *p_length = &array_length;
 ├── int *p_user_function_choice = &user_function_choice;
 ├── initialize(p_length, array)
 └── while(1)                                        ← 唯一的主循环，靠 exit() 退出
      ├── print_menu()
      ├── get_user_choice(p_user_function_choice)     ← 指针写入
      ├── function_start(*p_user_function_choice)     ← 指针读出后按值传入
      ├── switch (user_function_choice)
      │    ├── case 0  → program_exit()
      │    ├── case 1  → array_print(array, *p_length)
      │    ├── case 2  → pre_initialize() + array_print()
      │    ├── case 3  → statistics(array, *p_length)
      │    ├── case 4  → sort_NormalOrder(array, array_length)   ← 自己打印
      │    ├── case 5  → sort_ReverseOrder(array, array_length)  ← 自己打印
      │    ├── case 6  → search_num(*p_length, array)
      │    ├── case 7  → delete_element_by_location() + array_print()
      │    ├── case 8  → insert_element() + array_print()
      │    ├── case 9  → delete_elements_by_value()              ← 自己打印
      │    └── case 10 → array_unique() + array_print()          ← 打印两次
      ├── function_over()
      └── continue
```

---

## 六、本版更新内容

1. **单文件拆成三文件工程（核心改动）**：`main.c` 只留入口与流程，功能实现全部搬进 `prearr.c`，宏与函数原型集中到 `prearr.h`。V0.03 的 463 行单文件，拆成 80 行的 `main.c` + 344 行的 `prearr.c` + 37 行的 `prearr.h`。

   ```c
   // prearr.h：接口全部集中声明，函数定义前先让编译器认识它们
   #ifndef PREARR_H
   #define PREARR_H
   void array_print(double arr[], int arr_length);
   ...
   #endif
   ```

2. **按编码分目录**：原来靠 `ArrayManager-GBK.c` / `ArrayManager-UTF8.c` 两份单文件区分编码，现在改成 `GBK/` 与 `UTF-8/` 两个完整工程目录，各自都含三个文件，避免出现「改了 UTF-8 忘了同步 GBK」的情况（两份 `prearr.c` 除编码外逐行一致）。

3. **冒泡排序换成 `qsort`**：删掉原 `bubble_sort(arr, n, require_order)` 的 `switch(require_order)` 写法，改为「两个比较函数 + 两个排序函数」，用 `qsort` 排序。

   ```c
   int compar_NormalOrder(const void *a, const void *b)
   {
       double x = *(const double *)a;
       double y = *(const double *)b;
       return (x > y) - (x < y);
   }
   ```

   比较函数里 `(x>y)-(x<y)` 是核心技巧：升序返回 -1/0/1，不会出现直接相减导致的整数溢出，也不会出现 `double` 相减再转 `int` 的截断问题。

4. **排序改为「排副本」，不再破坏原数组**：`sort_NormalOrder()` 先 `double temp_arr[arr_length];` 复制，再 `qsort` 副本，最后只打印副本。

   ```c
   void sort_NormalOrder(double arr[], int arr_length)
   {
       double temp_arr[arr_length];        // C99 变长数组
       for (int i = 0; i < arr_length; i++) temp_arr[i] = arr[i];
       qsort(temp_arr, arr_length, sizeof(double), compar_NormalOrder);
       array_print(temp_arr, arr_length);
   }
   ```

   于是菜单文案「排序原数组并输出新数组」第一次名副其实：排完之后再选功能 1，看到的还是原始顺序。

5. **去重改为双循环 + 写指针，去掉哨兵值**：V0.03 是把 `NUM_TAG`(100000) 写进数组当「已删除」标记，再扫描覆盖；现在改成标准的原地去重算法，用 `write` 记录写入位置，把每个元素和「已保留的前缀」逐个比对。

   ```c
   void array_unique(int *p_length, double array[])
   {
       if (p_length == NULL) return;
       int len = *p_length, write = 0, j;
       for (int i = 0; i < len; i++) {
           for (j = 0; j < write; j++)
               if (array[j] == array[i]) break;
           if (j == write) { array[write] = array[i]; write++; }
       }
       *p_length = write;
       for (int i = write; i < MAX_LENGTH; i++) array[i] = 0.0;   // 尾部清零
   }
   ```

   不再依赖「100000 一定大于元素上限」这个隐含前提，去重结果与元素取值范围解耦。

6. **`search_num()` 去掉临时位置数组**：V0.03 先存 `int array_location[MAX_LENGTH]` 再统一输出，现在边扫边打印命中位置，省掉 400 字节缓冲，也少一次遍历。

7. **只读长度参数全部改成按值传递**：`array_print`、`statistics`、`search_num`、`sort_NormalOrder`、`sort_ReverseOrder` 的长度参数从 `int *` 改为 `int`；只有真正修改长度的 5 个函数（`pre_initialize`、`delete_element_by_location`、`insert_element`、`delete_elements_by_value`、`array_unique`）保留 `int *p_length`。接口意图一眼可辨：传指针 = 会被改，传值 = 只读。

8. **主循环去掉内层 `while(1)`**：V0.03 用「外层管菜单 + 内层管一次功能 + `break`」的结构，而内层恒只跑一轮，属于形式上的嵌套。现在只剩一层 `while(1)`，`switch` 后直接 `function_over(); continue;`。

9. **长度边界保护更完整**：
   - `delete_element_by_location()` 开头 `if (*p_length <= 1)` 直接拒绝删除，避免把数组删到长度 0；
   - 删除后 `array[*p_length] = 0.0`，把腾出来的位置清零；
   - `delete_elements_by_value()` 结束时若 `*p_length < MAX_LENGTH` 也清零尾位；
   - `array_unique()` 在长度之外把整个剩余数组清零。

10. **编译告警保持为 0**：`gcc -std=c11 -Wall -Wextra -Wshadow` 下无告警，GBK 版加 `-finput-charset=GBK -fexec-charset=UTF-8` 同样 0 告警。

---

## 七、验证记录

- **编译**：GCC 16.1.0（MinGW-W64 x86_64 UCRT）分别编译两个目录，均通过、退出码 0：

  ```
  gcc -std=c11 -Wall -Wextra -Wshadow main.c prearr.c                 → 0 告警
  gcc -std=c11 -Wall -Wextra -Wshadow -finput-charset=GBK -fexec-charset=UTF-8 main.c prearr.c → 0 告警
  ```

- **编码一致性**：把 `GBK/prearr.c` 按 GBK 解码后与 `UTF-8/prearr.c` 逐行比对，差异 0 行；`main.c`、`prearr.h` 两目录下字节完全相同。

- **功能回归**：以 `5` 个元素 `3 1 2 2 5` 完成初始化，依次执行功能 3 → 4 → 5 → 1 → 6 → 7 → 8 → 10 → 9 → 0：

  | 操作 | 结果 |
  | --- | --- |
  | 功能 3 统计 | 总和 13、平均 2.6、最大 5、最小 1 |
  | 功能 4 升序 | `1 2 2 3 5` |
  | 功能 5 降序 | `5 3 2 2 1` |
  | 功能 1 显示 | 仍是 `3 1 2 2 5`——证明功能 4/5 没有改动原数组 |
  | 功能 6 查找 2 | 出现 2 次，位于第 3、4 位 |
  | 功能 7 删除第 2 位 | `3 2 2 5` |
  | 功能 8 第 3 位插入 9.5 | `3 2 9.5 2 5` |
  | 功能 10 去重 | `3 2 9.5 5` |
  | 功能 9 删除 3 | 删除 1 个，剩 `2 9.5 5` |

- **边界回归一（删空数组）**：初始化为 `7 7`，用功能 9 把两个元素都删掉，提示「共计删除了 2 个元素」并提醒长度已小于最小值；随后依次执行功能 3 / 4 / 10 / 1，程序均正常返回菜单，无崩溃、无越界输出——功能 3 提示「数组长度小于最小值」，功能 4 与 1 输出空表（只有分隔线），功能 10 仍提示去重成功（问题见第八节第 2 条）。

- **边界回归二（长度为 1）**：初始化为 `1` 个元素 `5`，功能 7 被拒绝并提示「数组长度为最小值，无法进行删除！」；随后功能 8 在末位插入 `2.5`，得到 `5 2.5`，正确。

> 测试方式：把输入序列通过管道喂给程序（`pause` 在重定向 stdin 时会立即返回），采集完整输出后逐条核对上表。

---

## 八、已知问题与待改进

1. **`temp_arr` 用变长数组，长度 0 时是未定义行为**：`sort_*Order()` 里 `double temp_arr[arr_length]` 是 C99 变长数组。数组被删空后（长度 0）执行功能 4/5，会创建一个零长 VLA——GCC 下实测不崩，但标准上未定义；同时 MSVC 根本不支持 VLA，换到 Visual Studio 会直接编译不过。更稳的写法是固定 `double temp_arr[MAX_LENGTH]`，或加一句长度判断。

2. **空数组时功能 10 仍报成功**：长度为 0 时执行去重，会打印「操作成功！数组已成功去重！」，实际没有任何元素被处理。`search_num()` 有 `arr_length == 0` 的判断，`array_unique()` 没有，补一句即可。

3. **功能 10 的数组被打印两次**：`array_unique()` 内部调了一次 `array_print()`，`main.c` 的 `case 10` 又调了一次，屏幕上同一份数组连续出现两遍。功能 9 的打印则只在函数内部，两个功能的输出约定不统一——要么都「谁改谁打印」，要么都交给 `case` 打印。

4. **`main` 中两种取值方式并存**：`switch (user_function_choice)` 直接读局部变量，而 `function_start(*p_user_function_choice)` 通过指针读同一变量；`case 4/5` 的 `sort_*(array, array_length)` 也直接读局部变量。当前二者永远相等，但风格不统一，若将来把变量搬到别处，这些直接引用会静默失效。既然 `*p_...` 已在手边，全部用它更一致。

5. **`continue;` 冗余**：主循环末尾的 `continue` 与 `while(1)` 自然回到循环头效果相同，删掉更干净；`case 0` 里的 `break` 也因为 `program_exit()` 内部调了 `exit(0)` 而不可达。

6. **`switch` 没有 `default`**：选项已被限制在 0~10，`case` 也覆盖齐了 0~10，所以不会走到别处；但若将来改了 `MAX_NUM_FUNCTION` 而忘了加 `case`，用户会看到「你选择了功能 11」后什么都不发生。留一个提示性的 `default` 更稳妥。

7. **`p_length == NULL` 检查与 `array_unique` 的唯一性**：`array_unique()` 开头的 `if (p_length == NULL) return;` 只在指针为空时生效，其他函数都没有同类检查，风格不一致且实际调用点不可能传 `NULL`。

8. **局部变量与指针同名易混**：`main` 里 `array_length` 与 `p_length` 同时存在，函数参数里有的叫 `arr_length`、有的叫 `*p_length`，新手阅读时需要在脑中来回换算。

9. **`NUM_TAG` 名不副实**：它已经不再充当「删除标记」，只用来给 `num_location`、`num_del` 之类的局部变量填初值；继续叫 `TAG` 容易让人误以为是数据标记。用 `0` / `-1` 或干脆不初始化更清楚。

10. **重新输入更短的数组时旧元素残留**：超出新长度以外的旧元素仍留在数组里，只是打印受长度约束看不见（去重和删除会清零尾部，`pre_initialize()` 不会）。

11. **容量仍为固定数组**：没有动态分配，`MAX_LENGTH` 是编译期常量。

12. **平台相关调用**：`system("cls")` / `system("pause")` 仅适用于 Windows。

13. **历史存档缺 V0.04**：`ArrayManager.old/` 目前只到 V0.03，本版本尚未存档。

---

## 九、学习记录

- **20261002** 程序完工（V0.01）：写于学习一维数组阶段（课本：《C语言程序设计基础》清华大学出版社），涉及数组越界、冒泡排序。
- **20261005** 第一次重构（V0.02）：功能函数化、消除 `goto`、统一输入校验。
- **20261023** 第二次重构（V0.03）：把全局状态收进 `main()`，改用指针在函数间传递长度；`main` 中的 `function_start()` / `function_over()` 去重。
- **20261124** 第三次重构（V0.04）：拆分 `main.c` / `prearr.c` / `prearr.h`，按编码分目录；`bubble_sort` 换成 `qsort`（排副本），去重去掉哨兵值；接口按「是否改长度」区分传指针还是传值。

### 后续更新计划

- 给 `sort_*Order()` 换掉 VLA，改用固定缓冲或直接判断长度，兼容 MSVC；
- 统一功能 9 / 10 的打印职责，消除重复输出；
- 空数组时让功能 10 提前返回并提示；
- 统一 `main` 中长度的取值方式，全部走 `*p_length`，删掉多余的 `continue`；
- `pre_initialize()` 重新输入时把新长度之外的旧元素清零；
- 学习结构体后，把「数组 + 长度」打包成一个整体，彻底不需要到处传两个参数。

---

## 十、更新记录

- 20261002 程序完工，等待后续重构优化。
- 20261002 源码拆分 GBK / UTF-8 两个编码版本，补充说明文档。
- 20261005 V0.02：第一次重构完成。
- 20261023 V0.03：状态去全局化 + 指针传递长度。
- 20261124 V0.04：拆分为多文件工程（`main.c` / `prearr.c` / `prearr.h`），按编码分目录；排序改用 `qsort` 并改为排副本；去重改为双循环原地去重；只读长度参数改为按值传递（本版本）。

> 注：`ArrayManager.old/V0.03/` 为 V0.03 的源码与说明存档快照；V0.04 暂未存档。

---

## 声明

本项目为个人 C 语言学习记录，代码仅用于学习与交流。源码可按需自由使用、修改与分发。
