var NestedIterator = function(nestedList) {
    this.frames = [{ list: nestedList, index: 0 }];
};

NestedIterator.prototype.hasNext = function() {
    while (this.frames.length > 0) {
        const frame = this.frames[this.frames.length - 1];
        if (frame.index === frame.list.length) {
            this.frames.pop();
            continue;
        }
        const value = frame.list[frame.index];
        if (value.isInteger()) {
            return true;
        }
        frame.index++;
        this.frames.push({ list: value.getList(), index: 0 });
    }
    return false;
};

NestedIterator.prototype.next = function() {
    if (!this.hasNext()) {
        throw new RangeError("iterator exhausted");
    }
    const frame = this.frames[this.frames.length - 1];
    return frame.list[frame.index++].getInteger();
};
