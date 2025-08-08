#ifndef MYPYC_NATIVE_6486cd47b6f59329387b_H
#define MYPYC_NATIVE_6486cd47b6f59329387b_H
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

#ifndef MYPYC_DECLARED_tuple_T2OI
#define MYPYC_DECLARED_tuple_T2OI
typedef struct tuple_T2OI {
    PyObject *f0;
    CPyTagged f1;
} tuple_T2OI;
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

#ifndef MYPYC_DECLARED_tuple_T1O
#define MYPYC_DECLARED_tuple_T1O
typedef struct tuple_T1O {
    PyObject *f0;
} tuple_T1O;
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
    PyObject *_self;
    int32_t ___mypyc_next_label__;
    PyObject *_batches;
    PyObject *_last_failure;
    PyObject *___mypyc_temp__0;
    int64_t ___mypyc_temp__1;
    PyObject *___mypyc_temp__2;
    int64_t ___mypyc_temp__3;
    PyObject *_coro;
    PyObject *___mypyc_temp__4;
    int64_t ___mypyc_temp__5;
    PyObject *_batch;
    PyObject *_task;
    PyObject *___mypyc_temp__6;
    tuple_T3OOO ___mypyc_temp__7;
    tuple_T3OOO ___mypyc_temp__8;
    PyObject *_e;
    PyObject *___mypyc_temp__9;
    tuple_T3OOO ___mypyc_temp__10;
} dank_mids____batch____await_DankBatch_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_self;
    int32_t ___mypyc_next_label__;
    PyObject *_working_batch;
    PyObject *_batch_append;
    PyObject *_check_len;
    PyObject *___mypyc_temp__11;
    CPyTagged ___mypyc_temp__12;
    int64_t ___mypyc_temp__13;
    PyObject *___mypyc_temp__14;
    PyObject *_mcall;
    PyObject *_call;
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
    PyObject *_normalizers;
    PyObject *_abis;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_temp__0;
    CPyTagged ___mypyc_temp__1;
    int64_t ___mypyc_temp__2;
    PyObject *___mypyc_temp__3;
    PyObject *_method;
    PyObject *_abi_types;
    PyObject *_single_dict_formatter;
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
    PyObject *_self;
    PyObject *_args;
    PyObject *_block_identifier;
    PyObject *_decimals;
    PyObject *_override;
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
} dank_mids___brownie_patch___call___coroutine_gen___3_147Object;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_call;
    CPyTagged _len_inputs;
    PyObject *_get_request_data;
    PyObject *_args;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_temp__27;
    int64_t ___mypyc_temp__28;
    PyObject *_arg;
    PyObject *_data;
    PyObject *___mypyc_temp__29;
    tuple_T3OOO ___mypyc_temp__30;
    tuple_T3OOO ___mypyc_temp__31;
    PyObject *_exc_str;
} dank_mids___brownie_patch___call___encode_input_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_call;
    PyObject *_data;
    int32_t ___mypyc_next_label__;
    PyObject *_decoded;
    PyObject *___mypyc_temp__32;
    tuple_T3OOO ___mypyc_temp__33;
    tuple_T3OOO ___mypyc_temp__34;
    tuple_T3OOO ___mypyc_temp__35;
    PyObject *_e;
    PyObject *___mypyc_temp__36;
    tuple_T3OOO ___mypyc_temp__37;
} dank_mids___brownie_patch___call___decode_output_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_call;
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
    PyObject *_self;
    PyObject *_args;
    PyObject *_block_identifier;
    PyObject *_decimals;
    PyObject *_override;
    PyObject *_type;
    PyObject *_value;
    PyObject *_traceback;
    PyObject *_arg;
    PyObject **_stop_iter_ptr;
    int32_t ___mypyc_next_label__;
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
    int64_t ___mypyc_temp__6;
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
    PyObject *_self;
    PyObject *_args;
    PyObject *_block_identifier;
    PyObject *_decimals;
    PyObject *_override;
    int32_t ___mypyc_next_label__;
    PyObject *_call;
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
    vectorcallfunc vectorcall;
} dank_mids___helpers____codec_____mypyc_lambda__0_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_coros;
    PyObject *_name;
    int32_t ___mypyc_next_label__;
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
} dank_mids___helpers____gather___gatherish_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_fs;
    char _cancel;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_temp__17;
    tuple_T3OOO ___mypyc_temp__18;
    PyObject *___mypyc_temp__19;
    tuple_T3OOO ___mypyc_temp__20;
    PyObject *_done;
    PyObject *_pending;
    PyObject *___mypyc_temp__21;
    PyObject *___mypyc_temp__22;
    PyObject *_p;
} dank_mids___helpers____gather___first_completed_genObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *__refs;
} dank_mids___helpers____weaklist___WeakListObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    PyObject *_self;
    int32_t ___mypyc_next_label__;
    PyObject *___mypyc_temp__0;
    CPyTagged ___mypyc_temp__1;
    int64_t ___mypyc_temp__2;
    PyObject *___mypyc_temp__3;
    PyObject *_reference;
    PyObject *_obj;
} dank_mids___helpers____weaklist_____iter___3_WeakList_genObject;

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
    PyObject *_self;
    int32_t ___mypyc_next_label__;
    double _start;
    double _time_since_notified;
    PyObject *___mypyc_temp__0;
    tuple_T3OOO ___mypyc_temp__1;
    double _now;
    double _duration;
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

#endif
