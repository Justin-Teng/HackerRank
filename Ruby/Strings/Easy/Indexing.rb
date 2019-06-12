def serial_average(str)
    "#{str[0,4]}#{((str[4,5].to_f + str[10,5].to_f) / 2).round(2)}"
end
