foo :: [Char] -> Int
foo [] = 0
foo (_:t) = 1 + foo t

main = do
    print (foo "hello world")
    print (foo "")
    print (foo "Haskell")