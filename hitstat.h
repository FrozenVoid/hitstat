#pragma once

#include <x86intrin.h>
/* zero-overhead hitcounter/meancounters
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


*/
//https://github.com/FrozenVoid/hitstat/

/* print.h standalone print macros
https://github.com/FrozenVoid/print.h
print(args) print all arguments(space separated)
hexprint(args) prints all arguments in hex(except strings)
dbgprint(args) prints all arguments to stderr
dbghexprint(args) prints all arguments to stderr in hex(if possible)

dprint(delim,args) prints all arguments separated by delim string
hexdprint(delim,args) hex prints all arguments separated by delim string

fprint(FILE*,args) write all arguments(space separated) to file
hexfprint(FILE*,args) hex-write all arguments(space separated) to file

fdprint(delim,file,args)  writes all arguments with custom delim
hexfdprint(delim,file,args) writes all arguments in hex(except strings) with custom delim */
#include <stdint.h>
#include <inttypes.h>
#include <float.h>
#include <stdio.h>
#include <string.h>
#define num1_1023  1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64
#define num0_1023 0,num1_1023
#define argcount_count1(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,\
_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_30,_31,\
_32,_33,_34,_35,_36,_37,_38,_39,_40,_41,_42,_43,_44,_45,_46,_47,_48,\
_49,_50,_51,_52,_53,_54,_55,_56,_57,_58,_59,_60,_61,_62,_63,_64,_65,N,...) N
#define argcount_count(args...) argcount_count1(args)
#define argcount(...) argcount_count(0,##__VA_ARGS__,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,\
49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,\
26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)
#define merge1(a,b) a##b
#define merge(a,b) merge1(a,b)
#define id(args...) args
#define detuple(arg) id arg
#define stringify1(args...) #args
#define stringify(args...) stringify1(args)
#define mergetuples(a,b) (detuple(a),detuple(b))
#define chainapply(func,arg...) merge(chainapply,argcount(arg))(func,arg)
#define chainapply0(...)
#define chainapply1(func,a,args...) func(a)
#define chainapply2(func,a,args...) func(a),chainapply1(func,args)
#define chainapply3(func,a,args...) func(a),chainapply2(func,args)
#define chainapply4(func,a,args...) func(a),chainapply3(func,args)
#define chainapply5(func,a,args...) func(a),chainapply4(func,args)
#define chainapply6(func,a,args...) func(a),chainapply5(func,args)
#define chainapply7(func,a,args...) func(a),chainapply6(func,args)
#define chainapply8(func,a,args...) func(a),chainapply7(func,args)
#define chainapply9(func,a,args...) func(a),chainapply8(func,args)
#define chainapply10(func,a,args...) func(a),chainapply9(func,args)
#define chainapply11(func,a,args...) func(a),chainapply10(func,args)
#define chainapply12(func,a,args...) func(a),chainapply11(func,args)
#define chainapply13(func,a,args...) func(a),chainapply12(func,args)
#define chainapply14(func,a,args...) func(a),chainapply13(func,args)
#define chainapply15(func,a,args...) func(a),chainapply14(func,args)
#define chainapply16(func,a,args...) func(a),chainapply15(func,args)
#define chainapply17(func,a,args...) func(a),chainapply16(func,args)
#define chainapply18(func,a,args...) func(a),chainapply17(func,args)
#define chainapply19(func,a,args...) func(a),chainapply18(func,args)
#define chainapply20(func,a,args...) func(a),chainapply19(func,args)
#define chainapply21(func,a,args...) func(a),chainapply20(func,args)
#define chainapply22(func,a,args...) func(a),chainapply21(func,args)
#define chainapply23(func,a,args...) func(a),chainapply22(func,args)
#define chainapply24(func,a,args...) func(a),chainapply23(func,args)
#define chainapply25(func,a,args...) func(a),chainapply24(func,args)
#define chainapply26(func,a,args...) func(a),chainapply25(func,args)
#define chainapply27(func,a,args...) func(a),chainapply26(func,args)
#define chainapply28(func,a,args...) func(a),chainapply27(func,args)
#define chainapply29(func,a,args...) func(a),chainapply28(func,args)
#define chainapply30(func,a,args...) func(a),chainapply29(func,args)
#define chainapply31(func,a,args...) func(a),chainapply30(func,args)
#define chainapply32(func,a,args...) func(a),chainapply31(func,args)
#define chainapply33(func,a,args...) func(a),chainapply32(func,args)
#define chainapply34(func,a,args...) func(a),chainapply33(func,args)
#define chainapply35(func,a,args...) func(a),chainapply34(func,args)
#define chainapply36(func,a,args...) func(a),chainapply35(func,args)
#define chainapply37(func,a,args...) func(a),chainapply36(func,args)
#define chainapply38(func,a,args...) func(a),chainapply37(func,args)
#define chainapply39(func,a,args...) func(a),chainapply38(func,args)
#define chainapply40(func,a,args...) func(a),chainapply39(func,args)
#define chainapply41(func,a,args...) func(a),chainapply40(func,args)
#define chainapply42(func,a,args...) func(a),chainapply41(func,args)
#define chainapply43(func,a,args...) func(a),chainapply42(func,args)
#define chainapply44(func,a,args...) func(a),chainapply43(func,args)
#define chainapply45(func,a,args...) func(a),chainapply44(func,args)
#define chainapply46(func,a,args...) func(a),chainapply45(func,args)
#define chainapply47(func,a,args...) func(a),chainapply46(func,args)
#define chainapply48(func,a,args...) func(a),chainapply47(func,args)
#define chainapply49(func,a,args...) func(a),chainapply48(func,args)
#define chainapply50(func,a,args...) func(a),chainapply49(func,args)
#define chainapply51(func,a,args...) func(a),chainapply50(func,args)
#define chainapply52(func,a,args...) func(a),chainapply51(func,args)
#define chainapply53(func,a,args...) func(a),chainapply52(func,args)
#define chainapply54(func,a,args...) func(a),chainapply53(func,args)
#define chainapply55(func,a,args...) func(a),chainapply54(func,args)
#define chainapply56(func,a,args...) func(a),chainapply55(func,args)
#define chainapply57(func,a,args...) func(a),chainapply56(func,args)
#define chainapply58(func,a,args...) func(a),chainapply57(func,args)
#define chainapply59(func,a,args...) func(a),chainapply58(func,args)
#define chainapply60(func,a,args...) func(a),chainapply59(func,args)
#define chainapply61(func,a,args...) func(a),chainapply60(func,args)
#define chainapply62(func,a,args...) func(a),chainapply61(func,args)
#define chainapply63(func,a,args...) func(a),chainapply62(func,args)
#define chainapply64(func,a,args...) func(a),chainapply63(func,args)
#define tapply(tup,func,args...) merge(tapply,argcount(args))(tup,func,args)
#define tapply0(...)
#define tapply1(tup,func,x,...) func(tup,x)
#define tapply2(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply3(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply4(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply5(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply6(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply7(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply8(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply9(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply10(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply11(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply12(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply13(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply14(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply15(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply16(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply17(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply18(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply19(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply20(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply21(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply22(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply23(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply24(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply25(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply26(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply27(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply28(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply29(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply30(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply31(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply32(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply33(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply34(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply35(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply36(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply37(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply38(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply39(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply40(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply41(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply42(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply43(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply44(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply45(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply46(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply47(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply48(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply49(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply50(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply51(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply52(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply53(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply54(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply55(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply56(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply57(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply58(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply59(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply60(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply61(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply62(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply63(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define tapply64(tup,func,x,args...) func(tup,x),merge(tapply,argcount(args))(tup,func,args)
#define appendall1(tup,arg) mergetuples(tup,(arg))
#define appendall(tup,args...) tapply(tup,appendall1,args)
#define SPACE_DELIM " "
#define pformat(x) _Generic((x),\
 char:   "%c",\
 char*:  "%s",\
