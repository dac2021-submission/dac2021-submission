#include <flex.h>
bool flex::decode_Child_GBLayerNorm_gb_layer_norm_norm_vector_prep() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_gb_layer_norm_child_valid_flag == local_var_1);
sc_biguint<4> local_var_4 = 4;
bool local_var_5 = (flex_gb_layer_norm_child_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
auto& univ_var_733 = local_var_6;
return univ_var_733;
}
void flex::update_Child_GBLayerNorm_gb_layer_norm_norm_vector_prep() {
bool local_var_2 = (Child_GBLayerNorm_gb_layer_norm_cntr_vector == flex_gb_layer_norm_num_vector_1);
bool local_var_3 = (Child_GBLayerNorm_gb_layer_norm_cntr_vector > flex_gb_layer_norm_num_vector_1);
bool local_var_4 = (local_var_2 | local_var_3);
sc_biguint<4> local_var_5 = 6;
sc_biguint<4> local_var_6 = 5;
auto local_var_7 = (local_var_4) ? local_var_5 : local_var_6;
auto local_var_7_nxt_holder = local_var_7;
sc_biguint<5> local_var_8 = 0;
auto local_var_8_nxt_holder = local_var_8;
sc_biguint<8> local_var_9 = 1;
sc_biguint<8> local_var_10 = (Child_GBLayerNorm_gb_layer_norm_cntr_vector + local_var_9);
auto local_var_10_nxt_holder = local_var_10;
sc_biguint<12> local_var_12 = 0;
univ_var_734 = (sc_biguint<12>(local_var_12), sc_biguint<8>(Child_GBLayerNorm_gb_layer_norm_cntr_vector));
sc_biguint<20> local_var_14 = 256;
sc_biguint<20> local_var_15 = (univ_var_734 * local_var_14);
sc_biguint<20> local_var_16 = (Child_GBLayerNorm_gb_layer_norm_timestep_level_base_addr + local_var_15);
auto local_var_16_nxt_holder = local_var_16;
sc_biguint<4> local_var_17 = 0;
univ_var_735 = (sc_biguint<4>(local_var_17), sc_biguint<16>(flex_gb_core_mem_mngr_small_base_small_6));
sc_biguint<20> local_var_20 = 4;
sc_biguint<20> local_var_21 = (univ_var_735 << local_var_20);
sc_biguint<20> local_var_22 = 16;
sc_biguint<20> local_var_23 = (univ_var_734 * local_var_22);
sc_biguint<20> local_var_24 = (local_var_21 + local_var_23);
auto local_var_24_nxt_holder = local_var_24;
sc_biguint<4> local_var_26 = 0;
univ_var_736 = (sc_biguint<16>(flex_gb_core_mem_mngr_small_base_small_5), sc_biguint<4>(local_var_26));
sc_biguint<20> local_var_28 = 16;
sc_biguint<20> local_var_29 = (univ_var_734 * local_var_28);
sc_biguint<20> local_var_30 = (univ_var_736 + local_var_29);
auto local_var_30_nxt_holder = local_var_30;
flex_gb_layer_norm_child_state = local_var_7_nxt_holder;
Child_GBLayerNorm_gb_layer_norm_cntr_byte = local_var_8_nxt_holder;
Child_GBLayerNorm_gb_layer_norm_cntr_vector = local_var_10_nxt_holder;
Child_GBLayerNorm_gb_layer_norm_vector_base_addr = local_var_16_nxt_holder;
Child_GBLayerNorm_gb_layer_norm_vector_level_base_addr_beta = local_var_24_nxt_holder;
Child_GBLayerNorm_gb_layer_norm_vector_level_base_addr_gamma = local_var_30_nxt_holder;
}
