# frozen_string_literal: true
output_file = File.new("GroupWork3_readmeTaskA2.txt", "w")

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

a1 =  foo ["clown","cloud","badminton","apple"]

p "Printing new array:"
p "#{a1}"

output_file.write("Printing array: #{a1}")
output_file.close