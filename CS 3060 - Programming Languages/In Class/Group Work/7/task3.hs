players = ["x","y", "z"]
matches = [(m, n) | m <- players, n <- players, m < n]
letters = ["a", "b", "c"]
lettermatches = [(m, n, o) | m <- letters, n <- letters, o <- letters, m /= n, m /= o, n /= o]



--main = print matches
main = print lettermatches