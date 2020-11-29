#include <flex.h>
bool flex::decode_Child_GBZeroPadding_gb_zero_padding_child_timestep() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_gb_zero_padding_child_valid_flag == local_var_1);
sc_biguint<3> local_var_4 = 1;
bool local_var_5 = (flex_gb_zero_padding_child_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
auto& univ_var_765 = local_var_6;
return univ_var_765;
}
void flex::update_Child_GBZeroPadding_gb_zero_padding_child_timestep() {
sc_biguint<3> local_var_0 = 2;
auto local_var_0_nxt_holder = local_var_0;
sc_biguint<4> local_var_2 = 0;
sc_biguint<16> local_var_5 = (flex_gb_zero_padding_num_timestep_1 + Child_GBZeroPadding_gb_zero_padding_timestep_cntr);
sc_biguint<16> local_var_6 = 16;
sc_biguint<16> local_var_7 = (local_var_5 / local_var_6);
univ_var_766 = (sc_biguint<4>(local_var_2), sc_biguint<16>(local_var_7));
sc_biguint<12> local_var_9 = 0;
univ_var_767 = (sc_biguint<12>(local_var_9), sc_biguint<8>(flex_gb_zero_padding_num_vector_1));
sc_biguint<20> local_var_12 = 16;
sc_biguint<20> local_var_13 = (univ_var_767 * local_var_12);
sc_biguint<20> local_var_14 = 16;
sc_biguint<20> local_var_15 = (local_var_13 * local_var_14);
sc_biguint<20> local_var_16 = (univ_var_766 * local_var_15);
sc_biguint<4> local_var_17 = 0;
sc_biguint<16> local_var_18 = (local_var_5 % local_var_6);
univ_var_768 = (sc_biguint<4>(local_var_17), sc_biguint<16>(local_var_18));
sc_biguint<20> local_var_20 = 16;
sc_biguint<20> local_var_21 = (univ_var_768 * local_var_20);
sc_biguint<20> local_var_22 = (local_var_16 + local_var_21);
sc_biguint<20> local_var_23 = (Child_GBZeroPadding_gb_zero_padding_mem_base_addr + local_var_22);
auto local_var_23_nxt_holder = local_var_23;
sc_biguint<16> local_var_24 = 1;
sc_biguint<16> local_var_25 = (Child_GBZeroPadding_gb_zero_padding_timestep_cntr + local_var_24);
auto local_var_25_nxt_holder = local_var_25;
sc_biguint<8> local_var_26 = 0;
auto local_var_26_nxt_holder = local_var_26;
flex_gb_zero_padding_child_state = local_var_0_nxt_holder;
Child_GBZeroPadding_gb_zero_padding_mem_base_addr = local_var_23_nxt_holder;
Child_GBZeroPadding_gb_zero_padding_timestep_cntr = local_var_25_nxt_holder;
Child_GBZeroPadding_gb_zero_padding_vector_cntr = local_var_26_nxt_holder;
}
