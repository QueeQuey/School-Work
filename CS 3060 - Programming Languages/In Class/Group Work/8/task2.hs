--myFunc x = (length x > 2) -- what is the type of myFunc?
--y = filter myFunc ["abc", "de", "f", "gghher"] -- what is the value of y? why?
--z = filter myFunc [[6,7,4,5], [0,1,2]] -- what is the value of z? why?

--Altered Code:
myFunc = \x -> (length x > 2) -- right hand side is an anonymous function
y = filter myFunc ["abc", "de", "f", "gghher"]
z = filter myFunc [[6,7,4,5], [0,1,2]]