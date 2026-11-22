# 计算机科学学习笔记

## 在 WSL 中构建

在 Ubuntu 下先安装构建工具。

```bash
sudo apt install build-essential meson ninja-build
```

在项目根目录执行以下命令，编译并运行 K&R 第一章的温度转换练习。

```bash
meson setup build
meson compile -C build
'./build/K&R/ch1/kr_ch1_ex1'
```

修改源码后，重新运行 `meson compile -C build` 即可。

## 添加示例和练习

每个独立程序都有自己的 `main()`。在 `K&R/ch1/` 下按以下规则存放，Meson 会为匹配的文件生成独立目标。

| 目录 | 文件名 | 目标示例 |
| --- | --- | --- |
| `examples/` | `example数字.c` | `example4.c` → `kr_ch1_ex4` |
| `exercises/` | `ex数字.c` 或 `exercise数字.c` | `ex1.c` → `kr_ch1_exercises_ex1` |

新增、重命名或移除文件后，在 CLion 的 Meson 工具窗口点击「重新加载 Meson 项目」。使用终端时，重新配置并编译即可。

```bash
meson setup --reconfigure build
meson compile -C build
```

新增章节时，在根目录的 `meson.build` 中用 `subdir()` 引入该章节。
