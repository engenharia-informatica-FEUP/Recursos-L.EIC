## Pergunta 1
O asterisco ao pé do símbolo da agregação serve apenas para confundir e não influencia a resposta. 
<br>
| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✖        |  |
| **b.** | ✔        |  |
| **c.** | ✖        |  |
| **d.** | ✔        |  |

## Pergunta 2

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✖        |  |
| **b.** | ✖        | Não quero responder. |
| **c.** | ✔        | É a definição. |
| **d.** | ✖        |  |
| **e.** | ✖        |  |

## Pergunta 3

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✖        | |
| **b.** | ✔        | Um paciente pode não fazer nenhum teste ou fazer vários. Mas um teste tem apenas um paciente associado. |
| **c.** | ✖        | |
| **d.** | ✖        | Não quero responder. |
| **e.** | ✖        | |

## Pergunta 4

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✖        |  |
| **b.** | ✖        | Não quero responder. |
| **c.** | ✔        |  |
| **d.** | ✔        |  |
| **e.** | ✖        |  |

## Pergunta 5

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✔        | |
| **b.** | ✖        | |
| **c.** | ✖        | |
| **d.** | ✖        | Não quero responder. |
| **e.** | ✖        |  |

## Pergunta 6

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✖        | |
| **b.** | ✖        | |
| **c.** | ✔        | |
| **d.** | ✔        | |

## Pergunta 7

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✔        | Em generalições completas, se o método de "Object-oriented" for usado, podemos eliminar a superclasse `Person`. |
| **b.** | ✖        | |
| **c.** | ✖        | O método de "Use nulls" está bem aplicado, no entanto, uma vez que esta é uma generalização exclusiva, não se trata de uma conversão adequada. |
| **d.** | ✔        | |

## Pergunta 8

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✔        | A chave estrangeria está sempre associado ao lado "many". |
| **b.** | ✖        | A terceira relação de associação, sendo do tipo many-to-one, terá apenas 1 chave primária: a que está associada ao lado “many”, ou seja, `plate`. |
| **c.** | ✔        | |
| **d.** | ✖        | |

## Pergunta 9

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✖        | |
| **b.** | ✔        | |
| **c.** | ✔        | |

## Pergunta 10

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✔        | |
| **b.** | ✔        | |
| **c.** | ✖        | |
| **d.** | ✖        | |

## Pergunta 11

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✖        | |
| **b.** | ✖        | |
| **c.** | ✔        | |
| **d.** | ✔        | |

## Pergunta 12

`{A, F, G}+ = {A, D, F, G}+ = {A, D, E, F, G}+ = {A, C, D, E, F, G}+`

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✔        | |
| **b.** | ✖        | |
| **c.** | ✔        | |
| **d.** | ✔        | |
| **e.** | ✔        | |
| **f.** | ✔        | |
| **g.** | ✔        | |
| **h.** | ✖        | |
| **i.** | ✖        | |

## Pergunta 13

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✔        | Se está na BCNF, também está na 3NF. |
| **b.** | ✔        | |
| **c.** | ✖        | Tal nem sempre se verifica, por exemplo, a BCNF não garante preservação das dependências. |
| **d.** | ✖        | |

## Pergunta 14

> **Algorithm for projecting FDs:**
> <br>
> 1. X+, for every set of attributes X of R1
> 2. T : all FDs X → Y such that Y⊆X+, Y is an attribute of R1 and Y not contained in X
> 3. Construct minimal basis


| Fecho        | FDs      |
|--------------|----------|
| A+ = AD      | -        |
| B+ = BI      | -        | 
| H+ = H       | -        | 
| AB+ = ABDHI  | AB->H    |
| AH+ = ADH    | -        |
| BH+ = BHI    | -        |
| ABH+ = ABDHI | -        |


T da nova relação R1(A,C,D) será:
```
AB->H
```

E T já se encontra na sua forma minimal. 

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✔        | |
| **b.** | ✖        | |
| **c.** | ✖        | Não quero responder. |
| **d.** | ✖        | |
| **e.** | ✖        | |

## Pergunta 15

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✔        | |
| **b.** | ✖        | |
| **c.** | ✖        | Chave primária é apenas uma das chaves candidatas. |
| **d.** | ✖        | |

## Pergunta 16

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✖        | |
| **b.** | ✖        | |
| **c.** | ✔        | |
| **d.** | ✖        | |
| **e.** | ✖        | Não quero responder. |

## Pergunta 17

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✔        | |
| **b.** | ✖        | A palavra `PROPAGATE` não existe em SQL.|
| **c.** | ✖        | A palavra `MODIFY` não existe em SQL. |
| **d.** | ✖        | Não quero responder. |
| **e.** | ✖        | As palavras `PROPAGATE` e `MODIFY` não existem em SQL. |

## Pergunta 18

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✖        | Não quero responder. |
| **b.** | ✖        | Só podemos omitir `id` quando esta indica uma chave primária em `Product`, o que neste caso não se verifica.|
| **c.** | ✔        | |
| **d.** | ✖        | |
| **e.** | ✖        | |

## Pergunta 19

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✖        | |
| **b.** | ✖        | |
| **c.** | ✖        | Não quero responder. |
| **d.** | ✖        | |
| **e.** | ✔        | A chave primária deve ser bem escolhida e não pode ser uma coluna/atributo qualquer. |

## Pergunta 20

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✔        | |
| **b.** | ✖        | Não quero responder. |
| **c.** | ✖        | |
| **d.** | ✖        | `Role` tem um nome e uma descrição, logo deve ser uma classe e não um atributo. |
| **e.** | ✖        | |

## Pergunta 21

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✖        | Não quero responder. |
| **b.** | ✖        | |
| **c.** | ✖        | |
| **d.** | ✔        | Primeiro renomeamos a tabela `Color` para `interiorColor`r e depois comparamos o novo atributo `interiorcolor` com `color`. |
| **e.** | ✖        | |

## Pergunta 22

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✔        | |
| **b.** | ✖        | |
| **c.** | ✖        | Não quero responder. |
| **d.** | ✖        | |
| **e.** | ✖        | |

## Pergunta 23

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✖        | Não quero responder. |
| **b.** | ✔        | |
| **c.** | ✖        | |
| **d.** | ✖        | |
| **e.** | ✖        | |

## Pergunta 24

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✔        | |
| **b.** | ✖        | |
| **c.** | ✖        | Não quero responder. |
| **d.** | ✖        | |
| **e.** | ✖        | |

## Pergunta 25

| Item   | Resposta | Nota |
|--------|----------|------|
| **a.** | ✖        | |
| **b.** | ✖        | Não quero responder. |
| **c.** | ✖        | |
| **d.** | ✖        | |
| **e.** | ✔        | |
