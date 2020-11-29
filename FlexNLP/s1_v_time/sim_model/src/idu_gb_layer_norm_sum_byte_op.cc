#include <flex.h>
bool flex::decode_Child_GBLayerNorm_gb_layer_norm_sum_byte_op() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_gb_layer_norm_child_valid_flag == local_var_1);
sc_biguint<4> local_var_4 = 2;
bool local_var_5 = (flex_gb_layer_norm_child_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
auto& univ_var_728 = local_var_6;
return univ_var_728;
}
void flex::update_Child_GBLayerNorm_gb_layer_norm_sum_byte_op() {
sc_biguint<5> local_var_1 = 15;
bool local_var_2 = (Child_GBLayerNorm_gb_layer_norm_cntr_byte == local_var_1);
bool local_var_3 = (Child_GBLayerNorm_gb_layer_norm_cntr_byte > local_var_1);
bool local_var_4 = (local_var_2 | local_var_3);
sc_biguint<4> local_var_5 = 1;
sc_biguint<4> local_var_6 = 2;
auto local_var_7 = (local_var_4) ? local_var_5 : local_var_6;
auto local_var_7_nxt_holder = local_var_7;
sc_biguint<5> local_var_8 = 1;
sc_biguint<5> local_var_9 = (Child_GBLayerNorm_gb_layer_norm_cntr_byte + local_var_8);
auto local_var_9_nxt_holder = local_var_9;
sc_biguint<12> local_var_12 = 0;
sc_biguint<15> local_var_14 = 0;
univ_var_729 = (sc_biguint<15>(local_var_14), sc_biguint<5>(Child_GBLayerNorm_gb_layer_norm_cntr_byte));
sc_biguint<20> local_var_16 = (Child_GBLayerNorm_gb_layer_norm_vector_base_addr + univ_var_729);
univ_var_730 = (sc_biguint<12>(local_var_12), sc_biguint<20>(local_var_16));
auto local_var_18 = flex_gb_core_large_buffer[univ_var_730];
auto local_var_20 = Adptfloat2Fixed(local_var_18, flex_gb_layer_norm_adpbias_1);
auto local_var_21 = PEActEadd(Child_GBLayerNorm_gb_layer_norm_vector_sum_x, local_var_20);
auto local_var_21_nxt_holder = local_var_21;
auto local_var_23 = PEActEmul(local_var_20, local_var_20);
auto local_var_24 = PEActEadd(Child_GBLayerNorm_gb_layer_norm_vector_sum_x_sq, local_var_23);
auto local_var_24_nxt_holder = local_var_24;
flex_gb_layer_norm_child_state = local_var_7_nxt_holder;
Child_GBLayerNorm_gb_layer_norm_cntr_byte = local_var_9_nxt_holder;
Child_GBLayerNorm_gb_layer_norm_vector_sum_x = local_var_21_nxt_holder;
Child_GBLayerNorm_gb_layer_norm_vector_sum_x_sq = local_var_24_nxt_holder;
}
