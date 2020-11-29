#include <flex.h>
bool flex::decode_Child_GB_Control_gb_control_child_send_back_prep() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_gb_control_child_valid_flag == local_var_1);
sc_biguint<4> local_var_4 = 6;
bool local_var_5 = (flex_gb_control_child_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
auto& univ_var_710 = local_var_6;
return univ_var_710;
}
void flex::update_Child_GB_Control_gb_control_child_send_back_prep() {
sc_biguint<4> local_var_0 = 7;
auto local_var_0_nxt_holder = local_var_0;
sc_biguint<3> local_var_2 = 0;
bool local_var_3 = (flex_gb_control_memory_index_2 == local_var_2);
sc_biguint<4> local_var_5 = 0;
univ_var_658 = (sc_biguint<16>(flex_gb_core_mem_mngr_large_base_large_0), sc_biguint<4>(local_var_5));
sc_biguint<3> local_var_7 = 1;
bool local_var_8 = (flex_gb_control_memory_index_2 == local_var_7);
sc_biguint<4> local_var_10 = 0;
univ_var_659 = (sc_biguint<16>(flex_gb_core_mem_mngr_large_base_large_1), sc_biguint<4>(local_var_10));
sc_biguint<3> local_var_12 = 2;
bool local_var_13 = (flex_gb_control_memory_index_2 == local_var_12);
sc_biguint<4> local_var_15 = 0;
univ_var_660 = (sc_biguint<16>(flex_gb_core_mem_mngr_large_base_large_2), sc_biguint<4>(local_var_15));
sc_biguint<4> local_var_18 = 0;
univ_var_661 = (sc_biguint<16>(flex_gb_core_mem_mngr_large_base_large_3), sc_biguint<4>(local_var_18));
auto local_var_20 = (local_var_13) ? univ_var_660 : univ_var_661;
auto local_var_21 = (local_var_8) ? univ_var_659 : local_var_20;
auto local_var_22 = (local_var_3) ? univ_var_658 : local_var_21;
sc_biguint<4> local_var_23 = 0;
sc_biguint<16> local_var_25 = 16;
sc_biguint<16> local_var_26 = (Child_GB_Control_gb_control_child_timestep_index / local_var_25);
univ_var_711 = (sc_biguint<4>(local_var_23), sc_biguint<16>(local_var_26));
sc_biguint<12> local_var_28 = 0;
univ_var_712 = (sc_biguint<12>(local_var_28), sc_biguint<8>(flex_gb_control_num_vector_2));
sc_biguint<20> local_var_31 = 16;
sc_biguint<20> local_var_32 = (univ_var_712 * local_var_31);
sc_biguint<20> local_var_33 = 16;
sc_biguint<20> local_var_34 = (local_var_32 * local_var_33);
sc_biguint<20> local_var_35 = (univ_var_711 * local_var_34);
sc_biguint<4> local_var_36 = 0;
sc_biguint<16> local_var_37 = (Child_GB_Control_gb_control_child_timestep_index % local_var_25);
univ_var_713 = (sc_biguint<4>(local_var_36), sc_biguint<16>(local_var_37));
sc_biguint<20> local_var_39 = 16;
sc_biguint<20> local_var_40 = (univ_var_713 * local_var_39);
sc_biguint<20> local_var_41 = (local_var_35 + local_var_40);
sc_biguint<20> local_var_42 = (local_var_22 + local_var_41);
auto local_var_42_nxt_holder = local_var_42;
sc_biguint<8> local_var_43 = 0;
auto local_var_43_nxt_holder = local_var_43;
flex_gb_control_child_state = local_var_0_nxt_holder;
Child_GB_Control_gb_control_child_timestep_base_addr = local_var_42_nxt_holder;
Child_GB_Control_gb_control_child_vector_cntr = local_var_43_nxt_holder;
}
