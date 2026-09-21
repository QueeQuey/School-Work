# Seth Scholz, Layne Woodruff, James Roach, Joe Boyle
# CS 3060 - Fall 2024
# Group Activity 3B task 1 - Due September 20, 2024
def sum_of_cubes(a, b)
  result = (a..b).inject(0) { |sum, x| sum + (x**3) }
  return result
end

puts sum_of_cubes(5, 10)