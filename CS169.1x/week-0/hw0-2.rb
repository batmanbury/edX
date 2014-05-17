#!/usr/bin/env ruby

# hw0-2.rb
# CS169.1x -- Engineering Software as a Service
# Matthew T. Banbury
# matbanbury (at) gmail

'''
Define a method hello(name) that takes a string representing a name
	and returns the string "Hello, " concatenated with the name.
Define a method starts_with_consonant?(s) that takes a string and
	returns true if it starts with a consonant and false otherwise.
	(For our purposes, a consonant is any letter other than A, E, I, O, U.)
	NOTE: be sure it works for both upper and lower case and for nonletters!
Define a method binary_multiple_of_4?(s) that takes a string and returns
	true if the string represents a binary number that is a multiple of 4.
	NOTE: be sure it returns false if the string is not a valid binary number! 
'''

def hello(name)
	"Hello, " << name
end

def starts_with_consonant?(s)
	if s =~ /^[[:alpha:]]/
		return true unless s[0] =~ /[aeiou]/i
	end
	false
end

def binary_multiple_of_4?(s)
	return true if s == '0'
	unless s =~ /[^10]/
		return true if s =~ /00$/
	end
	false
end


if __FILE__ == $0
	puts hello('CS169')
	# Hello, CS169
	puts starts_with_consonant?('consonant')
	# true
	puts starts_with_consonant?('onsonants')
	# false
	puts binary_multiple_of_4?('0')
	# true
	puts binary_multiple_of_4?('1010100100')
	# true
	puts binary_multiple_of_4?('1010100101')
	# false
	puts binary_multiple_of_4?(1010100100)
	# false
	puts binary_multiple_of_4?('AAA100')
	# false
end
