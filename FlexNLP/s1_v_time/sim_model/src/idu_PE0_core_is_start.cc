#include <flex.h>
bool flex::decode_PE0_CORE_CHILD_PE0_core_is_start() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_pe0_rnn_layer_sizing_is_valid == local_var_1);
sc_biguint<1> local_var_4 = 1;
bool local_var_5 = (flex_pe_core_start_signal == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
sc_biguint<3> local_var_8 = 0;
bool local_var_9 = (flex_pe0_core_state == local_var_8);
bool local_var_10 = (local_var_6 & local_var_9);
sc_biguint<3> local_var_12 = 0;
bool local_var_13 = (flex_pe_core_cntr == local_var_12);
bool local_var_14 = (local_var_10 & local_var_13);
auto& univ_var_27 = local_var_14;
return univ_var_27;
}
void flex::update_PE0_CORE_CHILD_PE0_core_is_start() {
sc_biguint<1> local_var_0 = 0;
auto local_var_0_nxt_holder = local_var_0;
sc_biguint<1> local_var_1 = 1;
auto local_var_1_nxt_holder = local_var_1;
sc_biguint<3> local_var_2 = 1;
auto local_var_2_nxt_holder = local_var_2;
bool local_var_3 = false;
sc_biguint<3> local_var_4 = 0;
sc_biguint<3> local_var_5 = 1;
auto local_var_6 = (local_var_3) ? local_var_4 : local_var_5;
auto local_var_6_nxt_holder = local_var_6;
sc_biguint<1> local_var_7 = 0;
auto local_var_9 = (local_var_3) ? local_var_7 : flex_pe_core_start_signal;
auto local_var_9_nxt_holder = local_var_9;
flex_pe0_act_reg_port_valid = local_var_0_nxt_holder;
PE0_CORE_CHILD_pe0_core_is_start = local_var_1_nxt_holder;
flex_pe0_core_state = local_var_2_nxt_holder;
flex_pe_core_cntr = local_var_6_nxt_holder;
flex_pe_core_start_signal = local_var_9_nxt_holder;
}
