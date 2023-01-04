--2
CREATE TABLE jobs
    AS SELECT * FROM hr.jobs
WHERE 1 = 2;

ALTER TABLE jobs
    MODIFY job_id PRIMARY KEY;
    
CREATE TABLE job_history
    AS SELECT * FROM hr.jobs
WHERE 1 = 2;


--3
ALTER TABLE jobs
    MODIFY job_id NUMERIC;

ALTER TABLE jobs
    MODIFY job_id VARCHAR2(10 BYTE);
    
--4
ALTER TABLE job_history ADD CONSTRAINT fk_key FOREIGN KEY(job_id)
    REFERENCES jobs(job_id);
    
--5
INSERT INTO jobs VALUES(12, 'Manager', 2000, 5000);
INSERT INTO job_history VALUES(12, 'Manager', 2000, 5000);

--6
ALTER TABLE jobs ADD Job_Nature VARCHAR(20);

--7
CREATE TABLE Replica_of_Employee 
    AS SELECT * FROM hr.employees;
    
TRUNCATE TABLE Replica_of_Employee;
--8
ALTER TABLE job_history ADD employee_id NUMBER;

ALTER TABLE Replica_of_Employee
    MODIFY employee_id PRIMARY KEY;
    
ALTER TABLE  job_history ADD CONSTRAINT emp_fk_key FOREIGN KEY(employee_id)
    REFERENCES Replica_of_Employee(employee_id);
    
--9
ALTER TABLE jobs DROP COLUMN Job_Nature;

--10
ALTER TABLE Replica_of_Employee ADD CONSTRAINT fname
    CHECK (first_name = UPPER(first_name));

--11
ALTER TABLE Replica_of_Employee ADD UNIQUE(salary);

--12
ALTER TABLE Replica_of_Employee MODIFY(phone_number NOT NULL);

--13
INSERT INTO Replica_of_Employee (employee_id, first_name, phone_number, salary)
    VALUES(190, 'MOHAMMAD', '0333-1234567', 50000);

--14
UPDATE Replica_of_Employee SET salary = 2000
WHERE salary < 1000
    AND employee_id = 105;
    
--15
ALTER TABLE Replica_of_Employee
    ADD PRIMARY KEY(job_id, employee_id);
--we cannot add two primary key in the same table    

--16
CREATE UNIQUE INDEX indx_job_id 
    ON job_history(job_id);

--17
TRUNCATE TABLE Replica_of_Employee;