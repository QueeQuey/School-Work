# frozen_string_literal: true
output_File = File.new(" readmeTask4.txt", "w")
input_FileA = File.new("storyA.txt", "r")
input_FileB = File.new("storyB.txt", "r")
filea_array = []
fileb_array = []


File.foreach(input_FileA) do |line|
  #tempArray = x.chomp.split(/[^\w\s]/) #Don't need to chomp or split because of gsub
  temp_line = line.gsub(/[^\w\s]/, '') #gsub from StackOverflow
  filea_array.concat(temp_line.split(/\s+/)) #Concationation of strings to put into array
  end
#p "#{filea_array[1]}" #Testing
File.foreach(input_FileB) do |line|
  #tempArray = x.chomp.split(/[^\w\s]/) #Don't need to chomp or split because of gsub
  temp_line = line.gsub(/[^\w\s]/, '') #gsub from StackOverflow
  fileb_array.concat(temp_line.split(/\s+/)) #Concationation of strings to put into array
end

input_FileA.close
input_FileB.close

p "Total number of words in story A: #{filea_array.size}"
p "Total number of words in story B: #{fileb_array.size}"
output_File.write("Total number of words in story A: #{filea_array.size}")
output_File.write(p "Total number of words in story B: #{fileb_array.size}")

filea_vector = filea_array.tally
fileb_vector = fileb_array.tally
#p "#{filea_vector}" # Testing vector

p "Total number of UNIQUE words in storyA: #{filea_vector.length}"
p "Total number of UNIQUE words in storyB: #{fileb_vector.length}"
output_File.write("Total number of UNIQUE words in storyA: #{filea_vector.length}")
output_File.write("Total number of UNIQUE words in storyB: #{fileb_vector.length}")

filea_sortedvector = filea_vector.sort_by { |_word, count| -count }
fileb_sortedvector = fileb_vector.sort_by { |_word, count| -count }

filea_sortedvector_values = filea_vector.values.sort.reverse
fileb_sortedvector_values = fileb_vector.values.sort.reverse

#For testing
#filea_sortedvector.each do |x|
#  p "x: #{x}"
#end

p "The 4th most common word in story A at #{filea_sortedvector_values[3]} occurances is #{filea_sortedvector[3]}."
p "The 4th most common word in story A at #{fileb_sortedvector_values[3]} occurances is #{fileb_sortedvector[3]}."
output_File.write("The 4th most common word in story A at #{filea_sortedvector_values[3]} occurances is #{filea_sortedvector[3]}.")
output_File.write("The 4th most common word in story A at #{fileb_sortedvector_values[3]} occurances is #{fileb_sortedvector[3]}.")

#combined_vector = filea_vector + fileb_vector
combined_vector = filea_vector.merge(fileb_vector)
p "Total number of UNIQUE words BETWEEN story A and story B: #{combined_vector.length}"
output_File.write("Total number of UNIQUE words BETWEEN story A and story B: #{combined_vector.length}")




#OLD CODE KEEPING FOR NOW
# p "Printing temp array #{tempArray}"
# filea_array.push(tempArray)
#}
#puts filea_array[0]
#fileA_string = File.read(input_FileA).chomp
#filea_array = fileA_string.split(' ')
#p "#{filea_array}"


#TO DO:
# Get total number of words in file A and B
# Get number of Unique words in file A and B
# Get 4th most Frequent words in A and B and it's frequency? I assume it means how many times
# Report number of unique words BETWEEN BOTH A and B
# Reccomended to use Array and Data Hash

#output_File.write("")

output_File.close