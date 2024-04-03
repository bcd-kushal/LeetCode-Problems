declare global {
    interface Array<T> {
        groupBy(fn: (item: T) => string): Record<string, T[]>
    }
}

Array.prototype.groupBy = function(fn):object {
    const map:object = {}
    
    this.forEach((el:any) => {
        const result:string = fn(el)
        const key:string = `${result}`
        
        if(result!==undefined && result!==null && key!=='undefined' && key!=='null') {
            if(key in map)   map[key].push(el)
            else             map[key] = [el]
        }    
    }) 
    
    return map
};