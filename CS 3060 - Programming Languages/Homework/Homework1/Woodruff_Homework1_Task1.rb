# frozen_string_literal: true
outputFile = File.new(" readmeTask1.txt", "w")
p "Enter a string input for line 1"
line1 = gets.chomp
p "Enter a string input for line 2"
line2 = gets.chomp
p "Enter a string input for line 3"
line3 = gets.chomp

#Printing step
p "L1: #{line1}"
outputFile.write("#{line1}")
p "L2: #{line2}"
outputFile.write("#{line2}")
p "L3: #{line3}"
outputFile.write("#{line3}")
outputFile.close
#Words checker using arrays
line1Length = line1.split
line2Length = line2.split
line3Length = line3.split


p "L1: #{line1Length.length},L2: #{line2Length.length},L3: #{line3Length.length}"
