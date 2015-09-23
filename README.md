% A C++-11 compliant version of the CADNA library
% T. Helfer
% 23/09/2015

# Overview of CADNA

The CADNA (Control of Accuracy and Debugging for Numerical
Applications) software estimates round-off errors in numerical
simulations.

CADNA uses the CESTAC method to estimate in any computed result which
digits are affected by round-off errors. Moreover CADNA implements all
the concepts and definitions of the stochastic arithmetic, specially
the definitions of order relations and equality relation. To be very
short, these definitions take into account the accuracy of the
operands. Therefore CADNA enables a real numerical debugging by
detecting numerical instabilities which usually involve numerical
noise. The last (but not the least) tool provided by CADNA is that
data errors can be taken into account for the estimation of the final
accuracy.

CADNA contains all the controls that are necessary for a good and
efficient implementation of the CESTAC method. These controls, that
were pointed out by the theoretical study, lead to a self-validation
of the library. CADNA is able to detect when the conditions for a
right estimation of the round-off errors are not satisfied anymore and
when it happens, CADNA is able to advise the users.

The official website of CADNA is hosted at:

<http://www-pequan.lip6.fr/cadna/>

# Purpose of this repository

This repository contains an experimental implementation of CADNA based
on C++-11 which aims at being more standard compliant.

This code is *not* ready for production use.
