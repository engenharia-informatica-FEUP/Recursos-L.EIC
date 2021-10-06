# Aarch64 most common instructions

* Só se pode multiplicar dois operandos com o mesmo número de bits. 
* Por exemplo, não é possível multiplicar diretamente um registo de 32 bits com um de 64 bits.  

<table>
    <tr>
        <th rowspan="20"><b>Arithmetic operations</b></td>
    </tr>
    <tr>
        <td><b>Instruction</b></td>
        <td><b>Mnemonic</b></td>
        <td><b>Syntax</b></td>
        <td><b>Explanation</b></td>
    </tr>
    <tr>
        <td>Addition</td>
        <td>ADD{S}</td>
        <td>ADD{S} rd, rn, op2 </td>
        <td><a href=#Addition>Explanation</a></td>
    </tr>
    <tr>
        <td>Subtraction</td>
        <td>SUB{S}</td>
        <td>SUB{S} rd, rn, op2 </td>
        <td><a href=#Subtraction>Explanation</a></td>
    </tr>
    <tr>
        <td>Negation</td>
        <td>NEG{S}</td>
        <td>NEG{S} rd, op2 </td>
        <td><a href=#Negation>Explanation</a></td>
    </tr>
    <tr>
        <td>Negation with carry</td>
        <td>NGC{S}</td>
        <td>NGC{S} rd, rm </td>
        <td><a href="#Negation-with-carry">Explanation</a></td>
    </tr>
    <tr>
        <td>Unsigned multiply</td>
        <td>MUL</td>
        <td>MUL rd, rn, rm </td>
        <td><a href="#Unsigned-multiply">Explanation</a></td>
    </tr>
    <tr>
        <td>Unsigned multiply long</td>
        <td>UMUL</td>
        <td>UMUL xd, wn, wm </td>
        <td><a href="#Unsigned-multiply-long">Explanation</a></td>
    </tr>
    <tr>
        <td>Unsigned multiply high</td>
        <td>UMULH</td>
        <td>UMUL xd, xn, xm </td>
        <td><a href="#Unsigned-multiply-high">Explanation</a></td>
    </tr>
    <tr>
        <td>Signed multiply long</td>
        <td>SMULL</td>
        <td>SMULL xd, wn, wm </td>
        <td><a href="#Signed-multiply-long">Explanation</a></td>
    </tr>
    <tr>
        <td>Signed multiply high</td>
        <td>SMULH</td>
        <td>SMULH xd, xn, xm </td>
        <td><a href="#Signed-multiply-high">Explanation</a></td>
    </tr>
    <tr>
        <td>Multiply and add</td>
        <td>MADD</td>
        <td>MADD rd, rn, rm, ra </td>
        <td><a href="#Multiply-and-add">Explanation</a></td>
    </tr>
    <tr>
        <td>Multiply and subtract</td>
        <td>MSUB</td>
        <td>MSUB rd, rn, rm, ra </td>
        <td><a href="#Multiply-and-subtract">Explanation</a></td>
    </tr>
    <tr>
        <td>Multiply and negate</td>
        <td>MNEG</td>
        <td>MNEG rd, rn, rm </td>
        <td><a href="#Multiply-and-negate">Explanation</a></td>
    </tr>
    <tr>
        <td>Unsigned multiply and add long</td>
        <td>UMADDL</td>
        <td>UMADDL xd, wn, wm, xa </td>
        <td><a href="#Unsigned-multiply-and-add-long">Explanation</a></td>
    </tr>
</table>

## Addition
> ADD{S} rd, rn, op2

    rd = rn + op

## Subtraction
> SUB{S} rd, rn, op2

    rd = rn - op

## Negation
> NEG{S} rd, op2

    rd = -op2

## Negation with carry
> NGC{S} rd, rm

    rd = -rm - !C 

onde C é a "carry flag"

## Unsigned multiply
> MUL rd, rn, rm
 
    rd = rn * rm

* rd tem de ser do mesmo tamanho que os seus operandos, rn e rm
* qualquer overflow é ignorado

## Unsigned multiply long 
> UMUL xd, wn, wm

    xd = wn * wm

* multiplica dois registos de 32 bits (wn e wm) e coloca o resultado em xd
* caso seja necessário, o resultado é extendido com zeros para a esquerda e colocado no registo de 64 bits (xd)

## Unsigned multiply high
> UMULH xd, xn, xm

    xd = <127:64> of (xn * xm)

* multiplica dois registos de 64 bits (xn e xm)
* o resultado tem 128 bits
* desse resultado extrai-se os bits [127:64] e coloca-se em xd
> 
    exemplo:
    Seja X0 = #0xFFFF FFFF FFFF FFFF e X1 = #0x0000 0000 0000 0010

    MUL X2, X0, X1 

    X2 = X0 * X1
    
    O resultado da multiplicação dá  0x1 FFFF FFFF FFFF FFFE. 
    
    Contudo apenas podemos guardar em X2, os 64 bits mais significativos (0xFFFF FFFF FFFF FFFE). 
    
    Como podemos obter aquele 1? Usando a instrução UMULH:

    UMULH X3, X0, X1

    X3 = <127:64> of X0 * X1

    X3 = 0x0000 0000 0000 0001

## Signed multiply long 
> SMULL xd, wn, wm

    xd = wn * wm

* multiplica dois registos de 32 bits (wn e wm) e coloca o resultado de 64 bits em xd

## Signed multiply high 
> SMULH xd, xn, xm

    xd = <127:64> of (xn * xm)

* multiplica dois registos de 64 bits (xn e xm)
* o resultado tem 128 bits
* desse resultado extrai-se os bits [127:64] e coloca-se em xd

## Multiply and add 
> MADD rd, rn, rm, ra

    rd = ra + (rn * rm)

## Multiply and subtract 
> MSUB rd, rn, rm, ra

    rd = ra - (rn * rm)

## Multiply and negate 
> MNEG rd, rn, rm

    rd = - (rn * rm)

## Unsigned multiply and add long 
> UMADDL xd, wn, wm, xa

    xd = xa + (wm * wn)

* multiplica dois registos de 32 bits (wn e wn) produzindo um resultado com 64 bits
* soma esse resultado com outro registo de 64 bits e coloca o resultado dessa soma em xd


