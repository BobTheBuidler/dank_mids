#ifndef MYPYC_NATIVE_0bf4c1c413ed1d8eb97f_H
#define MYPYC_NATIVE_0bf4c1c413ed1d8eb97f_H
#include <Python.h>
#include <CPy.h>
#ifndef MYPYC_DECLARED_tuple_T3CIO
#define MYPYC_DECLARED_tuple_T3CIO
typedef struct tuple_T3CIO {
    char f0;
    CPyTagged f1;
    PyObject *f2;
} tuple_T3CIO;
#endif

#ifndef MYPYC_DECLARED_tuple_T3OOO
#define MYPYC_DECLARED_tuple_T3OOO
typedef struct tuple_T3OOO {
    PyObject *f0;
    PyObject *f1;
    PyObject *f2;
} tuple_T3OOO;
#endif

#ifndef MYPYC_DECLARED_tuple_T2OO
#define MYPYC_DECLARED_tuple_T2OO
typedef struct tuple_T2OO {
    PyObject *f0;
    PyObject *f1;
} tuple_T2OO;
#endif

#ifndef MYPYC_DECLARED_tuple_T6OOOOOO
#define MYPYC_DECLARED_tuple_T6OOOOOO
typedef struct tuple_T6OOOOOO {
    PyObject *f0;
    PyObject *f1;
    PyObject *f2;
    PyObject *f3;
    PyObject *f4;
    PyObject *f5;
} tuple_T6OOOOOO;
#endif

#ifndef MYPYC_DECLARED_tuple_T3FIO
#define MYPYC_DECLARED_tuple_T3FIO
typedef struct tuple_T3FIO {
    double f0;
    CPyTagged f1;
    PyObject *f2;
} tuple_T3FIO;
#endif

#ifndef MYPYC_DECLARED_tuple_T2II
#define MYPYC_DECLARED_tuple_T2II
typedef struct tuple_T2II {
    CPyTagged f0;
    CPyTagged f1;
} tuple_T2II;
#endif

#ifndef MYPYC_DECLARED_tuple_T1O
#define MYPYC_DECLARED_tuple_T1O
typedef struct tuple_T1O {
    PyObject *f0;
} tuple_T1O;
#endif

#ifndef MYPYC_DECLARED_tuple_T0
#define MYPYC_DECLARED_tuple_T0
typedef struct tuple_T0 {
    int empty_struct_error_flag;
} tuple_T0;
#endif

#ifndef MYPYC_DECLARED_tuple_T4CIOO
#define MYPYC_DECLARED_tuple_T4CIOO
typedef struct tuple_T4CIOO {
    char f0;
    CPyTagged f1;
    PyObject *f2;
    PyObject *f3;
} tuple_T4CIOO;
#endif

#ifndef MYPYC_DECLARED_tuple_T2CO
#define MYPYC_DECLARED_tuple_T2CO
typedef struct tuple_T2CO {
    char f0;
    PyObject *f1;
} tuple_T2CO;
#endif

#ifndef MYPYC_DECLARED_tuple_T3IIO
#define MYPYC_DECLARED_tuple_T3IIO
typedef struct tuple_T3IIO {
    CPyTagged f0;
    CPyTagged f1;
    PyObject *f2;
} tuple_T3IIO;
#endif

#ifndef MYPYC_DECLARED_tuple_T4OOOO
#define MYPYC_DECLARED_tuple_T4OOOO
typedef struct tuple_T4OOOO {
    PyObject *f0;
    PyObject *f1;
    PyObject *f2;
    PyObject *f3;
} tuple_T4OOOO;
#endif

#ifndef MYPYC_DECLARED_tuple_T2IO
#define MYPYC_DECLARED_tuple_T2IO
typedef struct tuple_T2IO {
    CPyTagged f0;
    PyObject *f1;
} tuple_T2IO;
#endif

