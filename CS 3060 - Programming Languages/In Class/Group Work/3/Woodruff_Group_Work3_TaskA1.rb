# frozen_string_literal: true
output_file = File.new("GroupWork3_readmeTaskA1.txt", "w")

def foo(arr)
  #Filter out strings that start with C and END with D
  for x in arr do
    #p "String #{x}"
    if x[0] == 'c' && x[x.length-1] == 'd'
      #p "Hello World"
      arr -= [x]
    end
  end
  #p "#{newmap}"
  return arr
end
a1 = Array["apple", "cat","carad","badminton"]
a2 = foo(a1)

p "Printing new array:"
p "#{a2}"

output_file.write("Array: #{a2}")
output_file.close