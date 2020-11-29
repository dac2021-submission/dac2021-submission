#include <flex.h>
bool flex::decode_Child_GBLayerNorm_gb_layer_norm_sum_vector_level_prep() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_gb_layer_norm_child_valid_flag == local_var_1);
sc_biguint<4> local_var_4 = 1;
bool local_var_5 = (flex_gb_layer_norm_child_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
auto& univ_var_726 = local_var_6;
return univ_var_726;
}
void flex::update_Child_GBLayerNorm_gb_layer_norm_sum_vector_level_prep() {
bool local_var_2 = (Child_GBLayerNorm_gb_layer_norm_cntr_vector == flex_gb_layer_norm_num_vector_1);
bool local_var_3 = (Child_GBLayerNorm_gb_layer_norm_cntr_vector > flex_gb_layer_norm_num_vector_1);
bool local_var_4 = (local_var_2 | local_var_3);
sc_biguint<4> local_var_5 = 3;
sc_biguint<4> local_var_6 = 2;
auto local_var_7 = (local_var_4) ? local_var_5 : local_var_6;
auto local_var_7_nxt_holder = local_var_7;
sc_biguint<5> local_var_8 = 0;
auto local_var_8_nxt_holder = local_var_8;
sc_biguint<8> local_var_9 = 1;
sc_biguint<8> local_var_10 = (Child_GBLayerNorm_gb_layer_norm_cntr_vector + local_var_9);
auto local_var_10_nxt_holder = local_var_10;
auto local_var_13 = GBNormAdd_24_20(Child_GBLayerNorm_gb_layer_norm_sum_X, Child_GBLayerNorm_gb_layer_norm_vector_sum_x);
auto local_var_13_nxt_holder = local_var_13;
auto local_var_16 = GBNormAdd_24_20(Child_GBLayerNorm_gb_layer_norm_sum_X_SQ, Child_GBLayerNorm_gb_layer_norm_vector_sum_x_sq);
auto local_var_16_nxt_holder = local_var_16;
sc_biguint<12> local_var_18 = 0;
univ_var_727 = (sc_biguint<12>(local_var_18), sc_biguint<8>(Child_GBLayerNorm_gb_layer_norm_cntr_vector));
sc_biguint<20> local_var_20 = 256;
sc_biguint<20> local_var_21 = (univ_var_727 * local_var_20);
sc_biguint<20> local_var_22 = (Child_GBLayerNorm_gb_layer_norm_timestep_level_base_addr + local_var_21);
auto local_var_22_nxt_holder = local_var_22;
sc_biguint<20> local_var_23 = 0;
auto local_var_23_nxt_holder = local_var_23;
sc_biguint<20> local_var_24 = 0;
auto local_var_24_nxt_holder = local_var_24;
flex_gb_layer_norm_child_state = local_var_7_nxt_holder;
Child_GBLayerNorm_gb_layer_norm_cntr_byte = local_var_8_nxt_holder;
Child_GBLayerNorm_gb_layer_norm_cntr_vector = local_var_10_nxt_holder;
Child_GBLayerNorm_gb_layer_norm_sum_X = local_var_13_nxt_holder;
Child_GBLayerNorm_gb_layer_norm_sum_X_SQ = local_var_16_nxt_holder;
Child_GBLayerNorm_gb_layer_norm_vector_base_addr = local_var_22_nxt_holder;
Child_GBLayerNorm_gb_layer_norm_vector_sum_x = local_var_23_nxt_holder;
Child_GBLayerNorm_gb_layer_norm_vector_sum_x_sq = local_var_24_nxt_holder;
}
