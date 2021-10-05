--
-- File generated with SQLiteStudio v3.2.1 on quarta abr 15 20:50:13 2020
--
-- Text encoding used: UTF-8
--
PRAGMA foreign_keys = off;
BEGIN TRANSACTION;

-- Table: aluno
DROP TABLE IF EXISTS aluno;
CREATE TABLE aluno (nr INTEGER PRIMARY KEY, Nome TEXT);
INSERT INTO aluno (nr, Nome) VALUES (100, 'Joao');
INSERT INTO aluno (nr, Nome) VALUES (110, 'Manuel');
INSERT INTO aluno (nr, Nome) VALUES (120, 'Rui');
INSERT INTO aluno (nr, Nome) VALUES (130, 'Abel');
INSERT INTO aluno (nr, Nome) VALUES (140, 'Fernando');
INSERT INTO aluno (nr, Nome) VALUES (150, 'Ismael');

-- Table: cadeira
DROP TABLE IF EXISTS cadeira;
CREATE TABLE cadeira (cod TEXT PRIMARY KEY, Design TEXT, curso TEXT, regente TEXT REFERENCES prof (sigla));
INSERT INTO cadeira (cod, Design, curso, regente) VALUES ('TS1', 'Teoria dos sistemas I', 'IS', 'FNF');
INSERT INTO cadeira (cod, Design, curso, regente) VALUES ('BD', 'Bases de Dados', 'IS', 'ECO');
INSERT INTO cadeira (cod, Design, curso, regente) VALUES ('EIA', 'Estruturas de Informacao e Algoritmos', 'IS', 'ECO');
INSERT INTO cadeira (cod, Design, curso, regente) VALUES ('EP', 'Electronica de Potencia', 'AC', 'JLS');
INSERT INTO cadeira (cod, Design, curso, regente) VALUES ('IE', 'Instalacoes Eletricas', 'AC', 'JLS');

-- Table: prof
DROP TABLE IF EXISTS prof;
CREATE TABLE prof (sigla PRIMARY KEY, Nome);
INSERT INTO prof (sigla, Nome) VALUES ('ECO', 'Eugenio');
INSERT INTO prof (sigla, Nome) VALUES ('FNF', 'Fernando');
INSERT INTO prof (sigla, Nome) VALUES ('JLS', 'Joao');
INSERT INTO prof (sigla, Nome) VALUES ('JRS', 'Joao');

-- Table: prova
DROP TABLE IF EXISTS prova;
CREATE TABLE prova (nr INTEGER REFERENCES aluno (nr), cod TEXT REFERENCES cadeira (cod), data DATE, nota INTEGER, PRIMARY KEY (nr, cod, data));
INSERT INTO prova (nr, cod, data, nota) VALUES (100, 'TS1', '92-02-11', 8);
INSERT INTO prova (nr, cod, data, nota) VALUES (100, 'TS1', '93-02-02', 11);
INSERT INTO prova (nr, cod, data, nota) VALUES (100, 'BD', '93-02-04', 17);
INSERT INTO prova (nr, cod, data, nota) VALUES (100, 'EIA', '92-01-29', 16);
INSERT INTO prova (nr, cod, data, nota) VALUES (100, 'EIA', '93-02-02', 13);
INSERT INTO prova (nr, cod, data, nota) VALUES (110, 'EP', '92-01-30', 12);
INSERT INTO prova (nr, cod, data, nota) VALUES (110, 'IE', '92-02-05', 10);
INSERT INTO prova (nr, cod, data, nota) VALUES (120, 'TS1', '93-01-31', 15);
INSERT INTO prova (nr, cod, data, nota) VALUES (120, 'EP', '93-02-04', 13);
INSERT INTO prova (nr, cod, data, nota) VALUES (130, 'BD', '93-02-04', 12);
INSERT INTO prova (nr, cod, data, nota) VALUES (130, 'EIA', '93-02-02', 7);
INSERT INTO prova (nr, cod, data, nota) VALUES (130, 'TS1', '92-02-11', 8);
INSERT INTO prova (nr, cod, data, nota) VALUES (140, 'TS1', '93-01-31', 10);
INSERT INTO prova (nr, cod, data, nota) VALUES (140, 'TS1', '92-02-11', 13);
INSERT INTO prova (nr, cod, data, nota) VALUES (140, 'EIA', '93-02-02', 11);
INSERT INTO prova (nr, cod, data, nota) VALUES (150, 'TS1', '92-02-11', 10);
INSERT INTO prova (nr, cod, data, nota) VALUES (150, 'EP', '93-02-02', 11);
INSERT INTO prova (nr, cod, data, nota) VALUES (150, 'BD', '93-02-04', 17);
INSERT INTO prova (nr, cod, data, nota) VALUES (150, 'EIA', '92-01-29', 16);
INSERT INTO prova (nr, cod, data, nota) VALUES (150, 'IE', '93-02-02', 13);
INSERT INTO prova (nr, cod, data, nota) VALUES (110, 'IE', '93-02-01', 14);

COMMIT TRANSACTION;
PRAGMA foreign_keys = on;
