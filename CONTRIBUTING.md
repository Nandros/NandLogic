# Contribution to NandLogic

## Names

There are the differents cases used in this project

camelCase :
> Variables, Functions, Methods, types form struct, enum, ...

PascalCase :
> Files, Classes

MACRO_CASE :
> Defines, constants

### Files

File name should foolow this logic : `<objectFunction>`.  
Like, `inputHandler` where `input` is the obejct and `Handler` is the function. So this file should Handle user inputs.  
We could have `inputGetter` that get inputs to send to `inputHandler`.

### Identifiers

Identifiers should follow the same logic as Files's name.

#### Prefix 

Pointers should have `p` before the name. (e.g. `pVal` for pointer of `val`).

#### Suffix

| Type   | Suffix | Explanation         |
| ----   | ------ | -----------         |
| Type   | _t     | Type of variable    |
| Global | _g     | Globals variables   |

## Comments

All files should be commented, there is `__template.cpp` and `__template.hpp` file to indicate how to comment/separate files.

**Doxygen** is used as the main docummentation style.