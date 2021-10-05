-- Apaga os registos das tabelas
DELETE FROM FuncionarioReparacao;
DELETE FROM Funcionario;
DELETE FROM Especialidade;
DELETE FROM PecaModelo;
DELETE FROM ReparacaoPeca;
DELETE FROM Peca;
DELETE FROM Reparacao;
DELETE FROM Carro;
DELETE FROM Cliente;
DELETE FROM CodPostal;
DELETE FROM Modelo;
DELETE FROM Marca;
DELETE FROM FuncionarioReparacao;
DELETE FROM Funcionario;
DELETE FROM Especialidade;

-- Inserção de registos na tabela codPostal
INSERT INTO CodPostal (codPostal1, localidade) VALUES ('4200','Porto');
INSERT INTO CodPostal (codPostal1, localidade) VALUES ('4400','Vila Nova de Gaia');
INSERT INTO CodPostal (codPostal1, localidade) VALUES ('4450','Matosinhos');

-- Inserção de registos na tabela Cliente
INSERT INTO Cliente (nome, morada, codPostal1, codPostal2, telefone)
	VALUES ('Alberto Sousa', 'Rua Brito e Cunha, 125','4450','086','932853425');
INSERT INTO Cliente (nome, morada, codPostal1, codPostal2, telefone)
	VALUES ('Maria Francisca Pereira Nobre','Avenida Meneres, 201','4450','191','933278005');
INSERT INTO Cliente (nome, morada, codPostal1, codPostal2, telefone)
	VALUES ('Rodrigo Meireles de Aguiar','Rua da Cunha, 310 1º Dir','4200','250','928604666');
INSERT INTO Cliente (nome, morada, codPostal1, codPostal2, telefone)
	VALUES ('Adão Lopes Sá','Rua Domingos de Matos, 200 3º Esq','4400','120','963670913');

-- Inserção de registos na tabela Marca
INSERT INTO Marca (nome) VALUES ('Renault');
INSERT INTO Marca (nome) VALUES ('Volvo');

-- Inserção de registos na tabela Modelo
INSERT INTO Modelo (nome, idMarca) 
	VALUES ('Clio 1.9D', 1);
INSERT INTO Modelo (nome, idMarca)
	VALUES ('V50 Momentum', 2);
INSERT INTO Modelo (nome, idMarca)
	VALUES ('C30 Drive', 2);

-- Inserção de registos na tabela Carro
INSERT INTO Carro (matricula, idModelo, idCliente)
	VALUES ('2490CV', 1, 4);
INSERT INTO Carro (matricula, idModelo, idCliente)
	VALUES ('36DH79', 2, 2);
INSERT INTO Carro (matricula, idModelo, idCliente)
	VALUES ('1127XY', 3, 3);
INSERT INTO Carro (matricula, idModelo, idCliente)
	VALUES ('78AB27', 3, 2);
INSERT INTO Carro (matricula, idModelo, idCliente)
	VALUES ('16IU02', 3, 4);

-- Inserção de registos na tabela Reparacao
INSERT INTO Reparacao (dataInicio, dataFim, idCliente, idCarro)
	VALUES ('2010-09-17', '2010-09-20', 1, 3);
INSERT INTO Reparacao (dataInicio, dataFim, idCliente, idCarro)
	VALUES ('2010-09-15', '2010-09-16', 4, 1);
INSERT INTO Reparacao (dataInicio, dataFim, idCliente, idCarro)
	VALUES ('2009-09-18', '2009-09-27', 4, 5);

SELECT * FROM Reparacao; -- Ver que o idCliente já não é NULL;

-- Inserção de registos na tabela Peca
INSERT INTO Peca (codigo, designacao, custoUnitario, quantidade)
	VALUES ('37XX98', NULL, 3, 100);
INSERT INTO Peca (codigo, designacao, custoUnitario, quantidade)
	VALUES ('75VBO98', NULL, 25, 10);

-- Inserção de registos na tabela PecaModelo
INSERT INTO PecaModelo (idPeca, idModelo) VALUES (1, 1);
INSERT INTO PecaModelo (idPeca, idModelo) VALUES (2, 3);

-- Inserção de registos na tabela ReparacaoPeca
INSERT INTO ReparacaoPeca (idReparacao, idPeca, quantidade) VALUES (2, 1, 8);
--INSERT INTO ReparacaoPeca (idReparacao, idPeca, quantidade) VALUES (3, 2, 2);

-- Inserção de registos na tabela Especialidade
INSERT INTO Especialidade(nome, custoHorario)
	VALUES ('Electricista', 15);
INSERT INTO Especialidade(nome, custoHorario)
	VALUES ('Mecânico', 12);
INSERT INTO Especialidade(nome, custoHorario)
	VALUES ('Chapeiro', 10);

-- Inserção de registos na tabela Funcionario
INSERT INTO Funcionario(nome, morada, codPostal1, codpostal2, telefone, idEspecialidade)
	VALUES ('Abel Sousa', 'Rua da Preciosa, 317-1º Esq', 4200, 137, '226903271', 1);
INSERT INTO Funcionario(nome, morada, codPostal1, codpostal2, telefone, idEspecialidade)
	VALUES ('Mário Teixeira', 'Rua Seca, 17', 4400, 210, '227519090', 2);
INSERT INTO Funcionario(nome, morada, codPostal1, codpostal2, telefone, idEspecialidade)
	VALUES ('Rogério Silva', 'Rua dos Caldeireiros, 312, 3ºF', 4400, 112, '227403728', 2);
INSERT INTO Funcionario(nome, morada, codPostal1, codpostal2, telefone, idEspecialidade)
	VALUES ('Luís Pereira', 'Rua Teixeira de Pascoaes, 117, 2º D', 4450, 117, '225901707', 3);

-- Inserção de registos na tabela FuncionarioReparacao
INSERT INTO FuncionarioReparacao (idFuncionario, idReparacao, numHoras) VALUES (1,1,1);
INSERT INTO FuncionarioReparacao (idFuncionario, idReparacao, numHoras) VALUES (4,1,4);
INSERT INTO FuncionarioReparacao (idFuncionario, idReparacao, numHoras) VALUES (1,2,1);
INSERT INTO FuncionarioReparacao (idFuncionario, idReparacao, numHoras) VALUES (2,2,6);
INSERT INTO FuncionarioReparacao (idFuncionario, idReparacao, numHoras) VALUES (4,2,2);
INSERT INTO FuncionarioReparacao (idFuncionario, idReparacao, numHoras) VALUES (1,3,1);
