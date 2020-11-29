#include <flex.h>
bool flex::decode_Child_GBLayerNorm_gb_layer_norm_child_next() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_gb_layer_norm_child_valid_flag == local_var_1);
sc_biguint<4> local_var_4 = 6;
bool local_var_5 = (flex_gb_layer_norm_child_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
auto& univ_var_743 = local_var_6;
return univ_var_743;
}
void flex::update_Child_GBLayerNorm_gb_layer_norm_child_next() {
sc_biguint<4> local_var_0 = 0;
auto local_var_0_nxt_holder = local_var_0;
sc_biguint<16> local_var_3 = 1;
sc_biguint<16> local_var_4 = (flex_gb_layer_norm_num_timestep_1 - local_var_3);
bool local_var_5 = (flex_gb_layer_norm_cntr_timestep == local_var_4);
bool local_var_6 = (flex_gb_layer_norm_cntr_timestep > local_var_4);
bool local_var_7 = (local_var_5 | local_var_6);
sc_biguint<1> local_var_8 = 0;
sc_biguint<1> local_var_9 = 1;
auto local_var_10 = (local_var_7) ? local_var_8 : local_var_9;
auto local_var_10_nxt_holder = local_var_10;
sc_biguint<16> local_var_11 = 1;
sc_biguint<16> local_var_12 = (flex_gb_layer_norm_cntr_timestep + local_var_11);
auto local_var_12_nxt_holder = local_var_12;
flex_gb_layer_norm_child_state = local_var_0_nxt_holder;
flex_gb_layer_norm_child_valid_flag = local_var_10_nxt_holder;
flex_gb_layer_norm_cntr_timestep = local_var_12_nxt_holder;
}
