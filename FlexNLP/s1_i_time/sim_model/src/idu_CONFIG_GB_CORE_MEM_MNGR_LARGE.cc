#include <flex.h>
bool flex::decode_flex_CONFIG_GB_CORE_MEM_MNGR_LARGE() {
sc_biguint<1> local_var_2 = ~flex_if_axi_rd;
sc_biguint<1> local_var_3 = (flex_if_axi_wr & local_var_2);
sc_biguint<1> local_var_4 = 1;
bool local_var_5 = (local_var_3 == local_var_4);
sc_biguint<32> local_var_7 = 859832336;
bool local_var_8 = (flex_addr_in == local_var_7);
bool local_var_9 = (local_var_5 & local_var_8);
auto& univ_var_779 = local_var_9;
return univ_var_779;
}
void flex::update_flex_CONFIG_GB_CORE_MEM_MNGR_LARGE() {
univ_var_780 = (sc_biguint<8>(flex_data_in_3), sc_biguint<8>(flex_data_in_2));
auto univ_var_780_nxt_holder = univ_var_780;
univ_var_781 = (sc_biguint<8>(flex_data_in_7), sc_biguint<8>(flex_data_in_6));
auto univ_var_781_nxt_holder = univ_var_781;
univ_var_782 = (sc_biguint<8>(flex_data_in_11), sc_biguint<8>(flex_data_in_10));
auto univ_var_782_nxt_holder = univ_var_782;
univ_var_783 = (sc_biguint<8>(flex_data_in_15), sc_biguint<8>(flex_data_in_14));
auto univ_var_783_nxt_holder = univ_var_783;
auto flex_data_in_0_nxt_holder = flex_data_in_0;
auto flex_data_in_4_nxt_holder = flex_data_in_4;
auto flex_data_in_8_nxt_holder = flex_data_in_8;
auto flex_data_in_12_nxt_holder = flex_data_in_12;
flex_gb_core_mem_mngr_large_base_large_0 = univ_var_780_nxt_holder;
flex_gb_core_mem_mngr_large_base_large_1 = univ_var_781_nxt_holder;
flex_gb_core_mem_mngr_large_base_large_2 = univ_var_782_nxt_holder;
flex_gb_core_mem_mngr_large_base_large_3 = univ_var_783_nxt_holder;
flex_gb_core_mem_mngr_large_num_vector_0 = flex_data_in_0_nxt_holder;
flex_gb_core_mem_mngr_large_num_vector_1 = flex_data_in_4_nxt_holder;
flex_gb_core_mem_mngr_large_num_vector_2 = flex_data_in_8_nxt_holder;
flex_gb_core_mem_mngr_large_num_vector_3 = flex_data_in_12_nxt_holder;
}