long long unsigned int: "%llu" ,\
long long int: "%lli" ,\
uint64_t: "%" PRIu64,\
 int64_t: "%" PRIi64,\
uint32_t: "%" PRIu32,\
 int32_t: "%" PRIi32,\
uint16_t: "%" PRIu16,\
 int16_t: "%" PRIi16,\
uint8_t:  "%" PRIu8,\
 int8_t:  "%" PRIi8,\
 float:  "%." stringify(FLT_DIG) "G",\
double:  "%." stringify(DBL_DIG) "G",\
 long double: "%." stringify(LDBL_DIG) "LG",\
default:"%p" )

#define hexformat(x) _Generic((x),\
 char:   "%c",\
 char*:  "%s",\
long long unsigned int: "%llx" ,\
long long int: "%llx" ,\
uint64_t: "%" PRIx64,\
 int64_t: "%" PRIx64,\
uint32_t: "%" PRIx32,\
 int32_t: "%" PRIx32,\
uint16_t: "%" PRIx16,\
 int16_t: "%" PRIx16,\
uint8_t:  "%" PRIx8,\
 int8_t:  "%" PRIx8,\
  float:  "%." stringify(FLT_DIG)"A",\
double:  "%." stringify(DBL_DIG) "A",\
 long double: "%." stringify(LDBL_DIG)"LA",\
