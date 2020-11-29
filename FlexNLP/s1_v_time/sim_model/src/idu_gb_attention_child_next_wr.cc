#include <flex.h>
bool flex::decode_GB_ATTENTION_CHILD_gb_attention_child_next_wr() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_gb_attention_child_valid_flag == local_var_1);
sc_biguint<5> local_var_4 = 7;
bool local_var_5 = (flex_gb_attention_child_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
auto& univ_var_541 = local_var_6;
return univ_var_541;
}
void flex::update_GB_ATTENTION_CHILD_gb_attention_child_next_wr() {
sc_biguint<2> local_var_1 = 3;
bool local_var_2 = (GB_ATTENTION_CHILD_gb_attention_softmax_cntr == local_var_1);
bool local_var_3 = (GB_ATTENTION_CHILD_gb_attention_softmax_cntr > local_var_1);
bool local_var_4 = (local_var_2 | local_var_3);
sc_biguint<16> local_var_7 = 16;
sc_biguint<16> local_var_8 = (flex_gb_attention_num_timestep_1 - local_var_7);
bool local_var_9 = (GB_ATTENTION_CHILD_gb_attention_timestep_cntr == local_var_8);
bool local_var_10 = (GB_ATTENTION_CHILD_gb_attention_timestep_cntr > local_var_8);
bool local_var_11 = (local_var_9 | local_var_10);
bool local_var_12 = (local_var_4 & local_var_11);
sc_biguint<1> local_var_13 = 1;
auto local_var_15 = (local_var_12) ? local_var_13 : GB_ATTENTION_CHILD_gb_attention_bmm_cntr;
auto local_var_15_nxt_holder = local_var_15;
bool local_var_16 = (local_var_4 & local_var_11);
sc_biguint<5> local_var_17 = 8;
bool local_var_18 = !local_var_11;
bool local_var_19 = (local_var_4 & local_var_18);
sc_biguint<5> local_var_20 = 1;
sc_biguint<5> local_var_21 = 5;
auto local_var_22 = (local_var_19) ? local_var_20 : local_var_21;
auto local_var_23 = (local_var_16) ? local_var_17 : local_var_22;
auto local_var_23_nxt_holder = local_var_23;
sc_biguint<2> local_var_24 = 0;
sc_biguint<2> local_var_25 = 1;
sc_biguint<2> local_var_26 = (GB_ATTENTION_CHILD_gb_attention_softmax_cntr + local_var_25);
auto local_var_27 = (local_var_4) ? local_var_24 : local_var_26;
auto local_var_27_nxt_holder = local_var_27;
sc_biguint<16> local_var_28 = 0;
sc_biguint<16> local_var_29 = 16;
sc_biguint<16> local_var_30 = (GB_ATTENTION_CHILD_gb_attention_timestep_cntr + local_var_29);
auto local_var_31 = (local_var_11) ? local_var_28 : local_var_30;
auto local_var_32 = (local_var_4) ? local_var_31 : GB_ATTENTION_CHILD_gb_attention_timestep_cntr;
auto local_var_32_nxt_holder = local_var_32;
std::map<sc_biguint<32>, sc_biguint<8>> local_var_33;
store_542(local_var_33);
GB_ATTENTION_CHILD_gb_attention_bmm_cntr = local_var_15_nxt_holder;
flex_gb_attention_child_state = local_var_23_nxt_holder;
GB_ATTENTION_CHILD_gb_attention_softmax_cntr = local_var_27_nxt_holder;
GB_ATTENTION_CHILD_gb_attention_timestep_cntr = local_var_32_nxt_holder;
for (auto& it : local_var_33) {
  flex_gb_core_small_buffer[it.first] = it.second;
}
}
