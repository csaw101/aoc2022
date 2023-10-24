greater :: Int -> Int -> Int
greater a b = if a > b then a else b

stringToInt :: String -> Int
stringToInt str = read str :: Int

handle :: [String] -> Int -> Int -> Int
handle [] calorie_count max_calories = max_calories
handle xs calorie_count max_calories =
    if head xs /= "" then
        handle (tail xs) (calorie_count + stringToInt (head xs)) max_calories
    else
        handle (tail xs) 0 (greater calorie_count max_calories)

main = do
    input <- readFile "input.txt"
    let result = handle (lines input) 0 0
    print result