default:"%p" )
#define core_print1(delim,file,format_type,arg) \
fprintf(file,delim),fprintf(file,format_type(arg),arg)
#define print1(arg) printf(SPACE_DELIM),printf(pformat(arg),arg)
#define hexprint1(arg) printf(SPACE_DELIM),printf(hexformat(arg),arg)
#define fprint2(file,arg) core_print1(SPACE_DELIM,file,pformat,arg)
#define fprint1(tup) fprint2 tup
#define hexfprint2(file,arg) core_print1(SPACE_DELIM,file,hexformat,arg)
#define hexfprint1(tup) hexfprint2 tup
#define dprint2(delim,arg) printf(delim),printf(pformat(arg),arg)
#define dprint1(tup) dprint2 tup
#define hexdprint2(delim,arg) core_print1(delim,stdout,hexformat,arg)
#define hexdprint1(tup) hexdprint2 tup
#define dfprint2(delim,file,arg) core_print1(delim,file,pformat,arg)
#define dfprint1(tup) dfprint2 tup
#define hexfdprint2(delim,file,arg) core_print1(delim,file,hexformat,arg)
#define hexfdprint1(tup) hexfdprint2 tup
//---- applicative
#define print(args...) chainapply(print1,args)
#define hexprint(args...) chainapply(hexprint1,args)
#define fprint(file,args...) chainapply(fprint1,appendall((file),args))
#define hexfprint(file,args...) chainapply(hexfprint1,appendall((file),args))
#define dprint(delim,args...) chainapply(dprint1,appendall((delim),args))
#define hexdprint(delim,args...) chainapply(hexdprint1,appendall((delim),args))
#define dfprint(delim,file,args...) chainapply(dfprint1,appendall((delim,file),args))
#define hexfdprint(delim,file,args...) chainapply(hexfdprint1,appendall((delim,file),args))
#define dbgprint(args...) fprint(stderr,args)
#define dbghexprint(args...) hexfprint(stderr,args)

#define HIT_COUNT_INTERVAL  8000000000ULL
#define MEAN_COUNT_INTERVAL 8000000000ULL
#define COST_COUNT_INTERVAL 19000000000ULL

#define meantypemax(value) _Generic((value),\
long long unsigned int:  UINT64_MAX ,\
long long int: INT64_MAX ,\
uint64_t:  UINT64_MAX  ,\
 int64_t: INT64_MAX,\
uint32_t:  UINT32_MAX  ,\
 int32_t: INT32_MAX,\
uint16_t: UINT16_MAX,\
 int16_t: INT16_MAX   ,\
uint8_t:  UINT8_MAX ,\
 int8_t:  INT8_MAX ,\
  float:  FLT_MAX,\
double:   DBL_MAX ,\
 long double:  LDBL_MAX ,\
default: INT64_MAX  )
#define meantypemin(value) _Generic((value),\
long long unsigned int: 0 ,\
long long int: INT64_MIN ,\
uint64_t: 0,\
 int64_t: INT64_MIN,\
uint32_t: 0,\
 int32_t:  INT32_MIN ,\
uint16_t: 0,\
 int16_t: INT16_MIN  ,\
uint8_t:  0,\
 int8_t:  INT8_MIN,\
  float:   FLT_MIN ,\
double: DBL_MIN,\
 long double: LDBL_MIN ,\
default: 0 )

