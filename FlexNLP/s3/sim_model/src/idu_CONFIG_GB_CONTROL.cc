#include <flex.h>
bool flex::decode_flex_CONFIG_GB_CONTROL() {
sc_biguint<1> local_var_2 = ~flex_if_axi_rd;
sc_biguint<1> local_var_3 = (flex_if_axi_wr & local_var_2);
sc_biguint<1> local_var_4 = 1;
bool local_var_5 = (local_var_3 == local_var_4);
sc_biguint<32> local_var_7 = 862978064;
bool local_var_8 = (flex_addr_in == local_var_7);
bool local_var_9 = (local_var_5 & local_var_8);
auto& univ_var_777 = local_var_9;
return univ_var_777;
}
void flex::update_flex_CONFIG_GB_CONTROL() {
auto local_var_1 = flex_data_in_2.range(0, 0);
auto local_var_1_nxt_holder = local_var_1;
auto local_var_3 = flex_data_in_0.range(0, 0);
auto local_var_3_nxt_holder = local_var_3;
auto local_var_5 = flex_data_in_4.range(2, 0);
auto local_var_5_nxt_holder = local_var_5;
auto local_var_7 = flex_data_in_5.range(2, 0);
auto local_var_7_nxt_holder = local_var_7;
auto local_var_9 = flex_data_in_1.range(2, 0);
auto local_var_9_nxt_holder = local_var_9;
univ_var_778 = (sc_biguint<8>(flex_data_in_9), sc_biguint<8>(flex_data_in_8));
auto univ_var_778_nxt_holder = univ_var_778;
auto flex_data_in_6_nxt_holder = flex_data_in_6;
auto flex_data_in_7_nxt_holder = flex_data_in_7;
flex_gb_control_is_rnn = local_var_1_nxt_holder;
flex_gb_control_is_valid = local_var_3_nxt_holder;
flex_gb_control_memory_index_1 = local_var_5_nxt_holder;
flex_gb_control_memory_index_2 = local_var_7_nxt_holder;
flex_gb_control_mode = local_var_9_nxt_holder;
flex_gb_control_num_timestep_1 = univ_var_778_nxt_holder;
flex_gb_control_num_vector_1 = flex_data_in_6_nxt_holder;
flex_gb_control_num_vector_2 = flex_data_in_7_nxt_holder;
}
