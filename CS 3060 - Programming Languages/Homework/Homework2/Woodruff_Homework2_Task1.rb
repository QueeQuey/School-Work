# frozen_string_literal: true
output_File = File.new("Homework2_readmeTask1.txt", "w")
f = File.new("task1TestFile.txt", "r") #Not sure of what the input file name would be, so I created a temp.
#p "Hello World"

File.foreach(f) do |line|
  temp_line = line.gsub(/[^\w\s]/, '') #gsub from StackOverflow
  stringArray = temp_line.split(' ')

  stringArray.each do |string|{}
  if string[0] =~ /[A-Z]/ && string[-1] =~ /[a-z]/
    output_File.write("#{string}")
    p string
    output_File.write("#{string} \n")
  end
  end
end


#p f
output_File.close
f.close
#tempf.close