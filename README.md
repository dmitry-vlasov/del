del - an EL signature decomposer 
================================

DEL stands for 'Decomposition in description logic EL'

del ('d' EL description logic) - is a solver / theory decomposer for
the EL description  logic. It uses a special language, which occasionally
has the same name del, to state the problem of signature decomposition
of some theory, relative to some fixed signature, and to state the solution
for such decomposition. The program del is a solver / decomposer for
theories and signatures, which solves the problem of decomposition and
outputs the result of decomposition in the same format del.

The package contains following parts:
	* del  : the decomposer and solver
	* nstd : non-standard template library
	* math : directory with test source files and test scripts

Installation
------------
For installation instructions read INSTALL.

System requirements
-------------------
Full translation tests demand not less then 1Gb of RAM, not less then 150 Mb of
free space on the hard disk.

Test scripts
------------
Test scripts may be run to test the del program. To run tests first compile package 
with the command './configure; make'. Then go to the directory 'math' and 
run appropriate script.

Decomposition tests
-------------------
Script 'decomposition', runs a del program on a simple decomposable theory 
To run the test run:
    :~$./decomposition decompose    

Script 'solver', runs a del program on a simple theory 
To run the test run:
    :~$./solver solve
