# Infix-Calculator
An infix calculator that uses the shunting yard algorithm.

## General overview
This calculator uses a REPL approach where the user inputs a single line expression, and then if possible outputs the result on the next line. It goes through several stages before printing the output.
1. Lexer
2. Shuntyard
3. Evaluation

> There are also two commands that can be entered instead of an expression. `test` will run some cases that use all current features of the calculator. It will either print out that the case passed, or that it failed. If it failed it will also print out the expression, the tokens that were generated, as well the objects. The other command is `debug`. Whenever an expression is entered, it will print out the tokens generated, as well the objects generated. This can help weed out problems with either the lexer, or the shuntyard.

## Features
The calculator is able to use either integers or real numbers in expressions, as well the standard arithmetic operators, `+`, `-`, `/`, and `*`. It is also able to parse parenthesised expressions. 

It is also possible to do trigonometry functions such as `sin`, `cos`, and `tan`. And other functions such as `log`.


## Lexing
The calculator uses a lexer to turn the input into a vector of tokens. This is where a string of digits are converted into the full number, where a `-` symbol is evaluated to be either a unary or binary operator etc. Any unknown operators or symbols holt the lexer and returns an empty vector of tokens. Upon successful lexing the lexer will return a vector of tokens.

## Shuntyard
The shuntyard algorithm is an algorithm designed by Dijkstra to convert an infix expression, which can be difficult to evaluate, into postfix notation, which is fairly simple to evaluate. 

The shuntyard takes a vector of tokens, and returns a vector of Objects.
> There are three specific types of Objects in the code, an IntObject, an OpObject, and a RealObject. An IntObject holds a numerical value, and a literal for the value. The OpObject holds an enum for the operator that it holds, it also holds a literal for the operator. A RealObject holds a double that represents the objects value as well as a literal.

When a token is removed from the input vector it is then converted into the required object, and placed onto either the output or operator vector/stack. If the current token is a `NEG` token then simply negate the next token value, and skip past the next token.

## Evaluation
The evaluation step uses a fairly simple algorithm for evaluating the output from the shuntyard.
1. For each object in the input vector...
2. If it is an IntObject, push it on the output stack.
3. If it is an OpObject, pop two numbers off the output stack, evaluate the result of the two numbers with the operator.
4. When there are no more numbers in the input vector, then return the top value of the output stack.
