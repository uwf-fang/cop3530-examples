**********************
Multiple class project
**********************

Concepts
========
+ header file .hpp

  * declaration
  * prefer .hpp for C++

+ source code file .cpp

  * definitions

+ module: paired .hpp and .cpp
+ driver

  * driver.cpp, main.cpp, or a good name for your app
  * should the main entry of your app (main function)

Building Configuration
======================
+ makefile

Code Organization
=================
+ Store item class as a module
+ Store class as a module
+ test.cpp as a driver
+ no main driver yet

Tips
====
+ only use "using namespace ..." in .cpp files; never in .hpp files
+ incremental development flow suggestion

  * finish StoreItem class
  * write test code in driver
  * test run
  * finish Store class
  * write test code in driver
  * test run

