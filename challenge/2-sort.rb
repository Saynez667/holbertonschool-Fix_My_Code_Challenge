result = []
ARGV.each do |arg|
  # skip if not integer
  next if arg !~ /^-?\d+$/

  i_arg = arg.to_i

  # Find the correct position to insert
  inserted = false
  result.each_with_index do |val, idx|
    if i_arg < val
      result.insert(idx, i_arg)
      inserted = true
      break
    end
  end
  result << i_arg unless inserted
end

puts result
