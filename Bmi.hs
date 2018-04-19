bmiTell::(RealFloat a) => a -> a -> String
bmiTell weight height 
    | bmi <= skinny = "underweight"
    | bmi <= normal = "normal"
    | bmi <= fat    = "overweight"
    | otherwise     = "super overweight"
    where bmi = weight / height ^ 2
          skinny = 18.5 
          normal = 25.0
          fat = 30.0

main = do
    print (bmiTell 50 165)
