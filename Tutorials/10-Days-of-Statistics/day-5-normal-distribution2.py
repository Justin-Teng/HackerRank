import math

def cum_prob(x, mean, std):
    return 0.5 * (1 + math.erf((x-mean) / (math.sqrt(2)*std)))

mean = 70.0
std = 10.0
q1 = 80.0
q2 = 60.0

print format(100*(1.0 - cum_prob(q1, mean, std)), '.2f')
print format(100*(1.0 - cum_prob(q2, mean, std)), '.2f')
print format(100*(cum_prob(q2, mean, std)), '.2f')
