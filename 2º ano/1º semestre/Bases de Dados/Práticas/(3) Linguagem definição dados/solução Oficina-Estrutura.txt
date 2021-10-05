-- Apaga triggers
DROP VIEW IF EXISTS modelosMarcas;
DROP TRIGGER IF EXISTS defaultCliente;
DROP TRIGGER IF EXISTS AtualizaStockPecas;
DROP TRIGGER IF EXISTS validaPecasReparacao;
DROP TRIGGER IF EXISTS insertOnView;

-- Apaga tabelas
DROP Table IF EXISTS FuncionarioReparacao;
DROP Table IF EXISTS Funcionario;
DROP Table IF EXISTS Especialidade;
DROP Table IF EXISTS PecaModelo;
DROP Table IF EXISTS ReparacaoPeca;
DROP Table IF EXISTS Peca;
DROP Table IF EXISTS Reparacao;
DROP Table IF EXISTS Carro;
DROP Table IF EXISTS Cliente;
DROP Table IF EXISTS CodPostal;
DROP Table IF EXISTS Modelo;
DROP Table IF EXISTS Marca;

-- Cria tabelas
CREATE TABLE Marca (
idMarca INTEGER PRIMARY KEY AUTOINCREMENT,
nome NVARCHAR2(50) NOT NULL);

CREATE TABLE Modelo (
idModelo INTEGER PRIMARY KEY AUTOINCREMENT,
nome NVARCHAR2(50) NOT NULL,
idMarca NUMBER REFERENCES Marca(idMarca));

CREATE TABLE CodPostal (
codPostal1 CHAR(4) PRIMARY KEY,
localidade NVARCHAR2(30));

CREATE TABLE Cliente (
idCliente INTEGER PRIMARY KEY AUTOINCREMENT,
nome NVARCHAR2(50) NOT NULL, 
morada NVARCHAR2(50),
codPostal1 CHAR(4) REFERENCES CodPostal(codPostal1),
codPostal2 CHAR(3),
telefone CHAR(9));

CREATE TABLE Carro (
idCarro INTEGER PRIMARY KEY AUTOINCREMENT,
Matricula CHAR(6) UNIQUE,
idModelo NUMBER REFERENCES Modelo(idModelo),
idCliente NUMBER REFERENCES Cliente(idCliente));

CREATE TABLE Reparacao (
idReparacao INTEGER PRIMARY KEY AUTOINCREMENT,
dataInicio DATE,
dataFim DATE,
idCliente NUMBER REFERENCES Cliente(idCliente),
idCarro NUMBER REFERENCES Carro(idCarro),
CONSTRAINT ch_df_di CHECK (dataFim>=dataInicio));

CREATE TABLE Peca (
idPeca INTEGER PRIMARY KEY AUTOINCREMENT,
codigo CHAR(20) UNIQUE,
designacao NVARCHAR2(50),
custoUnitario NUMBER(9,3) CHECK (custoUnitario >= 0),
quantidade NUMBER(7,0) CHECK (quantidade >= 0));

CREATE TABLE ReparacaoPeca (
idReparacao NUMBER REFERENCES Reparacao(idReparacao),
idPeca NUMBER REFERENCES Peca(idPeca),
quantidade NUMBER(7,0) CHECK (quantidade >= 0),
CONSTRAINT pk_reparacao_peca PRIMARY KEY (idReparacao, idPeca));

CREATE TABLE PecaModelo (
idPeca NUMBER REFERENCES Peca(idPeca),
idModelo NUMBER REFERENCES Modelo(idModelo),
CONSTRAINT pk_peca_modelo PRIMARY KEY (idPeca, idModelo));

CREATE TABLE Especialidade (
idEspecialidade INTEGER PRIMARY KEY AUTOINCREMENT,
nome NVARCHAR2(50) NOT NULL,
custoHorario NUMBER(9,3) CHECK (custoHorario >= 0));

CREATE TABLE Funcionario (
idFuncionario INTEGER PRIMARY KEY AUTOINCREMENT,
nome NVARCHAR2(50) NOT NULL,
morada NVARCHAR2(50),
codPostal1 CHAR(4) REFERENCES CodPostal(codPostal1),
codPostal2 CHAR(3),
telefone CHAR(9),
idEspecialidade NUMBER REFERENCES Especialidade(idEspecialidade));

CREATE TABLE FuncionarioReparacao (
idFuncionario NUMBER REFERENCES Funcionario(idFuncionario),
idReparacao NUMBER REFERENCES Reparacao(idReparacao),
numHoras NUMBER(7,0) CHECK (numHoras >= 0),
CONSTRAINT pk_funcionario_reparacao PRIMARY KEY (idFuncionario, idReparacao));

