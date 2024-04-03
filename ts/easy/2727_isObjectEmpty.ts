type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type Obj = Record<string, JSONValue> | JSONValue[]

function isEmpty(obj: Obj): boolean {
    const returnType = (x:Obj) =>  { return Object.prototype.toString.call(x) }

    const isEmptyArray = (x:Obj) => {
        return (x.length===0) ? true : false
    }
    
    const isEmptyObject = (x:Obj) => {
        return (Object.keys(x).length===0) ? true : false
    }
    
    if(returnType(obj)==='[object Array]')
        return isEmptyArray(obj)

    return isEmptyObject(obj)
};