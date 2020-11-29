#include <flex.h>
bool flex::decode_Child_GB_Control_gb_control_child_recv_next() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_gb_control_child_valid_flag == local_var_1);
sc_biguint<4> local_var_4 = 5;
bool local_var_5 = (flex_gb_control_child_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
sc_biguint<1> local_var_8 = 1;
bool local_var_9 = (flex_pe_done_signal_shared == local_var_8);
bool local_var_10 = (local_var_6 & local_var_9);
auto& univ_var_709 = local_var_10;
return univ_var_709;
}
void flex::update_Child_GB_Control_gb_control_child_recv_next() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_pe_done_signal_shared == local_var_1);
sc_biguint<1> local_var_4 = 1;
bool local_var_5 = (flex_gb_control_is_rnn == local_var_4);
sc_biguint<4> local_var_6 = 6;
sc_biguint<4> local_var_7 = 8;
auto local_var_8 = (local_var_5) ? local_var_6 : local_var_7;
sc_biguint<4> local_var_9 = 5;
auto local_var_10 = (local_var_2) ? local_var_8 : local_var_9;
auto local_var_10_nxt_holder = local_var_10;
sc_biguint<1> local_var_11 = 0;
auto local_var_11_nxt_holder = local_var_11;
flex_gb_control_child_state = local_var_10_nxt_holder;
flex_pe_done_signal_shared = local_var_11_nxt_holder;
}
