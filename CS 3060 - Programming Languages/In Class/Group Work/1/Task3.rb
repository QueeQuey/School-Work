# frozen_string_literal: true
aFile = File.new("CS3060Students.txt", "r")
hA = Hash.new("")
i = 0
aFile.each do |line|
  words3060 = line.split # split func breaks line in words
  hA[words3060[0]] = words3060[1] # storing (id => firstName) in hash
  i+=1
end
aFile.close
p "number of students in CS 3060:#{i - 1}"

bFile = File.new("CS4390Students.txt", "r")
hA = Hash.new("")
j = 0
bFile.each do |line|
  words4390 = line.split # split func breaks line in words
  hA[words4390[0]] = words4390[1] # storing (id => firstName) in hash
  j+=1
end
bFile.close
p "number of students in CS 4390:#{j - 1}"
p "students in both classes #{}"