def check(input, output, expected):
    s = input["s"]
    if not isinstance(output, str):
        return "the output is not a string"
    if output not in s:
        return "%r is not a substring of s" % (output,)
    if output != output[::-1]:
        return "%r is not a palindrome" % (output,)
    if len(output) != len(expected):
        return "%r has length %d, but the longest palindromic substring has length %d" % (
            output,
            len(output),
            len(expected),
        )
