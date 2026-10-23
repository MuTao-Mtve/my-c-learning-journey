# ArrayManager · 一维数组综合管理器 · V0.03

# 包含AIGC内容，请谨慎辨别！

> 个人 C 语言学习项目：一个一维数组管理器。
> 版本定位：**状态管理重构版**——把上一版残留的全局变量收进 `main()`，改用指针在函数间传递。

---

## 一、目录结构

```
project/ArrayManager/
├── ArrayManager-GBK.c          GBK 编码源代码（当前版本）
├── ArrayManager-UTF8.c         UTF-8 编码源代码（当前版本）
└── ArrayManager.old/           历史版本
    ├── V0.01/                  初版：单文件、main 里堆满算法
    ├── V0.02/                  第一次重构：功能函数化、消除 goto
    └── V0.03/                  本版本快照（源码 + 本文件）
```

`V0.03/` 内是当前源码的存档副本，与本目录下的两份 `.c` 完全一致（已用哈希核对）。

---

## 二、功能一览

功能与 V0.02 相同，未增删。

| 序号 | 功能 | 说明 |
| :--: | --- | --- |
| 1 | 显示当前数组 | 按位置逐个输出全部元素 |
| 2 | 重新输入数组 | 重新指定长度并录入元素，结束后立即回显数组 |
| 3 | 统计信息 | 总和、平均值、最大值、最小值 |
| 4 | 升序排序并输出 | 冒泡排序（就地升序）后输出 |
| 5 | 降序排序并输出 | 冒泡排序（就地降序）后输出 |
| 6 | 查找某个值 | 出现次数 + 所有出现位置 |
| 7 | 删除指定位置的元素 | 后续元素前移，长度减一，被空出的位置清零 |
| 8 | 在指定位置插入一个元素 | 指定位置及之后元素后移，长度加一 |
| 9 | 删除所有等于指定值的元素 | 删除全部匹配项并报告删除个数 |
| 10 | 数组去重 | 重复元素只保留第一次出现的位置 |
| 0 | 退出程序 | 结束运行 |

> 菜单里功能 4/5 写的是「排序原数组并输出新数组」，但实现仍是**就地排序**，没有生成新数组，属于文案瑕疵（见第八节）。

---

## 三、编译与运行

1. 用 IDE（Dev-C++ / VS Code / Code::Blocks 等）打开 `.c` 文件；
2. 编译器标准选 C11；
3. 编译后运行 `.exe`；请根据自己控制台的编码选择 GBK 或 UTF-8 那份源码。

> - 系统：Win10 / Win11（更旧的 Windows 版本应该也能跑）。
> - 程序启动后**先完成初始化**（输入数组长度 → 依次输入各元素），之后才进入功能菜单。
> - `system("cls")` / `system("pause")` 是 Windows 命令，在 Linux / macOS 下会有报错提示，但程序仍可继续使用。
> - 用 GCC 编译 GBK 版需加参数：`-finput-charset=GBK -fexec-charset=UTF-8`。

---

## 四、输入约束

与 V0.02 相同。

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

## 五、源码结构（V0.03）

### 1. 宏定义（文件顶部）

| 宏 | 当前值 | 含义 |
| --- | --- | --- |
| `MAX_LENGTH` | 100 | 数组最大长度 |
| `MIN_LENGTH` | 1 | 数组最小长度 |
| `MIN_VALUE` | -10000 | 元素允许的最小值 |
| `MAX_VALUE` | 10000 | 元素允许的最大值 |
| `MIN_NUM_FUNCTION` | 0 | 菜单选项最小值 |
| `MAX_NUM_FUNCTION` | 10 | 菜单选项最大值 |
| `NUM_TAG` | 100000 | 去重用的哨兵标记值 |
| `INT_CHOICE` | 1 | 输入校验：要求整数 |
| `FLOAT_CHOICE` | 2 | 输入校验：允许浮点数 |
| `NORMAL_ORDER` | 1 | 排序方向：升序 |
| `REVERSE_ORDER` | 2 | 排序方向：降序 |

**与 V0.02 的差别**：文件顶部不再有全局变量。

| 版本 | 文件顶部的状态变量 |
| --- | --- |
| V0.02 | `int array_length`、`int user_function_choice`、`double array[MAX_LENGTH]`（均为全局） |
| V0.03 | **无**——三者全部移入 `main()` 成为局部变量 |

### 2. 函数框架

带 `*p` 的参数表示「通过指针读写的长度变量」。

