# Seth Scholz, Layne Woodruff, James Roach, Joe Boyle
# CS 3060 - Fall 2024
# Group Activity 3B task 2 - Due September 20, 2024
def foo s
  p = /\w*[aoeiu]{2}\w*/ # this pattern represents a word with two consecutive vowels
  res = s.scan(p)
  puts res.inspect
end
foo("You are a beautiful human being")

