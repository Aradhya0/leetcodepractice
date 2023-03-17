var Trie = function() {
  this.store = new Set();
};

/** 
 * @param {string} word
 * @return {void}
 */
Trie.prototype.insert = function(word) {
      return  this.store.add(word)
};

/** 
 * @param {string} word
 * @return {boolean}
 */
Trie.prototype.search = function(word) {
   return this.store.has(word)
};

/** 
 * @param {string} prefix
 * @return {boolean}
 */
Trie.prototype.startsWith =function(prefix) {
    let curr = this.store
    for(let cha of curr) {
        let temp =cha.substring(0,prefix.length)
        if(temp==prefix) {
            return true
        }
    }
    return false
};
