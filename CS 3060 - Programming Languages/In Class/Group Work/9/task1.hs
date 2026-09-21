prod x y = x*y 
foo = prod 3
z1 = foo 4

expo x y = x^y
bar = expo 3
z2 = bar 4


-- What is foo? What does it compute/output?
--main :: IO ()
--main = do
    --let result = foo 4.35
    --print result



-- What is foo? What does it compute/output?
main :: IO ()
main = do
    let result = bar 5
    print result