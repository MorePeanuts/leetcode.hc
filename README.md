# leetcode.hc

English · [简体中文](README_zh.md)

LeetCode problems for [handcoding (hc)](https://github.com/MorePeanuts/handcoding), which judges them locally and offline. Every problem has Go and Python reference solutions, and its statement in English and Chinese.

> [!NOTE]
> This pack is not affiliated with LeetCode. The statements remain LeetCode's; see [NOTICE](NOTICE).

## Install

You need hc v0.1.0-alpha.7 or later.

```sh
hc pack install https://github.com/MorePeanuts/leetcode.hc.git                 # follow main
hc pack install https://github.com/MorePeanuts/leetcode.hc.git --ref v0.1.0    # or a release
hc list --group arrays-hashing                                                 # the problems of a group
```

The pack is named `leetcode`, so its problems are `leetcode/two-sum` and so on. `hc pack update leetcode` brings in new problems; switch releases with `hc pack update leetcode --ref <tag>`.

## Contents

There is no fixed problem list: problems are added over time, and every problem in the pack is ready to practice. They are arranged by topic, in the order hc shows them: Arrays & Hashing, Two Pointers, Sliding Window, Stack, Binary Search, Linked List, Trees, Heap / Priority Queue, Backtracking, Tries, Graphs, Advanced Graphs, 1-D and 2-D Dynamic Programming, Greedy, Intervals, Bit Manipulation, Math & Geometry.

The [releases](https://github.com/MorePeanuts/leetcode.hc/releases) say what each version added, fixed or removed.

## Contributing

Problems are added in batches tracked in the issues and milestones. [CONTRIBUTING.md](CONTRIBUTING.md) says how to add or fix one, and how versions are numbered.

## License

The pack's own content (test cases, reference solutions, checkers, signatures, judge rules, groups) is under the [MIT license](LICENSE). The problem statements are not: see [NOTICE](NOTICE).
