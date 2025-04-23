#ifndef MYPYC_NATIVE_dank_mids___brownie_patch___call_H
#define MYPYC_NATIVE_dank_mids___brownie_patch___call_H
#include <Python.h>
#include <CPy.h>
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
    PyObject *_components;
    PyObject *_item_type;
    PyObject *_type_str;
    PyObject *_abi_type;
    PyObject *_values;
} dank_mids___brownie_patch___call____format_array_but_cache_checksums_envObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} dank_mids___brownie_patch___call_____mypyc_lambda__2__format_array_but_cache_checksums_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} dank_mids___brownie_patch___call_____mypyc_lambda__3__format_array_but_cache_checksums_objObject;

typedef struct {
    PyObject_HEAD
    CPyVTableItem *vtable;
    vectorcallfunc vectorcall;
    PyObject *___mypyc_env__;
} dank_mids___brownie_patch___call_____mypyc_lambda__4__format_array_but_cache_checksums_objObject;


struct export_table_dank_mids___brownie_patch___call {
    PyObject **CPyStatic_encode;
    PyTypeObject **CPyType___mypyc_lambda__0_obj;
    PyObject *(*CPyDef___mypyc_lambda__0_obj)(void);
    PyTypeObject **CPyType___mypyc_lambda__1_obj;
    PyObject *(*CPyDef___mypyc_lambda__1_obj)(void);
    PyTypeObject **CPyType__get_coroutine_fn_env;
    PyObject *(*CPyDef__get_coroutine_fn_env)(void);
    PyTypeObject **CPyType_coroutine__get_coroutine_fn_env;
    PyObject *(*CPyDef_coroutine__get_coroutine_fn_env)(void);
    PyTypeObject **CPyType_coroutine__get_coroutine_fn_obj;
    PyObject *(*CPyDef_coroutine__get_coroutine_fn_obj)(void);
    PyTypeObject **CPyType_coroutine__get_coroutine_fn_gen;
    PyObject *(*CPyDef_coroutine__get_coroutine_fn_gen)(void);
    PyTypeObject **CPyType_encode_input_env;
    PyObject *(*CPyDef_encode_input_env)(void);
    PyTypeObject **CPyType_encode_input_gen;
    PyObject *(*CPyDef_encode_input_gen)(void);
    PyTypeObject **CPyType_decode_output_env;
    PyObject *(*CPyDef_decode_output_env)(void);
    PyTypeObject **CPyType_decode_output_gen;
    PyObject *(*CPyDef_decode_output_gen)(void);
    PyTypeObject **CPyType__request_data_no_args_env;
    PyObject *(*CPyDef__request_data_no_args_env)(void);
    PyTypeObject **CPyType__request_data_no_args_gen;
    PyObject *(*CPyDef__request_data_no_args_gen)(void);
    PyTypeObject **CPyType__format_array_but_cache_checksums_env;
    PyObject *(*CPyDef__format_array_but_cache_checksums_env)(void);
    PyTypeObject **CPyType___mypyc_lambda__2__format_array_but_cache_checksums_obj;
    PyObject *(*CPyDef___mypyc_lambda__2__format_array_but_cache_checksums_obj)(void);
    PyTypeObject **CPyType___mypyc_lambda__3__format_array_but_cache_checksums_obj;
    PyObject *(*CPyDef___mypyc_lambda__3__format_array_but_cache_checksums_obj)(void);
    PyTypeObject **CPyType___mypyc_lambda__4__format_array_but_cache_checksums_obj;
    PyObject *(*CPyDef___mypyc_lambda__4__format_array_but_cache_checksums_obj)(void);
    PyObject *(*CPyDef___mypyc_lambda__0_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef___mypyc_lambda__0_obj_____call__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_self, PyObject *cpy_r_args);
    PyObject *(*CPyDef___mypyc_lambda__1_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef___mypyc_lambda__1_obj_____call__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_self, PyObject *cpy_r_data);
    char (*CPyDef__patch_call)(PyObject *cpy_r_call, PyObject *cpy_r_w3);
    PyObject *(*CPyDef_coroutine__get_coroutine_fn_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef_coroutine__get_coroutine_fn_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_coroutine__get_coroutine_fn_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_coroutine__get_coroutine_fn_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_coroutine__get_coroutine_fn_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_coroutine__get_coroutine_fn_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef_coroutine__get_coroutine_fn_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_coroutine__get_coroutine_fn_gen_____await__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_coroutine__get_coroutine_fn_obj_____call__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_self, PyObject *cpy_r_args, PyObject *cpy_r_block_identifier, PyObject *cpy_r_decimals, PyObject *cpy_r_override);
    PyObject *(*CPyDef__get_coroutine_fn)(PyObject *cpy_r_w3, CPyTagged cpy_r_len_inputs);
    PyObject *(*CPyDef__call_no_args)(PyObject *cpy_r_self);
    PyObject *(*CPyDef_encode_input_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_encode_input_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_encode_input_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_encode_input_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_encode_input_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef_encode_input_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_encode_input_gen_____await__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_encode_input)(PyObject *cpy_r_call, CPyTagged cpy_r_len_inputs, PyObject *cpy_r_get_request_data, PyObject *cpy_r_args);
    PyObject *(*CPyDef_decode_output_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_decode_output_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_decode_output_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef_decode_output_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_decode_output_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef_decode_output_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_decode_output_gen_____await__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef_decode_output)(PyObject *cpy_r_call, PyObject *cpy_r_data);
    PyObject *(*CPyDef__request_data_no_args_gen_____mypyc_generator_helper__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback, PyObject *cpy_r_arg);
    PyObject *(*CPyDef__request_data_no_args_gen_____next__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__request_data_no_args_gen___send)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_arg);
    PyObject *(*CPyDef__request_data_no_args_gen_____iter__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__request_data_no_args_gen___throw)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_type, PyObject *cpy_r_value, PyObject *cpy_r_traceback);
    PyObject *(*CPyDef__request_data_no_args_gen___close)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__request_data_no_args_gen_____await__)(PyObject *cpy_r___mypyc_self__);
    PyObject *(*CPyDef__request_data_no_args)(PyObject *cpy_r_call);
    PyObject *(*CPyDef___encode_input)(PyObject *cpy_r_abi, PyObject *cpy_r_signature, PyObject *cpy_r_args);
    PyObject *(*CPyDef___decode_output)(PyObject *cpy_r_hexstr, PyObject *cpy_r_abi);
    char (*CPyDef___validate_output)(PyObject *cpy_r_abi, PyObject *cpy_r_hexstr);
    PyObject *(*CPyDef_format_input_but_cache_checksums)(PyObject *cpy_r_abi, PyObject *cpy_r_inputs);
    PyObject *(*CPyDef_format_output_but_cache_checksums)(PyObject *cpy_r_abi, PyObject *cpy_r_outputs);
    PyObject *(*CPyDef__format_tuple_but_cache_checksums)(PyObject *cpy_r_abi_types, PyObject *cpy_r_values);
    PyObject *(*CPyDef___mypyc_lambda__2__format_array_but_cache_checksums_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef___mypyc_lambda__2__format_array_but_cache_checksums_obj_____call__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_v);
    PyObject *(*CPyDef___mypyc_lambda__3__format_array_but_cache_checksums_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef___mypyc_lambda__3__format_array_but_cache_checksums_obj_____call__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_v);
    PyObject *(*CPyDef___mypyc_lambda__4__format_array_but_cache_checksums_obj_____get__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
    PyObject *(*CPyDef___mypyc_lambda__4__format_array_but_cache_checksums_obj_____call__)(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_v);
    PyObject *(*CPyDef__format_array_but_cache_checksums)(PyObject *cpy_r_abi_type, PyObject *cpy_r_values);
    PyObject *(*CPyDef__format_single_but_cache_checksums)(PyObject *cpy_r_type_str, PyObject *cpy_r_value);
    char (*CPyDef___top_level__)(void);
};
#endif
