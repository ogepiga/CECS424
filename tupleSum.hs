tupleSum::(Num a)=>(a,a)->(a,a)->(a,a)
tupleSum (a,b) (c,d) = (a+c , b+d)

main = do 
    print(tupleSum (1,3)(12,67))
