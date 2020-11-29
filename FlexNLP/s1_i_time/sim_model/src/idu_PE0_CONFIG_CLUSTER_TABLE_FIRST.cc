#include <flex.h>
bool flex::decode_flex_PE0_CONFIG_CLUSTER_TABLE_FIRST() {
sc_biguint<1> local_var_2 = ~flex_if_axi_rd;
sc_biguint<1> local_var_3 = (flex_if_axi_wr & local_var_2);
sc_biguint<1> local_var_4 = 1;
bool local_var_5 = (local_var_3 == local_var_4);
sc_biguint<32> local_var_7 = 876609584;
bool local_var_8 = (flex_addr_in == local_var_7);
bool local_var_9 = (local_var_5 & local_var_8);
auto& univ_var_804 = local_var_9;
return univ_var_804;
}
void flex::update_flex_PE0_CONFIG_CLUSTER_TABLE_FIRST() {
auto flex_data_in_0_nxt_holder = flex_data_in_0;
auto flex_data_in_1_nxt_holder = flex_data_in_1;
auto flex_data_in_10_nxt_holder = flex_data_in_10;
auto flex_data_in_11_nxt_holder = flex_data_in_11;
auto flex_data_in_12_nxt_holder = flex_data_in_12;
auto flex_data_in_13_nxt_holder = flex_data_in_13;
auto flex_data_in_14_nxt_holder = flex_data_in_14;
auto flex_data_in_15_nxt_holder = flex_data_in_15;
auto flex_data_in_2_nxt_holder = flex_data_in_2;
auto flex_data_in_3_nxt_holder = flex_data_in_3;
auto flex_data_in_4_nxt_holder = flex_data_in_4;
auto flex_data_in_5_nxt_holder = flex_data_in_5;
auto flex_data_in_6_nxt_holder = flex_data_in_6;
auto flex_data_in_7_nxt_holder = flex_data_in_7;
auto flex_data_in_8_nxt_holder = flex_data_in_8;
auto flex_data_in_9_nxt_holder = flex_data_in_9;
flex_pe0_cluster_table_first_Entry0 = flex_data_in_0_nxt_holder;
flex_pe0_cluster_table_first_Entry1 = flex_data_in_1_nxt_holder;
flex_pe0_cluster_table_first_Entry10 = flex_data_in_10_nxt_holder;
flex_pe0_cluster_table_first_Entry11 = flex_data_in_11_nxt_holder;
flex_pe0_cluster_table_first_Entry12 = flex_data_in_12_nxt_holder;
flex_pe0_cluster_table_first_Entry13 = flex_data_in_13_nxt_holder;
flex_pe0_cluster_table_first_Entry14 = flex_data_in_14_nxt_holder;
flex_pe0_cluster_table_first_Entry15 = flex_data_in_15_nxt_holder;
flex_pe0_cluster_table_first_Entry2 = flex_data_in_2_nxt_holder;
flex_pe0_cluster_table_first_Entry3 = flex_data_in_3_nxt_holder;
flex_pe0_cluster_table_first_Entry4 = flex_data_in_4_nxt_holder;
flex_pe0_cluster_table_first_Entry5 = flex_data_in_5_nxt_holder;
flex_pe0_cluster_table_first_Entry6 = flex_data_in_6_nxt_holder;
flex_pe0_cluster_table_first_Entry7 = flex_data_in_7_nxt_holder;
flex_pe0_cluster_table_first_Entry8 = flex_data_in_8_nxt_holder;
flex_pe0_cluster_table_first_Entry9 = flex_data_in_9_nxt_holder;
}
