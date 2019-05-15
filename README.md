# DotFin
**Disclaimer: Since DotFin doesn't currently have it's own syntax highlighting format, the codeblocks will be 
formatted in JavaScript format as it's somewhat the closest to what this language is planned to be.**

## What is DotFin?
DotFin is an interpreted programming language in development that is intended for creating 2d applications or games. DotFin is created with C++ so it has the capability to do some low level things like memory management from C's 
standard library, or access the operating system's api. DotFin is still in heavy development so don't expect too 
much as of now. The roadmap for what is planned in the language can be found in [planning.txt](planning.txt).

## What is the syntax?
The syntax is planned to appear like a basic language, think something close to JavaScript. Here is an example of 
a "Hello, World" program, shown in multiple ways.
```js
// Print using variable
var helloWorld = "Hello, World!";
println(helloWorld);

// Print using string without variable
println("Hello, World!");

// Print by adding strings
println("Hello" + ", " + "World!");

// Print with multiple print statements
print("Hello, ");
println("World!");

// Print with multiple statements on one line
print("Hello, "); print("World!");
```
Output:
```
Hello, World!
Hello, World!
Hello, World!
Hello, World!
Hello, World!
```
All of this is valid DotFin as of this commit. 

## What all is planned?
You can find the roadmap in [planning.txt](planning.txt) which will show what has been completed by the hyphens 
(------------). Any plan that appears before the hyphens, is complete, or as complete as can be without other 
plans. Anything after the hyphens, is planned and incomplete. If you would like to see something added to this 
language, you can add it to the end of planning.txt via pull request, or program it yourself and add via pull 
request with proof of successful compilation and no evident bugs. Please see the next section for the pull 
request etiquite. 

## What should I do when making a pull request?
If you are going to make a pull request to change something or add a new feature, be aware that the request may 
not always be accepted. It may be deemed uneccessary, improper way of going about it, buggy, etc. If you are 
adding something, please make sure that the code compiles and does not break existing features. 

### Date information
**Project started:** May 6th, 2019


