CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
DECLARE M INT;
SET M=N-1;
  RETURN (
      # Write your MySQL query statement below.
      select ifnull(
          (select distinct Salary
          from Employee
          order by Salary DESC
          limit 1 offset M), null
      )
  );
END