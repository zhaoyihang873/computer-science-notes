# CS:APP Data Lab

这里使用《深入理解计算机系统》第三版的 [CMU 官方自学包](https://csapp.cs.cmu.edu/3e/labs.html)。先阅读 [实验说明](datalab.pdf) 和 [bits.c](bits.c) 中每道题的约束，然后只在 `bits.c` 里写自己的实现。官方目录说明在 [README](README) 中。

## 在 WSL 中自测

在当前目录执行以下命令。Makefile 已适配 x86-64 WSL，可使用现有的 GCC、Make 和 Perl。

```bash
make
./btest -f bitXor
./dlc -e bits.c
./driver.pl
```

- `btest -f 函数名` 检查单题的运行结果。直接运行 `./btest` 检查全部题目。它会列出错误输入和预期结果。
- `dlc -e` 检查可用运算符、用法和运算次数。每题的规则以 `bits.c` 中的注释为准。
- `driver.pl` 会在临时目录给出正确性分和运算次数合规分。
- `./ishow 0x12345678` 查看整数的位表示；`./fshow 1.5` 查看浮点的符号位、阶码和尾数。

## 在 CLion 中构建

重新加载 Meson 项目后，可选择 `datalab_btest`、`datalab_ishow` 或 `datalab_fshow`。在 `datalab_btest` 的运行配置里填入 `-f 函数名` 可以只跑一题。运算规则和总分仍用上面的 `dlc` 与 `driver.pl` 检查。

## 完成后订正

参考实现和逐题推导在 `solutions/`。做完后，从本目录单独评分参考实现，自己的 `bits.c` 会继续作为默认的评分输入。

```bash
./driver.pl -f solutions/bits.c
```

官方自学包和说明由 Randal E. Bryant 与 David R. O’Hallaron 提供。[自学包](https://csapp.cs.cmu.edu/3e/datalab-handout.tar) · [实验说明](https://csapp.cs.cmu.edu/3e/datalab.pdf)
