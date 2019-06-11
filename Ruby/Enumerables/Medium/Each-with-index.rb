def skip_animals(animals, skip)
    result = []
    animals.each_with_index { |item, index| result.push("#{index}:#{item}") if index >= skip }
    return result
end
