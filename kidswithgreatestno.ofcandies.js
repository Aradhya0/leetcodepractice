var kidsWithCandies = function(candies, extraCandies) {
    
    let maxCandies=Math.max(...candies)
    let arr=[]
    candies.forEach(ele => ele+extraCandies < maxCandies ? arr.push(false) : arr.push(true))
    return arr
};
