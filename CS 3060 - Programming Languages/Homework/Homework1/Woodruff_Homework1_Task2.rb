# frozen_string_literal: true
def foo(str)
outputFile = File.new(" readmeTask2.txt", "w")
#If we needed to do string input within the definition we could do it this way
#p "Enter one phrase in English"
# line1 = gets.chomp
# #line1.split((/\w+/))

#.chars would also work here instead of split
temp_Array = str.delete(' ').split('')
#p "#{temp_Array[2]}" #For testing
#p "#{temp_Array.length}" #For testing

#out_hash = Hash{*temp_Array}...
# I remember we did the each_with in class. Had to find this function on Stack Overflow
# Saving it for later just in case. Finds the locations of the index of letters
#out_hash = temp_Array.each_with_index.to_h

#This is what was asked:
out_hash = temp_Array.tally

#Printing
puts out_hash
outputFile.write("#{out_hash}")
outputFile.close
end

String string_pass =  "I think this is how we do it"
foo(string_pass)