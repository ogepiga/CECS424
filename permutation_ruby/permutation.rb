#!/usr/bin/ruby

puts "Enter n:"
num = gets.to_i

#(1..num).each do |value| #foreach for ruby
#  puts value
#end

a=*(1..num)
puts a.permutation.to_a #to_a not working
puts a.combination(1).to_a
