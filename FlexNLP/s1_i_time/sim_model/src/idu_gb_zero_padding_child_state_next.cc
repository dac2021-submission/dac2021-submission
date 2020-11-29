#include <flex.h>
bool flex::decode_Child_GBZeroPadding_gb_zero_padding_child_state_next() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_gb_zero_padding_child_valid_flag == local_var_1);
sc_biguint<3> local_var_4 = 4;
bool local_var_5 = (flex_gb_zero_padding_child_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
auto& univ_var_774 = local_var_6;
return univ_var_774;
}
void flex::update_Child_GBZeroPadding_gb_zero_padding_child_state_next() {
bool local_var_2 = (Child_GBZeroPadding_gb_zero_padding_vector_cntr < flex_gb_zero_padding_num_vector_1);
sc_biguint<3> local_var_3 = 2;
sc_biguint<16> local_var_7 = (flex_gb_zero_padding_num_timestep_2 - flex_gb_zero_padding_num_timestep_1);
bool local_var_8 = (Child_GBZeroPadding_gb_zero_padding_timestep_cntr < local_var_7);
sc_biguint<3> local_var_9 = 1;
sc_biguint<3> local_var_10 = 5;
auto local_var_11 = (local_var_8) ? local_var_9 : local_var_10;
auto local_var_12 = (local_var_2) ? local_var_3 : local_var_11;
auto local_var_12_nxt_holder = local_var_12;
bool local_var_13 = !local_var_2;
bool local_var_14 = !local_var_8;
bool local_var_15 = (local_var_13 & local_var_14);
sc_biguint<1> local_var_16 = 0;
sc_biguint<1> local_var_17 = 1;
auto local_var_18 = (local_var_15) ? local_var_16 : local_var_17;
auto local_var_18_nxt_holder = local_var_18;
flex_gb_zero_padding_child_state = local_var_12_nxt_holder;
flex_gb_zero_padding_child_valid_flag = local_var_18_nxt_holder;
}
