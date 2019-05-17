# DotFin
**Disclaimer1: Since DotFin doesn't currently have its own syntax highlighting format, the codeblocks will be formatted in JavaScript format as it's somewhat the closest to what this language is planned to be.**
<br/>
**Disclaimer2: I am well aware that this language's type handling is absolutely not conventional, but it works for my first experiment, and was the easiest way I could think of to get started**

## What is DotFin?
DotFin is an interpreted programming language in development that is intended for creating 2d applications or games. DotFin is created with C++ so it has the capability to do some low-level things like memory management from C's 
standard library or access the operating system's API. DotFin is still in heavy development so don't expect too 
much as of now. The roadmap for what is planned in the language can be found in [planning.txt](planning.txt).

## What is the syntax?
The syntax is planned to appear like a basic language, think something close to JavaScript. Here is an example of 
a "Hello, World" program, shown in multiple ways.
```js
// Print using variable
var helloWorld = "Hello, World! - Variable";
println(helloWorld);

// Print by adding variables
var hello = "Hello";
var world = "World! - Adding Variable";
println(hello + ", " + world);

// Print using string without variable
println("Hello, World! - String");

// Print by adding strings
println("Hello" + ", " + "World! - Adding Strings");

// Print with multiple print statements
print("Hello, ");
print("World!");
println(" - Multiple Prints, Multiple Lines");

// Print with multiple statements on one line
print("Hello, "); print("World!"); print(" - Multiple Prints, Same Line");
```
Output:
```
Hello, World! - Variable
Hello, World! - Adding Variable
Hello, World! - String
Hello, World! - Adding Strings
Hello, World! - Multiple Prints, Multiple Lines
Hello, World! - Multiple Prints, Same Line
```
All of this is valid DotFin as of this commit. 

## What all is planned?
You can find the roadmap in [planning.txt](planning.txt) which will show what has been completed by the hyphens 
(------------). Any plan that appears before the hyphens, is complete, or as complete as can be without other 
plans. Anything after the hyphens is planned and incomplete. If you would like to see something added to this 
language, you can add it to the end of planning.txt via pull request, or program it yourself and add via pull 
request with proof of successful compilation and no evident bugs. Please see the next section for the pull 
request etiquette. 

## What should I do when making a pull request?
If you are going to make a pull request to change something or add a new feature, be aware that the request may 
not always be accepted. It may be deemed unnecessary, improper way of going about it, buggy, etc. If you are 
adding something, please make sure that the code compiles and does not break existing features. 

### Date information
**Project started:** May 6th, 2019
