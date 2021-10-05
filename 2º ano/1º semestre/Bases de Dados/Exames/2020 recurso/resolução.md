> [Original resolution](https://github.com/dmfrodrigues/feup-bdad-ex/blob/master/exams/2020R/2020R.md) made by [Diogo Rodrigues](https://github.com/dmfrodrigues), [João António Sousa](https://github.com/JoaoASousa) and [Tomás Agante Martins](https://github.com/tagantemartins)
> <br>
> A resolução aqui presente tem algumas modificações/correções em relação à publicação original. 

## Pergunta 1

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✔        | A melhor resposta, por exclusão de partes. |
| **b.** | ✖        | Uma `Contracted Person` é uma especialização de `Person`, logo só pode corresponder a uma `Person`. |
| **c.** | ✖        | Não quero responder. |
| **d.** | ✖        | Uma `Contracted Person` é uma especialização de `Person`, logo a relação tem que ser uma generalização, e não uma associação. |
| **e.** | ✖        | A generalização não pode ser `complete`, porque nem todas as pessoas foram contratadas. |

## Pergunta 2

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✖        | Não se menciona o `date/time` da viagem. |
| **b.** | ✖        | Uma viagem não é um conjunto de percursos, mas sim uma sequência. |
| **c.** | ✖        | Não quero responder. |
| **d.** | ✖        | Uma viagem pode ter vários percursos, não só um local de início e outro de fim. |
| **e.** | ✔        | A melhor resposta, por exclusão de partes. |

## Pergunta 3

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✖        | `CarModel` não tem nenhum atributo `model`. |
| **b.** | ✖        | Não quero responder. |
| **c.** | ✖        | Muito confuso, uma relação ternária só dá origem a uma relação. |
| **d.** | ✖        | `promotion` tem que ser uma chave externa. |
| **e.** | ✔        | A melhor resposta, por exclusão de partes. |

## Pergunta 4

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✖        | Não quero responder. |
| **b.** | ✖        | Uma `Salad` só consegue apontar para duas plantas. |
| **c.** | ✖        | Um `ingredient` não precisa de apontar para uma salada. |
| **d.** | ✔        | Possivelmente correta. Apesar disso, dá para meter mais que um sauce em cada Salad |
| **e.** | ✖        | Se for planta, countyr é NULL; se for sauce, color é NULL... |

## Pergunta 5

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** UNIQUEs e chaves externas/estrangeiras   | ✖        | O enunciado pede por "restrições adicionais". As chaves estrangeiras são sempre obrigatórias. |
| **b.** NOT NULLs e chaves externas/estrangeiras | ✖        | |
| **c.** UNIQUEs                                  | ✔        | |
| **d.** Não quero responder                      | ✖        | |
| **e.** NOT NULLs                                | ✖        | |

## Pergunta 6

>**Algorithm to construct minimal basis from T:**
><br>
> If there is an FD F in T that follows from the other FDs in T, remove F from T.
><br>
> 1. Let Y → B be an FD in T, with at least two attributes in Y,and let Z be Y with one of its attributes removed. If Z → B follows from the FDs in T(including Y → B), then replace Y → B by Z → B.
> 2. Repeat the above steps in all possible ways until no more changes to T can be made.

```
R(A,B,C,D,E)

A  → BC
AC → E
BE → D
```

**Para `AC → E`:**

`A → E` segue-se das FDs?

`C → E` segue-se das FDs?

`A+ = ABCDE`, `A` determina `E` logo podemos substituir `AC → E` por `A → E`.

`C+ = C`, `C` não determina `E` logo `C → E` não se segue das FDs.

<br>

**Para `BE → D`:**

`B → D` segue-se das FDs?

`E → D` segue-se das FDs?

`B+ = B`, `B` não determina `D` logo `B → D` não se segue das FDs.

`E+ = E`, `E` não determina `D` logo `E → D` não se segue das FDs.

<br>

Ficamos, então com:
```
A  → BC
A → E
BE → D
```

Podemos juntar pela regra da combinação as duas primeiras FDs `A  → BC`, `A → E`.

A base mínima é:
```
A  → BCE
BE → D
```

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✖        | -    |
| **b.** | ✔        | -    |
| **c.** | ✖        | Não quero responder. |
| **d.** | ✖        | -    |
| **e.** | ✖        | -    |

## Pergunta 7

> **Algorithm for projecting FDs:**
> <br>
> 1. X+, for every set of attributes X of R1
> 2. T : all FDs X → Y such that Y⊆X+, Y is an attribute of R1 and Y not contained in X
> 3. Construct minimal basis

```
R(A,B,C,D,E)

A->BC
AC->E
BE->D

FDs for R1(A,C,D)
```

| Fecho        | FDs      |
|--------------|----------|
| A+ = ABCDE   | A->CD    |
| C+ = C       | -        | 
| D+ = D       | -        | 
| AC+ = ABCDE  | AC->D    | 
| AD+ = ABCDE  | AD->C    | 
| CD+ = CD     | -        | 
| ACD+ = ABCDE | -        | 

T da nova relação R1(A,C,D) será:
```
A->CD
AC->D
AD->C
```

**Construct minimal basis:** 
<br>
**Para `AC → D`:**

`A → D` segue-se das FDs?

`C → D` segue-se das FDs?

`A+ = ACD`, `A` determina `D` logo podemos substituir `AC → D` por `A → D`.

`C+ = C`, `C` não determina `D` logo `C → D` não se segue das FDs.

<br>

**Para `AD → C`:**

`A → C` segue-se das FDs?

`D → C` segue-se das FDs?

`A+ = ACD`, `A` determina `C` logo podemos substituir `AD → C` por `A → C`.

`D+ = D`, `D` não determina `C` logo `D → C` não se segue das FDs.

<br>

Ficamos, então com:
```
A->CD
A->D
A->C
```

Podemos juntar pela regra da combinação as duas últimas FDs `A  → D`, `A → C`.

A base mínima é:
```
A->CD
```

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✖        | `B` não faz parte de `R1` |
| **b.** | ✖        | Não quero responder. |
| **c.** | ✖        | Falso, porque encontrámos uma resposta correta. |
| **d.** | ✖        | |
| **e.** | ✔        | |

## Pergunta 8

```
R(A,B,C,D,E)

A->BC
AC->E 
BE->D 
```

`R` está trivialmente na 1NF.
<br>

**Verificar se está na BCNF:**
> A relação R está na BCNF se o lado esquerdo de todas as dependência não-trivais for uma superkey. 

A única chave candidata é `{A}` (`{A}+ = {A, B, C}+ = {A, B, C, E}+ = {A, B, C, D, E}+ = {A, B, C, D, E}`).
<br>
Ora, a `BE->D` viola a BCNF, pois `BE` não é uma superkey. 
<br>

**Verificar se está na 3NF:**
> A relação R está na 3NF se pelo menos uma das seguintes condições se verifica para todas as dependências não trivais X → Y:
> <br>
> 1.  X é uma superkey ou
> 2.  Y é um atributo primo (cada elemento de Y pertence a alguma chave candidata)

Ora, a `BE->D` viola a 3NF, pois nem `BE` é uma superkey, nem `D` pertence à chave candidata. 
<br>

**Verificar se está na 2NF:**

> A relação R está na 2NF se R não contiver nenhuma dependência parcial (subconjunto da chave candidata a determinar atributos não-primos - atributos que pertencem a nenhuma chave candidata).

Tal se verifica, logo a relação R está na 2ª forma normal. 

| Item                              | Resposta |
|-----------------------------------|----------|
| **a.** Forma normal de Boyce-Codd | ✖        |
| **b.** 1ª Forma Normal            | ✖        |
| **c.** Não quero responder        | ✖        |
| **d.** 3ª Forma Normal            | ✖        |
| **e.** 2ª Forma Normal            | ✔        |


## Pergunta 9

|      | A  | B  | C  | D  | E  |
|------|----|----|----|----|----|
| `R1` | a  | b  | c  | d1 | e1 |
| `R2` | a2 | b  | c  | d  | e2 |
| `R3` | a  | b3 | c  | d3 | e  |

`A → D`

|      | A  | B  | C  | D  | E  |
|------|----|----|----|----|----|
| `R1` | a  | b  | c  | d1 | e1 |
| `R2` | a2 | b  | c  | d  | e2 |
| `R3` | a  | b3 | c  | d1 | e  |

`D → E`

|      | A  | B  | C  | D  | E  |
|------|----|----|----|----|----|
| `R1` | a  | b  | c  | d1 | e  |
| `R2` | a2 | b  | c  | d  | e2 |
| `R3` | a  | b3 | c  | d1 | e  |

`B → D`

|      | A  | B  | C  | D  | E  |
|------|----|----|----|----|----|
| `R1` | a  | b  | c  | d  | e  |
| `R2` | a2 | b  | c  | d  | e2 |
| `R3` | a  | b3 | c  | d1 | e  |

`A → D`

|      | A  | B  | C  | D  | E  |
|------|----|----|----|----|----|
| `R1` | a  | b  | c  | d  | e  |
| `R2` | a2 | b  | c  | d  | e2 |
| `R3` | a  | b3 | c  | d  | e  |

`D → E`

|      | A  | B  | C  | D  | E  |
|------|----|----|----|----|----|
| `R1` | a  | b  | c  | d  | e  |
| `R2` | a2 | b  | c  | d  | e  |
| `R3` | a  | b3 | c  | d  | e  |

| Item                              | Resposta | Nota |
|-----------------------------------|----------|------|
| **a.**                            | ✔        | Resposta correta. |
| **b.**                            | ✖        | Não é uma coluna, é uma linha. |
| **c.**                            | ✖        | Não interessa se nenhuma linha tem só subscritos. |
| **d.** Não quero responder        | ✖        |      |
| **e.**                            | ✖        | A 1ª linha ficou só com símbolos com subscrito. |

## Pergunta 10

**d.** ✔
```
π_{nome}((σ_{massa='fina'} pizza) ⋈_{nome=nomepizza} (σ_{nomeingrediente='camarão'} feita))
```

## Pergunta 11

| Item                              | Resposta | Nota |
|-----------------------------------|----------|------|
| **a.** `INSERT INTO V VALUES('teste')`                  | ✖        |      |
| **b.** Não quero responder                              | ✖        |  |
| **c.** Todas as atualizações apresentadas são ambíguas. | ✔        | Resposta correta (acho eu). |
| **d.** `UPDATE V SET A='teste'`                           | ✖        |      |
| **e.** `DELETE FROM V WHERE A='teste'`        | ✖        |      |

## Pergunta 12

| Item                              | Resposta | Nota |
|-----------------------------------|----------|------|
| **a.** `AFTER INSERT ON R`        | ✖        |      |
| **b.** `INSTEAD OF INSERT ON V`   | ✔        | Resposta correta. |
| **c.** `INSTEAD OF INSERT ON R`   | ✖        |      |
| **d.** `BEFORE INSERT ON R`       | ✖        |      |
| **e.** Não quero responder        | ✖        |      |

## Pergunta 13

```sql
SELECT nomepizza FROM feita WHERE nomeingrediente='camarão';
```

| Item                              | Resposta | Nota |
|-----------------------------------|----------|------|
| **a.**                            | ✖        |      |
| **b.**                            | ✖        |      |
| **c.** Não quero responder        | ✖        |      |
| **d.**                            | ✖        |      |
| **e.**                            | ✔        | Resposta correta. |

## Pergunta 14

| Item                              | Resposta | Nota |
|-----------------------------------|----------|------|
| **a.** Repeatable Read.           | ✖        |      |
| **b.** Não quero responder.       | ✖        |      |
| **c.** Read Uncommited            | ✖        |      |
| **d.** Serializable.              | ✖        |      |
| **e.** Read Commited.             | ✔        | Resposta correta. |

## Pergunta 15

| Item                                                                                           | Resposta | Nota |
|------------------------------------------------------------------------------------------------|----------|------|
| **a.** Sistema que regista e analisa os registos de pesquisa no Google                         | ✖        | DB muito grande. |
| **b.** Banco online                                                                            | ✔        | Consistência é muito importante. |
| **c.** Aplicação web de companhia aérea que permite aos clientes escolherem o seu lugar no voo | ✔        | Consistência é muito importante. |
| **d.** Sistema de Informação Universitário (p.ex.: SIGARRA)                                    | ✔        | Consistência é importante. Base de dados não é assim tão grande. |
| **e.** Sistema que analisa a estrutura de todas as páginas Wikipedia                           | ✖        | DB muito grande. |
| **f.** Loja de comércio eletrónico                                                             | ✔        | Consistência importante (determinar se tem em stock ou não). |
| **g.** Sistema que analisa as relações e dinâmica existente no LinkedIn                        | ✖        | DB muito grande. |

## Pergunta 16

```sql
SELECT DISTINCT Speaker.Name, Talk.Title, Speaker.Country
FROM Speaker, Talk
WHERE Talk.Speaker = Speaker.Id
ORDER BY Speaker.Country ASC;
```

## Pergunta 17

```sql
SELECT Name
FROM Speaker JOIN Talk
WHERE Talk.Speaker = Speaker.Id
GROUP BY Id
HAVING COUNT(*) > 1;
```

## Pergunta 18

```sql
SELECT DISTINCT Topic.Name 
FROM Topic 
WHERE Topic.Id NOT IN 
	(
		SELECT Talk.topic
		FROM Talk 
	);
```

## Pergunta 19

```sql
SELECT Name, COUNT(Day)
FROM (
    SELECT DISTINCT Id, Name, Day
    FROM Topic
    LEFT JOIN Talk ON Topic.Id=Talk.topic
)
GROUP BY Id
ORDER BY Name;
```
