--Lab 3 - CECS424
--Taina Coleman 012535859
--1 
maxi :: Integer->Integer->Integer 
maxi a b = max a b

--2
fib :: Integer->Integer
fib 0 = 0
fib n = product[1..n]

--3
doubleList :: [Integer]->[Integer]
doubleList [] =[]
doubleList (a:xs) = a*2:doubleList xs 

--4
myconcat :: [[a]]->[a]
myconcat [] = []
myconcat [x] = x
myconcat (x:xs)= x ++ (myconcat xs)

--5
prefix :: [a] -> [[a]]
prefix [] = [[]]
prefix x = (prefix (init x))++[x]
 
main = do 
    print(maxi 5 78)
    print(fib 4)
    print(doubleList [1,2,3,4])
    print(myconcat [[1,2],[3,4],[5,6]])
    print(prefix [1,2,3])
    
