#include <flex.h>
bool flex::decode_PE3_ACT_CHILD_PE3_act_child_op_store() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (PE3_ACT_CHILD_pe3_act_is_start_reg == local_var_1);
sc_biguint<3> local_var_4 = 1;
bool local_var_5 = (PE3_ACT_CHILD_pe3_act_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
sc_biguint<4> local_var_8 = 2;
bool local_var_9 = (PE3_ACT_CHILD_pe3_act_op == local_var_8);
bool local_var_10 = (local_var_6 & local_var_9);
auto& univ_var_434 = local_var_10;
return univ_var_434;
}
void flex::update_PE3_ACT_CHILD_PE3_act_child_op_store() {
std::map<sc_biguint<32>, sc_biguint<8>> local_var_0;
store_435(local_var_0);
sc_biguint<3> local_var_1 = 2;
auto local_var_1_nxt_holder = local_var_1;
for (auto& it : local_var_0) {
  flex_pe3_act_buffer[it.first] = it.second;
}
PE3_ACT_CHILD_pe3_act_state = local_var_1_nxt_holder;
}
