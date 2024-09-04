function isHappy(n: number): boolean {
    if (n <= 3 && n !== 1)
        return false

    const sumOfSquares = (n: number): number =>
        n === 0
            ? 0
            : Math.pow(n % 10, 2) + sumOfSquares(parseInt(String(n / 10)))

    let set = new Set()
    let sq: number = sumOfSquares(n)

    while (n !== 1 && !set.has(sq)) {
        set.add(sq)
        sq = sumOfSquares(sq)
    }

    if (sq === 1)
        return true

    return false

};