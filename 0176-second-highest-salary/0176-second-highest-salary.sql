SELECT (
    SELECT DISTINCT e1.salary
    FROM Employee AS e1
    WHERE 2 = (
        SELECT COUNT(DISTINCT e2.salary)
        FROM Employee AS e2
        WHERE e2.salary >= e1.salary
    )
) AS SecondHighestSalary;