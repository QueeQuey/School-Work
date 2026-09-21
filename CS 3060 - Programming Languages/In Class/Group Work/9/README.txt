Task 1
{

Code:

-- Style 1: Using an anonymous function with `map`
style1 :: [Int] -> [Int]
style1 list = map (\x -> x * x) list

-- Style 2: Using `where` to define the square function
squareAll :: [Int] -> [Int]
squareAll list = map square list
  where square x = x * x

-- Main function to test both styles
main :: IO ()
main = do
    let result1 = style1 [4, 5, 6, 7]
    let result2 = squareAll [4, 5, 6, 7]
    putStrLn ("Style 1 Output: " ++ show result1)
    putStrLn ("Style 2 Output: " ++ show result2)


Answers:

The output of both functions are the same. This is partially due to the use
of map in both functions. Even though Style 1 uses an anonymous function while
Style 2 is using a named function, both of the contained functions apply the
same computation.

Output:

ghci> :load task8-1.hs
[1 of 2] Compiling Main             ( task8-1.hs, interpreted )
Ok, one module loaded.
ghci> main
Style 1 Output: [16,25,36,49]
Style 2 Output: [16,25,36,49]

}

Task 2
{
Original Code:

myFunc x = (length x > 2) -- what is the type of myFunc?
y = filter myFunc ["abc", "de", "f", "gghher"] -- what is the value of y? why?
z = filter myFunc [[6,7,4,5], [0,1,2]] -- what is the value of z? why?

Altered Code:
myFunc = \x -> (length x > 2) -- right hand side is an anonymous function
y = filter myFunc ["abc", "de", "f", "gghher"]
z = filter myFunc [[6,7,4,5], [0,1,2]]


Answers:

myFunc is considered a boolean. myFunc takes in a list of any
type and returns a boolean. This can be shown in the following
format:

    myFunc :: [a] -> Bool

The value of y is ["abc","gghher"]. This is because the purpose
of myFunc is to find any members in the list that have a length
greater than 2. So, ["abc","gghher"] are returned since "de"
and "f" are shorter than 3 characters.

The value of z is [[6,7,4,5],[0,1,2]]. This is because each element
of the list is longer than 2 characters. In this case, the elements
z are separated into [6,7,4,5] and [0,1,2]. These are not separated
any farther, since each element is considered like a string rather
than individual lists. So, both [6,7,4,5] and [0,1,2] are longer than
2 characters; therefore, both elements satisfy the condition provided
by myFunc.

The altered code provides the same results for the y and z. Even though
the altered code

Output:

ghci> :load task8-2.hs
[1 of 2] Compiling Main             ( task8-2.hs, interpreted )
Ok, one module loaded.
ghci> y
["abc","gghher"]
ghci> z
[[6,7,4,5],[0,1,2]]

Altered Code Output:

ghci> :load task8-2.hs
[1 of 2] Compiling Main             ( task8-2.hs, interpreted )
Ok, one module loaded.
ghci> y
["abc","gghher"]
ghci> z
[[6,7,4,5],[0,1,2]]

}



