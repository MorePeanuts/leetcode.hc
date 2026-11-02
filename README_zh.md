# leetcode.hc

[English](README.md) · 简体中文

供 [handcoding (hc)](https://github.com/MorePeanuts/handcoding) 使用的 LeetCode 题目包，在本地离线判题。每道题都有 Go 和 Python 的参考解，以及中英文题面。

> [!NOTE]
> 本题目包与 LeetCode（力扣）无关。题面版权仍归 LeetCode 所有，见 [NOTICE](NOTICE)。

## 安装

需要 hc v0.1.0-alpha.7 或更高版本。

```sh
hc pack install https://github.com/MorePeanuts/leetcode.hc.git                 # 跟随 main
hc pack install https://github.com/MorePeanuts/leetcode.hc.git --ref v0.1.0    # 或某个版本
hc list --group arrays-hashing                                                 # 某个分组的题目
```

题目包名为 `leetcode`，题目即 `leetcode/two-sum` 等。`hc pack update leetcode` 获取新题；用 `hc pack update leetcode --ref <tag>` 切换版本。

## 内容

题目没有固定清单，会逐步加入，包中每道题都可直接练习。题目按专题分组，顺序即 hc 中显示的顺序：Arrays & Hashing、Two Pointers、Sliding Window、Stack、Binary Search、Linked List、Trees、Heap / Priority Queue、Backtracking、Tries、Graphs、Advanced Graphs、1-D 与 2-D Dynamic Programming、Greedy、Intervals、Bit Manipulation、Math & Geometry。

每个版本新增、修复或删除了哪些题，见 [Releases](https://github.com/MorePeanuts/leetcode.hc/releases)。

## 许可

题目包自身的内容（测试用例、参考解、checker、签名、判题规则、分组）采用 [MIT 许可](LICENSE)，题面不在其列，见 [NOTICE](NOTICE)。
