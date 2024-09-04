function twoSum(nums: number[], target: number): number[] {
    let map: Record<number, number> = {}

    for (let i = 0; i < nums.length; i++) {
        const requiredRemainder = target - nums[i]
        if (requiredRemainder in map)
            return [map[requiredRemainder], i]
        else
            map[nums[i]] = i
    }
    return []
}