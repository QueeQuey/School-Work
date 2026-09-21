myFunc :: [Int] -> Int
myFunc [] = 1
myFunc (h:t) = 2 * h * (myFunc t)
main = print(myFunc [3,1,2])