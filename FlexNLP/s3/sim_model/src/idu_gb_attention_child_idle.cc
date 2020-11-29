#include <flex.h>
bool flex::decode_GB_ATTENTION_CHILD_gb_attention_child_idle() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_gb_attention_child_valid_flag == local_var_1);
sc_biguint<5> local_var_4 = 0;
bool local_var_5 = (flex_gb_attention_child_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
auto& univ_var_512 = local_var_6;
return univ_var_512;
}
void flex::update_GB_ATTENTION_CHILD_gb_attention_child_idle() {
sc_biguint<1> local_var_0 = 0;
auto local_var_0_nxt_holder = local_var_0;
sc_biguint<5> local_var_1 = 1;
auto local_var_1_nxt_holder = local_var_1;
sc_biguint<32> local_var_2 = 3221225472;
auto local_var_2_nxt_holder = local_var_2;
sc_biguint<2> local_var_3 = 0;
auto local_var_3_nxt_holder = local_var_3;
sc_biguint<32> local_var_4 = 0;
auto local_var_4_nxt_holder = local_var_4;
sc_biguint<16> local_var_5 = 0;
auto local_var_5_nxt_holder = local_var_5;
sc_biguint<8> local_var_6 = 0;
auto local_var_6_nxt_holder = local_var_6;
GB_ATTENTION_CHILD_gb_attention_bmm_cntr = local_var_0_nxt_holder;
flex_gb_attention_child_state = local_var_1_nxt_holder;
GB_ATTENTION_CHILD_gb_attention_max_value = local_var_2_nxt_holder;
GB_ATTENTION_CHILD_gb_attention_softmax_cntr = local_var_3_nxt_holder;
GB_ATTENTION_CHILD_gb_attention_sum_exp = local_var_4_nxt_holder;
GB_ATTENTION_CHILD_gb_attention_timestep_cntr = local_var_5_nxt_holder;
GB_ATTENTION_CHILD_gb_attention_vector_cntr = local_var_6_nxt_holder;
}
