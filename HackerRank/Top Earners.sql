SELECT P.earnings, COUNT(*)
FROM (
    SELECT MAX(months * salary) AS earnings
    FROM Employee
) AS P, Employee AS E
WHERE E.months * E.salary = P.earnings
GROUP BY P.earnings;