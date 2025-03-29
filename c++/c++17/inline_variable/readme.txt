b.h includes int x=10;

- a.h includes b.h
- a.cpp includes a.h (and, b.h)
- b.cpp includes b.h

so now b.h is included in both a.cpp & b.cpp
so, "int x =10;" is defined twice!
if you tried to compile this code with c++ not 17 (i.e. c++14), it won't compile!

to solve this problem [multiple definition],
declare the variable x to be inline! (see b.h for more).
Now when you try to compile with c++17, it will work!