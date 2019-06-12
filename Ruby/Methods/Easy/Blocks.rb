def factorial
    yield
end

n = gets.to_i
factorial do 
    puts (2..n).reduce(1) {|product, x| product * x}
end
