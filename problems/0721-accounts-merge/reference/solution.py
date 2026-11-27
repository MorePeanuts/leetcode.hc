class Solution:
    def accountsMerge(self, accounts: list[list[str]]) -> list[list[str]]:
        parent = list(range(len(accounts)))

        def root(i):
            while parent[i] != i:
                parent[i] = parent[parent[i]]
                i = parent[i]
            return i

        owner = {}
        for i, account in enumerate(accounts):
            for email in account[1:]:
                if email in owner:
                    parent[root(i)] = root(owner[email])
                else:
                    owner[email] = i

        groups = [[] for _ in accounts]
        for email, i in owner.items():
            groups[root(i)].append(email)
        return [[accounts[i][0], *sorted(emails)] for i, emails in enumerate(groups) if emails]
