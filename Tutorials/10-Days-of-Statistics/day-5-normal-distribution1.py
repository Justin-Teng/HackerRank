import math

def cum_prob(x, mean, std):
    return 0.5 * (1 + math.erf((x-mean) / (math.sqrt(2)*std)))

mean = 20.0
std = 2.0
q1 = 19.5
q2a = 20.0
q2b = 22.0

print format(cum_prob(q1, mean, std), '.3f')
print format(cum_prob(q2b, mean, std) - cum_prob(q2a, mean, std), '.3f')
