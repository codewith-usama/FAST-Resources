--1
SELECT department_id, COUNT(employee_id) AS num_of_emp,
    ROUND(AVG(salary), 2) AS avg_salary
FROM employees
GROUP BY department_id;

--2
SELECT job_id, COUNT(employee_id)
FROM employees
WHERE job_id = job_id
GROUP BY job_id;

--3
SELECT first_name, hire_date
FROM employees
WHERE hire_date IN (SELECT hire_date
    FROM employees
    WHERE employee_id > 110);
    
--4
SELECT DISTINCT(department_name)
FROM departments, employees
WHERE salary > (SELECT MAX(salary)
    FROM employees
    WHERE salary > 15000);
    
--5
SELECT first_name || ' ' || last_name AS name,
    employee_id, job_id
FROM employees
WHERE salary < ALL (SELECT salary
    FROM employees
    WHERE job_id = 'IT_PROG');
    
--6
SELECT *
FROM employees
WHERE hire_date IS NULL;

--7
SELECT manager_id, salary
FROM employees
WHERE salary = ANY (SELECT salary
    FROM employees
    WHERE manager_id IS NOT NULL
    AND salary > 2000)
ORDER BY manager_id desc;

--8
CREATE TABLE employees_BKP
AS SELECT * FROM employees
WHERE 1 = 2;

INSERT INTO employees_BKP
SELECT *
FROM employees
WHERE hire_date IN (SELECT start_date
    FROM job_history
    WHERE start_date = '13-JAN-01');

--9
UPDATE employees_BKP
SET salary = (salary*0.2) + salary
WHERE employee_id IN (SELECT employee_id
    FROM employees_BKP
    WHERE salary = 6000);

--10
DELETE FROM employees_BKP
WHERE employee_id = (SELECT department_id
    FROM departments
    WHERE department_name = 'Finance');

--11
SELECT department_id, COUNT(employee_id)
FROM employees
WHERE salary > 20000
HAVING COUNT(employee_id) > 5;