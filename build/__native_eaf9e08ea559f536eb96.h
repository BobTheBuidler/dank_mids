#ifndef MYPYC_NATIVE_eaf9e08ea559f536eb96_H
#define MYPYC_NATIVE_eaf9e08ea559f536eb96_H
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

#ifndef MYPYC_DECLARED_tuple_T1O
#define MYPYC_DECLARED_tuple_T1O
typedef struct tuple_T1O {
    PyObject *f0;
} tuple_T1O;
#endif

#ifndef MYPYC_DECLARED_tuple_T5OOOOO
#define MYPYC_DECLARED_tuple_T5OOOOO
typedef struct tuple_T5OOOOO {
    PyObject *f0;
    PyObject *f1;
    PyObject *f2;
    PyObject *f3;
    PyObject *f4;
} tuple_T5OOOOO;
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

#ifndef MYPYC_DECLARED_tuple_T2OI
#define MYPYC_DECLARED_tuple_T2OI
typedef struct tuple_T2OI {
    PyObject *f0;
    CPyTagged f1;
} tuple_T2OI;
#endif

#ifndef MYPYC_DECLARED_tuple_T1I
#define MYPYC_DECLARED_tuple_T1I
typedef struct tuple_T1I {
    CPyTagged f0;
} tuple_T1I;
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
    PyObject *__check_len;
} dank_mids____batch___DankBatchObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_self;
    PyObject *_type;
    PyObject *_value;
    PyObject *_traceback;
    PyObject *_arg;
    CPyTagged ___mypyc_next_label__;
    PyObject *_batches;
    PyObject *_last_failure;
    PyObject *___mypyc_temp__0;
    CPyTagged ___mypyc_temp__1;
    PyObject *___mypyc_temp__2;
    CPyTagged ___mypyc_temp__3;
    PyObject *_coro;
    PyObject *___mypyc_temp__4;
    CPyTagged ___mypyc_temp__5;
    PyObject *_batch;
    PyObject *_task;
    PyObject *___mypyc_temp__6;
    tuple_T3OOO ___mypyc_temp__7;
    tuple_T3OOO ___mypyc_temp__8;
    PyObject *_e;
    PyObject *___mypyc_temp__9;
    tuple_T3OOO ___mypyc_temp__10;
} dank_mids____batch____await_DankBatch_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_env__;
} dank_mids____batch____await_DankBatch_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_self;
    PyObject *_type;
    PyObject *_value;
    PyObject *_traceback;
    PyObject *_arg;
    CPyTagged ___mypyc_next_label__;
    PyObject *_working_batch;
    PyObject *_batch_append;
    PyObject *_check_len;
    PyObject *___mypyc_temp__11;
    CPyTagged ___mypyc_temp__12;
    CPyTagged ___mypyc_temp__13;
    PyObject *___mypyc_temp__14;
    PyObject *_mcall;
    PyObject *_call;
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
    CPyTagged __value;
    PyObject *__lock;
} dank_mids____uid___UIDGeneratorObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_abi;
    PyObject *_input_sig;
    PyObject *_signature;
} dank_mids___brownie_patch____abi___FunctionABIObject;

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
    PyObject *_self;
    PyObject *_args;
    PyObject *_block_identifier;
    PyObject *_decimals;
    PyObject *_override;
    PyObject *_type;
    PyObject *_value;
    PyObject *_traceback;
    PyObject *_arg;
    CPyTagged ___mypyc_next_label__;
    PyObject *___mypyc_temp__0;
    PyObject *___mypyc_temp__1;
    char ___mypyc_temp__2;
    PyObject *___mypyc_temp__3;
    tuple_T3OOO ___mypyc_temp__4;
    PyObject *___mypyc_temp__5;
    tuple_T3OOO ___mypyc_temp__6;
    PyObject *_data;
    PyObject *___mypyc_temp__7;
    PyObject *___mypyc_temp__8;
    char ___mypyc_temp__9;
    PyObject *___mypyc_temp__10;
    tuple_T3OOO ___mypyc_temp__11;
    PyObject *___mypyc_temp__12;
    tuple_T3OOO ___mypyc_temp__13;
    PyObject *_output;
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
    PyObject *_decoded;
    tuple_T3OOO ___mypyc_temp__26;
    PyObject *_e;
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
} dank_mids___brownie_patch___call___coroutine__get_coroutine_fn_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_call;
    CPyTagged _len_inputs;
    PyObject *_get_request_data;
    PyObject *_args;
    PyObject *_type;
    PyObject *_value;
    PyObject *_traceback;
    PyObject *_arg;
    CPyTagged ___mypyc_next_label__;
    PyObject *___mypyc_temp__27;
    CPyTagged ___mypyc_temp__28;
    PyObject *_data;
    PyObject *___mypyc_temp__29;
    tuple_T3OOO ___mypyc_temp__30;
    tuple_T3OOO ___mypyc_temp__31;
    PyObject *_exc_str;
} dank_mids___brownie_patch___call___encode_input_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_env__;
} dank_mids___brownie_patch___call___encode_input_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_call;
    PyObject *_data;
    PyObject *_type;
    PyObject *_value;
    PyObject *_traceback;
    PyObject *_arg;
    CPyTagged ___mypyc_next_label__;
    PyObject *_decoded;
    PyObject *___mypyc_temp__32;
    tuple_T3OOO ___mypyc_temp__33;
    tuple_T3OOO ___mypyc_temp__34;
    tuple_T3OOO ___mypyc_temp__35;
    PyObject *_e;
    PyObject *___mypyc_temp__36;
    tuple_T3OOO ___mypyc_temp__37;
} dank_mids___brownie_patch___call___decode_output_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_env__;
} dank_mids___brownie_patch___call___decode_output_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_call;
    PyObject *_type;
    PyObject *_value;
    PyObject *_traceback;
    PyObject *_arg;
    CPyTagged ___mypyc_next_label__;
} dank_mids___brownie_patch___call____request_data_no_args_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_env__;
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
    PyObject *_self;
    PyObject *_args;
    PyObject *_block_identifier;
    PyObject *_decimals;
    PyObject *_override;
    PyObject *_type;
    PyObject *_value;
    PyObject *_traceback;
    PyObject *_arg;
    CPyTagged ___mypyc_next_label__;
    PyObject *_fn;
    tuple_T3OOO ___mypyc_temp__0;
    PyObject *_e;
    PyObject *_exc_str;
    tuple_T2OO _match_on;
    tuple_T2OO ___mypyc_temp__1;
    PyObject *___mypyc_temp__2;
    PyObject *_s;
    CPyTagged _breakpoint;
    PyObject *_kwargs;
    PyObject *___mypyc_temp__3;
    PyObject *___mypyc_temp__4;
    CPyTagged ___mypyc_temp__5;
    CPyTagged ___mypyc_temp__6;
    PyObject *___mypyc_temp__7;
    PyObject *_k;
    PyObject *_v;
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
} dank_mids___brownie_patch___overloaded___coroutine__patch_overloaded_method_genObject;

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
    PyObject *___mypyc_self__;
    PyObject *_self;
    PyObject *_args;
    PyObject *_block_identifier;
    PyObject *_decimals;
    PyObject *_override;
    PyObject *_type;
    PyObject *_value;
    PyObject *_traceback;
    PyObject *_arg;
    CPyTagged ___mypyc_next_label__;
    PyObject *_call;
    PyObject *___mypyc_temp__0;
    tuple_T3OOO ___mypyc_temp__1;
} dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_env__;
} dank_mids___brownie_patch___types___coroutine_DankOverloadedMethod_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *__raw;
} dank_mids___helpers____codec___RawResponseObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
} dank_mids___helpers____codec_____mypyc_lambda__0_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_coros;
    PyObject *_name;
    PyObject *_type;
    PyObject *_value;
    PyObject *_traceback;
    PyObject *_arg;
    CPyTagged ___mypyc_next_label__;
    PyObject *_loop;
    PyObject *___mypyc_temp__0;
    PyObject *___mypyc_temp__1;
    PyObject *___mypyc_temp__2;
    PyObject *_coro;
    PyObject *_tasks;
    PyObject *___mypyc_temp__3;
    tuple_T3OOO ___mypyc_temp__4;
    PyObject *___mypyc_temp__5;
    tuple_T3OOO ___mypyc_temp__6;
    PyObject *___mypyc_temp__7;
    PyObject *___mypyc_temp__8;
    PyObject *_task;
    PyObject *___mypyc_temp__9;
    tuple_T3OOO ___mypyc_temp__10;
    tuple_T3OOO ___mypyc_temp__11;
    PyObject *___mypyc_temp__12;
    PyObject *___mypyc_temp__13;
    PyObject *___mypyc_temp__14;
    tuple_T3OOO ___mypyc_temp__15;
    tuple_T3OOO ___mypyc_temp__16;
} dank_mids___helpers____gather___gatherish_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_env__;
} dank_mids___helpers____gather___gatherish_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_fs;
    char _cancel;
    PyObject *_type;
    PyObject *_value;
    PyObject *_traceback;
    PyObject *_arg;
    CPyTagged ___mypyc_next_label__;
    PyObject *___mypyc_temp__17;
    tuple_T3OOO ___mypyc_temp__18;
    PyObject *___mypyc_temp__19;
    tuple_T3OOO ___mypyc_temp__20;
    PyObject *_done;
    PyObject *_pending;
    PyObject *___mypyc_temp__21;
    PyObject *___mypyc_temp__22;
    PyObject *_p;
} dank_mids___helpers____gather___first_completed_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_env__;
} dank_mids___helpers____gather___first_completed_genObject;

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
    PyObject *__refs;
} dank_mids___helpers____weaklist___WeakListObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_self__;
    PyObject *_self;
    PyObject *_type;
    PyObject *_value;
    PyObject *_traceback;
    PyObject *_arg;
    CPyTagged ___mypyc_next_label__;
    PyObject *___mypyc_temp__0;
    CPyTagged ___mypyc_temp__1;
    CPyTagged ___mypyc_temp__2;
    PyObject *___mypyc_temp__3;
    PyObject *_r;
    PyObject *_obj;
} dank_mids___helpers____weaklist_____iter___3_WeakList_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *___mypyc_env__;
} dank_mids___helpers____weaklist_____iter___3_WeakList_genObject;


