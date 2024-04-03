type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type Obj = Record<string, JSONValue> | Array<JSONValue>;

function chunk(arr: Obj[], size: number): Obj[][] {
    const n: number = arr.length
    
    // if size >= n -------------------------
    if(size >= n) 
        return n==0 ? [] : [arr]
    
    
    // if size < n ---------------------------
    let chunkArr: Obj[][] = []
    let subArr: Obj[] = []
    for(let i=0; i<n; i+=size) {
        if(i+size>=n)
            subArr = arr.slice(i)
        else
            subArr = arr.slice(i,i+size)
        chunkArr.push(subArr)
        subArr = []
    }
    
    return chunkArr
};
