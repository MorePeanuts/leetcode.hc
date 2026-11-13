def check(input, output, expected):
    nums = input["nums"]
    if type(output) is not int:
        return "peak index must be an integer"
    if not 0 <= output < len(nums):
        return "peak index is outside nums"
    if output > 0 and nums[output] <= nums[output - 1]:
        return "selected element is not greater than its left neighbor"
    if output + 1 < len(nums) and nums[output] <= nums[output + 1]:
        return "selected element is not greater than its right neighbor"
    return True
