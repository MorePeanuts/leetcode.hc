package main

type NestedIterator struct{ stack []*NestedInteger }

func Constructor(nestedList []*NestedInteger) *NestedIterator {
	stack := make([]*NestedInteger, 0, len(nestedList))
	for i := len(nestedList) - 1; i >= 0; i-- {
		stack = append(stack, nestedList[i])
	}
	return &NestedIterator{stack: stack}
}
func (s *NestedIterator) HasNext() bool {
	for len(s.stack) > 0 {
		item := s.stack[len(s.stack)-1]
		if item.IsInteger() {
			return true
		}
		s.stack = s.stack[:len(s.stack)-1]
		children := item.GetList()
		for i := len(children) - 1; i >= 0; i-- {
			s.stack = append(s.stack, children[i])
		}
	}
	return false
}
func (s *NestedIterator) Next() int {
	s.HasNext()
	last := len(s.stack) - 1
	value := s.stack[last].GetInteger()
	s.stack = s.stack[:last]
	return value
}
