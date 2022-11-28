Task : Creat simple calculator with addition, subtraction ,multiplication, division compatible for signed int, unsigned int and for floating point;

Since float is higher bit value then signed and unsigned int it is also compatible with int

    test cases
    if FLT_MAX , '+', 1.0 then error
    if 3.0 , '+', 1.0 then 4.0
    if FLT_MIN, '-', 1.0 then error
    if 3.0 , '-', 1.0 then 2.0
    if FLT_MAX, '*', 2.0 then error
    if 5.0 , '*', -2.0 then -10.0
    if 5.0 , '/', 0 then error
    if 5.0 , '/', 2 then 2.5