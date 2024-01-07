# Polymorphism benchmark: OOP-style vs. FP-style

There are three big features defining an OO language: encapsulation, inheritance and polymorphism. When comparing OOP to other modern paradigms, the most distinguishing one is polymorphism. In one form or another, encapsulation is present in most modern languages; inheritance is not, but without the polymorphism, inheritance is functionally equivalent to composition. So, polymorphism.

Practically OO polymorphism is class-based, the base class instances and the subclass instances can exhibit different behaviors while having the same APIs. I never really liked this approach, and I typically prefer to solve the same problem with functions as first-class citizens, which is more of FP-style way. I was wandering which way is faster, because theoretically the OO-style polymorphism is achieved through a hashtable, and it should be slower than just dynamically calling a function. So I created this benchmark, and on my machine using references to functions is 2x faster:

```
----- VIRTUAL METHODS -----
Initialization time = 838 ms
Execution time      = 137 ms
Result              = 11000000

----- FUNCTION POINTERS -----
Initialization time = 192 ms
Execution time      = 59 ms
Result              = 11000000

----- FUNCTION POINTERS IN OBJECTS -----
Initialization time = 189 ms
Execution time      = 55 ms
Result              = 11000000
```
