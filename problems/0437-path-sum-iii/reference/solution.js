function pathSum(root, targetSum) {
    const prefixes = new Map([[0, 1]]);

    function visit(node, sum) {
        if (node === null) {
            return 0;
        }
        sum += node.val;
        let count = prefixes.get(sum - targetSum) ?? 0;
        const original = prefixes.get(sum) ?? 0;
        prefixes.set(sum, original + 1);
        count += visit(node.left, sum);
        count += visit(node.right, sum);
        if (original === 0) {
            prefixes.delete(sum);
        } else {
            prefixes.set(sum, original);
        }
        return count;
    }

    return visit(root, 0);
}
