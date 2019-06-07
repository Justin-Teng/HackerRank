SELECT
    N,
    CASE
        WHEN P IS NULL THEN 'Root'
        WHEN N in (SELECT P FROM BST) THEN 'Inner'
        ELSE 'Leaf'
    END
FROM BST
ORDER BY N
