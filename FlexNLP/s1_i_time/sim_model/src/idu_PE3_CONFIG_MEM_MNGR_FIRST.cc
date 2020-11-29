#include <flex.h>
bool flex::decode_flex_PE3_CONFIG_MEM_MNGR_FIRST() {
sc_biguint<1> local_var_2 = ~flex_if_axi_rd;
sc_biguint<1> local_var_3 = (flex_if_axi_wr & local_var_2);
sc_biguint<1> local_var_4 = 1;
bool local_var_5 = (local_var_3 == local_var_4);
sc_biguint<32> local_var_7 = 926941216;
bool local_var_8 = (flex_addr_in == local_var_7);
bool local_var_9 = (local_var_5 & local_var_8);
auto& univ_var_857 = local_var_9;
return univ_var_857;
}
void flex::update_flex_PE3_CONFIG_MEM_MNGR_FIRST() {
auto local_var_1 = flex_data_in_2.range(2, 0);
auto local_var_1_nxt_holder = local_var_1;
auto local_var_3 = flex_data_in_3.range(2, 0);
auto local_var_3_nxt_holder = local_var_3;
auto local_var_5 = flex_data_in_1.range(2, 0);
auto local_var_5_nxt_holder = local_var_5;
univ_var_858 = (sc_biguint<8>(flex_data_in_9), sc_biguint<8>(flex_data_in_8));
auto univ_var_858_nxt_holder = univ_var_858;
univ_var_859 = (sc_biguint<8>(flex_data_in_11), sc_biguint<8>(flex_data_in_10));
auto univ_var_859_nxt_holder = univ_var_859;
univ_var_860 = (sc_biguint<8>(flex_data_in_7), sc_biguint<8>(flex_data_in_6));
auto univ_var_860_nxt_holder = univ_var_860;
univ_var_861 = (sc_biguint<8>(flex_data_in_5), sc_biguint<8>(flex_data_in_4));
auto local_var_18 = univ_var_861.range(7, 0);
auto local_var_18_nxt_holder = local_var_18;
auto local_var_20 = flex_data_in_0.range(0, 0);
auto local_var_20_nxt_holder = local_var_20;
flex_pe3_mem_mngr_first_adpfloat_bias_b = local_var_1_nxt_holder;
flex_pe3_mem_mngr_first_adpfloat_bias_i = local_var_3_nxt_holder;
flex_pe3_mem_mngr_first_adpfloat_bias_w = local_var_5_nxt_holder;
flex_pe3_mem_mngr_first_base_bias = univ_var_858_nxt_holder;
flex_pe3_mem_mngr_first_base_input = univ_var_859_nxt_holder;
flex_pe3_mem_mngr_first_base_weight = univ_var_860_nxt_holder;
flex_pe3_mem_mngr_first_num_input = local_var_18_nxt_holder;
flex_pe3_mem_mngr_first_zero_active = local_var_20_nxt_holder;
}
