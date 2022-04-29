# hitstat

zero-overhead hitcounter/meancounters
hit(conditions...) record percent of condition==true for each condition
mean(values...) record min/average/max of values
cost(func(x)) record cost of function calls
examples:
insertion: if(a>mean(d) && hit(a>b)){cost( bigfunc(a));}
will result in `if(a>d && (a>b)){bigfunc(a);}
with (a>b) condition being recorded
and (d) being sampled for min/max/avg
and bigfunc(a) measured cost in CPU cycles
collection:
hit(a>b,b<c,d>b); will record true% of conditions in sequence
mean(a,b,c); will record min/max/avg of a,b,c
