# Dynamic Language Interpreter

## Instructions
`number variableName 5` create integer _variableName_ with value _5_

`text stringVariable HelloWorld!` create string _stringVariable_ with value _HelloWorld!_

`sum output number1 number2` create integer _output_ with value _(number1+number2)_

`minus output number1 number2` create integer _output_ with value _(number1-number2)_

`product output number1 number2` create integer _output_ with value _(number1*number2)_

`concat result string1 string2` create string _result_ whose value is concatenation of _string1_ and _string2_

`longConcat 4 delimiter result string1 string2 string3 string4`  concatenate more than 2 variables, first parameter determines amount, delimiter will be put between all strings

`greaterThen outcome num1 num2` create integer _outcome_, if _num1_ > _num2_ set _outcome_ to 1, else set it to 0

`lessThen outcome num1 num2` create integer _outcome_, if _num1_ < _num2_ set _outcome_ to 1, else set it to 0

`print integer` print value in variable _integer_ to console

`print string` print value in variable _string_ to console and write "" around it

`goto 15` jump to line _15_

`jumpIfTrue 15 cond` jump to line _15_ if variable _cond_ is not 0 or empty string

`jumpIfFalse 15` jump to line _15_ if variable _cond_ is 0 or empty string

### Planned

`label:`  jump instructions can reference to label name instead of line number

## Examples
### Hello World!
Program:
```
text hello HelloWorld!
print hello
```
Output:

```
HelloWorld!
```
### Simple arithmetics
Program:
```
number a -5
number b 17
number c 100
text plus +
text equals =

sum sum a b
concat aplus a plus
concat aplusb aplus b
concat aplusbequals aplusb equals
concat aplusbequalssum aplusbequals sum
print aplusbequalssum

product product b c
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
number i 0
number increment 1
number maximum 10

lessThen break i maximum
jumpIfFalse 11 break
sum i i increment
print i
lessThen break i maximum
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
