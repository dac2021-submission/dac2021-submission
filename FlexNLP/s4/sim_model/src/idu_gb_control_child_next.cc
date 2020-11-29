#include <flex.h>
bool flex::decode_Child_GB_Control_gb_control_child_next() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_gb_control_child_valid_flag == local_var_1);
sc_biguint<4> local_var_4 = 8;
bool local_var_5 = (flex_gb_control_child_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
auto& univ_var_718 = local_var_6;
return univ_var_718;
}
void flex::update_Child_GB_Control_gb_control_child_next() {
sc_biguint<16> local_var_1 = 1;
sc_biguint<16> local_var_2 = (Child_GB_Control_gb_control_child_timestep_cntr + local_var_1);
bool local_var_4 = (local_var_2 == flex_gb_control_num_timestep_1);
sc_biguint<4> local_var_5 = 0;
sc_biguint<4> local_var_6 = 1;
auto local_var_7 = (local_var_4) ? local_var_5 : local_var_6;
auto local_var_7_nxt_holder = local_var_7;
auto local_var_2_nxt_holder = local_var_2;
sc_biguint<1> local_var_8 = 0;
sc_biguint<1> local_var_9 = 1;
auto local_var_10 = (local_var_4) ? local_var_8 : local_var_9;
auto local_var_10_nxt_holder = local_var_10;
flex_gb_control_child_state = local_var_7_nxt_holder;
Child_GB_Control_gb_control_child_timestep_cntr = local_var_2_nxt_holder;
flex_gb_control_child_valid_flag = local_var_10_nxt_holder;
}
