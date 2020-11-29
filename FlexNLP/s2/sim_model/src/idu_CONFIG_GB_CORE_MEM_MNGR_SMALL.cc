#include <flex.h>
bool flex::decode_flex_CONFIG_GB_CORE_MEM_MNGR_SMALL() {
sc_biguint<1> local_var_2 = ~flex_if_axi_rd;
sc_biguint<1> local_var_3 = (flex_if_axi_wr & local_var_2);
sc_biguint<1> local_var_4 = 1;
bool local_var_5 = (local_var_3 == local_var_4);
sc_biguint<32> local_var_7 = 859832352;
bool local_var_8 = (flex_addr_in == local_var_7);
bool local_var_9 = (local_var_5 & local_var_8);
auto& univ_var_784 = local_var_9;
return univ_var_784;
}
void flex::update_flex_CONFIG_GB_CORE_MEM_MNGR_SMALL() {
univ_var_785 = (sc_biguint<8>(flex_data_in_1), sc_biguint<8>(flex_data_in_0));
auto univ_var_785_nxt_holder = univ_var_785;
univ_var_786 = (sc_biguint<8>(flex_data_in_3), sc_biguint<8>(flex_data_in_2));
auto univ_var_786_nxt_holder = univ_var_786;
univ_var_787 = (sc_biguint<8>(flex_data_in_5), sc_biguint<8>(flex_data_in_4));
auto univ_var_787_nxt_holder = univ_var_787;
univ_var_788 = (sc_biguint<8>(flex_data_in_7), sc_biguint<8>(flex_data_in_6));
auto univ_var_788_nxt_holder = univ_var_788;
univ_var_789 = (sc_biguint<8>(flex_data_in_9), sc_biguint<8>(flex_data_in_8));
auto univ_var_789_nxt_holder = univ_var_789;
univ_var_790 = (sc_biguint<8>(flex_data_in_11), sc_biguint<8>(flex_data_in_10));
auto univ_var_790_nxt_holder = univ_var_790;
univ_var_791 = (sc_biguint<8>(flex_data_in_13), sc_biguint<8>(flex_data_in_12));
auto univ_var_791_nxt_holder = univ_var_791;
univ_var_792 = (sc_biguint<8>(flex_data_in_15), sc_biguint<8>(flex_data_in_14));
auto univ_var_792_nxt_holder = univ_var_792;
flex_gb_core_mem_mngr_small_base_small_0 = univ_var_785_nxt_holder;
flex_gb_core_mem_mngr_small_base_small_1 = univ_var_786_nxt_holder;
flex_gb_core_mem_mngr_small_base_small_2 = univ_var_787_nxt_holder;
flex_gb_core_mem_mngr_small_base_small_3 = univ_var_788_nxt_holder;
flex_gb_core_mem_mngr_small_base_small_4 = univ_var_789_nxt_holder;
flex_gb_core_mem_mngr_small_base_small_5 = univ_var_790_nxt_holder;
flex_gb_core_mem_mngr_small_base_small_6 = univ_var_791_nxt_holder;
flex_gb_core_mem_mngr_small_base_small_7 = univ_var_792_nxt_holder;
}
