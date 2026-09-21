# frozen_string_literal: true
output_file = File.new("GroupWork2_readmeTask1.txt", "w")

def foo(arr)
  #Modulo 3
  newmap = arr.map { |x| x % 3 }
  #p "#{newmap}"
  return newmap
end

arr = Array[1,2,3,4,5,6,7,8,9,10,11,12]
testmap = foo(arr)
p "Printing new array:"
p "#{testmap}"

output_file.write("Printing array: #{testmap}")
output_file.close