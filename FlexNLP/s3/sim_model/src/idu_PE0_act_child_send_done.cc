#include <flex.h>
bool flex::decode_PE0_ACT_CHILD_PE0_act_child_send_done() {
sc_biguint<3> local_var_1 = 3;
bool local_var_2 = (PE0_ACT_CHILD_pe0_act_state == local_var_1);
sc_biguint<3> local_var_4 = 0;
bool local_var_5 = (flex_pe_act_done_cntr == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
sc_biguint<1> local_var_8 = 0;
bool local_var_9 = (PE0_ACT_CHILD_pe0_act_is_start_reg == local_var_8);
bool local_var_10 = (local_var_6 & local_var_9);
auto& univ_var_159 = local_var_10;
return univ_var_159;
}
void flex::update_PE0_ACT_CHILD_PE0_act_child_send_done() {
sc_biguint<3> local_var_0 = 4;
auto local_var_0_nxt_holder = local_var_0;
sc_biguint<3> local_var_2 = 3;
bool local_var_3 = (flex_pe_act_done_cntr == local_var_2);
bool local_var_4 = (flex_pe_act_done_cntr > local_var_2);
bool local_var_5 = (local_var_3 | local_var_4);
sc_biguint<3> local_var_6 = 0;
sc_biguint<3> local_var_7 = 1;
sc_biguint<3> local_var_8 = (flex_pe_act_done_cntr + local_var_7);
auto local_var_9 = (local_var_5) ? local_var_6 : local_var_8;
auto local_var_9_nxt_holder = local_var_9;
sc_biguint<1> local_var_10 = 1;
sc_biguint<1> local_var_11 = 0;
auto local_var_12 = (local_var_5) ? local_var_10 : local_var_11;
auto local_var_12_nxt_holder = local_var_12;
PE0_ACT_CHILD_pe0_act_state = local_var_0_nxt_holder;
flex_pe_act_done_cntr = local_var_9_nxt_holder;
flex_pe_done_signal_shared = local_var_12_nxt_holder;
}
