#include <flex.h>
bool flex::decode_GB_ATTENTION_CHILD_gb_attention_child_sfm1_rd() {
sc_biguint<1> local_var_1 = 1;
bool local_var_2 = (flex_gb_attention_child_valid_flag == local_var_1);
sc_biguint<5> local_var_4 = 8;
bool local_var_5 = (flex_gb_attention_child_state == local_var_4);
bool local_var_6 = (local_var_2 & local_var_5);
auto& univ_var_555 = local_var_6;
return univ_var_555;
}
void flex::update_GB_ATTENTION_CHILD_gb_attention_child_sfm1_rd() {
sc_biguint<5> local_var_0 = 9;
auto local_var_0_nxt_holder = local_var_0;
sc_biguint<12> local_var_2 = 0;
sc_biguint<3> local_var_3 = 7;
sc_biguint<3> local_var_4 = 0;
bool local_var_5 = (local_var_3 == local_var_4);
sc_biguint<4> local_var_7 = 0;
univ_var_556 = (sc_biguint<16>(flex_gb_core_mem_mngr_small_base_small_0), sc_biguint<4>(local_var_7));
sc_biguint<3> local_var_9 = 1;
bool local_var_10 = (local_var_3 == local_var_9);
sc_biguint<4> local_var_12 = 0;
univ_var_557 = (sc_biguint<16>(flex_gb_core_mem_mngr_small_base_small_1), sc_biguint<4>(local_var_12));
sc_biguint<3> local_var_14 = 2;
bool local_var_15 = (local_var_3 == local_var_14);
sc_biguint<4> local_var_17 = 0;
univ_var_558 = (sc_biguint<16>(flex_gb_core_mem_mngr_small_base_small_2), sc_biguint<4>(local_var_17));
sc_biguint<3> local_var_19 = 3;
bool local_var_20 = (local_var_3 == local_var_19);
sc_biguint<4> local_var_22 = 0;
univ_var_559 = (sc_biguint<16>(flex_gb_core_mem_mngr_small_base_small_3), sc_biguint<4>(local_var_22));
sc_biguint<3> local_var_24 = 4;
bool local_var_25 = (local_var_3 == local_var_24);
sc_biguint<4> local_var_27 = 0;
univ_var_560 = (sc_biguint<16>(flex_gb_core_mem_mngr_small_base_small_4), sc_biguint<4>(local_var_27));
sc_biguint<3> local_var_29 = 5;
bool local_var_30 = (local_var_3 == local_var_29);
sc_biguint<4> local_var_32 = 0;
univ_var_561 = (sc_biguint<16>(flex_gb_core_mem_mngr_small_base_small_5), sc_biguint<4>(local_var_32));
sc_biguint<3> local_var_34 = 6;
bool local_var_35 = (local_var_3 == local_var_34);
sc_biguint<4> local_var_37 = 0;
univ_var_562 = (sc_biguint<16>(flex_gb_core_mem_mngr_small_base_small_6), sc_biguint<4>(local_var_37));
sc_biguint<4> local_var_40 = 0;
univ_var_563 = (sc_biguint<16>(flex_gb_core_mem_mngr_small_base_small_7), sc_biguint<4>(local_var_40));
auto local_var_42 = (local_var_35) ? univ_var_562 : univ_var_563;
auto local_var_43 = (local_var_30) ? univ_var_561 : local_var_42;
auto local_var_44 = (local_var_25) ? univ_var_560 : local_var_43;
auto local_var_45 = (local_var_20) ? univ_var_559 : local_var_44;
auto local_var_46 = (local_var_15) ? univ_var_558 : local_var_45;
auto local_var_47 = (local_var_10) ? univ_var_557 : local_var_46;
auto local_var_48 = (local_var_5) ? univ_var_556 : local_var_47;
univ_var_564 = (sc_biguint<12>(local_var_2), sc_biguint<20>(local_var_48));
sc_biguint<12> local_var_50 = 0;
sc_biguint<16> local_var_52 = 2;
sc_biguint<16> local_var_53 = (GB_ATTENTION_CHILD_gb_attention_timestep_cntr >> local_var_52);
sc_biguint<14> local_var_54 = 0;
univ_var_565 = (sc_biguint<14>(local_var_54), sc_biguint<2>(GB_ATTENTION_CHILD_gb_attention_softmax_cntr));
sc_biguint<16> local_var_57 = (local_var_53 + univ_var_565);
sc_biguint<4> local_var_58 = 0;
univ_var_566 = (sc_biguint<16>(local_var_57), sc_biguint<4>(local_var_58));
univ_var_567 = (sc_biguint<12>(local_var_50), sc_biguint<20>(univ_var_566));
sc_biguint<32> local_var_61 = (univ_var_564 + univ_var_567);
sc_biguint<32> local_var_62 = 0;
sc_biguint<32> local_var_63 = (local_var_61 + local_var_62);
sc_biguint<32> local_var_64 = 3;
sc_biguint<32> local_var_65 = (local_var_63 + local_var_64);
auto local_var_66 = flex_gb_core_small_buffer[local_var_65];
sc_biguint<32> local_var_67 = 2;
sc_biguint<32> local_var_68 = (local_var_63 + local_var_67);
auto local_var_69 = flex_gb_core_small_buffer[local_var_68];
sc_biguint<32> local_var_70 = 1;
sc_biguint<32> local_var_71 = (local_var_63 + local_var_70);
auto local_var_72 = flex_gb_core_small_buffer[local_var_71];
sc_biguint<32> local_var_73 = 0;
sc_biguint<32> local_var_74 = (local_var_63 + local_var_73);
auto local_var_75 = flex_gb_core_small_buffer[local_var_74];
univ_var_568 = (sc_biguint<8>(local_var_72), sc_biguint<8>(local_var_75));
univ_var_569 = (sc_biguint<8>(local_var_69), sc_biguint<16>(univ_var_568));
univ_var_570 = (sc_biguint<8>(local_var_66), sc_biguint<24>(univ_var_569));
auto univ_var_570_nxt_holder = univ_var_570;
sc_biguint<32> local_var_79 = 4;
sc_biguint<32> local_var_80 = (local_var_61 + local_var_79);
sc_biguint<32> local_var_81 = 3;
sc_biguint<32> local_var_82 = (local_var_80 + local_var_81);
auto local_var_83 = flex_gb_core_small_buffer[local_var_82];
sc_biguint<32> local_var_84 = 2;
sc_biguint<32> local_var_85 = (local_var_80 + local_var_84);
auto local_var_86 = flex_gb_core_small_buffer[local_var_85];
sc_biguint<32> local_var_87 = 1;
sc_biguint<32> local_var_88 = (local_var_80 + local_var_87);
auto local_var_89 = flex_gb_core_small_buffer[local_var_88];
sc_biguint<32> local_var_90 = 0;
sc_biguint<32> local_var_91 = (local_var_80 + local_var_90);
auto local_var_92 = flex_gb_core_small_buffer[local_var_91];
univ_var_571 = (sc_biguint<8>(local_var_89), sc_biguint<8>(local_var_92));
univ_var_572 = (sc_biguint<8>(local_var_86), sc_biguint<16>(univ_var_571));
univ_var_573 = (sc_biguint<8>(local_var_83), sc_biguint<24>(univ_var_572));
auto univ_var_573_nxt_holder = univ_var_573;
sc_biguint<32> local_var_96 = 8;
sc_biguint<32> local_var_97 = (local_var_61 + local_var_96);
sc_biguint<32> local_var_98 = 3;
sc_biguint<32> local_var_99 = (local_var_97 + local_var_98);
auto local_var_100 = flex_gb_core_small_buffer[local_var_99];
sc_biguint<32> local_var_101 = 2;
sc_biguint<32> local_var_102 = (local_var_97 + local_var_101);
auto local_var_103 = flex_gb_core_small_buffer[local_var_102];
sc_biguint<32> local_var_104 = 1;
sc_biguint<32> local_var_105 = (local_var_97 + local_var_104);
auto local_var_106 = flex_gb_core_small_buffer[local_var_105];
sc_biguint<32> local_var_107 = 0;
sc_biguint<32> local_var_108 = (local_var_97 + local_var_107);
auto local_var_109 = flex_gb_core_small_buffer[local_var_108];
univ_var_574 = (sc_biguint<8>(local_var_106), sc_biguint<8>(local_var_109));
univ_var_575 = (sc_biguint<8>(local_var_103), sc_biguint<16>(univ_var_574));
univ_var_576 = (sc_biguint<8>(local_var_100), sc_biguint<24>(univ_var_575));
auto univ_var_576_nxt_holder = univ_var_576;
sc_biguint<32> local_var_113 = 12;
sc_biguint<32> local_var_114 = (local_var_61 + local_var_113);
sc_biguint<32> local_var_115 = 3;
sc_biguint<32> local_var_116 = (local_var_114 + local_var_115);
auto local_var_117 = flex_gb_core_small_buffer[local_var_116];
sc_biguint<32> local_var_118 = 2;
sc_biguint<32> local_var_119 = (local_var_114 + local_var_118);
auto local_var_120 = flex_gb_core_small_buffer[local_var_119];
sc_biguint<32> local_var_121 = 1;
sc_biguint<32> local_var_122 = (local_var_114 + local_var_121);
auto local_var_123 = flex_gb_core_small_buffer[local_var_122];
sc_biguint<32> local_var_124 = 0;
sc_biguint<32> local_var_125 = (local_var_114 + local_var_124);
auto local_var_126 = flex_gb_core_small_buffer[local_var_125];
univ_var_577 = (sc_biguint<8>(local_var_123), sc_biguint<8>(local_var_126));
univ_var_578 = (sc_biguint<8>(local_var_120), sc_biguint<16>(univ_var_577));
univ_var_579 = (sc_biguint<8>(local_var_117), sc_biguint<24>(univ_var_578));
auto univ_var_579_nxt_holder = univ_var_579;
flex_gb_attention_child_state = local_var_0_nxt_holder;
GB_ATTENTION_CHILD_gb_attention_exp_vector_0 = univ_var_570_nxt_holder;
GB_ATTENTION_CHILD_gb_attention_exp_vector_1 = univ_var_573_nxt_holder;
GB_ATTENTION_CHILD_gb_attention_exp_vector_2 = univ_var_576_nxt_holder;
GB_ATTENTION_CHILD_gb_attention_exp_vector_3 = univ_var_579_nxt_holder;
}