# Brainfuck interpreter in C

Written for fun mand educational purposes. feel free to do whatever with it.
<br>
The code is provided as is. and is probalby messy. sorry :/

## info on brainfuck
An esoteric programming language that is basically just a turing machine.<br>
it has 8 possible operations, repersented by `> < + - [ ] , .`<br>
all other characters are treated as comments.
<br>
<hr>
|   |                                                                      |
|---|----------------------------------------------------------------------|
| > | Move the data pointer right by 1. (increment it)                     |
| < | Move the data pointer left by 1. (decrement it)                      |
| + | Increment the byte at the data pointer by 1                          |
| - | Decrement the byte at the data pointer by 1                          |
| . | Output the byte at the data pointer                                  |
| , | Accept one byte of data as input, stored in the byte at data pointer |
| [ |  If byte at pointer is 0, jump to closing bracket                    |
| ] | If byte at pointer is non zero, jump to opening bracket              |
