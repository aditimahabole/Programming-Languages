function chunk(arr,size){
    
    let res = [];
    let temp = []
    let cur_size = 0;
    
    
    for(let i = 0;i<arr.length;i++){
        if(cur_size<size){
            temp.push(arr[i]);
            cur_size++;
            
        }
        else{
            res.push(temp);
            temp = []
            temp.push(arr[i]);
            cur_size = 1;
            
        }
    }
    if(temp.length>0){
        res.push(temp);
    }
    return res;
    
}
console.log(chunk([1,2,3,4,5],1));
console.log(chunk([1,2,3,4,5],2));
console.log(chunk([1,2,3,4,5],3));
console.log(chunk([1,2,3,4,5],4));


// Output
// [ [ 1 ], [ 2 ], [ 3 ], [ 4 ], [ 5 ] ]
// [ [ 1, 2 ], [ 3, 4 ], [ 5 ] ]
// [ [ 1, 2, 3 ], [ 4, 5 ] ]
// [ [ 1, 2, 3, 4 ], [ 5 ] ]
