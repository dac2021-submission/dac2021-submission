#include <flex.h>
bool flex::decode_PE3_ACT_CHILD_PE3_act_child_initiate() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_pe3_act_mngr_is_valid == local_var_1);
sc_biguint<1> local_var_4 = 0;
bool local_var_5 = (PE3_ACT_CHILD_pe3_act_is_start_reg == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
sc_biguint<1> local_var_8 = 1;
bool local_var_9 = (flex_pe3_act_start_signal == local_var_8);
bool local_var_10 = (local_var_6 & local_var_9);
sc_biguint<3> local_var_12 = 4;
bool local_var_13 = (PE3_ACT_CHILD_pe3_act_state == local_var_12);
bool local_var_14 = (local_var_10 & local_var_13);
auto& univ_var_422 = local_var_14;
return univ_var_422;
}
void flex::update_PE3_ACT_CHILD_PE3_act_child_initiate() {
std::map<sc_biguint<4>, sc_biguint<20>> local_var_0;
store_423(local_var_0);
std::map<sc_biguint<4>, sc_biguint<20>> local_var_1;
store_424(local_var_1);
std::map<sc_biguint<4>, sc_biguint<20>> local_var_2;
store_425(local_var_2);
std::map<sc_biguint<4>, sc_biguint<20>> local_var_3;
store_426(local_var_3);
sc_biguint<6> local_var_4 = 0;
auto local_var_4_nxt_holder = local_var_4;
sc_biguint<1> local_var_5 = 1;
auto local_var_5_nxt_holder = local_var_5;
sc_biguint<8> local_var_6 = 0;
auto local_var_6_nxt_holder = local_var_6;
sc_biguint<1> local_var_7 = 0;
auto local_var_7_nxt_holder = local_var_7;
sc_biguint<3> local_var_8 = 0;
auto local_var_8_nxt_holder = local_var_8;
for (auto& it : local_var_0) {
  PE3_ACT_CHILD_PE3_act_regs_0[it.first] = it.second;
}
for (auto& it : local_var_1) {
  PE3_ACT_CHILD_PE3_act_regs_1[it.first] = it.second;
}
for (auto& it : local_var_2) {
  PE3_ACT_CHILD_PE3_act_regs_2[it.first] = it.second;
}
for (auto& it : local_var_3) {
  PE3_ACT_CHILD_PE3_act_regs_3[it.first] = it.second;
}
PE3_ACT_CHILD_pe3_act_instruction_counter = local_var_4_nxt_holder;
PE3_ACT_CHILD_pe3_act_is_start_reg = local_var_5_nxt_holder;
PE3_ACT_CHILD_pe3_act_output_counter = local_var_6_nxt_holder;
flex_pe3_act_start_signal = local_var_7_nxt_holder;
PE3_ACT_CHILD_pe3_act_state = local_var_8_nxt_holder;
}
