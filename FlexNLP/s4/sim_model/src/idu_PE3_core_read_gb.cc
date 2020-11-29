#include <flex.h>
bool flex::decode_PE3_CORE_CHILD_PE3_core_read_gb() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_pe3_rnn_layer_sizing_is_valid == local_var_1);
sc_biguint<1> local_var_4 = 0;
bool local_var_5 = (PE3_CORE_CHILD_pe3_core_is_start == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
sc_biguint<1> local_var_8 = 1;
bool local_var_9 = (flex_gb_control_data_out_valid == local_var_8);
bool local_var_10 = (local_var_6 & local_var_9);
sc_biguint<3> local_var_12 = 3;
bool local_var_13 = (flex_pe_core_cntr == local_var_12);
bool local_var_14 = (local_var_10 & local_var_13);
sc_biguint<3> local_var_16 = 0;
bool local_var_17 = (flex_pe3_core_state == local_var_16);
bool local_var_18 = (local_var_14 & local_var_17);
auto& univ_var_137 = local_var_18;
return univ_var_137;
}
void flex::update_PE3_CORE_CHILD_PE3_core_read_gb() {
bool local_var_0 = true;
sc_biguint<1> local_var_1 = 0;
sc_biguint<1> local_var_2 = 1;
auto local_var_3 = (local_var_0) ? local_var_1 : local_var_2;
auto local_var_3_nxt_holder = local_var_3;
std::map<sc_biguint<32>, sc_biguint<8>> local_var_4;
store_138(local_var_4);
sc_biguint<3> local_var_5 = 0;
sc_biguint<3> local_var_6 = 4;
auto local_var_7 = (local_var_0) ? local_var_5 : local_var_6;
auto local_var_7_nxt_holder = local_var_7;
flex_gb_control_data_out_valid = local_var_3_nxt_holder;
for (auto& it : local_var_4) {
  flex_pe3_core_input_buffer[it.first] = it.second;
}
flex_pe_core_cntr = local_var_7_nxt_holder;
}
