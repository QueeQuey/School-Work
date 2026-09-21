aFile = File.new("data.txt", "r")
h = Hash.new(0)
i = 0
aFile.each do |line|
  words = line.split # split func breaks line in words
  h[words[0]] = words[2] # storing important things in hash h
  i +=1
end
p "number of lines: #{i}"
p "price of Desk is: #{h["Desk"]}"
aFile.close