#ifndef MYPYC_DECLARED_tuple_T10OOOOOOOOOO
#define MYPYC_DECLARED_tuple_T10OOOOOOOOOO
typedef struct tuple_T10OOOOOOOOOO {
    PyObject *f0;
    PyObject *f1;
    PyObject *f2;
    PyObject *f3;
    PyObject *f4;
    PyObject *f5;
    PyObject *f6;
    PyObject *f7;
    PyObject *f8;
    PyObject *f9;
} tuple_T10OOOOOOOOOO;
#endif

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_controller;
    PyObject *_multicalls;
    PyObject *_rpc_calls;
    char __awaited;
    CPyTagged __check_len;
} dank_mids____batch___DankBatchObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *___mypyc_generator_attribute__self;
    PyObject *_type;
    PyObject *_value;
    PyObject *_traceback;
    PyObject *_arg;
    PyObject **_stop_iter_ptr;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_generator_attribute__working_batch;
    PyObject *___mypyc_generator_attribute__batch_append;
    CPyTagged ___mypyc_generator_attribute__check_len;
    PyObject *___mypyc_temp__0;
    CPyTagged ___mypyc_temp__1;
    int64_t ___mypyc_temp__2;
    PyObject *___mypyc_temp__3;
    PyObject *___mypyc_generator_attribute__mcall;
    PyObject *___mypyc_generator_attribute__call;
} dank_mids____batch___coroutines_DankBatch_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_env__;
} dank_mids____batch___coroutines_DankBatch_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} dank_mids____demo_mode___DummyLoggerObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} dank_mids____exceptions___BadResponseObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} dank_mids____exceptions___EmptyBatchObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} dank_mids____exceptions___ExecutionRevertedObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} dank_mids____exceptions___OutOfGasObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} dank_mids____exceptions___PayloadTooLargeObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} dank_mids____exceptions___ExceedsMaxBatchSizeObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_request;
    PyObject *_args;
    PyObject *__exception;
} dank_mids____exceptions___DankMidsClientResponseErrorObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} dank_mids____exceptions___DankMidsInternalErrorObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} dank_mids____exceptions___BatchResponseSortErrorObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} dank_mids____exceptions___RateLimitErrorObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} dank_mids____exceptions___ChainstackRateLimitErrorObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} dank_mids____exceptions___QuiknodeRateLimitErrorObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_inner;
    PyObject *_outer;
    PyObject *__inner_done_callback;
    PyObject *__outer_done_callback;
    PyObject *_arg;
    PyObject *_loop;
} dank_mids____tasks___shield_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} dank_mids____tasks____inner_done_callback_shield_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} dank_mids____tasks____outer_done_callback_shield_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    CPyTagged __value;
    PyObject *__lock;
} dank_mids____uid___UIDGeneratorObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    double _max_rate;
    double _time_period;
    PyObject *__event_loop;
    double __rate_per_sec;
    double __level;
    double __last_check;
    PyObject *__waker_handle;
    PyObject *__waiters;
    PyObject *__next_count;
} dank_mids____vendor___aiolimiter___src___aiolimiter___leakybucket___AsyncLimiterObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    uint32_t bitmap;
    PyObject *___mypyc_generator_attribute__self;
    double ___mypyc_generator_attribute__amount;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_generator_attribute__loop;
    PyObject *___mypyc_generator_attribute__fut;
    PyObject *___mypyc_temp__0;
    tuple_T3OOO ___mypyc_temp__1;
} dank_mids____vendor___aiolimiter___src___aiolimiter___leakybucket___acquire_AsyncLimiter_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_generator_attribute__self;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_temp__2;
    tuple_T3OOO ___mypyc_temp__3;
} dank_mids____vendor___aiolimiter___src___aiolimiter___leakybucket_____aenter___3_AsyncLimiter_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_generator_attribute__self;
    PyObject *___mypyc_generator_attribute__exc_type;
    PyObject *___mypyc_generator_attribute__exc;
    PyObject *___mypyc_generator_attribute__tb;
    int32_t ___mypyc_next_label__;
} dank_mids____vendor___aiolimiter___src___aiolimiter___leakybucket_____aexit___3_AsyncLimiter_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *_normalizers;
    PyObject *_types;
} dank_mids____web3___abi___FormatterObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *_func;
} dank_mids____web3___abi___map_to_typed_dataObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_abi_type;
    PyObject *_data;
} dank_mids____web3___abi___ABITypedDataObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_generator_attribute__normalizers;
    PyObject *___mypyc_generator_attribute__abis;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_temp__0;
    CPyTagged ___mypyc_temp__1;
    int64_t ___mypyc_temp__2;
    PyObject *___mypyc_temp__3;
    PyObject *___mypyc_generator_attribute__method;
    PyObject *___mypyc_generator_attribute__abi_types;
    PyObject *___mypyc_generator_attribute__single_dict_formatter;
} dank_mids____web3___formatters___abi_request_formatters_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
} dank_mids___brownie_patch____abi_____init___3_FunctionABI_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
} dank_mids___brownie_patch____abi___singleton_FunctionABI_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
} dank_mids___brownie_patch___call_____mypyc_lambda__0_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
} dank_mids___brownie_patch___call_____mypyc_lambda__1_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_w3;
    CPyTagged _len_inputs;
    PyObject *_get_request_data;
    PyObject *_coroutine;
} dank_mids___brownie_patch___call____get_coroutine_fn_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *___mypyc_env__;
    PyObject *___mypyc_generator_attribute__self;
    PyObject *___mypyc_generator_attribute__args;
    PyObject *___mypyc_generator_attribute__block_identifier;
    PyObject *___mypyc_generator_attribute__decimals;
    PyObject *___mypyc_generator_attribute__override;
    CPyTagged ___mypyc_generator_attribute___attempt_number;
    PyObject *_type;
    PyObject *_value;
    PyObject *_traceback;
    PyObject *_arg;
    PyObject **_stop_iter_ptr;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_temp__0;
    PyObject *___mypyc_temp__1;
    char ___mypyc_temp__2;
    PyObject *___mypyc_temp__3;
    tuple_T3OOO ___mypyc_temp__4;
    PyObject *___mypyc_temp__5;
    tuple_T3OOO ___mypyc_temp__6;
    PyObject *___mypyc_generator_attribute__data;
    PyObject *___mypyc_temp__7;
    PyObject *___mypyc_temp__8;
    char ___mypyc_temp__9;
    PyObject *___mypyc_temp__10;
    tuple_T3OOO ___mypyc_temp__11;
    PyObject *___mypyc_temp__12;
    tuple_T3OOO ___mypyc_temp__13;
    PyObject *___mypyc_generator_attribute__output;
    tuple_T3OOO ___mypyc_temp__14;
    PyObject *___mypyc_temp__15;
    tuple_T3OOO ___mypyc_temp__16;
    PyObject *___mypyc_temp__17;
    tuple_T3OOO ___mypyc_temp__18;
    tuple_T3OOO ___mypyc_temp__19;
    PyObject *___mypyc_temp__20;
    tuple_T3OOO ___mypyc_temp__21;
    PyObject *___mypyc_temp__22;
    tuple_T3OOO ___mypyc_temp__23;
    PyObject *___mypyc_temp__24;
    tuple_T3OOO ___mypyc_temp__25;
    PyObject *___mypyc_generator_attribute__decoded;
    tuple_T3OOO ___mypyc_temp__26;
    PyObject *___mypyc_generator_attribute__e;
    PyObject *___mypyc_temp__27;
    tuple_T3OOO ___mypyc_temp__28;
} dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_env__;
} dank_mids___brownie_patch___call___coroutine_gen___3_147Object;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_generator_attribute__call;
    CPyTagged ___mypyc_generator_attribute__len_inputs;
    PyObject *___mypyc_generator_attribute__get_request_data;
    PyObject *___mypyc_generator_attribute__args;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_temp__29;
    int64_t ___mypyc_temp__30;
    int64_t ___mypyc_temp__31;
    PyObject *___mypyc_generator_attribute__arg;
    PyObject *___mypyc_generator_attribute__data;
    PyObject *___mypyc_temp__32;
    tuple_T3OOO ___mypyc_temp__33;
    tuple_T3OOO ___mypyc_temp__34;
    PyObject *___mypyc_generator_attribute__exc_str;
} dank_mids___brownie_patch___call___encode_input_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_generator_attribute__call;
    PyObject *___mypyc_generator_attribute__data;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_generator_attribute__decoded;
    PyObject *___mypyc_temp__35;
    tuple_T3OOO ___mypyc_temp__36;
    tuple_T3OOO ___mypyc_temp__37;
    tuple_T3OOO ___mypyc_temp__38;
    PyObject *___mypyc_generator_attribute__e;
    PyObject *___mypyc_temp__39;
    tuple_T3OOO ___mypyc_temp__40;
} dank_mids___brownie_patch___call___decode_output_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_generator_attribute__call;
    int32_t ___mypyc_next_label__;
} dank_mids___brownie_patch___call____request_data_no_args_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_call;
    PyObject *_coroutine;
    PyObject *_w3;
} dank_mids___brownie_patch___overloaded____patch_overloaded_method_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *___mypyc_env__;
    PyObject *___mypyc_generator_attribute__self;
    PyObject *___mypyc_generator_attribute__args;
    PyObject *___mypyc_generator_attribute__block_identifier;
    PyObject *___mypyc_generator_attribute__decimals;
    PyObject *___mypyc_generator_attribute__override;
    PyObject *_type;
    PyObject *_value;
    PyObject *_traceback;
    PyObject *_arg;
    PyObject **_stop_iter_ptr;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_generator_attribute__fn;
    tuple_T3OOO ___mypyc_temp__0;
    PyObject *___mypyc_generator_attribute__e;
    PyObject *___mypyc_generator_attribute__exc_str;
    tuple_T2OO ___mypyc_generator_attribute__match_on;
    tuple_T2OO ___mypyc_temp__1;
    PyObject *___mypyc_temp__2;
    PyObject *___mypyc_generator_attribute__s;
    CPyTagged ___mypyc_generator_attribute__breakpoint;
    PyObject *___mypyc_generator_attribute__kwargs;
    PyObject *___mypyc_temp__3;
    PyObject *___mypyc_temp__4;
    CPyTagged ___mypyc_temp__5;
    int64_t ___mypyc_temp__6;
    PyObject *___mypyc_temp__7;
    PyObject *___mypyc_generator_attribute__k;
    PyObject *___mypyc_generator_attribute__v;
    PyObject *___mypyc_temp__8;
    tuple_T3OOO ___mypyc_temp__9;
} dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_env__;
} dank_mids___brownie_patch___overloaded___coroutine_gen___3_23Object;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} dank_mids___brownie_patch___types___DankContractCallObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} dank_mids___brownie_patch___types___DankContractTxObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_methods;
} dank_mids___brownie_patch___types___DankOverloadedMethodObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_generator_attribute__self;
    PyObject *___mypyc_generator_attribute__args;
    PyObject *___mypyc_generator_attribute__block_identifier;
    PyObject *___mypyc_generator_attribute__decimals;
    PyObject *___mypyc_generator_attribute__override;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_generator_attribute__call;
    PyObject *___mypyc_temp__0;
    tuple_T3OOO ___mypyc_temp__1;
} dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *__raw;
} dank_mids___helpers____codec___RawResponseObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_generator_attribute__coros;
    PyObject *___mypyc_generator_attribute__name;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_generator_attribute__loop;
    PyObject *___mypyc_temp__0;
    PyObject *___mypyc_temp__1;
    PyObject *___mypyc_temp__2;
    PyObject *___mypyc_generator_attribute__coro;
    PyObject *___mypyc_generator_attribute__tasks;
    PyObject *___mypyc_temp__3;
    tuple_T3OOO ___mypyc_temp__4;
    PyObject *___mypyc_temp__5;
    tuple_T3OOO ___mypyc_temp__6;
    PyObject *___mypyc_temp__7;
    PyObject *___mypyc_temp__8;
    PyObject *___mypyc_generator_attribute__task;
    PyObject *___mypyc_temp__9;
    tuple_T3OOO ___mypyc_temp__10;
    tuple_T3OOO ___mypyc_temp__11;
    PyObject *___mypyc_temp__12;
    PyObject *___mypyc_temp__13;
    PyObject *___mypyc_temp__14;
    tuple_T3OOO ___mypyc_temp__15;
    tuple_T3OOO ___mypyc_temp__16;
} dank_mids___helpers____gather___gatherish_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_generator_attribute__task;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_temp__17;
    tuple_T3OOO ___mypyc_temp__18;
    tuple_T3OOO ___mypyc_temp__19;
} dank_mids___helpers____gather____log_cancelled_error_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
} dank_mids___helpers____rate_limit_____mypyc_lambda__0_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_generator_attribute__endpoint;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_generator_attribute__existing;
    PyObject *___mypyc_temp__0;
    tuple_T3OOO ___mypyc_temp__1;
    PyObject *___mypyc_generator_attribute__task;
    PyObject *___mypyc_temp__2;
    tuple_T3OOO ___mypyc_temp__3;
} dank_mids___helpers____rate_limit___rate_limit_inactive_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_generator_attribute__endpoint;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_generator_attribute__yield_to_loop;
    PyObject *___mypyc_generator_attribute__waiters;
    tuple_T3FIO ___mypyc_generator_attribute__last_waiter_tuple;
    PyObject *___mypyc_generator_attribute__last_waiter;
    PyObject *___mypyc_temp__4;
    tuple_T3OOO ___mypyc_temp__5;
    tuple_T3OOO ___mypyc_temp__6;
    CPyTagged ___mypyc_temp__7;
    CPyTagged ___mypyc_temp__8;
    PyObject *___mypyc_generator_attribute___;
    PyObject *___mypyc_temp__9;
    tuple_T3OOO ___mypyc_temp__10;
} dank_mids___helpers____rate_limit_____rate_limit_inactive_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *__refs;
} dank_mids___helpers____weaklist___WeakListObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_generator_attribute__self;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_temp__0;
    CPyTagged ___mypyc_temp__1;
    int64_t ___mypyc_temp__2;
    PyObject *___mypyc_temp__3;
    PyObject *___mypyc_generator_attribute__reference;
    PyObject *___mypyc_generator_attribute__obj;
} dank_mids___helpers____weaklist_____iter___3_WeakList_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
} dank_mids___helpers___hashing_____init___3_AttributeDict_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
} dank_mids___helpers___hashing_____hash___3_AttributeDict_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
} dank_mids___helpers___hashing_____eq___3_AttributeDict_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
} dank_mids___helpers___hashing_____setattr___3_AttributeDict_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
} dank_mids___helpers___hashing_____delattr___3_AttributeDict_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
} dank_mids___helpers___hashing_____getitem___3_AttributeDict_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
} dank_mids___helpers___hashing_____iter___3_AttributeDict_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
} dank_mids___helpers___hashing_____len___3_AttributeDict_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
} dank_mids___helpers___hashing_____repr___3_AttributeDict_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
} dank_mids___helpers___hashing____repr_pretty__AttributeDict_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
} dank_mids___helpers___hashing___recursive_AttributeDict_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
} dank_mids___helpers___hashing___keys_AttributeDict_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
} dank_mids___helpers___hashing___values_AttributeDict_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
} dank_mids___helpers___hashing___items_AttributeDict_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *_registry;
    PyObject *_dispatch_cache;
} dank_mids___helpers___hashing____to_tuple_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_func;
    PyObject *_cache;
    PyObject *_cache_miss;
    PyObject *_lru_cache_lite_wrap;
} dank_mids___helpers___lru_cache___lru_cache_lite_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_func;
    PyObject *_cache;
    PyObject *_lru_cache_lite_wrap;
} dank_mids___helpers___lru_cache___lru_cache_lite_nonull_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} dank_mids___helpers___lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *__daemon;
} dank_mids___stats____StatsLoggerObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_errd_batches;
    PyObject *_durations;
    PyObject *_types;
    PyObject *_event_loop_times;
    PyObject *_validation_errors;
} dank_mids___stats____CollectorObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
} dank_mids___stats____WriterObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_metrics;
    PyObject *_units;
    PyObject *_set_tag;
    PyObject *_set_measurement;
    PyObject *__exc;
} dank_mids___stats____SentryExporterObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    uint32_t bitmap;
    PyObject *___mypyc_generator_attribute__self;
    int32_t ___mypyc_next_label__;
    double ___mypyc_generator_attribute__start;
    double ___mypyc_generator_attribute__time_since_notified;
    PyObject *___mypyc_temp__0;
    tuple_T3OOO ___mypyc_temp__1;
    double ___mypyc_generator_attribute__now;
    double ___mypyc_generator_attribute__duration;
} dank_mids___stats____stats_daemon__StatsLogger_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_self;
} dank_mids___stats_____init___3__Collector_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} dank_mids___stats_____mypyc_lambda__0___3_init___3__Collector_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} dank_mids___stats_____mypyc_lambda__1___3_init___3__Collector_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    uint32_t bitmap;
    PyObject *_pending_rpc_calls;
    PyObject *__loop;
    PyObject *_w3;
    CPyTagged _max_jsonrpc_batch_size;
    PyObject *_sync_w3;
    PyObject *_chain_id;
    PyObject *_client_version;
    PyObject *_request_type;
    double __request_type_changed_ts;
    char _state_override_not_supported;
    PyObject *_endpoint;
    char __sort_calls;
    char __sort_response;
    CPyTagged __instance;
    PyObject *_mc2;
    PyObject *_mc3;
    PyObject *_no_multicall;
    PyObject *__latest_mc;
    PyObject *_eth_call_semaphores;
    PyObject *_batcher;
    PyObject *_call_uid;
    PyObject *_multicall_uid;
    PyObject *_request_uid;
    PyObject *_jsonrpc_batch_uid;
    PyObject *_pools_closed_lock;
    PyObject *_pending_eth_calls;
} dank_mids___controller___DankMiddlewareControllerObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_self;
    PyObject *_w3;
    PyObject *_chainid;
    char _using_reth_client;
    PyObject *_using_tenderly_client;
    char _using_chainstack_rpc;
    PyObject *_multicall;
} dank_mids___controller_____init___3_DankMiddlewareController_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} dank_mids___controller_____mypyc_lambda__0___3_init___3_DankMiddlewareController_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_generator_attribute__self;
    PyObject *___mypyc_generator_attribute__method;
    PyObject *___mypyc_generator_attribute__params;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_temp__0;
    tuple_T3OOO ___mypyc_temp__1;
    PyObject *___mypyc_temp__2;
    PyObject *___mypyc_temp__3;
    char ___mypyc_temp__4;
    PyObject *___mypyc_temp__5;
    tuple_T3OOO ___mypyc_temp__6;
    PyObject *___mypyc_temp__7;
    tuple_T3OOO ___mypyc_temp__8;
    PyObject *___mypyc_temp__9;
    PyObject *___mypyc_temp__10;
    tuple_T3OOO ___mypyc_temp__11;
    tuple_T3OOO ___mypyc_temp__12;
    PyObject *___mypyc_temp__13;
    tuple_T3OOO ___mypyc_temp__14;
    PyObject *___mypyc_temp__15;
    tuple_T3OOO ___mypyc_temp__16;
    PyObject *___mypyc_temp__17;
    tuple_T3OOO ___mypyc_temp__18;
    tuple_T3OOO ___mypyc_temp__19;
    PyObject *___mypyc_temp__20;
    tuple_T3OOO ___mypyc_temp__21;
} dank_mids___controller_____call___3_DankMiddlewareController_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *___mypyc_generator_attribute__self;
    PyObject *___mypyc_generator_attribute__method;
    PyObject *___mypyc_generator_attribute__params;
    PyObject *___mypyc_generator_attribute__request_id;
    PyObject *_type;
    PyObject *_value;
    PyObject *_traceback;
    PyObject *_arg;
    PyObject **_stop_iter_ptr;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_generator_attribute__request;
    PyObject *___mypyc_temp__22;
    tuple_T3OOO ___mypyc_temp__23;
    tuple_T3OOO ___mypyc_temp__24;
    PyObject *___mypyc_generator_attribute__e;
} dank_mids___controller___make_request_DankMiddlewareController_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_env__;
} dank_mids___controller___make_request_DankMiddlewareController_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_generator_attribute__self;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_temp__25;
    PyObject *___mypyc_temp__26;
    char ___mypyc_temp__27;
    PyObject *___mypyc_generator_attribute__multicalls;
    PyObject *___mypyc_generator_attribute__rpc_calls;
    tuple_T3OOO ___mypyc_temp__28;
    PyObject *___mypyc_generator_attribute__batch;
    PyObject *___mypyc_temp__29;
    tuple_T3OOO ___mypyc_temp__30;
} dank_mids___controller___execute_batch_DankMiddlewareController_genObject;

#endif
