# frozen_string_literal: true
outputFile = File.new(" readmeTask3.txt", "w")
p "Enter how many times the coin should be flipped, ideally between 100 and 200"
flip_count = gets.chomp.to_i
head_count = 0 #used later to count 'H's in the array
tails_count = 0 #used later to count 'T's in the array
flips_array = []
#i = 0
for i in 0...flip_count
  random_Number = rand(2)

  if random_Number == 1
    flips_array.push('H') #.push is to append to the array
  elsif random_Number == 0
    flips_array.push('T') #.push is to append to the array
  else
    "Random number generator isnt working"
  end
end
p "#{flips_array}" #Printing the array for testing

i = 0
for flips_array in flips_array
  if flips_array[i] == 'H'
    head_count += 1
  elsif flips_array[i] == 'T'
    tails_count += 1
  else
    p 'Comparison is not working'
  end
end
p "Heads Count: #{head_count}"
p "Tails Count: #{tails_count}"
p "Ratio between heads and tails: #{head_count}:#{tails_count}"
ratio = head_count/tails_count.to_f
p "Ratio between heads and tails (heads to tails): #{ratio}"


outputFile.write("Heads Count: #{head_count}")
outputFile.write("Tails Count: #{tails_count}")
outputFile.write("Ratio between heads and tails: #{head_count}:#{tails_count}")
outputFile.write("Ratio between heads and tails (heads to tails): #{ratio}")
outputFile.close