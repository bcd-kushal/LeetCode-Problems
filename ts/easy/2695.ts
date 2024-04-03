class ArrayWrapper {
    arr: number[]
    constructor(nums: number[]) { this.arr = nums }
    valueOf(): number           { return this.arr.reduce((sum,curr) => sum+curr, 0) }
    toString(): string          { return `[${this.arr.join(',')}]` }
};