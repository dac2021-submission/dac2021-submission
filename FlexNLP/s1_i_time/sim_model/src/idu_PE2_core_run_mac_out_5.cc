#include <flex.h>
bool flex::decode_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_5() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (PE2_CORE_CHILD_pe2_core_child_run_mac_flag == local_var_1);
sc_biguint<5> local_var_4 = 16;
bool local_var_5 = (PE2_CORE_CHILD_pe2_core_child_run_mac_cntr < local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
sc_biguint<4> local_var_8 = 3;
bool local_var_9 = (PE2_CORE_CHILD_pe2_core_run_mac_child_state == local_var_8);
bool local_var_10 = (local_var_6 & local_var_9);
sc_biguint<5> local_var_11 = 5;
bool local_var_12 = (PE2_CORE_CHILD_pe2_core_child_run_mac_cntr == local_var_11);
bool local_var_13 = (local_var_10 & local_var_12);
auto& univ_var_88 = local_var_13;
return univ_var_88;
}
void flex::update_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_5() {
auto local_var_2 = AccumAdd2(PE2_CORE_CHILD_PE2_core_accum_vector_5, PE2_CORE_RUN_MAC_CHILD_pe2_core_run_mac_child_result_temp);
auto local_var_2_nxt_holder = local_var_2;
sc_biguint<5> local_var_4 = 1;
sc_biguint<5> local_var_5 = (PE2_CORE_CHILD_pe2_core_child_run_mac_cntr + local_var_4);
auto local_var_5_nxt_holder = local_var_5;
sc_biguint<5> local_var_6 = 15;
bool local_var_7 = (PE2_CORE_CHILD_pe2_core_child_run_mac_cntr == local_var_6);
bool local_var_8 = (PE2_CORE_CHILD_pe2_core_child_run_mac_cntr > local_var_6);
bool local_var_9 = (local_var_7 | local_var_8);
sc_biguint<1> local_var_10 = 0;
sc_biguint<1> local_var_11 = 1;
auto local_var_12 = (local_var_9) ? local_var_10 : local_var_11;
auto local_var_12_nxt_holder = local_var_12;
sc_biguint<1> local_var_14 = 1;
bool local_var_15 = (flex_pe2_rnn_layer_sizing_is_cluster == local_var_14);
sc_biguint<4> local_var_16 = 1;
sc_biguint<4> local_var_17 = 0;
auto local_var_18 = (local_var_15) ? local_var_16 : local_var_17;
auto local_var_18_nxt_holder = local_var_18;
PE2_CORE_CHILD_PE2_core_accum_vector_5 = local_var_2_nxt_holder;
PE2_CORE_CHILD_pe2_core_child_run_mac_cntr = local_var_5_nxt_holder;
PE2_CORE_CHILD_pe2_core_child_run_mac_flag = local_var_12_nxt_holder;
PE2_CORE_CHILD_pe2_core_run_mac_child_state = local_var_18_nxt_holder;
}
