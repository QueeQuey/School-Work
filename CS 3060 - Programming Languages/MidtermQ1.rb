#Layne Woodruff
# CS 3060 - Fall 2024
output_file = File.new("MidtermQ1.txt", "w")
def foo(a1, a2) #a1 array of string, #a2 ints
  h = {}
  a1.each_with_index do |x, i| #for each element of a1, element i
    #x = i -> #ith element of a1 is already done through x.
    v = a2[i] #ith element of a2
    if v && v > 50 #need to have first v for existence.
      h[x] = v
      end
  end
  h
end

a1 = ["p", "x", "abc", "w"]
a2 = [20, 200, 1000]
#puts(foo(a1, a2))
output_file.write("#{foo(a1, a2)}")