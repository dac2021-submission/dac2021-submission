#include <flex.h>
bool flex::decode_GB_ATTENTION_CHILD_gb_attention_child_out2() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_gb_attention_child_valid_flag == local_var_1);
sc_biguint<5> local_var_4 = 17;
bool local_var_5 = (flex_gb_attention_child_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
auto& univ_var_626 = local_var_6;
return univ_var_626;
}
void flex::update_GB_ATTENTION_CHILD_gb_attention_child_out2() {
sc_biguint<8> local_var_2 = 1;
sc_biguint<8> local_var_3 = (flex_gb_attention_num_vector_1 - local_var_2);
bool local_var_4 = (GB_ATTENTION_CHILD_gb_attention_vector_cntr == local_var_3);
bool local_var_5 = (GB_ATTENTION_CHILD_gb_attention_vector_cntr > local_var_3);
bool local_var_6 = (local_var_4 | local_var_5);
sc_biguint<1> local_var_7 = 0;
auto local_var_9 = (local_var_6) ? local_var_7 : GB_ATTENTION_CHILD_gb_attention_bmm_cntr;
auto local_var_9_nxt_holder = local_var_9;
sc_biguint<5> local_var_10 = 18;
sc_biguint<5> local_var_11 = 1;
auto local_var_12 = (local_var_6) ? local_var_10 : local_var_11;
auto local_var_12_nxt_holder = local_var_12;
sc_biguint<8> local_var_13 = 0;
sc_biguint<8> local_var_14 = 1;
sc_biguint<8> local_var_15 = (GB_ATTENTION_CHILD_gb_attention_vector_cntr + local_var_14);
auto local_var_16 = (local_var_6) ? local_var_13 : local_var_15;
auto local_var_16_nxt_holder = local_var_16;
std::map<sc_biguint<32>, sc_biguint<8>> local_var_17;
store_627(local_var_17);
GB_ATTENTION_CHILD_gb_attention_bmm_cntr = local_var_9_nxt_holder;
flex_gb_attention_child_state = local_var_12_nxt_holder;
GB_ATTENTION_CHILD_gb_attention_vector_cntr = local_var_16_nxt_holder;
for (auto& it : local_var_17) {
  flex_gb_core_small_buffer[it.first] = it.second;
}
}
