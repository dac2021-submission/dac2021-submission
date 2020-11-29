#include <flex.h>
bool flex::decode_GB_LAYER_REDUCE_gb_layer_reduce_vector_level_op() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_gb_layer_reduce_child_valid_flag == local_var_1);
sc_biguint<3> local_var_4 = 3;
bool local_var_5 = (flex_gb_layer_reduce_child_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
auto& univ_var_752 = local_var_6;
return univ_var_752;
}
void flex::update_GB_LAYER_REDUCE_gb_layer_reduce_vector_level_op() {
sc_biguint<5> local_var_0 = 0;
auto local_var_0_nxt_holder = local_var_0;
sc_biguint<3> local_var_1 = 4;
auto local_var_1_nxt_holder = local_var_1;
sc_biguint<8> local_var_3 = 1;
sc_biguint<8> local_var_4 = (GB_LAYER_REDUCE_gb_layer_reduce_vector_cntr + local_var_3);
auto local_var_4_nxt_holder = local_var_4;
sc_biguint<12> local_var_6 = 0;
univ_var_753 = (sc_biguint<12>(local_var_6), sc_biguint<8>(GB_LAYER_REDUCE_gb_layer_reduce_vector_cntr));
sc_biguint<20> local_var_8 = 16;
sc_biguint<20> local_var_9 = (univ_var_753 * local_var_8);
sc_biguint<20> local_var_10 = 16;
sc_biguint<20> local_var_11 = (local_var_9 * local_var_10);
sc_biguint<20> local_var_12 = (GB_LAYER_REDUCE_gb_layer_reduce_timestep_level_base_addr_0 + local_var_11);
auto local_var_12_nxt_holder = local_var_12;
sc_biguint<20> local_var_14 = (GB_LAYER_REDUCE_gb_layer_reduce_timestep_level_base_addr_result + local_var_11);
auto local_var_14_nxt_holder = local_var_14;
sc_biguint<20> local_var_16 = (GB_LAYER_REDUCE_gb_layer_reduce_timestep_level_base_addr_1 + local_var_11);
auto local_var_16_nxt_holder = local_var_16;
GB_LAYER_REDUCE_gb_layer_reduce_byte_level_cntr = local_var_0_nxt_holder;
flex_gb_layer_reduce_child_state = local_var_1_nxt_holder;
GB_LAYER_REDUCE_gb_layer_reduce_vector_cntr = local_var_4_nxt_holder;
GB_LAYER_REDUCE_gb_layer_reduce_vector_level_addr_0 = local_var_12_nxt_holder;
GB_LAYER_REDUCE_gb_layer_reduce_vector_level_addr_0_result = local_var_14_nxt_holder;
GB_LAYER_REDUCE_gb_layer_reduce_vector_level_addr_1 = local_var_16_nxt_holder;
}
