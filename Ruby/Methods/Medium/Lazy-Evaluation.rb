require 'prime'
n = gets
p Prime.each.lazy.select{|prime| prime.to_s == prime.to_s.reverse}.first(n.to_i)
