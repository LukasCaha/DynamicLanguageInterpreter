# Dynamic Language Interpreter

## Instructions
`stconst_i variableName 5` create integer _variableName_ with value _5_

`stconst_s stringVariable HelloWorld!` create string _stringVariable_ with value _HelloWorld!_

`stadd sum number1 number2` create integer _sum_ with value _(number1+number2)_

`stmul product number1 number2` create integer _product_ with value _(number1*number2)_

`stcat result string1 string2` create string _result_ whose value is concatenation of _string1_ and _string2_

`stgt outcome num1 num2` create integer _outcome_, if _num1_ > _num2_ set _outcome_ to 1, else set it to 0

`stlt outcome num1 num2` create integer _outcome_, if _num1_ < _num2_ set _outcome_ to 1, else set it to 0

`print integer` print value in variable _integer_ to console

`print string` print value in variable _string_ to console and write "" around it

`goto 15` jump to line _15_

`brt 15 cond` jump to line _15_ if variable _cond_ is not 0 or empty string

`brf 15` jump to line _15_ if variable _cond_ is 0 or empty string

## Examples
### Hello World!
Program:
```
stconst_s hello HelloWorld!
print hello
```
Output:

```
HelloWorld!
```
### Simple arithmetics
Program:
```
stconst_i a -5
stconst_i b 17
stconst_i c 100
stconst_s plus +
stconst_s equals =

stadd sum a b
stcat aplus a plus
stcat aplusb aplus b
stcat aplusbequals aplusb equals
stcat aplusbequalssum aplusbequals sum
print aplusbequalssum

stmul product b c
print product
```
Output:

```
"-5+17=12"
1700
```
### Loop
Program:
```
stconst_i i 0
stconst_i increment 1
stconst_i maximum 10

stlt break i maximum
brf 11 break
stadd i i increment
print i
stlt break i maximum
goto 5
```
Output:

```
1
2
3
4
5
6
7
8
9
10
```
