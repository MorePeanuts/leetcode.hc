function accountsMerge(accounts: string[][]): string[][] {
    const parent = accounts.map((_, i) => i);
    function root(i: number): number {
        while (parent[i] !== i) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }

    const owner = new Map<string, number>();
    for (let i = 0; i < accounts.length; i++) {
        for (let j = 1; j < accounts[i].length; j++) {
            const email = accounts[i][j];
            const first = owner.get(email);
            if (first === undefined) {
                owner.set(email, i);
            } else {
                parent[root(i)] = root(first);
            }
        }
    }
    const groups = new Map<number, string[]>();
    for (const [email, i] of owner) {
        const id = root(i);
        if (!groups.has(id)) groups.set(id, []);
        groups.get(id)!.push(email);
    }
    const result: string[][] = [];
    for (const [id, emails] of groups) {
        result.push([accounts[id][0], ...emails.sort()]);
    }
    return result;
}
