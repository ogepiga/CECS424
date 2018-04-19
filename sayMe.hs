sayMe::(Integral a)=>a->String
sayMe 1 = "one"
sayMe 2 = "two"
sayMe 3 = "three"
sayMe 4 = "four"
sayMe x = "Not defined!"

main = do 
    print(sayMe 2)
    