#define mean1(valuex) ({;__auto_type   value=valuex;\
static uint64_t mean_elapsed=0;\
static size_t meancount=0;\
static long double meansum=0;\
meansum+=value;meancount++;\
static typeof(value) valmin=meantypemax(value);\
static typeof(value) valmax=meantypemin(value);\
valmin=value<valmin?value:valmin;\
valmax=value>valmax?value:valmax;\
size_t curtime= __rdtsc();\
if(curtime-mean_elapsed>MEAN_COUNT_INTERVAL){mean_elapsed=curtime;\
long double avg=meansum/meancount;\
fprint(stderr,"\n",__FILE__,":",__LINE__,":[",stringify(valuex),"] ",meancount,"counts\n Min:",valmin,"Avg:",avg,"Max:",valmax,"\n");};value;})

#define hit1(condx) ({;__auto_type  cond=condx;\
static uint64_t hit_elapsed=0;\
static size_t hitcount=0;\
static size_t condcount=0;\
;hitcount++;condcount+=!!(cond);\
size_t curtime= __rdtsc();\
if(curtime-hit_elapsed>HIT_COUNT_INTERVAL){hit_elapsed=curtime;\
long double perc=100.0L*condcount/hitcount;\
fprint(stderr,"\n",__FILE__,":",__LINE__,":(",stringify(condx),") ",hitcount,"counts\n Hits:",condcount,"Hit%:",perc,"\n");};cond;})

#define cost1(funcx) ({;\
static uint64_t cost_elapsed=0;\
 size_t start_cycle=__rdtsc();\
;__auto_type  funcres=funcx;\
static size_t total_cycles=0;\
static size_t total_calls=0;\
static typeof(total_cycles) valmin=meantypemax(total_cycles);\
static typeof(total_cycles) valmax=meantypemin(total_cycles);\
 size_t curtime= __rdtsc();\
total_calls++;size_t cyclediff=curtime-start_cycle;\
valmin=cyclediff<valmin?cyclediff:valmin;\
valmax=cyclediff>valmax?cyclediff:valmax;\
total_cycles+=cyclediff;\
if(curtime-cost_elapsed>COST_COUNT_INTERVAL){cost_elapsed=curtime;\
long double avg=1.0L*total_cycles/total_calls;\
fprint(stderr,"\n",__FILE__,":",__LINE__,":{",stringify(funcx),"} ",total_calls,"calls\n Avg:",avg," cycles Min<>Max:",valmin,"<>",valmax,"cycles\n");};funcres;})


