CREATE DATABASE rick;
CREATE table children (
		childno INTEGER AUTO_INCREMENT NOT NULL,
		fname varchar(30),
		age INTEGER,
		PRIMARY KEY(chidno)
		);
INSERT INTO children(fname, age) VALUES("Jenny", 21);
INSERT INTO children(fname, age) VALUES("Andrew", 17);
SELECT childno, fname, age FROM children;
