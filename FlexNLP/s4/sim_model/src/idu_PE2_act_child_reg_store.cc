#include <flex.h>
bool flex::decode_PE2_ACT_CHILD_PE2_act_child_reg_store() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (PE2_ACT_CHILD_pe2_act_is_start_reg == local_var_1);
sc_biguint<3> local_var_4 = 5;
bool local_var_5 = (PE2_ACT_CHILD_pe2_act_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
auto& univ_var_357 = local_var_6;
return univ_var_357;
}
void flex::update_PE2_ACT_CHILD_PE2_act_child_reg_store() {
std::map<sc_biguint<4>, sc_biguint<20>> local_var_0;
ite_358(local_var_0);
std::map<sc_biguint<4>, sc_biguint<20>> local_var_1;
ite_374(local_var_1);
std::map<sc_biguint<4>, sc_biguint<20>> local_var_2;
ite_390(local_var_2);
std::map<sc_biguint<4>, sc_biguint<20>> local_var_3;
ite_406(local_var_3);
sc_biguint<3> local_var_4 = 2;
auto local_var_4_nxt_holder = local_var_4;
for (auto& it : local_var_0) {
  PE2_ACT_CHILD_PE2_act_regs_0[it.first] = it.second;
}
for (auto& it : local_var_1) {
  PE2_ACT_CHILD_PE2_act_regs_1[it.first] = it.second;
}
for (auto& it : local_var_2) {
  PE2_ACT_CHILD_PE2_act_regs_2[it.first] = it.second;
}
for (auto& it : local_var_3) {
  PE2_ACT_CHILD_PE2_act_regs_3[it.first] = it.second;
}
PE2_ACT_CHILD_pe2_act_state = local_var_4_nxt_holder;
}
