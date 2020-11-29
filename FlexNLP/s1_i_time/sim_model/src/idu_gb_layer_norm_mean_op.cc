#include <flex.h>
bool flex::decode_Child_GBLayerNorm_gb_layer_norm_mean_op() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_gb_layer_norm_child_valid_flag == local_var_1);
sc_biguint<4> local_var_4 = 3;
bool local_var_5 = (flex_gb_layer_norm_child_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
auto& univ_var_731 = local_var_6;
return univ_var_731;
}
void flex::update_Child_GBLayerNorm_gb_layer_norm_mean_op() {
sc_biguint<4> local_var_0 = 4;
auto local_var_0_nxt_holder = local_var_0;
sc_biguint<8> local_var_1 = 0;
auto local_var_1_nxt_holder = local_var_1;
sc_biguint<16> local_var_3 = 0;
univ_var_732 = (sc_biguint<16>(local_var_3), sc_biguint<8>(flex_gb_layer_norm_num_vector_1));
sc_biguint<24> local_var_6 = 16;
sc_biguint<24> local_var_7 = (univ_var_732 * local_var_6);
auto local_var_8 = GBNormDivide_24(Child_GBLayerNorm_gb_layer_norm_sum_X_SQ, local_var_7);
auto local_var_10 = GBNormDivide_24(Child_GBLayerNorm_gb_layer_norm_sum_X, local_var_7);
auto local_var_11 = PEActEmul(local_var_10, local_var_10);
auto local_var_12 = ActSignedMinus(local_var_8, local_var_11);
auto local_var_13 = SInvSqrt(local_var_12);
auto local_var_13_nxt_holder = local_var_13;
auto local_var_10_nxt_holder = local_var_10;
flex_gb_layer_norm_child_state = local_var_0_nxt_holder;
Child_GBLayerNorm_gb_layer_norm_cntr_vector = local_var_1_nxt_holder;
Child_GBLayerNorm_gb_layer_norm_inv_std = local_var_13_nxt_holder;
Child_GBLayerNorm_gb_layer_norm_mean = local_var_10_nxt_holder;
}
