#include <flex.h>
bool flex::decode_GB_ATTENTION_CHILD_gb_attention_sfm3() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_gb_attention_child_valid_flag == local_var_1);
sc_biguint<5> local_var_4 = 15;
bool local_var_5 = (flex_gb_attention_child_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
auto& univ_var_610 = local_var_6;
return univ_var_610;
}
void flex::update_GB_ATTENTION_CHILD_gb_attention_sfm3() {
sc_biguint<16> local_var_2 = 16;
sc_biguint<16> local_var_3 = (flex_gb_attention_num_timestep_1 - local_var_2);
bool local_var_4 = (GB_ATTENTION_CHILD_gb_attention_timestep_cntr == local_var_3);
bool local_var_5 = (GB_ATTENTION_CHILD_gb_attention_timestep_cntr > local_var_3);
bool local_var_6 = (local_var_4 | local_var_5);
sc_biguint<1> local_var_7 = 1;
auto local_var_9 = (local_var_6) ? local_var_7 : GB_ATTENTION_CHILD_gb_attention_bmm_cntr;
auto local_var_9_nxt_holder = local_var_9;
sc_biguint<5> local_var_10 = 1;
sc_biguint<5> local_var_11 = 10;
auto local_var_12 = (local_var_6) ? local_var_10 : local_var_11;
auto local_var_12_nxt_holder = local_var_12;
sc_biguint<16> local_var_13 = 0;
sc_biguint<16> local_var_14 = 16;
sc_biguint<16> local_var_15 = (GB_ATTENTION_CHILD_gb_attention_timestep_cntr + local_var_14);
auto local_var_16 = (local_var_6) ? local_var_13 : local_var_15;
auto local_var_16_nxt_holder = local_var_16;
std::map<sc_biguint<32>, sc_biguint<8>> local_var_17;
store_611(local_var_17);
GB_ATTENTION_CHILD_gb_attention_bmm_cntr = local_var_9_nxt_holder;
flex_gb_attention_child_state = local_var_12_nxt_holder;
GB_ATTENTION_CHILD_gb_attention_timestep_cntr = local_var_16_nxt_holder;
for (auto& it : local_var_17) {
  flex_gb_core_small_buffer[it.first] = it.second;
}
}
