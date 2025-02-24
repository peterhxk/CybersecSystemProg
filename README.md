# Cybersecurity & Systems Programming
Here includes my coding assignments from the class Introduction to Software Systems, involving Bash Scripts and C, ie. names in () are file names

# Navigate to Bash folder
(ReadLog)
- ReadLog is a bash program that reads the data on jerrington.me.log
- Along with it involves 4 commands:
- unique-ips counts the number of unique ips
- reqs-per-day gives the average requests made per day
- most-popular-post analyzes the data and extracts the most popular post along with its number of requests
- total-transferred sums up the number of total volume of data transferred in bytes

FileSearching folder
(search)
- by using ./search WHERE NAME, the program searches the WHERE directory for the NAME file and lists them out in stdout.
(total-size)
- total-size is run using search, and uses its output to sum up the sizes of the files found

# Now navigate to C folder
MathOperation folder
(minicalc.c)
- minicalc is a C program that does the square root of a number, finds the greatest common divisor of more than 2 numbers, and checks if two strings are anagrams.
(build)
- build is a bash file that compiles the minicalc.c program and also runs a series of tests to verify its output

Stringbuilder folder
(minicalc.c)
- The same minicalc file with return values adjusted to output the different types of error properly
(run-tests)
- Using Bash and creating a function to perform the error output better
(stringbuilder.c)
- A C program using dynamic array to build strings, along with some tests in main function.
(Makefile)
- By typing make in the terminal, it runs the Makefile
- make minicalc --> compiles minicalc.c
- make stringbuilder --> compiles stringbuilder.c
- make test --> runs ./run-tests

Server folder
(server.c)
- a server created with C that allows a maximum connection of 4 (can be adjusted)
- port number is written as 4324 (can be adjusted)
- the server is able to transfer the messages from one client to all other clients
(client.c)
- a client that connects to the 4324 port's server and is able to type messages to the server
(Makefile)
- make compiles both the server file and client file

OffensiveSecurity(Hacking) folder
(vulnerable.c)
- A vulnerable C program that contains a bug vulnerable to buffer-overflow attacks, which I will exploit and document in Solution.txt
(Makefile)
- make compiles the vulnerable.c
(Solution.txt)
- Documentation of the bug in vulnerable.c
