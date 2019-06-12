def convert_temp(temp, input_scale:, output_scale: 'celsius')
    case input_scale
    when 'fahrenheit'
        if output_scale == 'celsius'
            return (temp-32) / 1.8
        else
            return 273.15 + ((temp-32) / 1.8)
        end
    when 'celsius'
        if output_scale == 'fahrenheit'
            return 32 + (temp*1.8)
        else
            return temp + 273.15
        end
    when 'kelvin'
        if output_scale == 'fahrenheit'
            return 32 + ((temp-273.15)*1.8)
        else
            return temp - 273.15
        end
    end
end
