# frozen_string_literal: true
output_file = File.new("GroupWork2_readmeTask2.txt", "w")
def genRandomMatrix(n)
  #Generates ONE line of a matrix. Needs a helper loop function to make a specific length/width
  a = [ ]
  (1..n).each do
    b = [ ]
    (1..n).each do
      i = rand(10..20) #you may need to fill in a parameter in rand( ) here
      b.push(i)
    end
    a.push(b)
  end
  a
end

def genRandomRectMatrix(n, m)
  #Generates ONE line of a matrix. Needs a helper loop function to make a specific length/width
  a = [ ]
  (1..m).each do
    b = [ ]
    (1..n).each do
      i = rand(10..20) #you may need to fill in a parameter in rand( ) here
      b.push(i)
    end
    a.push(b)
  end
  a
end

def printMatrix(p)
  for row in p
    puts row.join(" ")
  end
end

def print_Matrix_file(m)
  output_file_Matrix = File.new("GroupWork2_readmeTask2.txt", "w")
  for row in m
    output_file_Matrix.write("#{row.join(" ")} \n")
  end
  output_file_Matrix.close
end

test_three_matrix = genRandomMatrix(3)
test_fifteen_matrix = genRandomMatrix(15)

test_rectangle_matrix = genRandomRectMatrix(10, 15)



printMatrix(test_three_matrix)
printMatrix(test_fifteen_matrix)
printMatrix(test_rectangle_matrix)
print_Matrix_file(test_rectangle_matrix)





#p "#{test_three_matrix}" #Base print function for testing
#p "#{test_fifteen_matrix}" #Base print function for testing


#output_file.write("Printing array: #{testmap}")
output_file.close