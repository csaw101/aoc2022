import Data.List (sort)

greater :: Int -> Int -> Int
greater a b = if a > b then a else b

stringToInt :: String -> Int
stringToInt str = read str :: Int

removeSmallest :: Int -> [Int] -> [Int]
removeSmallest n xs = tail $ sort (xs ++ [n])

handle :: [String] -> Int -> [Int] -> [Int]
handle [] calorieCount maxCalories = removeSmallest calorieCount maxCalories
handle xs calorieCount maxCalories =
    if xHead /= "" then
        handle xTail calorieSum maxCalories
    else
        handle xTail 0 (removeSmallest calorieCount maxCalories)
    where
        xHead = head xs
        xTail = tail xs
        calorieSum = calorieCount + stringToInt xHead

main = do
    input <- readFile "input.txt"
    let result = handle (lines input) 0 [0, 0, 0]
    print $ sum result
