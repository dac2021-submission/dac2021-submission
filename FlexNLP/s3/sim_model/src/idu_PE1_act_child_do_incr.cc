#include <flex.h>
bool flex::decode_PE1_ACT_CHILD_PE1_act_child_do_incr() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (PE1_ACT_CHILD_pe1_act_is_start_reg == local_var_1);
sc_biguint<3> local_var_4 = 2;
bool local_var_5 = (PE1_ACT_CHILD_pe1_act_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
auto& univ_var_248 = local_var_6;
return univ_var_248;
}
void flex::update_PE1_ACT_CHILD_PE1_act_child_do_incr() {
sc_biguint<6> local_var_2 = 1;
sc_biguint<6> local_var_3 = (flex_pe1_act_mngr_num_inst - local_var_2);
bool local_var_4 = (PE1_ACT_CHILD_pe1_act_instruction_counter == local_var_3);
sc_biguint<6> local_var_5 = 0;
sc_biguint<6> local_var_6 = 1;
sc_biguint<6> local_var_7 = (PE1_ACT_CHILD_pe1_act_instruction_counter + local_var_6);
auto local_var_8 = (local_var_4) ? local_var_5 : local_var_7;
auto local_var_8_nxt_holder = local_var_8;
sc_biguint<8> local_var_11 = 1;
sc_biguint<8> local_var_12 = (flex_pe1_act_mngr_num_output - local_var_11);
bool local_var_13 = (PE1_ACT_CHILD_pe1_act_output_counter == local_var_12);
bool local_var_14 = (local_var_4 & local_var_13);
sc_biguint<1> local_var_15 = 0;
sc_biguint<1> local_var_16 = 1;
auto local_var_17 = (local_var_14) ? local_var_15 : local_var_16;
auto local_var_17_nxt_holder = local_var_17;
sc_biguint<1> local_var_18 = 0;
auto local_var_20 = (local_var_14) ? local_var_18 : flex_pe1_act_mngr_is_zero_first;
auto local_var_20_nxt_holder = local_var_20;
sc_biguint<8> local_var_21 = 0;
bool local_var_22 = !local_var_13;
bool local_var_23 = (local_var_4 & local_var_22);
sc_biguint<8> local_var_24 = 1;
sc_biguint<8> local_var_25 = (PE1_ACT_CHILD_pe1_act_output_counter + local_var_24);
auto local_var_26 = (local_var_23) ? local_var_25 : PE1_ACT_CHILD_pe1_act_output_counter;
auto local_var_27 = (local_var_14) ? local_var_21 : local_var_26;
auto local_var_27_nxt_holder = local_var_27;
sc_biguint<3> local_var_28 = 3;
sc_biguint<3> local_var_29 = 0;
auto local_var_30 = (local_var_14) ? local_var_28 : local_var_29;
auto local_var_30_nxt_holder = local_var_30;
PE1_ACT_CHILD_pe1_act_instruction_counter = local_var_8_nxt_holder;
PE1_ACT_CHILD_pe1_act_is_start_reg = local_var_17_nxt_holder;
flex_pe1_act_mngr_is_zero_first = local_var_20_nxt_holder;
PE1_ACT_CHILD_pe1_act_output_counter = local_var_27_nxt_holder;
PE1_ACT_CHILD_pe1_act_state = local_var_30_nxt_holder;
}
