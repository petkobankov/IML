# Ivan Markup Language(Project)
Parser for custom markup language.

User writes names of two files in the console
The first file name is for input, the second for output.
If there are syntax errors, incorrect tags used, the order of tags is not correct or an invalid argument is given, the program signals the appropriate error. 

## Accepted tags:
```
Map: <MAP-INC "N"> and <MAP-MLT "N"> where N is a number.
<MAP-INC "1">1 2 3</MAP-INC> ⇒ 2 3 4
<MAP-MLT "2">1 2 3</MAP-MLT> ⇒ 2 4 6


Aggregate: <AGG-SUM>, <AGG-PRO>, <AGG-AVG>, <AGG-FST>, <AGG-LST>
<AGG-SUM>1 2 3</AGG-SUM> ⇒ 6
<AGG-PRO>1 2 3</AGG-PRO> ⇒ 6
<AGG-AVG>1 2 3</AGG-AVG> ⇒ 2
<AGG-FST>1 2 3</AGG-FST> ⇒ 1
<AGG-LST>1 2 3</AGG-LST> ⇒ 3


Sorting: <SRT-REV>, <SRT-ORD "ARG">, where ARG is ASC or DSC, <SRT-SLC "N">, where N is an unsigned int, <SRT-DST>
<SRT-REV>1 2 3</SRT-REV> ⇒ 3 2 1 (Reverses list)
<SRT-ORD "ASC">3 2 1</SRT-ORD> ⇒ 1 2 3 (sorts in ascending order (when argument is “ASC”) or in descending order (when argument is “DSC”)
<SRT-SLC "1">3 2 1</SRT-SLC> ⇒ 2 1 (returns sublist starting at the given index)
<SRT-DST>4 8 4 3</SRT-DST> ⇒ 4 8 3 (removes duplicates)
```

Nesting of tags is allowed. 
Only numbers should be used between tags.
