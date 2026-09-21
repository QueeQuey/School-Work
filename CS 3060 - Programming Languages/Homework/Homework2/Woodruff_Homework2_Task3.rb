# frozen_string_literal: true


def foo(arr)
  output_file = File.new("Homework2_readmeTask3.txt", "w")
  holding_Array = []
  arr.each do |num|
    lsd = num.abs % 10
    holding_Array.append(lsd)
    #p "#{lsd}" #Can print for each of the array, but would rather just print on one line.
  end
  #p "Least significant digit of each int: #{holding_Array}"
  output_file.write("Least significant digit of each int: #{holding_Array} \n")


  integers = arr.select { |num| num < 4 }
  #p "Elements less than 4: #{integers}"
  output_file.write("Elements less than 4: #{integers} \n")


  cubes_Array = arr.map { |num| num ** 3 }
  #p "Cubes of integers: #{cubes_Array}"
  output_file.write("Cubes of the ints: #{cubes_Array} \n")

  sum = arr.inject(0) { |sum, num| sum + num ** 2}
  #p "Sum of the squares of the integers: #{sum}"
  output_file.write("Sum of squares of the ints: #{sum} \n")
  output_file.close

end

input_array = Array.new(15) { rand(-10..10)}

# Test
foo(input_array)