# CPP Code and Usage for compilation <br>
## How to compile things without  *Makefile*?
- Create the header files and declare the functions and other initializing macros inside the header files (like utlities.h).
- Then using *utilities.cpp* we can define those functions, like what should they be doing if being called. 
- And then in *test.cpp* we are adding the header file and using the function's functionality parallely.
- Compilation would be done something like this:
` g++ test.cpp utilities.cpp -o a.out && ./a.out   `

**NOTE: The Makefile updates are still in progress**