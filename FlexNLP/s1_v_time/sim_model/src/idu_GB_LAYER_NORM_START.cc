#include <flex.h>
bool flex::decode_flex_GB_LAYER_NORM_START() {
sc_biguint<1> local_var_2 = ~flex_if_axi_rd;
sc_biguint<1> local_var_3 = (flex_if_axi_wr & local_var_2);
sc_biguint<1> local_var_5 = (local_var_3 & flex_gb_layer_norm_is_valid);
sc_biguint<1> local_var_6 = 1;
bool local_var_7 = (local_var_5 == local_var_6);
sc_biguint<32> local_var_9 = 855638064;
bool local_var_10 = (flex_addr_in == local_var_9);
bool local_var_11 = (local_var_7 & local_var_10);
auto& univ_var_898 = local_var_11;
return univ_var_898;
}
void flex::update_flex_GB_LAYER_NORM_START() {
sc_biguint<4> local_var_0 = 0;
auto local_var_0_nxt_holder = local_var_0;
sc_biguint<1> local_var_1 = 1;
auto local_var_1_nxt_holder = local_var_1;
sc_biguint<16> local_var_2 = 0;
auto local_var_2_nxt_holder = local_var_2;
flex_gb_layer_norm_child_state = local_var_0_nxt_holder;
flex_gb_layer_norm_child_valid_flag = local_var_1_nxt_holder;
flex_gb_layer_norm_cntr_timestep = local_var_2_nxt_holder;
}
