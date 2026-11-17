class NestedIterator {
    using Position = vector<NestedInteger>::const_iterator;
    vector<pair<Position, Position>> frames;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        frames.emplace_back(nestedList.cbegin(), nestedList.cend());
    }

    int next() {
        if (!hasNext()) {
            throw std::out_of_range("iterator exhausted");
        }
        return (frames.back().first++)->getInteger();
    }

    bool hasNext() {
        while (!frames.empty()) {
            auto &[current, end] = frames.back();
            if (current == end) {
                frames.pop_back();
                continue;
            }
            if (current->isInteger()) {
                return true;
            }
            const auto &children = (current++)->getList();
            frames.emplace_back(children.cbegin(), children.cend());
        }
        return false;
    }
};
