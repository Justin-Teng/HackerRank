def sum_terms(n)
    (1..n).inject(0) { |sum, x| sum + x*x + 1 }
end
