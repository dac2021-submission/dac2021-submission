#include <flex.h>
bool flex::decode_GB_ATTENTION_CHILD_gb_attention_child_next_max() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_gb_attention_child_valid_flag == local_var_1);
sc_biguint<5> local_var_4 = 6;
bool local_var_5 = (flex_gb_attention_child_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
auto& univ_var_540 = local_var_6;
return univ_var_540;
}
void flex::update_GB_ATTENTION_CHILD_gb_attention_child_next_max() {
sc_biguint<5> local_var_0 = 7;
auto local_var_0_nxt_holder = local_var_0;
auto local_var_3 = GBAttentionMax(GB_ATTENTION_CHILD_gb_attention_max_value, GB_ATTENTION_CHILD_gb_attention_vector_0);
auto local_var_5 = GBAttentionMax(local_var_3, GB_ATTENTION_CHILD_gb_attention_vector_1);
auto local_var_7 = GBAttentionMax(local_var_5, GB_ATTENTION_CHILD_gb_attention_vector_2);
auto local_var_9 = GBAttentionMax(local_var_7, GB_ATTENTION_CHILD_gb_attention_vector_3);
auto local_var_9_nxt_holder = local_var_9;
flex_gb_attention_child_state = local_var_0_nxt_holder;
GB_ATTENTION_CHILD_gb_attention_max_value = local_var_9_nxt_holder;
}
