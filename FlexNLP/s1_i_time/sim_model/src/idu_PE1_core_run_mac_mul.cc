#include <flex.h>
bool flex::decode_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_mul() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (PE1_CORE_CHILD_pe1_core_child_run_mac_flag == local_var_1);
sc_biguint<5> local_var_4 = 16;
bool local_var_5 = (PE1_CORE_CHILD_pe1_core_child_run_mac_cntr < local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
sc_biguint<4> local_var_8 = 2;
bool local_var_9 = (PE1_CORE_CHILD_pe1_core_run_mac_child_state == local_var_8);
bool local_var_10 = (local_var_6 & local_var_9);
auto& univ_var_44 = local_var_10;
return univ_var_44;
}
void flex::update_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_mul() {
sc_biguint<32> local_var_0 = 0;
auto local_var_3 = ProductSum(PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_weight_byte_0, PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_input_byte_0);
auto local_var_4 = AccumAdd(local_var_0, local_var_3);
auto local_var_7 = ProductSum(PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_weight_byte_1, PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_input_byte_1);
auto local_var_8 = AccumAdd(local_var_4, local_var_7);
auto local_var_11 = ProductSum(PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_weight_byte_2, PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_input_byte_2);
auto local_var_12 = AccumAdd(local_var_8, local_var_11);
auto local_var_15 = ProductSum(PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_weight_byte_3, PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_input_byte_3);
auto local_var_16 = AccumAdd(local_var_12, local_var_15);
auto local_var_19 = ProductSum(PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_weight_byte_4, PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_input_byte_4);
auto local_var_20 = AccumAdd(local_var_16, local_var_19);
auto local_var_23 = ProductSum(PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_weight_byte_5, PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_input_byte_5);
auto local_var_24 = AccumAdd(local_var_20, local_var_23);
auto local_var_27 = ProductSum(PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_weight_byte_6, PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_input_byte_6);
auto local_var_28 = AccumAdd(local_var_24, local_var_27);
auto local_var_31 = ProductSum(PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_weight_byte_7, PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_input_byte_7);
auto local_var_32 = AccumAdd(local_var_28, local_var_31);
auto local_var_35 = ProductSum(PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_weight_byte_8, PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_input_byte_8);
auto local_var_36 = AccumAdd(local_var_32, local_var_35);
auto local_var_39 = ProductSum(PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_weight_byte_9, PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_input_byte_9);
auto local_var_40 = AccumAdd(local_var_36, local_var_39);
auto local_var_43 = ProductSum(PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_weight_byte_10, PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_input_byte_10);
auto local_var_44 = AccumAdd(local_var_40, local_var_43);
auto local_var_47 = ProductSum(PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_weight_byte_11, PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_input_byte_11);
auto local_var_48 = AccumAdd(local_var_44, local_var_47);
auto local_var_51 = ProductSum(PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_weight_byte_12, PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_input_byte_12);
auto local_var_52 = AccumAdd(local_var_48, local_var_51);
auto local_var_55 = ProductSum(PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_weight_byte_13, PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_input_byte_13);
auto local_var_56 = AccumAdd(local_var_52, local_var_55);
auto local_var_59 = ProductSum(PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_weight_byte_14, PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_input_byte_14);
auto local_var_60 = AccumAdd(local_var_56, local_var_59);
auto local_var_63 = ProductSum(PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_weight_byte_15, PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_child_input_byte_15);
auto local_var_64 = AccumAdd(local_var_60, local_var_63);
auto local_var_64_nxt_holder = local_var_64;
sc_biguint<4> local_var_65 = 3;
auto local_var_65_nxt_holder = local_var_65;
PE1_CORE_RUN_MAC_CHILD_pe1_core_run_mac_child_result_temp = local_var_64_nxt_holder;
PE1_CORE_CHILD_pe1_core_run_mac_child_state = local_var_65_nxt_holder;
}
