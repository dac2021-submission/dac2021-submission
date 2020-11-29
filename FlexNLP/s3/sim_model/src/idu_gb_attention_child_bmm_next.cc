#include <flex.h>
bool flex::decode_GB_ATTENTION_CHILD_gb_attention_child_bmm_next() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_gb_attention_child_valid_flag == local_var_1);
sc_biguint<5> local_var_4 = 19;
bool local_var_5 = (flex_gb_attention_child_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
auto& univ_var_536 = local_var_6;
return univ_var_536;
}
void flex::update_GB_ATTENTION_CHILD_gb_attention_child_bmm_next() {
sc_biguint<1> local_var_1 = 0;
bool local_var_2 = (GB_ATTENTION_CHILD_gb_attention_bmm_cntr == local_var_1);
sc_biguint<8> local_var_5 = 1;
sc_biguint<8> local_var_6 = (flex_gb_attention_num_vector_1 - local_var_5);
bool local_var_7 = (GB_ATTENTION_CHILD_gb_attention_vector_cntr == local_var_6);
bool local_var_8 = (GB_ATTENTION_CHILD_gb_attention_vector_cntr > local_var_6);
bool local_var_9 = (local_var_7 | local_var_8);
sc_biguint<5> local_var_10 = 5;
sc_biguint<5> local_var_11 = 2;
auto local_var_12 = (local_var_9) ? local_var_10 : local_var_11;
sc_biguint<16> local_var_15 = 16;
sc_biguint<16> local_var_16 = (flex_gb_attention_num_timestep_1 - local_var_15);
bool local_var_17 = (GB_ATTENTION_CHILD_gb_attention_timestep_cntr == local_var_16);
bool local_var_18 = (GB_ATTENTION_CHILD_gb_attention_timestep_cntr > local_var_16);
bool local_var_19 = (local_var_17 | local_var_18);
sc_biguint<5> local_var_20 = 16;
sc_biguint<5> local_var_21 = 2;
auto local_var_22 = (local_var_19) ? local_var_20 : local_var_21;
auto local_var_23 = (local_var_2) ? local_var_12 : local_var_22;
auto local_var_23_nxt_holder = local_var_23;
sc_biguint<1> local_var_24 = 1;
bool local_var_25 = (GB_ATTENTION_CHILD_gb_attention_bmm_cntr == local_var_24);
sc_biguint<16> local_var_26 = 0;
sc_biguint<16> local_var_27 = 16;
sc_biguint<16> local_var_28 = (GB_ATTENTION_CHILD_gb_attention_timestep_cntr + local_var_27);
auto local_var_29 = (local_var_19) ? local_var_26 : local_var_28;
auto local_var_30 = (local_var_25) ? local_var_29 : GB_ATTENTION_CHILD_gb_attention_timestep_cntr;
auto local_var_30_nxt_holder = local_var_30;
sc_biguint<1> local_var_31 = 0;
bool local_var_32 = (GB_ATTENTION_CHILD_gb_attention_bmm_cntr == local_var_31);
sc_biguint<8> local_var_33 = 0;
sc_biguint<8> local_var_34 = 1;
sc_biguint<8> local_var_35 = (GB_ATTENTION_CHILD_gb_attention_vector_cntr + local_var_34);
auto local_var_36 = (local_var_9) ? local_var_33 : local_var_35;
auto local_var_37 = (local_var_32) ? local_var_36 : GB_ATTENTION_CHILD_gb_attention_vector_cntr;
auto local_var_37_nxt_holder = local_var_37;
flex_gb_attention_child_state = local_var_23_nxt_holder;
GB_ATTENTION_CHILD_gb_attention_timestep_cntr = local_var_30_nxt_holder;
GB_ATTENTION_CHILD_gb_attention_vector_cntr = local_var_37_nxt_holder;
}
