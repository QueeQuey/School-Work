# frozen_string_literal: true
output_file = File.new("GroupWork2_readmeTask3.txt", "w")

#Changed version
"#def seriesUpTo(max) # this func receives a code block
{  i = 1
  while i <= max
    yield i*i*i + i*i    # see correspondence b/w i*i and x in block later.
    i = i + 1
  end
end}"

#Lambda version!
seriesUpTo = -> (max, &block){ # this func receives a code block
  i = 1
  while i <= max
    block.call( i*i*i + i*i )   # see correspondence b/w i*i and x in block later.
    i = i + 1
  end
}
#seriesUpTo(100) { |x| puts x } # this will print some series
seriesUpTo.call(100){ |x| puts x }
puts "\n"



output_file.write("a) It is executed 50 times since the itteration is by 2. b) and others are in the code/console!")
output_file.close