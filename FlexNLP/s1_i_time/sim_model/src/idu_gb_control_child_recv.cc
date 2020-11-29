#include <flex.h>
bool flex::decode_Child_GB_Control_gb_control_child_recv() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_gb_control_child_valid_flag == local_var_1);
sc_biguint<4> local_var_4 = 5;
bool local_var_5 = (flex_gb_control_child_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
sc_biguint<1> local_var_8 = 1;
bool local_var_9 = (flex_gb_control_data_in_valid == local_var_8);
bool local_var_10 = (local_var_6 & local_var_9);
sc_biguint<1> local_var_12 = 0;
bool local_var_13 = (flex_pe_done_signal_shared == local_var_12);
bool local_var_14 = (local_var_10 & local_var_13);
auto& univ_var_665 = local_var_14;
return univ_var_665;
}
void flex::update_Child_GB_Control_gb_control_child_recv() {
sc_biguint<1> local_var_0 = 0;
auto local_var_0_nxt_holder = local_var_0;
std::map<sc_biguint<32>, sc_biguint<8>> local_var_1;
ite_666(local_var_1);
std::map<sc_biguint<32>, sc_biguint<8>> local_var_2;
ite_684(local_var_2);
flex_gb_control_data_in_valid = local_var_0_nxt_holder;
for (auto& it : local_var_1) {
  flex_gb_core_large_buffer[it.first] = it.second;
}
for (auto& it : local_var_2) {
  flex_gb_core_small_buffer[it.first] = it.second;
}
}
