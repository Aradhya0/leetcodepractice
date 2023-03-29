/**
 * @param {string[]} words
 * @param {number} k
 * @return {string[]}
 */
var topKFrequent = function(words, k) {
    const freq = new Map()

    for(let word of words) {
        freq.set(word, (freq.get(word) || 0) + 1)
    }

    let sortedWords = Array.from(freq.keys()).sort((a, b) => {
        if (freq.get(a) !== freq.get(b)) {
            return freq.get(b) - freq.get(a)
        } else {
            return a.localeCompare(b)
        }
    })

    return sortedWords.slice(0, k)
    
};