#define chainapplyhs_(func,arg...) merge(chainapplyhs_,argcount(arg))(func,arg)
#define chainapplyhs_0(...)
#define chainapplyhs_1(func,a,args...) func(a)
#define chainapplyhs_2(func,a,args...) func(a),chainapplyhs_1(func,args)
#define chainapplyhs_3(func,a,args...) func(a),chainapplyhs_2(func,args)
#define chainapplyhs_4(func,a,args...) func(a),chainapplyhs_3(func,args)
#define chainapplyhs_5(func,a,args...) func(a),chainapplyhs_4(func,args)
#define chainapplyhs_6(func,a,args...) func(a),chainapplyhs_5(func,args)
#define chainapplyhs_7(func,a,args...) func(a),chainapplyhs_6(func,args)
#define chainapplyhs_8(func,a,args...) func(a),chainapplyhs_7(func,args)
#define chainapplyhs_9(func,a,args...) func(a),chainapplyhs_8(func,args)
#define chainapplyhs_10(func,a,args...) func(a),chainapplyhs_9(func,args)
#define chainapplyhs_11(func,a,args...) func(a),chainapplyhs_10(func,args)
#define chainapplyhs_12(func,a,args...) func(a),chainapplyhs_11(func,args)
#define chainapplyhs_13(func,a,args...) func(a),chainapplyhs_12(func,args)
#define chainapplyhs_14(func,a,args...) func(a),chainapplyhs_13(func,args)
#define chainapplyhs_15(func,a,args...) func(a),chainapplyhs_14(func,args)
#define chainapplyhs_16(func,a,args...) func(a),chainapplyhs_15(func,args)
#define chainapplyhs_17(func,a,args...) func(a),chainapplyhs_16(func,args)
#define chainapplyhs_18(func,a,args...) func(a),chainapplyhs_17(func,args)
#define chainapplyhs_19(func,a,args...) func(a),chainapplyhs_18(func,args)
#define chainapplyhs_20(func,a,args...) func(a),chainapplyhs_19(func,args)
#define chainapplyhs_21(func,a,args...) func(a),chainapplyhs_20(func,args)
#define chainapplyhs_22(func,a,args...) func(a),chainapplyhs_21(func,args)
#define chainapplyhs_23(func,a,args...) func(a),chainapplyhs_22(func,args)
#define chainapplyhs_24(func,a,args...) func(a),chainapplyhs_23(func,args)
#define chainapplyhs_25(func,a,args...) func(a),chainapplyhs_24(func,args)
#define chainapplyhs_26(func,a,args...) func(a),chainapplyhs_25(func,args)
#define chainapplyhs_27(func,a,args...) func(a),chainapplyhs_26(func,args)
#define chainapplyhs_28(func,a,args...) func(a),chainapplyhs_27(func,args)
#define chainapplyhs_29(func,a,args...) func(a),chainapplyhs_28(func,args)
#define chainapplyhs_30(func,a,args...) func(a),chainapplyhs_29(func,args)
#define chainapplyhs_31(func,a,args...) func(a),chainapplyhs_30(func,args)
#define chainapplyhs_32(func,a,args...) func(a),chainapplyhs_31(func,args)
#define chainapplyhs_33(func,a,args...) func(a),chainapplyhs_32(func,args)
#define chainapplyhs_34(func,a,args...) func(a),chainapplyhs_33(func,args)
#define chainapplyhs_35(func,a,args...) func(a),chainapplyhs_34(func,args)
#define chainapplyhs_36(func,a,args...) func(a),chainapplyhs_35(func,args)
#define chainapplyhs_37(func,a,args...) func(a),chainapplyhs_36(func,args)
#define chainapplyhs_38(func,a,args...) func(a),chainapplyhs_37(func,args)
#define chainapplyhs_39(func,a,args...) func(a),chainapplyhs_38(func,args)
#define chainapplyhs_40(func,a,args...) func(a),chainapplyhs_39(func,args)
#define chainapplyhs_41(func,a,args...) func(a),chainapplyhs_40(func,args)
#define chainapplyhs_42(func,a,args...) func(a),chainapplyhs_41(func,args)
#define chainapplyhs_43(func,a,args...) func(a),chainapplyhs_42(func,args)
#define chainapplyhs_44(func,a,args...) func(a),chainapplyhs_43(func,args)
#define chainapplyhs_45(func,a,args...) func(a),chainapplyhs_44(func,args)
#define chainapplyhs_46(func,a,args...) func(a),chainapplyhs_45(func,args)
#define chainapplyhs_47(func,a,args...) func(a),chainapplyhs_46(func,args)
#define chainapplyhs_48(func,a,args...) func(a),chainapplyhs_47(func,args)
#define chainapplyhs_49(func,a,args...) func(a),chainapplyhs_48(func,args)
#define chainapplyhs_50(func,a,args...) func(a),chainapplyhs_49(func,args)
#define chainapplyhs_51(func,a,args...) func(a),chainapplyhs_50(func,args)
#define chainapplyhs_52(func,a,args...) func(a),chainapplyhs_51(func,args)
#define chainapplyhs_53(func,a,args...) func(a),chainapplyhs_52(func,args)
#define chainapplyhs_54(func,a,args...) func(a),chainapplyhs_53(func,args)
#define chainapplyhs_55(func,a,args...) func(a),chainapplyhs_54(func,args)
#define chainapplyhs_56(func,a,args...) func(a),chainapplyhs_55(func,args)
#define chainapplyhs_57(func,a,args...) func(a),chainapplyhs_56(func,args)
#define chainapplyhs_58(func,a,args...) func(a),chainapplyhs_57(func,args)
#define chainapplyhs_59(func,a,args...) func(a),chainapplyhs_58(func,args)
#define chainapplyhs_60(func,a,args...) func(a),chainapplyhs_59(func,args)
#define chainapplyhs_61(func,a,args...) func(a),chainapplyhs_60(func,args)
#define chainapplyhs_62(func,a,args...) func(a),chainapplyhs_61(func,args)
#define chainapplyhs_63(func,a,args...) func(a),chainapplyhs_62(func,args)
#define chainapplyhs_64(func,a,args...) func(a),chainapplyhs_63(func,args)


#define hit(args...) chainapplyhs_(hit1,args)
#define mean(args...) chainapplyhs_(mean1,args)

#define cost(args...) chainapplyhs_(cost1,args)
#define costvoid(arg) cost1((arg,1))

