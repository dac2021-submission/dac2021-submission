#include <flex.h>
bool flex::decode_GB_ATTENTION_CHILD_gb_attention_child_sfm1_comp() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_gb_attention_child_valid_flag == local_var_1);
sc_biguint<5> local_var_4 = 9;
bool local_var_5 = (flex_gb_attention_child_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
auto& univ_var_580 = local_var_6;
return univ_var_580;
}
void flex::update_GB_ATTENTION_CHILD_gb_attention_child_sfm1_comp() {
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
sc_biguint<5> local_var_13 = 10;
sc_biguint<5> local_var_14 = 8;
auto local_var_15 = (local_var_12) ? local_var_13 : local_var_14;
auto local_var_15_nxt_holder = local_var_15;
sc_biguint<2> local_var_16 = 0;
sc_biguint<2> local_var_17 = 1;
sc_biguint<2> local_var_18 = (GB_ATTENTION_CHILD_gb_attention_softmax_cntr + local_var_17);
auto local_var_19 = (local_var_4) ? local_var_16 : local_var_18;
auto local_var_19_nxt_holder = local_var_19;
sc_biguint<32> local_var_21 = 0;
auto local_var_24 = GBAttentionSub(GB_ATTENTION_CHILD_gb_attention_exp_vector_0, GB_ATTENTION_CHILD_gb_attention_max_value);
auto local_var_25 = GBAttentionExp(local_var_24);
sc_biguint<32> local_var_26 = (local_var_21 + local_var_25);
auto local_var_28 = GBAttentionSub(GB_ATTENTION_CHILD_gb_attention_exp_vector_1, GB_ATTENTION_CHILD_gb_attention_max_value);
auto local_var_29 = GBAttentionExp(local_var_28);
sc_biguint<32> local_var_30 = (local_var_26 + local_var_29);
auto local_var_32 = GBAttentionSub(GB_ATTENTION_CHILD_gb_attention_exp_vector_2, GB_ATTENTION_CHILD_gb_attention_max_value);
auto local_var_33 = GBAttentionExp(local_var_32);
sc_biguint<32> local_var_34 = (local_var_30 + local_var_33);
auto local_var_36 = GBAttentionSub(GB_ATTENTION_CHILD_gb_attention_exp_vector_3, GB_ATTENTION_CHILD_gb_attention_max_value);
auto local_var_37 = GBAttentionExp(local_var_36);
sc_biguint<32> local_var_38 = (local_var_34 + local_var_37);
sc_biguint<32> local_var_39 = (GB_ATTENTION_CHILD_gb_attention_sum_exp + local_var_38);
auto local_var_39_nxt_holder = local_var_39;
sc_biguint<16> local_var_40 = 0;
sc_biguint<16> local_var_41 = 16;
sc_biguint<16> local_var_42 = (GB_ATTENTION_CHILD_gb_attention_timestep_cntr + local_var_41);
auto local_var_43 = (local_var_11) ? local_var_40 : local_var_42;
auto local_var_44 = (local_var_4) ? local_var_43 : GB_ATTENTION_CHILD_gb_attention_timestep_cntr;
auto local_var_44_nxt_holder = local_var_44;
flex_gb_attention_child_state = local_var_15_nxt_holder;
GB_ATTENTION_CHILD_gb_attention_softmax_cntr = local_var_19_nxt_holder;
GB_ATTENTION_CHILD_gb_attention_sum_exp = local_var_39_nxt_holder;
GB_ATTENTION_CHILD_gb_attention_timestep_cntr = local_var_44_nxt_holder;
}
