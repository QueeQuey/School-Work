# frozen_string_literal: true
output_file = File.new("GroupWork3_readmeTaskA3.txt", "w")

def foo(a1)
  k = "bad"
  a3 = a1.map do |word|
    if word.include? k #Similar to .scan(substr). Returns True if it contains the substring.
      "replaced"
    else
       word
    end
  end
end

#a1 =  foo ["clown","cloud","badminton","apple"]
#p "Printing new array:"
#p "#{a1}"

a1 = [1,9,7,4]
output_file.write("Printing a1: #{a1} \n" )


a2 = a1.map{|x| x**3 } #// output = ? why/how?
p "#{a2}"
output_file.write("a2 Prints the array a1 cubed: #{a2} \n" )

a3 = a1.select{|x| x %  3 > 1 } #// output = ? why/how?
p "#{a3}"
output_file.write("a3 Prints an empty array since all values have a modulo of 1 or 0 from 3: #{a2} \n")

y = a1.any?{|x| x*x >  25} #// output = ? why/how?
p "#{y}"
output_file.write("y Prints true since one of the values in a1 is greater than 25: #{a2} \n")

z = a1.all?{|x| x >  7} #// output = ? why/how?
p "#{z}"
output_file.write("z Prints false since NOT ALL of the values in a1 are greater than 7: #{a2} \n")


#output_file.write("Printing array: #{a1}")
output_file.close