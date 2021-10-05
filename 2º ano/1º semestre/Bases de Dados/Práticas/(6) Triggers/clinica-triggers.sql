-- PT: A execução deste ficheiro pressupõe a execução prévia de LDDClinicaMedica.sql
-- ENG: you should execute the file LDDClinicaMedica.sql before this one

-- PT: Não permitir a marcação de uma consulta quando o número de marcações para esse dia ultrapassar a disponibilidade desse médico para esse dia. 
-- ENG: Do not allow to do an appointment when the number of appointments for that day exceeds the availability of that doctor for that day. 

DROP TRIGGER IF EXISTS validanumerodemarcacoes;

CREATE TRIGGER validanumerodemarcacoes
BEFORE INSERT ON ConsultasMarcadas
FOR EACH ROW
BEGIN 
SELECT CASE 
WHEN ((SELECT COUNT(*)-numdoentes FROM 
	 ConsultasMarcadas, Disponibilidade, HorarioConsultas
	 WHERE ConsultasMarcadas.codmedico=NEW.codmedico
	 AND ConsultasMarcadas.data=NEW.data
	 AND ConsultasMarcadas.data = Disponibilidade.dia
	 AND ConsultasMarcadas.codmedico = Disponibilidade.codigo
AND Disponibilidade.idHorarioConsulta=HorarioConsultas.idHorarioConsulta 
)>=0) 
THEN RAISE(ABORT, 'Marcacao nao perimitida por exceder o numero de doentes para esse dia.')
END; 
END;

-- PT: Não permitir marcar uma consulta com a mesma hora de início de uma outra consulta no mesmo dia, mesmo médico. 
-- ENG: Do not allow an appointment with the same start time than another appointment on the same day, same doctor. 

DROP TRIGGER IF EXISTS validanumerodemarcacoes;

CREATE TRIGGER validahorademarcacao
BEFORE INSERT ON ConsultasMarcadas
FOR EACH ROW
BEGIN 
SELECT CASE 
WHEN ((SELECT COUNT(*) FROM 
	 ConsultasMarcadas
	 WHERE ConsultasMarcadas.codmedico=NEW.codmedico
	 AND ConsultasMarcadas.data = NEW.data
	 AND ConsultasMarcadas.horainicio=NEW.horainicio)>0) 
THEN RAISE(ABORT, 'Marcacao nao perimitida para esse horario.')
END; 
END;


