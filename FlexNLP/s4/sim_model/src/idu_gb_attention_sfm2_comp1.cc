#include <flex.h>
bool flex::decode_GB_ATTENTION_CHILD_gb_attention_sfm2_comp1() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_gb_attention_child_valid_flag == local_var_1);
sc_biguint<5> local_var_4 = 12;
bool local_var_5 = (flex_gb_attention_child_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
auto& univ_var_607 = local_var_6;
return univ_var_607;
}
void flex::update_GB_ATTENTION_CHILD_gb_attention_sfm2_comp1() {
sc_biguint<5> local_var_0 = 10;
auto local_var_0_nxt_holder = local_var_0;
sc_biguint<2> local_var_2 = 3;
bool local_var_3 = (GB_ATTENTION_CHILD_gb_attention_softmax_cntr == local_var_2);
bool local_var_4 = (GB_ATTENTION_CHILD_gb_attention_softmax_cntr > local_var_2);
bool local_var_5 = (local_var_3 | local_var_4);
sc_biguint<2> local_var_6 = 0;
sc_biguint<2> local_var_7 = 1;
sc_biguint<2> local_var_8 = (GB_ATTENTION_CHILD_gb_attention_softmax_cntr + local_var_7);
auto local_var_9 = (local_var_5) ? local_var_6 : local_var_8;
auto local_var_9_nxt_holder = local_var_9;
auto local_var_12 = GBAttentionSub(GB_ATTENTION_CHILD_gb_attention_exp_vector_0, GB_ATTENTION_CHILD_gb_attention_max_value);
auto local_var_13 = GBAttentionExp(local_var_12);
auto local_var_15 = GBAttentionDiv(local_var_13, GB_ATTENTION_CHILD_gb_attention_sum_exp);
auto local_var_17 = GBAttentionCompress(local_var_15, flex_gb_attention_adpbias_3);
auto local_var_17_nxt_holder = local_var_17;
auto local_var_19 = GBAttentionSub(GB_ATTENTION_CHILD_gb_attention_exp_vector_1, GB_ATTENTION_CHILD_gb_attention_max_value);
auto local_var_20 = GBAttentionExp(local_var_19);
auto local_var_21 = GBAttentionDiv(local_var_20, GB_ATTENTION_CHILD_gb_attention_sum_exp);
auto local_var_22 = GBAttentionCompress(local_var_21, flex_gb_attention_adpbias_3);
auto local_var_22_nxt_holder = local_var_22;
auto local_var_24 = GBAttentionSub(GB_ATTENTION_CHILD_gb_attention_exp_vector_2, GB_ATTENTION_CHILD_gb_attention_max_value);
auto local_var_25 = GBAttentionExp(local_var_24);
auto local_var_26 = GBAttentionDiv(local_var_25, GB_ATTENTION_CHILD_gb_attention_sum_exp);
auto local_var_27 = GBAttentionCompress(local_var_26, flex_gb_attention_adpbias_3);
auto local_var_27_nxt_holder = local_var_27;
auto local_var_29 = GBAttentionSub(GB_ATTENTION_CHILD_gb_attention_exp_vector_3, GB_ATTENTION_CHILD_gb_attention_max_value);
auto local_var_30 = GBAttentionExp(local_var_29);
auto local_var_31 = GBAttentionDiv(local_var_30, GB_ATTENTION_CHILD_gb_attention_sum_exp);
auto local_var_32 = GBAttentionCompress(local_var_31, flex_gb_attention_adpbias_3);
auto local_var_32_nxt_holder = local_var_32;
flex_gb_attention_child_state = local_var_0_nxt_holder;
GB_ATTENTION_CHILD_gb_attention_softmax_cntr = local_var_9_nxt_holder;
GB_ATTENTION_CHILD_gb_attention_softmax_result_vector_4 = local_var_17_nxt_holder;
GB_ATTENTION_CHILD_gb_attention_softmax_result_vector_5 = local_var_22_nxt_holder;
GB_ATTENTION_CHILD_gb_attention_softmax_result_vector_6 = local_var_27_nxt_holder;
GB_ATTENTION_CHILD_gb_attention_softmax_result_vector_7 = local_var_32_nxt_holder;
}
