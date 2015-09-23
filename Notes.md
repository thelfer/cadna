% Notes
% Helfer Thomas
% September 9, 2015

# Modifications générales

- les fichiers d'entêtes sont dans le répertoire `include`
- les fichiers d'entête ont été renommés: leur suffixe est
  maintenant `hxx`
- les fichiers de source ont été renommés: leur suffixe est
  maintenant `cxx`
- création d'un répertoire `tests` pour les tests unitaires

# Points à regarder

## Dans les différentes sources

Voir les lignes commençant par `#pragma message` pour différentes
questions relatives à l'implémentation de cette version.

## configure.ac (version 2.0.a4)

- `cadna_math_gcc.cc` est référencé mais n'existe pas dans les
  sources. Je l'ai remplacé par `cadna_cmath_gnu.cxx`

## cadna_math_other.cc (version 2.0.a4)

- l'implémentation de `cos` donne monte des lignes du type
  `res.x==cos(a.x)` qui me semblent douteuses.
