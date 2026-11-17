type Item = { value: number; next: Item | null };

class MyLinkedList {
        private head: Item = { value: 0, next: null };
        private tail = this.head;
        private size = 0;

        private before(index: number): Item {
            let node = this.head;
            while (index-- > 0) node = node.next!;
            return node;
        }

        get(index: number): number {
            return index >= 0 && index < this.size ? this.before(index).next!.value : -1;
        }

        addAtIndex(index: number, val: number): void {
            if (index < 0 || index > this.size) return;
            const previous = index === this.size ? this.tail : this.before(index);
            const node = { value: val, next: previous.next };
            previous.next = node;
            if (index === this.size) this.tail = node;
            this.size++;
        }

        addAtHead(val: number): void { this.addAtIndex(0, val); }
        addAtTail(val: number): void { this.addAtIndex(this.size, val); }

        deleteAtIndex(index: number): void {
            if (index < 0 || index >= this.size) return;
            const previous = this.before(index);
            const removed = previous.next!;
            previous.next = removed.next;
            if (removed === this.tail) this.tail = previous;
            this.size--;
        }
    }
