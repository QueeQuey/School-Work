


# frozen_string_literal: true
output_File = File.new("Homework2_readmeTask6.txt", "w")
# Abstract Shape class
class Shape
  attr_accessor :color
  def initialize(color)
    @color = color
  end

  def side
    raise NotImplementedError, "Error given by Stack overflow, but put here to be overriden"
  end

  def area
    raise NotImplementedError, "Should not be called"
  end
end

class Octagon < Shape
  attr_accessor :side_length
  def initialize(color, side_length)
    super(color)
    @side_length = side_length
  end

  def side
    8
  end

  def area
    #(2 * (1 + sqrt(2)) * side_length^2)
    2 * (1 + Math.sqrt(2)) * @side_length**2
  end
end


class Hexagon < Shape
  attr_accessor :side_length
  def initialize(color, side_length)
    super(color)
    @side_length = side_length
  end

  def side
    6
  end


  def area
    #((3 * sqrt(3))/2) * side_length^2
    ((3 * Math.sqrt(3)) / 2) * @side_length**2
  end
end

def generate_random_shapes(num_shapes)
  colors = ['red', 'green', 'blue', 'yellow', 'purple', 'orange', 'magenta', 'cyan', 'burgungdy']
  shapes = []

  num_shapes.times do
    side_length = rand(1.0..10.0)
    color = colors.sample

    # Randomly choose between Hexagon and Octagon
    if rand(2) == 0
      shape = Hexagon.new(color, side_length)
    else
      shape = Octagon.new(color, side_length)
    end
    shapes << shape
  end
  shapes #Return command, just like the previous group project
end

# Generate and display random shapes
shapes = generate_random_shapes(25)

total_area_of_shapes = 0
shapes.each_with_index do |shape, index|
  #p "#{index + 1}. #{shape.class}, Area: #{shape.area}"
  output_File.write("#{index + 1}. #{shape.class}, Area: #{shape.area} \n")
  total_area_of_shapes += shape.area
end

p "Total area of shapes: #{total_area_of_shapes}"
output_File.write("Total area of shapes: #{total_area_of_shapes}")

output_File.close
