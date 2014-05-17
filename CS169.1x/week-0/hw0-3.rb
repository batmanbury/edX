#!/usr/bin/env ruby

# hw0-3.rb
# CS169.1x -- Engineering Software as a Service
# Matthew T. Banbury
# matbanbury (at) gmail

"""
Define a class BookInStock which represents a book with an isbn number,
isbn, and price of the book as a floating-point number, price, as
attributes. The constructor should accept the ISBN number (a string)
as the first argument and price as second argument, and should raise
ArgumentError (one of Ruby's built-in exception types) if the ISBN
number is the empty string or if the price is less than or equal to zero.

Include the proper getters and setters for these attributes. Include a
method price_as_string that returns the price of the book with a leading
dollar sign and trailing zeros, that is, a price of 20 should display as
'$20.00' and a price of 33.8 should display as '$33.80'.
"""

class BookInStock
	attr_accessor :isbn, :price

	def initialize(isbn, price)
		@isbn, @price = isbn, price
		raise ArgumentError if isbn == ""
		raise ArgumentError if price <= 0.0
	end

	def price_as_string
		sprintf("$%.2f", price)
	end
end


if __FILE__ == $0
	tp = BookInStock.new('144933072X', 33.3)
	puts tp.price_as_string
end