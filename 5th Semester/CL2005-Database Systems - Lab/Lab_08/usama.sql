--1
SET SERVEROUTPUT ON;
DECLARE 
    enum integer;
    esal integer;
BEGIN
    enum:=&enum;
    select salary into esal from employees where employee_id = enum;
    if(esal<1000) THEN
        esal := esal+(esal*0.1);
    ELSIF(esal>= 1000 and esal<=1500) THEN
        esal := esal+(esal*0.15);
    ELSIF(esal> 1500) THEN
        esal := esal+(esal*0.20);
    ELSE
        esal := 0;
    END IF;    
    dbms_output.put_line('Incremented salary is: '||esal);    
END;

--2
SET SERVEROUTPUT ON;
DECLARE 
    enum integer;
    esal integer;
    ecom float;
BEGIN
    enum:=&enum;
    select salary into esal from employees where enum=employee_id;
    select commission_pct into ecom from employees where enum = employee_id;
    if (ecom is not null) THEN
        esal := esal+(esal*ecom);
        update employees set salary = esal where enum=employee_id;
    else
        dbms_output.put_line('Commission is 0 ');
    end if;
END;

--3
SET SERVEROUTPUT ON;
DECLARE 
    dname varchar(40);
BEGIN
    select department_name into dname from departments d where d.DEPARTMENT_ID=30;
    dbms_output.put_line('The department name is: '||dname);
END;

--4
SET SERVEROUTPUT ON;
create or replace procedure getJobNature (dnum in integer)
as
    nature varchar(30);
BEGIN
    for v IN (select job_id,employee_id from employees where department_id = dnum)
    LOOP
        dbms_output.put_line('Job id for employee '|| v.employee_id || ' is: ' ||v.job_id);
    END LOOP;
END;
select getJobNature(20) from EMPLOYEES;

--5
SET SERVEROUTPUT ON;
create or replace procedure getSalary (dnum in integer)
as

BEGIN
    for v IN (select salary,employee_id from employees where department_id = dnum)
    LOOP
        dbms_output.put_line('Salary for employee '|| v.employee_id || ' is: ' ||v.salary);
    END LOOP;    
END;
    select getSalary(20) from employees;
    
--6
SET SERVEROUTPUT ON;
create or replace procedure updateSalary (empno in integer)
as
    
BEGIN
    update employees set salary = salary+(salary*10) where employee_id=empno;
    dbms_output.put_line('Salary Updated!');  
END;
    exec updateSalary(100);

--7
SET SERVEROUTPUT ON;
create or replace procedure getSalary (dnum in integer)
as
    
BEGIN
    update employees set salary = salary+1000 where salary>5000 and department_id=dnum;    
END;
exec getSalary(20);

--8
SET SERVEROUTPUT ON;
DECLARE 
    empno integer;
    fname varchar(30);
    dname varchar(30);
    hdate date;
BEGIN
    empno := &empno;
    select first_name into fname from employees 
    where employee_id = empno;
    select department_name into dname from departments 
    where department_id = (select department_id from employees 
    where employee_id = empno); 
    select hire_date into hdate from employees where employee_id = empno;
    dbms_output.put_line('The employee name is '|| fname);
    dbms_output.put_line('The employee department name is '|| fname);
    dbms_output.put_line('The employee hire date is '|| hdate);
END;


--9
SET SERVEROUTPUT ON;
DECLARE 
    num1 integer;
    num2 integer;
    sums integer;
BEGIN
    num1 := &num1;
    num2 := &num2;
    sums := num1+num2;
    dbms_output.put_line('The sum is: '|| sums);
END;

--10
SET SERVEROUTPUT ON;
DECLARE 
    num1 integer;
    num2 integer;
    sums integer;
BEGIN
    sums := 0;
    num1 := &num1;
    num2 := &num2;
    for a in num1..num2 LOOP
    sums := sums+a;
    END LOOP;
    dbms_output.put_line('The sum is: '|| sums);
END;

--11
SET SERVEROUTPUT ON;
DECLARE 
    empno integer;
    fname varchar(30);
    dname varchar(30);
    hdate date;
BEGIN
    empno := &empno;
    select first_name into fname from employees 
    where employee_id = empno;
    select department_name into dname from departments 
    where department_id = (select department_id from employees 
    where employee_id = empno); 
    select hire_date into hdate from employees where employee_id = empno;
    dbms_output.put_line('The employee name is '|| fname);
    dbms_output.put_line('The employee department name is '|| fname);
    dbms_output.put_line('The employee hire date is '|| hdate);
END;

--12
SET SERVEROUTPUT ON;
DECLARE 
temp integer;
numb integer;
rev integer;
BEGIN 
    rev := 0;
    numb := &numb;
    temp := numb;
    while temp>0 
    LOOP
        rev := rev*10;
        rev := rev + MOD(temp,10);
        temp := temp/10;
        
    END LOOP;
    IF(rev = numb) THEN
        dbms_output.put_line('Number is Paldindrome');
    ELSE
        dbms_output.put_line('Number is not Paldindrome');
    END IF;    
END;

--13
SET SERVEROUTPUT ON;
DECLARE 
EMPLOYEE_ID integer;
FIRST_NAME varchar(20);
LAST_NAME   varchar(20);
EMAIL   varchar(20);
PHONE_NUMBER    varchar(20);
HIRE_DATE   date;
JOB_ID  varchar(20);
SALARY  integer;
COMMISSION_PCT float;
MANAGER_ID  integer;
DEPARTMENT_ID   integer;
BEGIN 
    EMPLOYEE_ID := &EMPLOYEE_ID;
    FIRST_NAME := FIRST_NAME;
    LAST_NAME := LAST_NAME;
    EMAIL := EMAIL;
    PHONE_NUMBER := PHONE_NUMBER;
    HIRE_DATE := HIRE_DATE;
    JOB_ID := JOB_ID;
    SALARY := SALARY;
    COMMISSION_PCT := COMMISSION_PCT;
    MANAGER_ID := MANAGER_ID;
    DEPARTMENT_ID := DEPARTMENT_ID;
END;

--14
SET SERVEROUTPUT ON;
DECLARE
   salary         emp.sal%TYPE := 0;
   mgr_num        emp.mgr%TYPE;
   last_name      emp.ename%TYPE;
   starting_empno emp.empno%TYPE := 7499;
BEGIN
   SELECT mgr INTO mgr_num FROM emp 
      WHERE empno = starting_empno;
   WHILE salary <= 2500 LOOP
      SELECT sal, mgr, ename INTO salary, mgr_num, last_name
         FROM emp WHERE empno = mgr_num;
   END LOOP;
   INSERT INTO temp VALUES (NULL, salary, last_name);
   COMMIT;
EXCEPTION
   WHEN NO_DATA_FOUND THEN
      INSERT INTO temp VALUES (NULL, NULL, 'Not found');
      COMMIT;
END;


--15
SET SERVEROUTPUT ON;
DECLARE 
    sums integer;
BEGIN
    sums := 0;
    for a in 1..100 LOOP
    sums := sums+a;
    END LOOP;
    dbms_output.put_line('The sum is: '|| sums);
END;