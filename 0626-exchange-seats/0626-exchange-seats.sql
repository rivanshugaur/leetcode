Select 
CASE
WHEN id % 2 = 1 and id = (Select max(id) from seat) THEN id 
WHEN id % 2 = 1 THEN id + 1
ELSE id - 1
END
as id, student
from seat order by id;