struct export_table_eaf9e08ea559f536eb96 {
    PyObject **CPyStatic__batch___logger;
    PyTypeObject **CPyType__batch___DankBatch;
    PyObject *(*CPyDef__batch___DankBatch)(PyObject *cpy_r_controller, PyObject *cpy_r_multicalls, PyObject *cpy_r_rpc_calls);
    PyTypeObject **CPyType__batch____await_DankBatch_env;
    PyObject *(*CPyDef__batch____await_DankBatch_env)(void);
    PyTypeObject **CPyType__batch____await_DankBatch_gen;
    PyObject *(*CPyDef__batch____await_DankBatch_gen)(void);
    PyTypeObject **CPyType__batch___coroutines_DankBatch_env;
    PyObject *(*CPyDef__batch___coroutines_DankBatch_env)(void);
    PyTypeObject **CPyType__batch___coroutines_DankBatch_gen;
    PyObject *(*CPyDef__batch___coroutines_DankBatch_gen)(void);
    PyObject *(*CPyDef__batch____create_named_task)(PyObject *cpy_r_awaitable);
    char (*CPyDef__batch___DankBatch_____init__)(PyObject *cpy_r_self, PyObject *cpy_r_controller, PyObject *cpy_r_multicalls, PyObject *cpy_r_rpc_calls);
    PyObject *(*CPyDef__batch___DankBatch_____repr__)(PyObject *cpy_r_self);
    PyObject *(*CPyDef__batch___DankBatch_____await__)(PyObject *cpy_r_self);
    PyObject *(*CPyDef__batch____await_DankBatch_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef__batch____await_DankBatch_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__batch____await_DankBatch_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef__batch____await_DankBatch_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__batch____await_DankBatch_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef__batch____await_DankBatch_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__batch____await_DankBatch_gen_____await__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__batch___DankBatch____await)(PyObject *cpy_r_self);
    PyObject *(*CPyDef__batch___coroutines_DankBatch_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef__batch___coroutines_DankBatch_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__batch___coroutines_DankBatch_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef__batch___coroutines_DankBatch_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__batch___coroutines_DankBatch_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef__batch___coroutines_DankBatch_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__batch___DankBatch___coroutines)(PyObject *cpy_r_self);
    char (*CPyDef__batch_____top_level__)(void);
    PyObject **CPyStatic__demo_mode___demo_logger;
    PyTypeObject **CPyType__demo_mode___DummyLogger;
    PyObject *(*CPyDef__demo_mode___DummyLogger)(void);
    char (*CPyDef__demo_mode___DummyLogger___info)(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
    char (*CPyDef__demo_mode_____top_level__)(void);
    PyObject **CPyStatic__envs____factory;
    PyObject **CPyStatic__envs___create_env;
    PyObject **CPyStatic__envs____deprecated_format;
    char (*CPyDef__envs_____top_level__)(void);
    PyObject **CPyStatic__eth_utils___hexlify;
    PyObject **CPyStatic__eth_utils___unhexlify;
    char (*CPyDef__eth_utils___patch_eth_utils)(void);
    PyObject *(*CPyDef__eth_utils___to_hex)(PyObject *cpy_r_primitive, PyObject *cpy_r_hexstr, PyObject *cpy_r_text);
    PyObject *(*CPyDef__eth_utils___to_bytes)(PyObject *cpy_r_primitive, PyObject *cpy_r_hexstr, PyObject *cpy_r_text);
    PyObject *(*CPyDef__eth_utils___decode_hex)(PyObject *cpy_r_value);
    PyObject *(*CPyDef__eth_utils___encode_hex)(PyObject *cpy_r_value);
    char (*CPyDef__eth_utils___is_0x_prefixed)(PyObject *cpy_r_value);
    PyObject *(*CPyDef__eth_utils___remove_0x_prefix)(PyObject *cpy_r_value);
    PyObject *(*CPyDef__eth_utils___add_0x_prefix)(PyObject *cpy_r_value);
    char (*CPyDef__eth_utils_____top_level__)(void);
    PyObject **CPyStatic__exceptions___logger;
    PyObject **CPyStatic__exceptions___internal_err_types;
    PyTypeObject **CPyType__exceptions___BadResponse;
    PyTypeObject **CPyType__exceptions___EmptyBatch;
    PyTypeObject **CPyType__exceptions___ExecutionReverted;
    PyTypeObject **CPyType__exceptions___OutOfGas;
    PyTypeObject **CPyType__exceptions___PayloadTooLarge;
    PyTypeObject **CPyType__exceptions___ExceedsMaxBatchSize;
    PyTypeObject **CPyType__exceptions___DankMidsClientResponseError;
    PyObject *(*CPyDef__exceptions___DankMidsClientResponseError)(PyObject *cpy_r_exc, PyObject *cpy_r_request);
    PyTypeObject **CPyType__exceptions___DankMidsInternalError;
    PyTypeObject **CPyType__exceptions___BatchResponseSortError;
    PyTypeObject **CPyType__exceptions___RateLimitError;
    PyTypeObject **CPyType__exceptions___ChainstackRateLimitError;
    PyTypeObject **CPyType__exceptions___QuiknodeRateLimitError;
    char (*CPyDef__exceptions___BadResponse_____init__)(PyObject *cpy_r_self, PyObject *cpy_r_response);
    char (*CPyDef__exceptions___ExecutionReverted_____init__)(PyObject *cpy_r_self, PyObject *cpy_r_response);
    CPyTagged (*CPyDef__exceptions___ExceedsMaxBatchSize___limit)(PyObject *cpy_r_self);
    char (*CPyDef__exceptions___DankMidsClientResponseError_____init__)(PyObject *cpy_r_self, PyObject *cpy_r_exc, PyObject *cpy_r_request);
    char (*CPyDef__exceptions___DankMidsInternalError_____init__)(PyObject *cpy_r_self, PyObject *cpy_r_exc);
    char (*CPyDef__exceptions___BatchResponseSortError_____init__)(PyObject *cpy_r_self, PyObject *cpy_r_controller, PyObject *cpy_r_calls, PyObject *cpy_r_response);
    double (*CPyDef__exceptions___ChainstackRateLimitError___try_again_in)(PyObject *cpy_r_self);
    char (*CPyDef__exceptions_____top_level__)(void);
    PyObject **CPyStatic__logging___getLogger;
    CPyTagged *CPyStatic__logging___CRITICAL;
    CPyTagged *CPyStatic__logging___FATAL;
    CPyTagged *CPyStatic__logging___ERROR;
    CPyTagged *CPyStatic__logging___WARN;
    CPyTagged *CPyStatic__logging___WARNING;
    CPyTagged *CPyStatic__logging___INFO;
    CPyTagged *CPyStatic__logging___DEBUG;
    CPyTagged *CPyStatic__logging___NOTSET;
    char (*CPyDef__logging_____top_level__)(void);
    PyTypeObject **CPyType__uid___UIDGenerator;
    PyObject *(*CPyDef__uid___UIDGenerator)(void);
    char (*CPyDef__uid___UIDGenerator_____init__)(PyObject *cpy_r_self);
    CPyTagged (*CPyDef__uid___UIDGenerator___latest)(PyObject *cpy_r_self);
    CPyTagged (*CPyDef__uid___UIDGenerator___next)(PyObject *cpy_r_self);
    char (*CPyDef__uid_____top_level__)(void);
    char (*CPyDef_brownie_patch_____top_level__)(void);
    PyTypeObject **CPyType__abi___FunctionABI;
    PyObject *(*CPyDef__abi___FunctionABI)(PyObject *cpy_r_abi);
    char (*CPyDef__abi___FunctionABI_____init__)(PyObject *cpy_r_self, PyObject *cpy_r_abi);
    PyObject *(*CPyDef__abi___FunctionABI___singleton)(PyObject *cpy_r_abi);
    char (*CPyDef__abi_____top_level__)(void);
    PyObject **CPyStatic_call___ENVS;
    char *CPyStatic_call___APPLICATION_MODE;
    PyObject **CPyStatic_call___Decimal;
    PyObject **CPyStatic_call___HexBytes;
    PyObject **CPyStatic_call___Contract;
    PyObject **CPyStatic_call___ReturnValue;
    PyObject **CPyStatic_call___HexString;
    PyObject **CPyStatic_call___TupleType;
    PyObject **CPyStatic_call___Revert;
    PyObject **CPyStatic_call___to_bool;
    PyObject **CPyStatic_call___to_decimal;
    PyObject **CPyStatic_call___to_int;
    PyObject **CPyStatic_call___to_string;
    PyObject **CPyStatic_call___to_uint;
    PyObject **CPyStatic_call____check_array;
    PyObject **CPyStatic_call____get_abi_types;
    PyObject **CPyStatic_call___logger;
    PyObject **CPyStatic_call___encode;
    PyObject **CPyStatic_call___decode;
    PyObject **CPyStatic_call___to_checksum_address;
    PyObject **CPyStatic_call_____eth_abi_encode;
    PyObject **CPyStatic_call_____eth_abi_decode;
    PyTypeObject **CPyType_call_____mypyc_lambda__0_obj;
    PyObject *(*CPyDef_call_____mypyc_lambda__0_obj)(void);
    PyTypeObject **CPyType_call_____mypyc_lambda__1_obj;
    PyObject *(*CPyDef_call_____mypyc_lambda__1_obj)(void);
    PyTypeObject **CPyType_call____get_coroutine_fn_env;
    PyObject *(*CPyDef_call____get_coroutine_fn_env)(void);
    PyTypeObject **CPyType_call___coroutine__get_coroutine_fn_env;
    PyObject *(*CPyDef_call___coroutine__get_coroutine_fn_env)(void);
    PyTypeObject **CPyType_call___coroutine__get_coroutine_fn_obj;
    PyObject *(*CPyDef_call___coroutine__get_coroutine_fn_obj)(void);
    PyTypeObject **CPyType_call___coroutine__get_coroutine_fn_gen;
    PyObject *(*CPyDef_call___coroutine__get_coroutine_fn_gen)(void);
    PyTypeObject **CPyType_call___encode_input_env;
    PyObject *(*CPyDef_call___encode_input_env)(void);
    PyTypeObject **CPyType_call___encode_input_gen;
    PyObject *(*CPyDef_call___encode_input_gen)(void);
    PyTypeObject **CPyType_call___decode_output_env;
    PyObject *(*CPyDef_call___decode_output_env)(void);
    PyTypeObject **CPyType_call___decode_output_gen;
    PyObject *(*CPyDef_call___decode_output_gen)(void);
    PyTypeObject **CPyType_call____request_data_no_args_env;
    PyObject *(*CPyDef_call____request_data_no_args_env)(void);
    PyTypeObject **CPyType_call____request_data_no_args_gen;
    PyObject *(*CPyDef_call____request_data_no_args_gen)(void);
    PyObject *(*CPyDef_call_____mypyc_lambda__0_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef_call_____mypyc_lambda__0_obj_____call__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_self, PyObject *cpy_r_args);
    PyObject *(*CPyDef_call_____mypyc_lambda__1_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef_call_____mypyc_lambda__1_obj_____call__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_self, PyObject *cpy_r_data);
    char (*CPyDef_call____patch_call)(PyObject *cpy_r_call, PyObject *cpy_r_w3);
    PyObject *(*CPyDef_call___coroutine__get_coroutine_fn_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef_call___coroutine__get_coroutine_fn_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_call___coroutine__get_coroutine_fn_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_call___coroutine__get_coroutine_fn_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_call___coroutine__get_coroutine_fn_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_call___coroutine__get_coroutine_fn_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef_call___coroutine__get_coroutine_fn_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_call___coroutine__get_coroutine_fn_gen_____await__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_call___coroutine__get_coroutine_fn_obj_____call__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_self, PyObject *cpy_r_args, PyObject *cpy_r_block_identifier, PyObject *cpy_r_decimals, PyObject *cpy_r_override);
    PyObject *(*CPyDef_call____get_coroutine_fn)(PyObject *cpy_r_w3, CPyTagged cpy_r_len_inputs);
    PyObject *(*CPyDef_call____call_no_args)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_call___encode_input_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_call___encode_input_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_call___encode_input_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_call___encode_input_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_call___encode_input_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef_call___encode_input_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_call___encode_input_gen_____await__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_call___encode_input)(PyObject *cpy_r_call, CPyTagged cpy_r_len_inputs, PyObject *cpy_r_get_request_data, PyObject *cpy_r_args);
    PyObject *(*CPyDef_call___decode_output_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_call___decode_output_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_call___decode_output_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_call___decode_output_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_call___decode_output_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef_call___decode_output_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_call___decode_output_gen_____await__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_call___decode_output)(PyObject *cpy_r_call, PyObject *cpy_r_data);
    PyObject *(*CPyDef_call____request_data_no_args_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_call____request_data_no_args_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_call____request_data_no_args_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_call____request_data_no_args_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_call____request_data_no_args_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef_call____request_data_no_args_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_call____request_data_no_args_gen_____await__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_call____request_data_no_args)(PyObject *cpy_r_call);
    PyObject *(*CPyDef_call_____encode_input)(PyObject *cpy_r_abi, PyObject *cpy_r_signature, PyObject *cpy_r_args);
    PyObject *(*CPyDef_call_____decode_output)(PyObject *cpy_r_hexstr, PyObject *cpy_r_abi);
    char (*CPyDef_call_____validate_output)(PyObject *cpy_r_abi, PyObject *cpy_r_hexstr);
    PyObject *(*CPyDef_call___format_input_but_cache_checksums)(PyObject *cpy_r_abi, PyObject *cpy_r_inputs);
    PyObject *(*CPyDef_call___format_output_but_cache_checksums)(PyObject *cpy_r_abi, PyObject *cpy_r_outputs);
    PyObject *(*CPyDef_call____format_tuple_but_cache_checksums)(PyObject *cpy_r_abi_types, PyObject *cpy_r_values);
    PyObject *(*CPyDef_call____format_array_but_cache_checksums)(PyObject *cpy_r_abi_type, PyObject *cpy_r_values);
    PyObject *(*CPyDef_call____format_single_but_cache_checksums)(PyObject *cpy_r_type_str, PyObject *cpy_r_value);
    char (*CPyDef_call_____top_level__)(void);
    PyTypeObject **CPyType_overloaded____patch_overloaded_method_env;
    PyObject *(*CPyDef_overloaded____patch_overloaded_method_env)(void);
    PyTypeObject **CPyType_overloaded___coroutine__patch_overloaded_method_env;
    PyObject *(*CPyDef_overloaded___coroutine__patch_overloaded_method_env)(void);
    PyTypeObject **CPyType_overloaded___coroutine__patch_overloaded_method_obj;
    PyObject *(*CPyDef_overloaded___coroutine__patch_overloaded_method_obj)(void);
    PyTypeObject **CPyType_overloaded___coroutine__patch_overloaded_method_gen;
    PyObject *(*CPyDef_overloaded___coroutine__patch_overloaded_method_gen)(void);
    PyObject *(*CPyDef_overloaded___coroutine__patch_overloaded_method_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef_overloaded___coroutine__patch_overloaded_method_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_overloaded___coroutine__patch_overloaded_method_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_overloaded___coroutine__patch_overloaded_method_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_overloaded___coroutine__patch_overloaded_method_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_overloaded___coroutine__patch_overloaded_method_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef_overloaded___coroutine__patch_overloaded_method_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_overloaded___coroutine__patch_overloaded_method_gen_____await__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_overloaded___coroutine__patch_overloaded_method_obj_____call__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_self, PyObject *cpy_r_args, PyObject *cpy_r_block_identifier, PyObject *cpy_r_decimals, PyObject *cpy_r_override);
    char (*CPyDef_overloaded____patch_overloaded_method)(PyObject *cpy_r_call, PyObject *cpy_r_w3);
    char (*CPyDef_overloaded_____top_level__)(void);
    PyTypeObject **CPyType_types___DankContractCall;
    PyObject *(*CPyDef_types___DankContractCall)(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
    PyTypeObject **CPyType_types___DankContractTx;
    PyObject *(*CPyDef_types___DankContractTx)(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
    PyTypeObject **CPyType_types___DankOverloadedMethod;
    PyObject *(*CPyDef_types___DankOverloadedMethod)(PyObject *cpy_r_args, PyObject *cpy_r_kwargs);
    PyTypeObject **CPyType_types___coroutine_DankOverloadedMethod_env;
    PyObject *(*CPyDef_types___coroutine_DankOverloadedMethod_env)(void);
    PyTypeObject **CPyType_types___coroutine_DankOverloadedMethod_gen;
    PyObject *(*CPyDef_types___coroutine_DankOverloadedMethod_gen)(void);
    PyObject *(*CPyDef_types___coroutine_DankOverloadedMethod_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_types___coroutine_DankOverloadedMethod_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_types___coroutine_DankOverloadedMethod_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_types___coroutine_DankOverloadedMethod_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_types___coroutine_DankOverloadedMethod_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef_types___coroutine_DankOverloadedMethod_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_types___coroutine_DankOverloadedMethod_gen_____await__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_types___DankOverloadedMethod___coroutine)(PyObject *cpy_r_self, PyObject *cpy_r_args, PyObject *cpy_r_block_identifier, PyObject *cpy_r_decimals, PyObject *cpy_r_override);
    char (*CPyDef_types___DankOverloadedMethod____add_fn)(PyObject *cpy_r_self, PyObject *cpy_r_abi, PyObject *cpy_r_natspec);
    PyObject *(*CPyDef_types____get_method_object)(PyObject *cpy_r_address, PyObject *cpy_r_abi, PyObject *cpy_r_name, PyObject *cpy_r_owner, PyObject *cpy_r_natspec);
    char (*CPyDef_types_____top_level__)(void);
    PyObject **CPyStatic__codec___HexBytes;
    PyObject **CPyStatic__codec___Raw;
    PyObject **CPyStatic__codec___ContextFramesBytesIO;
    PyObject **CPyStatic__codec___DecodeError;
    PyObject **CPyStatic__codec___encode_uint_256;
    PyObject **CPyStatic__codec___decode_string;
    PyObject **CPyStatic__codec____decode_raw;
    PyObject **CPyStatic__codec___accumulate;
    PyObject **CPyStatic__codec___chain;
    PyObject **CPyStatic__codec___encode;
    PyObject **CPyStatic__codec____mcall_encoder;
    PyObject **CPyStatic__codec____array_encoder;
    PyObject **CPyStatic__codec____item_encoder;
    PyObject **CPyStatic__codec____mcall_decoder;
    PyTypeObject **CPyType__codec___RawResponse;
    PyObject *(*CPyDef__codec___RawResponse)(PyObject *cpy_r_raw);
    PyTypeObject **CPyType__codec_____mypyc_lambda__0_obj;
    PyObject *(*CPyDef__codec_____mypyc_lambda__0_obj)(void);
    char (*CPyDef__codec___RawResponse_____init__)(PyObject *cpy_r_self, PyObject *cpy_r_raw);
    PyObject *(*CPyDef__codec___RawResponse___decode)(PyObject *cpy_r_self, char cpy_r_partial);
    PyObject *(*CPyDef__codec___decode_raw)(PyObject *cpy_r_data);
    PyObject *(*CPyDef__codec___decode_jsonrpc_batch)(PyObject *cpy_r_data);
    PyObject *(*CPyDef__codec____encode_hook)(PyObject *cpy_r_obj);
    PyObject *(*CPyDef__codec____rudimentary_encode_dict_value)(PyObject *cpy_r_value);
    PyObject *(*CPyDef__codec_____mypyc_lambda__0_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef__codec_____mypyc_lambda__0_obj_____call__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r__);
    PyObject *(*CPyDef__codec_____encode_new)(PyObject *cpy_r_values);
    tuple_T2OI (*CPyDef__codec_____encode_elements_new)(PyObject *cpy_r_values);
    PyObject *(*CPyDef__codec___mcall_encode)(PyObject *cpy_r_data);
    PyObject *(*CPyDef__codec___mcall_decode)(PyObject *cpy_r_data);
    char (*CPyDef__codec_____import_from_types)(void);
    char (*CPyDef__codec_____make_decode_batch)(void);
    char (*CPyDef__codec_____top_level__)(void);
    PyObject **CPyStatic__errors___error_logger;
    PyObject **CPyStatic__errors___error_logger_debug;
    PyObject **CPyStatic__errors___error_logger_log;
    PyObject **CPyStatic__errors___revert_logger;
    PyObject **CPyStatic__errors___revert_logger_log;
    PyObject **CPyStatic__errors___timeout_logger;
    PyObject **CPyStatic__errors___timeout_logger_debug;
    PyObject **CPyStatic__errors___timeout_logger_warning;
    PyObject **CPyStatic__errors___gas_logger;
    PyObject **CPyStatic__errors___gas_logger_debug;
    PyObject **CPyStatic__errors___INDIVIDUAL_CALL_REVERT_STRINGS;
    char (*CPyDef__errors___error_logger_log_debug)(PyObject *cpy_r_msg, PyObject *cpy_r_args);
    char (*CPyDef__errors___revert_logger_log_debug)(PyObject *cpy_r_msg, PyObject *cpy_r_args);
    char (*CPyDef__errors___log_internal_error)(PyObject *cpy_r_logger, PyObject *cpy_r_batch, PyObject *cpy_r_exc);
    char (*CPyDef__errors___needs_full_request_spec)(PyObject *cpy_r_response);
    char (*CPyDef__errors___is_call_revert)(PyObject *cpy_r_e);
    char (*CPyDef__errors___log_request_type_switch)(void);
    char (*CPyDef__errors_____top_level__)(void);
    PyObject **CPyStatic__gather___Task;
    PyObject **CPyStatic__gather___get_running_loop;
    PyObject **CPyStatic__gather___wait;
    PyObject **CPyStatic__gather___yield_to_loop;
    PyTypeObject **CPyType__gather___gatherish_env;
    PyObject *(*CPyDef__gather___gatherish_env)(void);
    PyTypeObject **CPyType__gather___gatherish_gen;
    PyObject *(*CPyDef__gather___gatherish_gen)(void);
    PyTypeObject **CPyType__gather___first_completed_env;
    PyObject *(*CPyDef__gather___first_completed_env)(void);
    PyTypeObject **CPyType__gather___first_completed_gen;
    PyObject *(*CPyDef__gather___first_completed_gen)(void);
    PyObject *(*CPyDef__gather___gatherish_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef__gather___gatherish_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__gather___gatherish_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef__gather___gatherish_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__gather___gatherish_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef__gather___gatherish_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__gather___gatherish_gen_____await__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__gather___gatherish)(PyObject *cpy_r_coros, PyObject *cpy_r_name);
    PyObject *(*CPyDef__gather___first_completed_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef__gather___first_completed_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__gather___first_completed_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef__gather___first_completed_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__gather___first_completed_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef__gather___first_completed_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__gather___first_completed_gen_____await__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__gather___first_completed)(PyObject *cpy_r_fs, char cpy_r_cancel);
    char (*CPyDef__gather_____top_level__)(void);
    PyTypeObject **CPyType_lru_cache___lru_cache_lite_env;
    PyObject *(*CPyDef_lru_cache___lru_cache_lite_env)(void);
    PyTypeObject **CPyType_lru_cache___lru_cache_lite_wrap_lru_cache_lite_obj;
    PyObject *(*CPyDef_lru_cache___lru_cache_lite_wrap_lru_cache_lite_obj)(void);
    PyTypeObject **CPyType_lru_cache___lru_cache_lite_nonull_env;
    PyObject *(*CPyDef_lru_cache___lru_cache_lite_nonull_env)(void);
    PyTypeObject **CPyType_lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_obj;
    PyObject *(*CPyDef_lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_obj)(void);
    PyObject *(*CPyDef_lru_cache___lru_cache_lite_wrap_lru_cache_lite_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef_lru_cache___lru_cache_lite_wrap_lru_cache_lite_obj_____call__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_args);
    PyObject *(*CPyDef_lru_cache___lru_cache_lite)(PyObject *cpy_r_func);
    PyObject *(*CPyDef_lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef_lru_cache___lru_cache_lite_wrap_lru_cache_lite_nonull_obj_____call__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_args);
    PyObject *(*CPyDef_lru_cache___lru_cache_lite_nonull)(PyObject *cpy_r_func);
    char (*CPyDef_lru_cache_____top_level__)(void);
    PyObject **CPyStatic__weaklist___ref;
    PyObject **CPyStatic__weaklist____call_ref;
    PyTypeObject **CPyType__weaklist___WeakList;
    PyObject *(*CPyDef__weaklist___WeakList)(PyObject *cpy_r_data);
    PyTypeObject **CPyType__weaklist_____iter___3_WeakList_env;
    PyObject *(*CPyDef__weaklist_____iter___3_WeakList_env)(void);
    PyTypeObject **CPyType__weaklist_____iter___3_WeakList_gen;
    PyObject *(*CPyDef__weaklist_____iter___3_WeakList_gen)(void);
    char (*CPyDef__weaklist___WeakList_____init__)(PyObject *cpy_r_self, PyObject *cpy_r_data);
    PyObject *(*CPyDef__weaklist___WeakList_____repr__)(PyObject *cpy_r_self);
    CPyTagged (*CPyDef__weaklist___WeakList_____len__)(PyObject *cpy_r_self);
    char (*CPyDef__weaklist___WeakList_____bool__)(PyObject *cpy_r_self);
    char (*CPyDef__weaklist___WeakList_____contains__)(PyObject *cpy_r_self, PyObject *cpy_r_item);
    PyObject *(*CPyDef__weaklist_____iter___3_WeakList_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef__weaklist_____iter___3_WeakList_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__weaklist_____iter___3_WeakList_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef__weaklist_____iter___3_WeakList_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__weaklist_____iter___3_WeakList_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef__weaklist_____iter___3_WeakList_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__weaklist___WeakList_____iter__)(PyObject *cpy_r_self);
    char (*CPyDef__weaklist___WeakList___append)(PyObject *cpy_r_self, PyObject *cpy_r_item);
    char (*CPyDef__weaklist___WeakList___extend)(PyObject *cpy_r_self, PyObject *cpy_r_items);
    char (*CPyDef__weaklist___WeakList___remove)(PyObject *cpy_r_self, PyObject *cpy_r_item);
    char (*CPyDef__weaklist___WeakList____gc_callback)(PyObject *cpy_r_self, PyObject *cpy_r_item);
    char (*CPyDef__weaklist_____top_level__)(void);
    PyObject **CPyStatic_constants___TOO_MUCH_DATA_ERRS;
    PyObject **CPyStatic_constants___RETRY_ERRS;
    PyObject **CPyStatic_constants___GAS_LIMIT;
    PyObject **CPyStatic_constants___MULTICALL2_OVERRIDE_CODE;
    PyObject **CPyStatic_constants___MULTICALL3_OVERRIDE_CODE;
    PyObject **CPyStatic_constants___MULTICALL2_DEPLOY_BLOCKS;
    PyObject **CPyStatic_constants___MULTICALL3_DEPLOY_BLOCKS;
    tuple_T10OOOOOOOOOO *CPyStatic_constants___BAD_HEXES;
    tuple_T2OO *CPyStatic_constants___REVERT_SELECTORS;
    char (*CPyDef_constants_____top_level__)(void);
    PyObject **CPyStatic_ENVIRONMENT_VARIABLES___logger;
    PyObject **CPyStatic_ENVIRONMENT_VARIABLES___OPERATION_MODE;
    PyObject **CPyStatic_ENVIRONMENT_VARIABLES___MAX_MULTICALL_SIZE;
    PyObject **CPyStatic_ENVIRONMENT_VARIABLES___MAX_JSONRPC_BATCH_SIZE;
    PyObject **CPyStatic_ENVIRONMENT_VARIABLES___REQUESTS_PER_SECOND;
    PyObject **CPyStatic_ENVIRONMENT_VARIABLES___MIN_REQUESTS_PER_SECOND;
    PyObject **CPyStatic_ENVIRONMENT_VARIABLES___demo_mode;
    PyObject **CPyStatic_ENVIRONMENT_VARIABLES___DEMO_MODE;
    PyObject **CPyStatic_ENVIRONMENT_VARIABLES___ganache_fork;
    PyObject **CPyStatic_ENVIRONMENT_VARIABLES___GANACHE_FORK;
    PyObject **CPyStatic_ENVIRONMENT_VARIABLES___AIOHTTP_TIMEOUT;
    PyObject **CPyStatic_ENVIRONMENT_VARIABLES___brownie_semaphore;
    PyObject **CPyStatic_ENVIRONMENT_VARIABLES___BROWNIE_CALL_SEMAPHORE;
    PyObject **CPyStatic_ENVIRONMENT_VARIABLES___BROWNIE_ENCODER_SEMAPHORE;
    PyObject **CPyStatic_ENVIRONMENT_VARIABLES___COLLECTION_FACTOR;
    PyObject **CPyStatic_ENVIRONMENT_VARIABLES___USE_FULL_REQUEST;
    PyObject **CPyStatic_ENVIRONMENT_VARIABLES___DEBUG;
    PyObject **CPyStatic_ENVIRONMENT_VARIABLES___EXPORT_STATS;
    PyObject **CPyStatic_ENVIRONMENT_VARIABLES___COLLECT_STATS;
    PyObject **CPyStatic_ENVIRONMENT_VARIABLES___STUCK_CALL_TIMEOUT;
    PyObject **CPyStatic_ENVIRONMENT_VARIABLES___method_semaphores;
    char (*CPyDef_ENVIRONMENT_VARIABLES_____top_level__)(void);
};
#endif
