mylist = [1, 3 .. 9]

foo m list = map(\y -> y^m) list
--Data.Typeable> typeOf list

f x  = foldl(+) 0 (foo x mylist)-- fill in the blank

--All ints