| 函数 | 作用 |
| --- | --- |
| `clear_buffer()` | 清空键盘缓冲区，丢弃当前行剩余字符 |
| `get_user_input(max, min, function_selection)` | 统一的输入读取与校验 |
| `get_user_int_input(max, min)` | 在 `get_user_input` 基础上要求整数 |
| `print_menu()` | 只负责打印主菜单 |
| `get_user_choice(int *p)` | 读取用户选择，**写入指针所指变量** |
| `function_start(int *p)` | 打印「你选择了功能 N」，值由指针读入 |
| `function_over()` | 分支统一收尾：暂停 + 清屏，返回主菜单 |
| `bubble_sort(arr, n, require_order)` | 冒泡排序，按 `NORMAL_ORDER` / `REVERSE_ORDER` 决定方向 |
| `array_print(double arr[], int *p)` | 按位置输出数组，长度由指针读入 |
| `pre_initialize(int *p_length, double arr[])` | 输入数组长度与各元素 |
| `initialize(int *p_length, double arr[])` | 欢迎信息 + `pre_initialize()` + 清屏 |
| `program_exit()` | 打印告别语并 `exit(0)` |
| `statistics(double array[], int *p_length)` | 功能 3：总和、平均值、最大值、最小值 |
| `search_num(int *p_length, double array[])` | 功能 6：查找指定值并输出次数与位置 |
| `delete_element_by_location(int *p_length, double array[])` | 功能 7：按位置删除 |
| `insert_element(int *p_length, double array[])` | 功能 8：按位置插入 |
| `delete_elements_by_value(int *p_length, double array[])` | 功能 9：按值删除全部匹配项 |
| `array_unique(int *p_length, double array[])` | 功能 10：去重 |
| `main()` | 声明局部数组与长度，取指针后调 `initialize()`，再进主循环 |

### 3. 主流程

```
main()
 ├── int array_length = 0;
 ├── int user_function_choice = 0;
 ├── double array[MAX_LENGTH] = {0};
 ├── int *p_length = &array_length;                      ← 取地址
 ├── int *p_user_function_choice = &user_function_choice;
 ├── initialize(p_length, array)
 └── while(1)                                             ← 外层：管菜单
      ├── print_menu()
      ├── get_user_choice(p_user_function_choice)
      └── while(1)                                        ← 内层：管一次功能执行
           ├── function_start(p_user_function_choice)
           ├── switch (user_function_choice)
           │    ├── case 0  → program_exit()
           │    ├── case 1  → array_print(array, p_length)
           │    ├── case 2  → pre_initialize() + array_print()
           │    ├── case 3  → statistics(array, p_length)
           │    ├── case 4  → bubble_sort(NORMAL_ORDER)  + array_print()
           │    ├── case 5  → bubble_sort(REVERSE_ORDER) + array_print()
           │    ├── case 6  → search_num(p_length, array)
           │    ├── case 7  → delete_element_by_location() + array_print()
           │    ├── case 8  → insert_element() + array_print()
           │    ├── case 9  → delete_elements_by_value()
           │    ├── case 10 → array_unique() + array_print()
           │    └── default  → 提示重新选择
           ├── function_over()
           └── break                                        ← 内层只跑一轮
```

各 `case` 内不再出现 `function_start()` 和 `function_over()`，二者被提到 `switch` 前后各执行一次。

---

## 六、本版更新内容

1. **状态去全局化（核心改动）**：`array_length` 与 `user_function_choice` 由全局变量改为 `main()` 的局部变量，`array[]` 成为 `main()` 的局部数组。全局只剩宏定义，没有任何可变全局状态。
2. **指针传递长度**：所有会改变长度的函数（`pre_initialize`、`delete_element_by_location`、`insert_element`、`delete_elements_by_value`、`array_unique`）都改为接收 `int *p_length`，用 `(*p_length)--` / `(*p_length)++` 直接回写调用方的变量。
3. **只读函数按值/按指针读长度**：`array_print`、`function_start`、`get_user_choice` 接收指针只读；`bubble_sort` 仍按值接收 `int n`，因为排序不改变长度。
4. **主循环整理**：新增内层 `while(1)` 包住 `switch`，把 `function_start()` 与 `function_over()` 从每个 `case` 里提出来统一调用，`case` 内代码明显变短。

   ```c
   // V0.02：每个 case 都重复这两句
   case 1: { function_start(); array_print(); function_over(); break; }

   // V0.03：提到 switch 外
   while(1) {
       function_start(p_user_function_choice);
       switch (...) { case 1: { array_print(array, p_length); break; } ... }
       function_over();
       break;      // ← 内层只执行一轮
   }
   ```

5. **编译告警保持为 0**：`gcc -std=c11 -Wall -Wextra -Wshadow` 下无告警（V0.01 为 3 条）。

---

## 七、验证记录

