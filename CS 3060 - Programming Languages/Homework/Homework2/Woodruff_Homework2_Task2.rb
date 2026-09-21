# frozen_string_literal: true
output_file = File.new("Homework2_readmeTask2.txt", "w")

def bar(n)
  totalVal = 1
  for i in 1..n
    totalVal = totalVal * n;
  end
  #p "#{newmap}"
  return totalVal
end

a1 = bar(5)
a2 = bar(6)
#p "#{a1}"
#p "#{a2}"

output_file.write("Foo(5): #{a1}" "\n", "Foo(6): #{a2}")
output_file.close