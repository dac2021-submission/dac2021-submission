#include <flex.h>
bool flex::decode_flex_CONFIG_GB_LAYER_REDUCE() {
sc_biguint<1> local_var_2 = ~flex_if_axi_rd;
sc_biguint<1> local_var_3 = (flex_if_axi_wr & local_var_2);
sc_biguint<1> local_var_4 = 1;
bool local_var_5 = (local_var_3 == local_var_4);
sc_biguint<32> local_var_7 = 864026640;
bool local_var_8 = (flex_addr_in == local_var_7);
bool local_var_9 = (local_var_5 & local_var_8);
auto& univ_var_795 = local_var_9;
return univ_var_795;
}
void flex::update_flex_CONFIG_GB_LAYER_REDUCE() {
auto local_var_1 = flex_data_in_0.range(0, 0);
auto local_var_1_nxt_holder = local_var_1;
auto local_var_3 = flex_data_in_4.range(2, 0);
auto local_var_3_nxt_holder = local_var_3;
auto local_var_5 = flex_data_in_1.range(2, 0);
auto local_var_5_nxt_holder = local_var_5;
univ_var_796 = (sc_biguint<8>(flex_data_in_9), sc_biguint<8>(flex_data_in_8));
auto univ_var_796_nxt_holder = univ_var_796;
auto flex_data_in_6_nxt_holder = flex_data_in_6;
flex_gb_layer_reduce_is_valid = local_var_1_nxt_holder;
flex_gb_layer_reduce_memory_index_1 = local_var_3_nxt_holder;
flex_gb_layer_reduce_mode = local_var_5_nxt_holder;
flex_gb_layer_reduce_num_timestep_1 = univ_var_796_nxt_holder;
flex_gb_layer_reduce_num_vector_1 = flex_data_in_6_nxt_holder;
}
