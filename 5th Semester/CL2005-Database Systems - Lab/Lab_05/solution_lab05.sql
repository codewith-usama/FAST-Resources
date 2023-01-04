--1
SELECT E.first_name || ' ' || E.last_name AS name,
    J.job_title, D.department_name, E.salary
FROM departments D JOIN employees E
    ON D.department_id = E.employee_id JOIN jobs J
    ON E.job_id = j.job_id
ORDER BY D.department_name;

--2
SELECT department_id, COUNT(employee_id)
FROM employees
GROUP BY department_id
HAVING COUNT(*) > 1;

--3
SELECT *
FROM employees E, jobs J
WHERE E.job_id = J.job_id
    AND E.salary < J.min_salary;

--4
SELECT E.first_name || ' ' || E.last_name AS name,
    D.department_name, E.salary, E.department_id,
    D.department_name, L.city
FROM employees E, departments D, jobs J, locations L
WHERE E.department_id = D.department_id
    AND D.location_id = L.location_id
    AND E.job_id != 'Analyst'
    AND E.salary = 60000;

--5
SELECT E1.employee_id, E1.first_name, E2.first_name AS Manager_name
FROM employees E1 JOIN employees E2
    ON E1.manager_id = E2.manager_id;

--6
SELECT D.department_id, D.department_name
FROM departments D LEFT JOIN employees E
    ON d.department_id = E.department_id
WHERE E.employee_id IS NULL;

--7
SELECT E.first_name, E.salary, D.department_name
FROM employees E RIGHT JOIN departments D
    ON E.department_id = D.department_id;

--8
SELECT E.first_name, J.job_id, D.department_name,
    L.street_address, L.city, l.state_province
FROM jobs J JOIN employees E 
    ON J.job_id = E.job_id
    JOIN departments D
    ON E.department_id = D.department_id RIGHT JOIN locations L
    ON D.location_id = L.location_id
WHERE L.state_province IS NULL;

--9
SELECT *
FROM employees E 
    LEFT JOIN departments D
    ON E.department_id = D.department_id
WHERE E.DEPARTMENT_ID IS NULL;


--10
SELECT E.*, L.country_id, L.state_province
FROM employees E JOIN departments D
    ON E.department_id = D.department_id
    JOIN locations L ON D.location_id = L.location_id
WHERE L.country_id = 'US'
    AND state_province != 'Washington';
