import math

def cum_prob(x, mean, std):
    return 0.5 * (1 + math.erf((x-mean) / (math.sqrt(2)*std)))

max_weight = 9800
num_boxes = 49
mean_weight = 205
std = 15

print format(cum_prob(9800, 49*205, 15*math.sqrt(49)), '.4f')
