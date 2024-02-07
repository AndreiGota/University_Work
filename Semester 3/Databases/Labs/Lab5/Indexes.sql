CREATE TABLE Ta (
	aid INT PRIMARY KEY,
	a2 INT UNIQUE,
	a3 INT
)

CREATE TABLE Tb (
	bid INT PRIMARY KEY,
	b2 INT
)

CREATE TABLE Tc (
	cid INT PRIMARY KEY,
	aid INT FOREIGN KEY REFERENCES Ta(aid),
	bid INT FOREIGN KEY REFERENCES Tb(bid)
)


-- Procedure to generate and insert random data into Ta
GO
CREATE OR ALTER PROCEDURE insertIntoTa(@rows INT) AS
BEGIN
	DECLARE @max INT
	SET @max = @rows*2 + 100
	WHILE @rows > 0
	BEGIN
		INSERT INTO Ta VALUES (@rows, @max, @max%210)
		SET @rows = @rows - 1
		SET @max = @max - 2
	END
END

-- Procedure to generate and insert random data into Tb
GO
CREATE OR ALTER PROCEDURE insertIntoTb(@rows INT) AS
BEGIN
	WHILE @rows > 0 
	BEGIN
		INSERT INTO Tb VALUES(@rows, @rows%542)
		SET @rows = @rows - 1
	END
END

-- Procedure to generate and insert random data into Tc
GO
CREATE OR ALTER PROCEDURE insertIntoTc(@rows INT) AS
BEGIN
	DECLARE @aid INT
	DECLARE @bid INT
	WHILE @rows > 0
	BEGIN
		SET @aid = (SELECT TOP 1 aid FROM Ta ORDER BY NEWID())
		SET @bid = (SELECT TOP 1 bid FROM Tb ORDER BY NEWID())
		INSERT INTO Tc VALUES(@rows, @aid, @bid)
		SET @rows = @rows - 1
	END
END

-- Inserting data
EXEC insertIntoTa 5000
EXEC insertIntoTb 7500
EXEC insertIntoTc 3000

SELECT *
FROM Ta

SELECT *
FROM Tb

SELECT *
FROM Tc

--a)
-- clustered index scan - scan the entire table 
-- cost: 0.0243376
SELECT *
FROM Ta

-- clustered index seek - return a specific subset of rows from a clustered index
-- cost: 0.0034569
SELECT *
FROM Ta
WHERE aid < 160

-- nonclustered index scan - scan the entire nonclustered index
--cost: 0.0213746
SELECT a2
FROM Ta
ORDER BY a2

-- nonclustered index seek - return a specific subset of rows from a nonclustered index
-- cost: 0.0033099
SELECT a2
FROM Ta
WHERE a2 BETWEEN 102 AND 150

-- key lookup - nonclustered index seek + key lookup - the data is found in a nonclustered index, but additional data is needed
-- cost: 0.0065704
SELECT a3, a2
FROM Ta
WHERE a2 = 500

-- b) Write a query on table Tb with a WHERE clause of the form WHERE b2 = value and analyze its execution plan. Create a nonclustered index that can speed up the query. Examine the execution plan again.
SELECT *
FROM Tb
WHERE b2 = 150

-- Before creating a nonclustered index we have a clustered index scan with the cost: 0.0322727
DROP INDEX Tb_b2_index ON Tb
CREATE NONCLUSTERED INDEX Tb_b2_index ON Tb(b2)
-- After creating the nonclustered index on b2, we have a noclustered index seek with the cost: 0.0032974

GO
CREATE OR ALTER VIEW View1 AS
	SELECT A.aid, B.bid, C.cid
	FROM Tc C
	INNER JOIN Ta A ON A.aid = C.aid
	INNER JOIN Tb B ON B.bid = C.bid
	WHERE B.b2 > 500 AND A.a3 < 150


SELECT *
FROM View1

-- With existing indexes(the automatically created ones + nonclustered index on b2): 0.14561
-- When adding a nonclustered index on a3 to the existing indexes: 0.130515
-- Without the nonclustered index on b2 and the nonclustered index on a3: 0.16252
-- Automatically created indexes + nonclustered index on b2 + nonclustered index on a3 + nonclustered index on (aid, bid) from Tc: 0.126071

DROP INDEX Ta_a3_index ON Ta
CREATE NONCLUSTERED INDEX Ta_a3_index ON Ta(a3)

DROP INDEX Tc_index ON Tc
CREATE NONCLUSTERED INDEX Tc_index ON Tc(aid, bid)