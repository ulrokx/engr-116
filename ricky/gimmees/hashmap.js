hashStringToInt = (s, tableSize) => {
    let hash;
    for(let i = 0; i < s.length; i++) {
        hash = (3*hash * s.charCodeAt(i) )% tableSize;
    }
    return hash;
}

class Hashmap {
    table = new Array(100);

    getItem = (key) =>
    {
        const i = hashStringToInt(key, this.table.length);
        if(!this.table[i]) {
            return null;
        }
        return this.table[i].find(x => x[0] === key)[1];
    }

    setItem = (key, value) =>
    {
        const i = hashStringToInt(key, this.table.length);
        if(this.table[i])
        {
            this.table[i].push([key, value]);
        } else {
            this.table[i] = [[key,value]];
        }
    }
}

MyMap = new Hashmap();
MyMap.setItem("firstname", "bob");
MyMap.setItem("lastname", "kirk");
MyMap.setItem("age", 15);
MyMap.setItem("dob", "3/15/2");
MyMap.setItem("flagged", true);
console.log(MyMap.getItem("firstname"));