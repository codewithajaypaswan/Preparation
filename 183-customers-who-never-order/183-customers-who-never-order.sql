# Write your MySQL query statement below

# way 1 ------>
# select A.name as customers from Customers A
# where A.id not in(select B.customerId from Orders B);

# way 2 ------>
# select A.name as customers from Customers A
# where not exists (select B.customerId from Orders B where A.id = B.customerId); # instead B.customerId we can put (*) also

# Way 3 -----> (using left join)
select A.name as customers 
from Customers A LEFT JOIN Orders B
on A.id = B.customerId where B.customerId is NULL;