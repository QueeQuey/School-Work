#aFile = File.new("filename", "r")
#aFile.each{|x| p x}

# Gives program name - puts $0
#Can also PROGRAM_NAME

#a = ['human', 'tiger','dog']
#puts a[0]
#puts a[2]
#puts a[-1]

#sound = {'human' => 'talk', 'dog' => 'bark'}
#p sound ['dog']
#key1 = "human"
#key2 = "dog"

#arr = [1,2,3]
#puts arr.object_id
#arr.push(4)
#arr.object_id
#arr[5,6,7] #When assigned, the object changes
#arr.object_id

#Symbols - Kinda like pointers
#sym1 = :example
#sym2 = :example
#puts sym1.object_id
#puts sym2.object_id
#both sym1 and sym2 have the same obeject ID, confirming that they're the same object
#Symbols are preceded by a Colon

=begin
def greet(options = {})
  fn = options[:firstname]
  unless fn == nil
    puts "Hello #{fn}"
  else
    puts "Hello"
  end
end
greet({:firstname => "abc"})
greet
=end

#Strings are mutable!
#splitting Strings
#puts "abc's def ghi".split #default on spaces
#puts "abc's def ghi".scan(/\w+/) #Splits on spaces and aposterphe

#Regular Expression
=begin
x = /hardware|software/
if line =~ x
  puts "line includes pattern #{x}"
end
=end

=begin
Viven "File 1" read each line, append Line number at the begging
of the line, and write the append result to another file nameed "file2"
=end

=begin
#COMPLETED IN SLIDES
aFile = File.new("file1", "r")
bFile = File.new("file2", "w")
i=1
aFile.each do |x|
  newLine = 
  
=end

=begin
#Given named File 1 with each line having multiple words
#Populate a Hash with {key, value} pairs where key is the first word in a line of file 1
and value is the second word in the same line

=end