#include <flex.h>
bool flex::decode_Child_GBLayerNorm_gb_layer_norm_norm_byte_op() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_gb_layer_norm_child_valid_flag == local_var_1);
sc_biguint<4> local_var_4 = 5;
bool local_var_5 = (flex_gb_layer_norm_child_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
auto& univ_var_737 = local_var_6;
return univ_var_737;
}
void flex::update_Child_GBLayerNorm_gb_layer_norm_norm_byte_op() {
std::map<sc_biguint<32>, sc_biguint<8>> local_var_0;
store_738(local_var_0);
sc_biguint<5> local_var_2 = 15;
bool local_var_3 = (Child_GBLayerNorm_gb_layer_norm_cntr_byte == local_var_2);
bool local_var_4 = (Child_GBLayerNorm_gb_layer_norm_cntr_byte > local_var_2);
bool local_var_5 = (local_var_3 | local_var_4);
sc_biguint<4> local_var_6 = 4;
sc_biguint<4> local_var_7 = 5;
auto local_var_8 = (local_var_5) ? local_var_6 : local_var_7;
auto local_var_8_nxt_holder = local_var_8;
sc_biguint<5> local_var_9 = 1;
sc_biguint<5> local_var_10 = (Child_GBLayerNorm_gb_layer_norm_cntr_byte + local_var_9);
auto local_var_10_nxt_holder = local_var_10;
for (auto& it : local_var_0) {
  flex_gb_core_large_buffer[it.first] = it.second;
}
flex_gb_layer_norm_child_state = local_var_8_nxt_holder;
Child_GBLayerNorm_gb_layer_norm_cntr_byte = local_var_10_nxt_holder;
}
