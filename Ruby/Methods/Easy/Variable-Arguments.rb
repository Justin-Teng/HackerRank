def full_name(first_name, *other_names)
    other_names.reduce(first_name) {|entire_name, name| entire_name + " " + name}
end