- **编译**：UTF-8 / GBK 两份源码分别用 GCC 编译，均通过，退出码 0；`-Wall -Wextra -Wshadow` 下告警 0 条。
- **功能回归**：以 `5` 个元素 `3 1 2 2 5` 完成初始化后，依次执行功能 1/3/4/5/6/7/8/10/9 再退出，结果与预期一致：

  | 操作 | 结果 |
  | --- | --- |
  | 功能 3 统计 | 总和 13、平均 2.6、最大 5、最小 1 |
  | 功能 4 升序 | `1 2 2 3 5` |
  | 功能 5 降序 | `5 3 2 2 1` |
  | 功能 6 查找 2 | 出现 2 次，位于第 3、4 位 |
  | 功能 7 删除第 2 位 | `5 2 2 1` |
  | 功能 8 第 3 位插入 9.5 | `5 2 9.5 2 1` |
  | 功能 10 去重 | `5 2 9.5 1` |
  | 功能 9 删除 3（此时已不存在） | 提示未找到 |

- **边界回归**：初始化为 `7 7` 后用功能 9 删空数组，再依次执行功能 3/4/10/1，程序均正常返回菜单，无崩溃、无越界输出——功能 3 提示「数组长度小于最小值」，功能 4 与 1 静默返回，功能 10 提示去重成功。

---

## 八、已知问题与待改进

1. **内层 `while(1)` 实际只跑一轮**：`switch` 后的 `break` 使这个循环恒定执行一次，等价于普通语句块。功能正确，但多一层循环 + 一个 `break`，读者容易误以为内层会重复执行。可改为直接写语句块或用 `do { } while(0)`。
2. **`main` 中两种取值方式并存**：`switch (user_function_choice)` 直接读局部变量，而 `function_start(p_user_function_choice)` 通过指针读同一变量；`case 4/5` 的 `bubble_sort(array, array_length, ...)` 同样直接读局部变量。当前二者永远相等，但风格不统一，且若将来把变量搬到别处，这些直接引用会静默失效。
3. **局部变量与指针同名易混**：`main` 里 `array_length` 与 `p_length` 同时存在，函数参数里 `array_length`（V0.02 的写法）已全部改为 `*p_length`，新手阅读时需要在脑中来回换算。
4. **去重仍用数据值当删除标记**：`array_unique()` 把 `NUM_TAG`(100000) 写回数组作「已处理」标记，仅因 100000 落在允许范围 -10000~10000 之外才安全；若放宽元素上限到 ≥100000，去重会静默出错。
5. **查找函数的标记数组冗余**：`search_num()` 里的 `int array_location[MAX_LENGTH]` 只为记录命中位置，一次循环即可直接输出；`MAX_LENGTH` 为 100 时白占 400 字节。
6. **菜单文案与实现不符**：功能 4/5 写「排序原数组并输出新数组」，实际是就地排序。
7. **空数组时功能 10 仍报成功**：数组长度为 0 时执行去重，会打印「操作成功！数组已成功去重！」并回显空数组，而实际没有任何元素被处理。
8. **`default` 分支不可达**：选择范围已被限制在 0~10，该分支实际不会执行。
9. **重新输入更短的数组时旧元素残留**：超出新长度以外的旧元素仍留在数组里，只是打印受长度约束看不见。
10. **容量仍为固定数组**：没有动态分配，`MAX_LENGTH` 是编译期常量。
11. **平台相关调用**：`system("cls")` / `system("pause")` 仅适用于 Windows。

---

## 九、学习记录

- **20261002** 程序完工（V0.01）：写于学习一维数组阶段（课本：《C语言程序设计基础》清华大学出版社），涉及数组越界、冒泡排序。
- **20261005** 第一次重构（V0.02）：功能函数化、消除 `goto`、统一输入校验。
- **20261023** 第二次重构（V0.03）：把全局状态收进 `main()`，改用指针在函数间传递长度；`main` 中的 `function_start()` / `function_over()` 去重。

### 后续更新计划

- 优化去重算法，消除对哨兵值 `NUM_TAG` 的依赖，改用双循环或标记数组；
- 让 `search_num()` 去掉多余的 `array_location` 数组，边扫边输出；
- 统一 `main` 中长度的取值方式，全部走指针，消除直接引用；
- 去掉内层多余循环；
- 学习结构体后，把「数组 + 长度」打包成一个整体，彻底不需要到处传两个参数。

---

## 十、更新记录

- 20261002 程序完工，等待后续重构优化。
- 20261002 源码拆分 GBK / UTF-8 两个编码版本，补充说明文档。
- 20261005 V0.02：第一次重构完成。
- V0.03：状态去全局化 + 指针传递长度（本版本）。

> 注：`ArrayManager.old/V0.03/` 为本版本源码与说明的存档快照。

---

## 声明

本项目为个人 C 语言学习记录，代码仅用于学习与交流。源码可按需自由使用、修改与分发。
