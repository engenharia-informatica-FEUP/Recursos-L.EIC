-- A execução deste ficheiro pressupõe a execução prévia de LDD-Oficina-Estrutura-SQLite.sql e de LDD-Oficina-Dados-SQLite.sql

-- Gatilho que atribui como responsável da reparação o proprietário do 
-- carro, no caso de este atributo ser NULL.
-- Removi o max() que havia inicialmente porque me parece estar a mais. Só pode ser devolvido um idCliente no máximo por cada idCarro.
CREATE TRIGGER defaultCliente
AFTER INSERT ON Reparacao
FOR EACH ROW
WHEN (NEW.idCliente ISNULL)
BEGIN
  UPDATE Reparacao SET idCliente=(SELECT idCliente FROM Carro WHERE idCarro = NEW.idCarro) WHERE idReparacao=NEW.idReparacao;
END;

-- Gatilho que impede a atribuição de peças não compatíveis com o 
-- modelo do carro na reparacao. Também verifica se a quantidade de 
-- peças a utilizar existe em stock
CREATE TRIGGER validaPecasReparacao 
BEFORE INSERT ON ReparacaoPeca 
FOR EACH ROW
BEGIN 
SELECT CASE 
WHEN ((SELECT COUNT(*) FROM 
	 Peca, PecaModelo, Carro, Reparacao
	 WHERE Peca.idPeca = PecaModelo.idPeca
	 AND PecaModelo.idModelo = Carro.idModelo
	 AND Carro.idCarro = Reparacao.idCarro
	 AND Reparacao.idReparacao = NEW.idReparacao
	 AND Peca.idPeca = NEW.idPeca
	 AND Peca.quantidade >= NEW.quantidade) = 0) 
THEN RAISE(ABORT, 'Peça ou quantidade invalidos.')
END; 
END;

-- Gatilho que atualiza o stock de peças após inserção de registos na tabela ReparacaoPeca.
CREATE TRIGGER atualizaStockPecas 
AFTER INSERT ON ReparacaoPeca 
FOR EACH ROW
BEGIN 
  UPDATE Peca SET Quantidade = Quantidade - NEW.quantidade WHERE Peca.idPeca=NEW.idPeca;
END;

-- Gatilho INSTEAD OF
CREATE VIEW modelosMarcas AS
SELECT Modelo.nome AS nomeModelo, Marca.nome AS nomeMarca FROM Modelo, Marca
WHERE Modelo.idMarca=Marca.idMarca;


CREATE TRIGGER insertOnView 
INSTEAD OF INSERT ON modelosMarcas 
FOR EACH ROW
BEGIN 
  INSERT INTO Marca (nome) VALUES (NEW.nomeMarca);
  INSERT INTO Modelo (nome, idMarca) SELECT NEW.nomeModelo, idMarca FROM Marca WHERE nome=NEW.nomeMarca;
END;

-- Teste dos gatilhos validaPecasReparacao e atualizaStockPecas
--INSERT INTO ReparacaoPeca (idReparacao, idPeca, quantidade) VALUES (3, 1, 20);--Peça incompativel
--INSERT INTO ReparacaoPeca (idReparacao, idPeca, quantidade) VALUES (3, 2, 12);--Quantidade indiponível
--INSERT INTO ReparacaoPeca (idReparacao, idPeca, quantidade) VALUES (3, 2, 2);
--SELECT * FROM ReparacaoPeca;
--SELECT * FROM Peca;

-- Teste do gatilho defaultCliente
--INSERT INTO Reparacao (dataInicio, dataFim, idCliente, idCarro) VALUES ('2010-07-14', '2010-07-16', NULL, 5);
--SELECT * FROM Reparacao;

-- Teste do gatilho insertOnView
--INSERT INTO modelosMarcas VALUES ('Legacy 2.5i Premium','Subaru');
--INSERT INTO modelosMarcas VALUES ('Megane','Renault');
--SELECT * FROM Marca;
--SELECT * FROM Modelo;