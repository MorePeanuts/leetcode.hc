package main

type quote struct{ price, span int }
type StockSpanner struct{ stack []quote }

func Constructor() StockSpanner { return StockSpanner{} }
func (this *StockSpanner) Next(price int) int {
	span := 1
	for len(this.stack) > 0 && this.stack[len(this.stack)-1].price <= price {
		span += this.stack[len(this.stack)-1].span
		this.stack = this.stack[:len(this.stack)-1]
	}
	this.stack = append(this.stack, quote{price, span})
	return span
}
