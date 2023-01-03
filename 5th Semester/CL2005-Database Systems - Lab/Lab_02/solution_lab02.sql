-- Simple Select Query
SELECT first_name, employee_id
FROM employees;

-- Use of Column Alias
SELECT hire_date
    AS joining_date
FROM employees;

-- Use of Concatenation Operator
SELECT first_name || ' ' || last_name
    AS Full_Name
FROM employees;

-- Use of DISTINCT, Asterisk and WHERE Keyword
-- 1
SELECT salary
FROM employees
WHERE salary > 20000 AND salary < 30000;

-- 2
SELECT employee_id, first_name
FROM employees
WHERE department_id BETWEEN 60 AND 100;

-- 3
SELECT *
FROM locations, employees
WHERE city IN ('Toronto', 'Hiroshima', 'Sydney');

-- 4
SELECT *
FROM employees
WHERE first_name LIKE '%ll%'
    OR first_name LIKE 'll%'
    OR first_name LIKE '%ll';

-- 5
SELECT *
FROM employees
WHERE commission_pct IS NULL;

-- Sorting Rows with Order by Clause
SELECT *
FROM employees
ORDER BY salary desc;

--Built In Oracle Functions
-- 1
SELECT INITCAP(first_name), LOWER(job_id) 
FROM employees;

-- 2
SELECT first_name , job_id,
    LENGTH(first_name) AS length_of_emp_name,
    INSTR(LOWER(first_name), 'a') AS position_of_A
FROM employees
WHERE job_id LIKE 'SA%';

-- 3
SELECT employee_id, hire_date,
    EXTRACT(Month FROM hire_date)
FROM employees
WHERE EXTRACT(Year FROM hire_date) = 2003;

-- 4
SELECT employee_id, EXTRACT(Month FROM hire_date),
    EXTRACT(Year FROM hire_date)
FROM employees;

-- 5
SELECT first_name, TO_CHAR(hire_date, 'dd Month, YYYY') AS date_format
FROM employees;

-- 6
SELECT LPAD(salary, LENGTH(salary)+1 ,'$')
FROM employees
WHERE first_name = 'Neena';

-- 7
SELECT NEXT_DAY(sysdate, 'Monday')
FROM DUAL;

--8
SELECT *
FROM employees
WHERE INSTR(LOWER(last_name), 'a') <> 0;

-- 9
SELECT SUBSTR(first_name, LENGTH(first_name)-2)
FROM employees;

--10
SELECT employee_id, hire_date, 
    ROUND(MONTHS_BETWEEN(sysdate, hire_date), 1) AS num_of_months,
    NEXT_DAY(hire_date, 'Friday') AS first_friday,
    TO_CHAR(LAST_DAY(hire_date), 'Dy') AS last_day
FROM employees
WHERE MONTHS_BETWEEN(sysdate, hire_date) > 100;

--Aggregate Functions
-- 1
SELECT employee_id, first_name || ' ' || last_name AS name,
    salary, (((salary/100) * 15) + salary) AS Incremented_Salary,
    (((salary/100) * 15) + salary) - salary AS Incremented_Amount
FROM employees;

-- 2
SELECT first_name || ' ' || last_name, hire_date,
    TO_CHAR(hire_date, 'Day') AS DAY
FROM employees
ORDER BY (NEXT_DAY(hire_date, 'Monday') - hire_date) DESC;

-- 3
SELECT department_id, manager_id,
    ROUND(commission_pct, 1)
FROM employees;

-- 4
SELECT *
FROM employees
WHERE commission_pct > 0
    AND department_id NOT IN (90, 100);

-- 5
SELECT *
FROM employees
WHERE EXTRACT(Year FROM hire_date) = 2010;

-- 6
SELECT DISTINCT(job_id)
FROM jobs
WHERE min_salary > 8000 AND max_salary < 15000;

-- 7
SELECT first_name, last_name, job_id
FROM employees
WHERE (employee_id > 100 AND employee_id < 150)
    AND (department_id > 90 AND department_id < 100);
    
-- 8
SELECT (salary*commission_pct) + salary AS total_salary, commission_pct
FROM employees
WHERE commission_pct IS NOT NULL;
