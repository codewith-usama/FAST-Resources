-- 1
SELECT *
FROM jobs;

-- 2
SELECT min_salary, max_salary
FROM jobs
WHERE job_title = 'President';

-- 3
SELECT *
FROM employees
WHERE salary > 20000;

-- 4
SELECT *
FROM employees
WHERE salary >= 15000;

-- 5
SELECT employee_id, first_name, last_name
FROM employees
WHERE last_name = 'King';

-- 6
SELECT employee_id, first_name, last_name, department_id
FROM employees
WHERE department_id = 50;

-- 7
SELECT phone_number
FROM employees
WHERE department_id = 80
    AND manager_id = 100;

-- 8    
SELECT *
FROM employees
WHERE first_name IN ('NEENA', 'John', 'Lency');

-- 9
SELECT  city
FROM locations
WHERE country_id = 'IT';

-- 10
SELECT  city
FROM locations
WHERE country_id NOT IN ('IN', 'CH');

-- 11
SELECT job_title
FROM jobs
WHERE min_salary > 8000
    AND min_salary < 15000;

-- 12    
SELECT phone_number
FROM employees
WHERE department_id = 90
    AND job_id != 'IR_PROG';

-- 13
SELECT *
FROM employees
WHERE hire_date > '12-DEC-07';

-- 14
SELECT *
FROM employees
WHERE hire_date > '12-DEC-07'
    AND department_id = 100;

-- 15
SELECT *
FROM employees
WHERE hire_date > '12-DEC-07'
    AND department_id != 100;
