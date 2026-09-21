# Find the first name and last name of employees who work in a project which is done in Houston

use aheydar;

Select Fname, Lname
From EMPLOYEE
Where Ssn in
(Select Essn
From WORKS_ON
where Pno in 
(Select Pnumber
From PROJECT
Where Plocation = 'Houston'));

