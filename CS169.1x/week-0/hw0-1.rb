#!/usr/bin/env ruby

# hw0-1.rb
# CS169.1x -- Engineering Software as a Service
# Matthew T. Banbury
# matbanbury (at) gmail

'''
Define a method sum which takes an array of integers as an argument
	and returns the sum of its elements. For an empty array it should
	return zero.
Define a method max_2_sum which takes an array of integers as an
	argument and returns the sum of its two largest elements. For an
	empty array it should return zero. For an array with just one
	element, it should return that element.
Define a method sum_to_n? which takes an array of integers and an 
	additional integer, n, as arguments and returns true if any two
	distinct elements in the array of integers sum to n. An empty array
	or single element array should both return false.
'''

def sum(a)
	if a.length > 0
	    a.inject(:+)
	else 0
	end
end

def max_2_sum(a)
	if a.length == 0
	    0
	elsif a.length == 1
		a[0]
	else
		a.sort!
		a[-1] + a[-2]
	end
end

def sum_to_n?(a,n)
	return false if a.length < 2
	a.combination(2).each do |x,y|
		return true unless x + y != n
	end
	false
end


if __FILE__ == $0
	a1 = [12,2,14,4,16,6,19,9,13,3,18,8,11,1,15,5,17,7,20,10]
	a2 = []
	puts 'Non-empty array test', "\n"
	puts 'Original array:'
	print a1, "\n"
	puts 'Sorted array:'
	print a1.sort, "\n"
	puts 'Sum of array:', sum(a1)
	puts 'Sum largest pair:', max_2_sum(a1)
	puts 'Contains sum to 39?', sum_to_n?(a1, 39)
	puts 'Contains sum to 40?', sum_to_n?(a1, 40), "\n"
	puts 'EMPTY array test', "\n"
	puts 'Original array:'
	print a2, "\n"
	puts 'Sorted array:'
	print a2.sort, "\n"
	puts 'Sum of array:', sum(a2)
	puts 'Sum largest pair:', max_2_sum(a2)
	puts 'Contains sum to 39?', sum_to_n?(a2, 39)
	puts 'Contains sum to 0?', sum_to_n?(a2, 0)
end
