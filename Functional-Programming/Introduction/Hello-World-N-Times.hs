import Control.Applicative
import Control.Monad
import System.IO

printNTimes 0 = return ()
printNTimes n = do
    putStrLn "Hello World"
    printNTimes (n-1)

main :: IO ()
main = do
    n_temp <- getLine
    let n = read n_temp :: Int
    printNTimes n

getMultipleLines :: Int -> IO [String]

getMultipleLines n
    | n <= 0 = return []
    | otherwise = do          
        x <- getLine         
        xs <- getMultipleLines (n-1)    
        let ret = (x:xs)    
        return ret          

