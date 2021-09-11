class Shape a where
  name :: a -> String
  area :: a -> Float
  perimeter :: a -> Float

data Circle = Circle {r :: Float}
data Rectangle = Rectangle {w :: Float, h :: Float}

instance Shape Circle where
  name (Circle _) = "Circle"
  area (Circle r) = pi * r ^ 2
  perimeter (Circle r) = 2 * pi * r

instance Shape Rectangle where
  name (Rectangle _ _) = "Rectangle"
  area (Rectangle w h) = w * h
  perimeter (Rectangle w h) = 2 * w * 2 * h

printArea :: Shape a => a -> IO()
printArea s = putStrLn("My area is: " ++ show (area s) ++ "\n")

main = do
  printArea $ Circle 10
  printArea $ Rectangle 10 20
