class BrowserHistory {
    constructor(homepage) {
        this.pointer = 0;
        this.history = [homepage];   
    }
    
    visit(url) {
        this.history.splice(this.pointer+1, this.history.length);
        this.history.push(url);
        this.pointer++;
    }
    
    back(steps) {
        this.pointer -= Math.min(this.pointer, steps);
        return this.history[this.pointer];
    }
    
    forward(steps) {
        this.pointer += Math.min(this.history.length - this.pointer - 1, steps);
        return this.history[this.pointer];
    }
}
