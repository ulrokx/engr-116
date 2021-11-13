/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let dict = {}
    let i = 0
    nums.forEach((value) => {
        let d = target - value
        if(d in dict) {
            return [i, dict[d]];
        }
        else {
            dict[d] = i;
        }
        i = i + 1;
    })
};
console.log(twoSum([2,3], 5))