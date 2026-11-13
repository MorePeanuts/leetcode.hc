# 341. Flatten Nested List Iterator

You are given a nested list of integers `nestedList`. Each element is either an integer or a list whose elements may also be integers or other lists. Implement an iterator to flatten it.

Implement the `NestedIterator` class:

- `NestedIterator(List<NestedInteger> nestedList)` Initializes the iterator with the nested list `nestedList`.
- `int next()` Returns the next integer in the nested list.
- `boolean hasNext()` Returns `true` if there are still some integers in the nested list and `false` otherwise.

Your code will be tested with the following pseudocode:

```
initialize iterator with nestedList
res = []
while iterator.hasNext()
    append iterator.next() to the end of res
return res
```

If `res` matches the expected flattened list, then your code will be judged as correct.

**hc note:** Cases explicitly call the constructor and the iterator methods. The output contains one result per operation (`null` for the constructor), including `hasNext` booleans. `next` is called only while an integer remains, after a successful `hasNext`; repeated `hasNext` calls must not consume an integer.

For example 1, hc uses `ops = ["NestedIterator","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext","next","hasNext"]` and `args = [[[[1,1],2,[1,1]]],[],[],[],[],[],[],[],[],[],[],[]]`; the output is `[null,true,1,true,1,true,2,true,1,true,1,false]`.

For example 2, hc uses `ops = ["NestedIterator","hasNext","next","hasNext","next","hasNext","next","hasNext"]` and `args = [[[1,[4,[6]]]],[],[],[],[],[],[],[]]`; the output is `[null,true,1,true,4,true,6,false]`.

**Example 1:**

```
Input: nestedList = [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
```

**Example 2:**

```
Input: nestedList = [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
```

**Constraints:**

- `1 <= nestedList.length <= 500`
- The values of the integers in the nested list is in the range `[-10^6, 10^6]`.
