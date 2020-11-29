#include <iomanip>
#include <flex.h>
#define ILATOR_VERBOSE_PARENT
static int instr_cntr = 0;
void flex::LogInstrSequence(const std::string& instr_name) {
  instr_log << "Instr No." << std::setw(5) << instr_cntr << '\t';
  instr_log << instr_name << " is activated\n";
  instr_cntr++;
}
static bool g_initialized = false;
void flex::compute() {
if (!g_initialized) {
  setup_initial_condition();
  g_initialized = true;
}
#ifdef RUN_TANDEM
e_inst = NO_INST;
#endif
// std::cout << "compute" << std::endl;
// flex_if_axi_wr = flex_if_axi_wr_in.read();
// flex_if_axi_rd = flex_if_axi_rd_in.read();
// flex_addr_in = flex_addr_in_in.read();
// flex_data_in_0 = flex_data_in_0_in.read();
// flex_data_in_1 = flex_data_in_1_in.read();
// flex_data_in_2 = flex_data_in_2_in.read();
// flex_data_in_3 = flex_data_in_3_in.read();
// flex_data_in_4 = flex_data_in_4_in.read();
// flex_data_in_5 = flex_data_in_5_in.read();
// flex_data_in_6 = flex_data_in_6_in.read();
// flex_data_in_7 = flex_data_in_7_in.read();
// flex_data_in_8 = flex_data_in_8_in.read();
// flex_data_in_9 = flex_data_in_9_in.read();
// flex_data_in_10 = flex_data_in_10_in.read();
// flex_data_in_11 = flex_data_in_11_in.read();
// flex_data_in_12 = flex_data_in_12_in.read();
// flex_data_in_13 = flex_data_in_13_in.read();
// flex_data_in_14 = flex_data_in_14_in.read();
// flex_data_in_15 = flex_data_in_15_in.read();
// std::cout << "wr: " << flex_if_axi_wr << std::endl;
// std::cout << "rd: " << flex_if_axi_rd << std::endl;
// std::cout << "flex_addr_in: " << flex_addr_in << std::endl;

if (decode_flex_CONFIG_GB_ATTENTION()) {
  update_flex_CONFIG_GB_ATTENTION();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("CONFIG_GB_ATTENTION");
#endif
  #ifdef RUN_TANDEM
  e_inst = CONFIG_GB_ATTENTION;
  #endif
}
if (decode_flex_CONFIG_GB_CONTROL()) {
  update_flex_CONFIG_GB_CONTROL();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("CONFIG_GB_CONTROL");
#endif
  #ifdef RUN_TANDEM
  e_inst = CONFIG_GB_CONTROL;
  #endif
}
if (decode_flex_CONFIG_GB_CORE_MEM_MNGR_LARGE()) {
  update_flex_CONFIG_GB_CORE_MEM_MNGR_LARGE();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("CONFIG_GB_CORE_MEM_MNGR_LARGE");
#endif
  #ifdef RUN_TANDEM
  e_inst = CONFIG_GB_CORE_MEM_MNGR_LARGE;
  #endif
}
if (decode_flex_CONFIG_GB_CORE_MEM_MNGR_SMALL()) {
  update_flex_CONFIG_GB_CORE_MEM_MNGR_SMALL();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("CONFIG_GB_CORE_MEM_MNGR_SMALL");
#endif
  #ifdef RUN_TANDEM
  e_inst = CONFIG_GB_CORE_MEM_MNGR_SMALL;
  #endif
}
if (decode_flex_CONFIG_GB_LAYER_NORM()) {
  update_flex_CONFIG_GB_LAYER_NORM();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("CONFIG_GB_LAYER_NORM");
#endif
  #ifdef RUN_TANDEM
  e_inst = CONFIG_GB_LAYER_NORM;
  #endif
}
if (decode_flex_CONFIG_GB_LAYER_REDUCE()) {
  update_flex_CONFIG_GB_LAYER_REDUCE();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("CONFIG_GB_LAYER_REDUCE");
#endif
  #ifdef RUN_TANDEM
  e_inst = CONFIG_GB_LAYER_REDUCE;
  #endif
}
if (decode_flex_CONFIG_GB_ZERO_PADDING()) {
  update_flex_CONFIG_GB_ZERO_PADDING();
  #ifdef ILATOR_VERBOSE
  LogInstrSequence("CONFIG_GB_ZERO_PADDING");
#endif
  #ifdef RUN_TANDEM
  e_inst = CONFIG_GB_ZERO_PADDING;
  #endif
}
if (decode_flex_PE0_CONFIG_ACT_MNGR()) {
  update_flex_PE0_CONFIG_ACT_MNGR();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE0_CONFIG_ACT_MNGR");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE0_CONFIG_ACT_MNGR;
  #endif
}
if (decode_flex_PE0_CONFIG_ACT_VECTOR_0_15()) {
  update_flex_PE0_CONFIG_ACT_VECTOR_0_15();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE0_CONFIG_ACT_VECTOR_0_15");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE0_CONFIG_ACT_VECTOR_0_15;
  #endif
}
if (decode_flex_PE0_CONFIG_ACT_VECTOR_16_31()) {
  update_flex_PE0_CONFIG_ACT_VECTOR_16_31();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE0_CONFIG_ACT_VECTOR_16_31");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE0_CONFIG_ACT_VECTOR_16_31;
  #endif
}
if (decode_flex_PE0_CONFIG_CLUSTER_TABLE_FIRST()) {
  update_flex_PE0_CONFIG_CLUSTER_TABLE_FIRST();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE0_CONFIG_CLUSTER_TABLE_FIRST");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE0_CONFIG_CLUSTER_TABLE_FIRST;
  #endif
}
if (decode_flex_PE0_CONFIG_CLUSTER_TABLE_SECOND()) {
  update_flex_PE0_CONFIG_CLUSTER_TABLE_SECOND();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE0_CONFIG_CLUSTER_TABLE_SECOND");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE0_CONFIG_CLUSTER_TABLE_SECOND;
  #endif
}
if (decode_flex_PE0_CONFIG_MEM_MNGR_FIRST()) {
  update_flex_PE0_CONFIG_MEM_MNGR_FIRST();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE0_CONFIG_MEM_MNGR_FIRST");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE0_CONFIG_MEM_MNGR_FIRST;
  #endif
}
if (decode_flex_PE0_CONFIG_MEM_MNGR_SECOND()) {
  update_flex_PE0_CONFIG_MEM_MNGR_SECOND();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE0_CONFIG_MEM_MNGR_SECOND");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE0_CONFIG_MEM_MNGR_SECOND;
  #endif
}
if (decode_flex_PE0_CONFIG_RNN_LAYER_SIZING()) {
  update_flex_PE0_CONFIG_RNN_LAYER_SIZING();
  #ifdef ILATOR_VERBOSE_PARENT
  // instr_log << "is_valid: " << flex_pe0_rnn_layer_sizing_is_valid << "\n";
  // instr_log << "is_zero_first: " << flex_pe0_rnn_layer_sizing_is_zero_first << "\n";
  // instr_log << "is_cluster: " <<  flex_pe0_rnn_layer_sizing_is_cluster << "\n";  
  LogInstrSequence("PE0_CONFIG_RNN_LAYER_SIZING");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE0_CONFIG_RNN_LAYER_SIZING;
  #endif
}
if (decode_flex_PE1_CONFIG_ACT_MNGR()) {
  update_flex_PE1_CONFIG_ACT_MNGR();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE1_CONFIG_ACT_MNGR");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE1_CONFIG_ACT_MNGR;
  #endif
}
if (decode_flex_PE1_CONFIG_ACT_VECTOR_0_15()) {
  update_flex_PE1_CONFIG_ACT_VECTOR_0_15();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE1_CONFIG_ACT_VECTOR_0_15");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE1_CONFIG_ACT_VECTOR_0_15;
  #endif
}
if (decode_flex_PE1_CONFIG_ACT_VECTOR_16_31()) {
  update_flex_PE1_CONFIG_ACT_VECTOR_16_31();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE1_CONFIG_ACT_VECTOR_16_31");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE1_CONFIG_ACT_VECTOR_16_31;
  #endif
}
if (decode_flex_PE1_CONFIG_CLUSTER_TABLE_FIRST()) {
  update_flex_PE1_CONFIG_CLUSTER_TABLE_FIRST();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE1_CONFIG_CLUSTER_TABLE_FIRST");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE1_CONFIG_CLUSTER_TABLE_FIRST;
  #endif
}
if (decode_flex_PE1_CONFIG_CLUSTER_TABLE_SECOND()) {
  update_flex_PE1_CONFIG_CLUSTER_TABLE_SECOND();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE1_CONFIG_CLUSTER_TABLE_SECOND");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE1_CONFIG_CLUSTER_TABLE_SECOND;
  #endif
}
if (decode_flex_PE1_CONFIG_MEM_MNGR_FIRST()) {
  update_flex_PE1_CONFIG_MEM_MNGR_FIRST();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE1_CONFIG_MEM_MNGR_FIRST");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE1_CONFIG_MEM_MNGR_FIRST;
  #endif
}
if (decode_flex_PE1_CONFIG_MEM_MNGR_SECOND()) {
  update_flex_PE1_CONFIG_MEM_MNGR_SECOND();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE1_CONFIG_MEM_MNGR_SECOND");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE1_CONFIG_MEM_MNGR_SECOND;
  #endif
}
if (decode_flex_PE1_CONFIG_RNN_LAYER_SIZING()) {
  update_flex_PE1_CONFIG_RNN_LAYER_SIZING();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE1_CONFIG_RNN_LAYER_SIZING");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE1_CONFIG_RNN_LAYER_SIZING;
  #endif
}
if (decode_flex_PE2_CONFIG_ACT_MNGR()) {
  update_flex_PE2_CONFIG_ACT_MNGR();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE2_CONFIG_ACT_MNGR");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE2_CONFIG_ACT_MNGR;
  #endif
}
if (decode_flex_PE2_CONFIG_ACT_VECTOR_0_15()) {
  update_flex_PE2_CONFIG_ACT_VECTOR_0_15();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE2_CONFIG_ACT_VECTOR_0_15");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE2_CONFIG_ACT_VECTOR_0_15;
  #endif
}
if (decode_flex_PE2_CONFIG_ACT_VECTOR_16_31()) {
  update_flex_PE2_CONFIG_ACT_VECTOR_16_31();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE2_CONFIG_ACT_VECTOR_16_31");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE2_CONFIG_ACT_VECTOR_16_31;
  #endif
}
if (decode_flex_PE2_CONFIG_CLUSTER_TABLE_FIRST()) {
  update_flex_PE2_CONFIG_CLUSTER_TABLE_FIRST();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE2_CONFIG_CLUSTER_TABLE_FIRST");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE2_CONFIG_CLUSTER_TABLE_FIRST;
  #endif
}
if (decode_flex_PE2_CONFIG_CLUSTER_TABLE_SECOND()) {
  update_flex_PE2_CONFIG_CLUSTER_TABLE_SECOND();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE2_CONFIG_CLUSTER_TABLE_SECOND");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE2_CONFIG_CLUSTER_TABLE_SECOND;
  #endif
}
if (decode_flex_PE2_CONFIG_MEM_MNGR_FIRST()) {
  update_flex_PE2_CONFIG_MEM_MNGR_FIRST();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE2_CONFIG_MEM_MNGR_FIRST");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE2_CONFIG_MEM_MNGR_FIRST;
  #endif
}
if (decode_flex_PE2_CONFIG_MEM_MNGR_SECOND()) {
  update_flex_PE2_CONFIG_MEM_MNGR_SECOND();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE2_CONFIG_MEM_MNGR_SECOND");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE2_CONFIG_MEM_MNGR_SECOND;
  #endif
}
if (decode_flex_PE2_CONFIG_RNN_LAYER_SIZING()) {
  update_flex_PE2_CONFIG_RNN_LAYER_SIZING();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE2_CONFIG_RNN_LAYER_SIZING");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE2_CONFIG_RNN_LAYER_SIZING;
  #endif
}
if (decode_flex_PE3_CONFIG_ACT_MNGR()) {
  update_flex_PE3_CONFIG_ACT_MNGR();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE3_CONFIG_ACT_MNGR");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE3_CONFIG_ACT_MNGR;
  #endif
}
if (decode_flex_PE3_CONFIG_ACT_VECTOR_0_15()) {
  update_flex_PE3_CONFIG_ACT_VECTOR_0_15();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE3_CONFIG_ACT_VECTOR_0_15");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE3_CONFIG_ACT_VECTOR_0_15;
  #endif
}
if (decode_flex_PE3_CONFIG_ACT_VECTOR_16_31()) {
  update_flex_PE3_CONFIG_ACT_VECTOR_16_31();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE3_CONFIG_ACT_VECTOR_16_31");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE3_CONFIG_ACT_VECTOR_16_31;
  #endif
}
if (decode_flex_PE3_CONFIG_CLUSTER_TABLE_FIRST()) {
  update_flex_PE3_CONFIG_CLUSTER_TABLE_FIRST();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE3_CONFIG_CLUSTER_TABLE_FIRST");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE3_CONFIG_CLUSTER_TABLE_FIRST;
  #endif
}
if (decode_flex_PE3_CONFIG_CLUSTER_TABLE_SECOND()) {
  update_flex_PE3_CONFIG_CLUSTER_TABLE_SECOND();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE3_CONFIG_CLUSTER_TABLE_SECOND");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE3_CONFIG_CLUSTER_TABLE_SECOND;
  #endif
}
if (decode_flex_PE3_CONFIG_MEM_MNGR_FIRST()) {
  update_flex_PE3_CONFIG_MEM_MNGR_FIRST();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE3_CONFIG_MEM_MNGR_FIRST");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE3_CONFIG_MEM_MNGR_FIRST;
  #endif
}
if (decode_flex_PE3_CONFIG_MEM_MNGR_SECOND()) {
  update_flex_PE3_CONFIG_MEM_MNGR_SECOND();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE3_CONFIG_MEM_MNGR_SECOND");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE3_CONFIG_MEM_MNGR_SECOND;
  #endif
}
if (decode_flex_PE3_CONFIG_RNN_LAYER_SIZING()) {
  update_flex_PE3_CONFIG_RNN_LAYER_SIZING();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE3_CONFIG_RNN_LAYER_SIZING");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE3_CONFIG_RNN_LAYER_SIZING;
  #endif
}
if (decode_flex_GB_CORE_STORE_LARGE()) {
  update_flex_GB_CORE_STORE_LARGE();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("GB_CORE_STORE_LARGE");
#endif
  #ifdef RUN_TANDEM
  e_inst = GB_CORE_STORE_LARGE;
  #endif
}
if (decode_flex_GB_CORE_STORE_SMALL()) {
  update_flex_GB_CORE_STORE_SMALL();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("GB_CORE_STORE_SMALL");
#endif
  #ifdef RUN_TANDEM
  e_inst = GB_CORE_STORE_SMALL;
  #endif
}
if (decode_flex_PE0_CORE_STORE_WEIGHT_BUFFER()) {
  update_flex_PE0_CORE_STORE_WEIGHT_BUFFER();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE0_CORE_STORE_WEIGHT_BUFFER");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE0_CORE_STORE_WEIGHT_BUFFER;
  #endif
}
if (decode_flex_PE0_CORE_STORE_INPUT_BUFFER()) {
  update_flex_PE0_CORE_STORE_INPUT_BUFFER();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE0_CORE_STORE_INPUT_BUFFER");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE0_CORE_STORE_INPUT_BUFFER;
  #endif
}
if (decode_flex_PE0_ACT_STORE_BUFFER()) {
  update_flex_PE0_ACT_STORE_BUFFER();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE0_ACT_STORE_BUFFER");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE0_ACT_STORE_BUFFER;
  #endif
}
if (decode_flex_PE1_CORE_STORE_WEIGHT_BUFFER()) {
  update_flex_PE1_CORE_STORE_WEIGHT_BUFFER();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE1_CORE_STORE_WEIGHT_BUFFER");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE1_CORE_STORE_WEIGHT_BUFFER;
  #endif
}
if (decode_flex_PE1_CORE_STORE_INPUT_BUFFER()) {
  update_flex_PE1_CORE_STORE_INPUT_BUFFER();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE1_CORE_STORE_INPUT_BUFFER");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE1_CORE_STORE_INPUT_BUFFER;
  #endif
}
if (decode_flex_PE1_ACT_STORE_BUFFER()) {
  update_flex_PE1_ACT_STORE_BUFFER();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE1_ACT_STORE_BUFFER");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE1_ACT_STORE_BUFFER;
  #endif
}
if (decode_flex_PE2_CORE_STORE_WEIGHT_BUFFER()) {
  update_flex_PE2_CORE_STORE_WEIGHT_BUFFER();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE2_CORE_STORE_WEIGHT_BUFFER");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE2_CORE_STORE_WEIGHT_BUFFER;
  #endif
}
if (decode_flex_PE2_CORE_STORE_INPUT_BUFFER()) {
  update_flex_PE2_CORE_STORE_INPUT_BUFFER();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE2_CORE_STORE_INPUT_BUFFER");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE2_CORE_STORE_INPUT_BUFFER;
  #endif
}
if (decode_flex_PE2_ACT_STORE_BUFFER()) {
  update_flex_PE2_ACT_STORE_BUFFER();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE2_ACT_STORE_BUFFER");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE2_ACT_STORE_BUFFER;
  #endif
}
if (decode_flex_PE3_CORE_STORE_WEIGHT_BUFFER()) {
  update_flex_PE3_CORE_STORE_WEIGHT_BUFFER();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE3_CORE_STORE_WEIGHT_BUFFER");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE3_CORE_STORE_WEIGHT_BUFFER;
  #endif
}
if (decode_flex_PE3_CORE_STORE_INPUT_BUFFER()) {
  update_flex_PE3_CORE_STORE_INPUT_BUFFER();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE3_CORE_STORE_INPUT_BUFFER");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE3_CORE_STORE_INPUT_BUFFER;
  #endif
}
if (decode_flex_PE3_ACT_STORE_BUFFER()) {
  update_flex_PE3_ACT_STORE_BUFFER();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("PE3_ACT_STORE_BUFFER");
#endif
  #ifdef RUN_TANDEM
  e_inst = PE3_ACT_STORE_BUFFER;
  #endif
}
if (decode_flex_GB_ATTENTION_START()) {
  update_flex_GB_ATTENTION_START();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("GB_ATTENTION_START");
#endif
  #ifdef RUN_TANDEM
  e_inst = GB_ATTENTION_START;
  #endif
}
if (decode_flex_GB_CONTROL_START()) {
  update_flex_GB_CONTROL_START();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("GB_CONTROL_START");
#endif
  #ifdef RUN_TANDEM
  e_inst = GB_CONTROL_START;
  #endif
}
if (decode_flex_GB_LAYER_NORM_START()) {
  update_flex_GB_LAYER_NORM_START();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("GB_LAYER_NORM_START");
#endif
  #ifdef RUN_TANDEM
  e_inst = GB_LAYER_NORM_START;
  #endif
}
if (decode_flex_GB_LAYER_REDUCE_START()) {
  update_flex_GB_LAYER_REDUCE_START();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("GB_LAYER_REDUCE_START");
#endif
  #ifdef RUN_TANDEM
  e_inst = GB_LAYER_REDUCE_START;
  #endif
}
if (decode_flex_GB_ZEROPADDING_START()) {
  update_flex_GB_ZEROPADDING_START();
  #ifdef ILATOR_VERBOSE_PARENT
  LogInstrSequence("GB_ZEROPADDING_START");
#endif
  #ifdef RUN_TANDEM
  e_inst = GB_ZEROPADDING_START;
  #endif
}
while (1) {
  int schedule_counter = 0;
if (decode_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_data_nc()) {
  update_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_data_nc();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_run_mac_data_nc");
#endif
}
if (decode_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_data_c()) {
  update_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_data_c();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_run_mac_data_c");
#endif
}
if (decode_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_mul()) {
  update_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_mul();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_run_mac_mul");
#endif
}
if (decode_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_0()) {
  update_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_0();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_run_mac_out_0");
#endif
}
if (decode_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_1()) {
  update_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_1();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_run_mac_out_1");
#endif
}
if (decode_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_2()) {
  update_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_2();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_run_mac_out_2");
#endif
}
if (decode_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_3()) {
  update_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_3();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_run_mac_out_3");
#endif
}
if (decode_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_4()) {
  update_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_4();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_run_mac_out_4");
#endif
}
if (decode_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_5()) {
  update_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_5();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_run_mac_out_5");
#endif
}
if (decode_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_6()) {
  update_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_6();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_run_mac_out_6");
#endif
}
if (decode_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_7()) {
  update_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_7();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_run_mac_out_7");
#endif
}
if (decode_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_8()) {
  update_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_8();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_run_mac_out_8");
#endif
}
if (decode_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_9()) {
  update_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_9();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_run_mac_out_9");
#endif
}
if (decode_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_10()) {
  update_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_10();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_run_mac_out_10");
#endif
}
if (decode_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_11()) {
  update_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_11();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_run_mac_out_11");
#endif
}
if (decode_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_12()) {
  update_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_12();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_run_mac_out_12");
#endif
}
if (decode_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_13()) {
  update_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_13();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_run_mac_out_13");
#endif
}
if (decode_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_14()) {
  update_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_14();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_run_mac_out_14");
#endif
}
if (decode_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_15()) {
  update_PE0_CORE_RUN_MAC_CHILD_PE0_core_run_mac_out_15();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_run_mac_out_15");
#endif
}
if (decode_PE0_CORE_CHILD_PE0_core_read_gb()) {
  update_PE0_CORE_CHILD_PE0_core_read_gb();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_read_gb");
#endif
}
if (decode_PE0_CORE_CHILD_PE0_core_is_start()) {
  update_PE0_CORE_CHILD_PE0_core_is_start();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_is_start");
#endif
}
if (decode_PE0_CORE_CHILD_PE0_core_prep()) {
  update_PE0_CORE_CHILD_PE0_core_prep();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_prep");
#endif
}
if (decode_PE0_CORE_CHILD_PE0_core_mac()) {
  update_PE0_CORE_CHILD_PE0_core_mac();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_mac");
#endif
}
if (decode_PE0_CORE_CHILD_PE0_core_bias()) {
  update_PE0_CORE_CHILD_PE0_core_bias();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_bias");
#endif
}
if (decode_PE0_CORE_CHILD_PE0_core_out()) {
  update_PE0_CORE_CHILD_PE0_core_out();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_core_out");
#endif
}
if (decode_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_data_nc()) {
  update_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_data_nc();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_run_mac_data_nc");
#endif
}
if (decode_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_data_c()) {
  update_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_data_c();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_run_mac_data_c");
#endif
}
if (decode_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_mul()) {
  update_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_mul();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_run_mac_mul");
#endif
}
if (decode_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_0()) {
  update_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_0();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_run_mac_out_0");
#endif
}
if (decode_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_1()) {
  update_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_1();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_run_mac_out_1");
#endif
}
if (decode_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_2()) {
  update_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_2();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_run_mac_out_2");
#endif
}
if (decode_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_3()) {
  update_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_3();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_run_mac_out_3");
#endif
}
if (decode_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_4()) {
  update_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_4();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_run_mac_out_4");
#endif
}
if (decode_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_5()) {
  update_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_5();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_run_mac_out_5");
#endif
}
if (decode_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_6()) {
  update_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_6();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_run_mac_out_6");
#endif
}
if (decode_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_7()) {
  update_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_7();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_run_mac_out_7");
#endif
}
if (decode_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_8()) {
  update_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_8();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_run_mac_out_8");
#endif
}
if (decode_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_9()) {
  update_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_9();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_run_mac_out_9");
#endif
}
if (decode_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_10()) {
  update_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_10();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_run_mac_out_10");
#endif
}
if (decode_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_11()) {
  update_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_11();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_run_mac_out_11");
#endif
}
if (decode_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_12()) {
  update_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_12();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_run_mac_out_12");
#endif
}
if (decode_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_13()) {
  update_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_13();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_run_mac_out_13");
#endif
}
if (decode_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_14()) {
  update_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_14();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_run_mac_out_14");
#endif
}
if (decode_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_15()) {
  update_PE1_CORE_RUN_MAC_CHILD_PE1_core_run_mac_out_15();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_run_mac_out_15");
#endif
}
if (decode_PE1_CORE_CHILD_PE1_core_read_gb()) {
  update_PE1_CORE_CHILD_PE1_core_read_gb();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_read_gb");
#endif
}
if (decode_PE1_CORE_CHILD_PE1_core_is_start()) {
  update_PE1_CORE_CHILD_PE1_core_is_start();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_is_start");
#endif
}
if (decode_PE1_CORE_CHILD_PE1_core_prep()) {
  update_PE1_CORE_CHILD_PE1_core_prep();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_prep");
#endif
}
if (decode_PE1_CORE_CHILD_PE1_core_mac()) {
  update_PE1_CORE_CHILD_PE1_core_mac();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_mac");
#endif
}
if (decode_PE1_CORE_CHILD_PE1_core_bias()) {
  update_PE1_CORE_CHILD_PE1_core_bias();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_bias");
#endif
}
if (decode_PE1_CORE_CHILD_PE1_core_out()) {
  update_PE1_CORE_CHILD_PE1_core_out();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_core_out");
#endif
}
if (decode_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_data_nc()) {
  update_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_data_nc();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_run_mac_data_nc");
#endif
}
if (decode_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_data_c()) {
  update_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_data_c();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_run_mac_data_c");
#endif
}
if (decode_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_mul()) {
  update_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_mul();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_run_mac_mul");
#endif
}
if (decode_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_0()) {
  update_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_0();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_run_mac_out_0");
#endif
}
if (decode_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_1()) {
  update_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_1();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_run_mac_out_1");
#endif
}
if (decode_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_2()) {
  update_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_2();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_run_mac_out_2");
#endif
}
if (decode_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_3()) {
  update_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_3();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_run_mac_out_3");
#endif
}
if (decode_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_4()) {
  update_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_4();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_run_mac_out_4");
#endif
}
if (decode_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_5()) {
  update_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_5();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_run_mac_out_5");
#endif
}
if (decode_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_6()) {
  update_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_6();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_run_mac_out_6");
#endif
}
if (decode_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_7()) {
  update_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_7();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_run_mac_out_7");
#endif
}
if (decode_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_8()) {
  update_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_8();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_run_mac_out_8");
#endif
}
if (decode_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_9()) {
  update_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_9();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_run_mac_out_9");
#endif
}
if (decode_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_10()) {
  update_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_10();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_run_mac_out_10");
#endif
}
if (decode_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_11()) {
  update_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_11();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_run_mac_out_11");
#endif
}
if (decode_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_12()) {
  update_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_12();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_run_mac_out_12");
#endif
}
if (decode_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_13()) {
  update_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_13();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_run_mac_out_13");
#endif
}
if (decode_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_14()) {
  update_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_14();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_run_mac_out_14");
#endif
}
if (decode_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_15()) {
  update_PE2_CORE_RUN_MAC_CHILD_PE2_core_run_mac_out_15();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_run_mac_out_15");
#endif
}
if (decode_PE2_CORE_CHILD_PE2_core_read_gb()) {
  update_PE2_CORE_CHILD_PE2_core_read_gb();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_read_gb");
#endif
}
if (decode_PE2_CORE_CHILD_PE2_core_is_start()) {
  update_PE2_CORE_CHILD_PE2_core_is_start();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_is_start");
#endif
}
if (decode_PE2_CORE_CHILD_PE2_core_prep()) {
  update_PE2_CORE_CHILD_PE2_core_prep();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_prep");
#endif
}
if (decode_PE2_CORE_CHILD_PE2_core_mac()) {
  update_PE2_CORE_CHILD_PE2_core_mac();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_mac");
#endif
}
if (decode_PE2_CORE_CHILD_PE2_core_bias()) {
  update_PE2_CORE_CHILD_PE2_core_bias();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_bias");
#endif
}
if (decode_PE2_CORE_CHILD_PE2_core_out()) {
  update_PE2_CORE_CHILD_PE2_core_out();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_core_out");
#endif
}
if (decode_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_data_nc()) {
  update_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_data_nc();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_run_mac_data_nc");
#endif
}
if (decode_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_data_c()) {
  update_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_data_c();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_run_mac_data_c");
#endif
}
if (decode_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_mul()) {
  update_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_mul();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_run_mac_mul");
#endif
}
if (decode_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_0()) {
  update_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_0();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_run_mac_out_0");
#endif
}
if (decode_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_1()) {
  update_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_1();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_run_mac_out_1");
#endif
}
if (decode_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_2()) {
  update_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_2();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_run_mac_out_2");
#endif
}
if (decode_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_3()) {
  update_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_3();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_run_mac_out_3");
#endif
}
if (decode_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_4()) {
  update_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_4();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_run_mac_out_4");
#endif
}
if (decode_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_5()) {
  update_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_5();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_run_mac_out_5");
#endif
}
if (decode_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_6()) {
  update_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_6();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_run_mac_out_6");
#endif
}
if (decode_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_7()) {
  update_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_7();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_run_mac_out_7");
#endif
}
if (decode_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_8()) {
  update_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_8();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_run_mac_out_8");
#endif
}
if (decode_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_9()) {
  update_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_9();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_run_mac_out_9");
#endif
}
if (decode_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_10()) {
  update_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_10();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_run_mac_out_10");
#endif
}
if (decode_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_11()) {
  update_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_11();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_run_mac_out_11");
#endif
}
if (decode_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_12()) {
  update_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_12();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_run_mac_out_12");
#endif
}
if (decode_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_13()) {
  update_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_13();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_run_mac_out_13");
#endif
}
if (decode_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_14()) {
  update_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_14();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_run_mac_out_14");
#endif
}
if (decode_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_15()) {
  update_PE3_CORE_RUN_MAC_CHILD_PE3_core_run_mac_out_15();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_run_mac_out_15");
#endif
}
if (decode_PE3_CORE_CHILD_PE3_core_read_gb()) {
  update_PE3_CORE_CHILD_PE3_core_read_gb();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_read_gb");
#endif
}
if (decode_PE3_CORE_CHILD_PE3_core_is_start()) {
  update_PE3_CORE_CHILD_PE3_core_is_start();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_is_start");
#endif
}
if (decode_PE3_CORE_CHILD_PE3_core_prep()) {
  update_PE3_CORE_CHILD_PE3_core_prep();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_prep");
#endif
}
if (decode_PE3_CORE_CHILD_PE3_core_mac()) {
  update_PE3_CORE_CHILD_PE3_core_mac();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_mac");
#endif
}
if (decode_PE3_CORE_CHILD_PE3_core_bias()) {
  update_PE3_CORE_CHILD_PE3_core_bias();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_bias");
#endif
}
if (decode_PE3_CORE_CHILD_PE3_core_out()) {
  update_PE3_CORE_CHILD_PE3_core_out();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_core_out");
#endif
}
if (decode_PE0_ACT_CHILD_PE0_act_child_initiate()) {
  update_PE0_ACT_CHILD_PE0_act_child_initiate();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_act_child_initiate");
#endif
}
if (decode_PE0_ACT_CHILD_PE0_act_child_fetch()) {
  update_PE0_ACT_CHILD_PE0_act_child_fetch();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_act_child_fetch");
#endif
}
if (decode_PE0_ACT_CHILD_PE0_act_child_do_incr()) {
  update_PE0_ACT_CHILD_PE0_act_child_do_incr();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_act_child_do_incr");
#endif
}
if (decode_PE0_ACT_CHILD_PE0_act_child_send_done()) {
  update_PE0_ACT_CHILD_PE0_act_child_send_done();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_act_child_send_done");
#endif
}
if (decode_PE0_ACT_CHILD_PE0_act_child_op_load_zero()) {
  update_PE0_ACT_CHILD_PE0_act_child_op_load_zero();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_act_child_op_load_zero");
#endif
}
if (decode_PE0_ACT_CHILD_PE0_act_child_op_load()) {
  update_PE0_ACT_CHILD_PE0_act_child_op_load();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_act_child_op_load");
#endif
}
if (decode_PE0_ACT_CHILD_PE0_act_child_op_store()) {
  update_PE0_ACT_CHILD_PE0_act_child_op_store();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_act_child_op_store");
#endif
}
if (decode_PE0_ACT_CHILD_PE0_act_child_op_inpe()) {
  update_PE0_ACT_CHILD_PE0_act_child_op_inpe();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_act_child_op_inpe");
#endif
}
if (decode_PE0_ACT_CHILD_PE0_act_child_op_outgb()) {
  update_PE0_ACT_CHILD_PE0_act_child_op_outgb();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_act_child_op_outgb");
#endif
}
if (decode_PE0_ACT_CHILD_PE0_act_child_op_copy()) {
  update_PE0_ACT_CHILD_PE0_act_child_op_copy();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_act_child_op_copy");
#endif
}
if (decode_PE0_ACT_CHILD_PE0_act_child_op_eadd()) {
  update_PE0_ACT_CHILD_PE0_act_child_op_eadd();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_act_child_op_eadd");
#endif
}
if (decode_PE0_ACT_CHILD_PE0_act_child_op_emul()) {
  update_PE0_ACT_CHILD_PE0_act_child_op_emul();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_act_child_op_emul");
#endif
}
if (decode_PE0_ACT_CHILD_PE0_act_child_op_sigm()) {
  update_PE0_ACT_CHILD_PE0_act_child_op_sigm();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_act_child_op_sigm");
#endif
}
if (decode_PE0_ACT_CHILD_PE0_act_child_op_tanh()) {
  update_PE0_ACT_CHILD_PE0_act_child_op_tanh();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_act_child_op_tanh");
#endif
}
if (decode_PE0_ACT_CHILD_PE0_act_child_op_relu()) {
  update_PE0_ACT_CHILD_PE0_act_child_op_relu();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_act_child_op_relu");
#endif
}
if (decode_PE0_ACT_CHILD_PE0_act_child_op_onex()) {
  update_PE0_ACT_CHILD_PE0_act_child_op_onex();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_act_child_op_onex");
#endif
}
if (decode_PE0_ACT_CHILD_PE0_act_child_reg_store()) {
  update_PE0_ACT_CHILD_PE0_act_child_reg_store();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE0_act_child_reg_store");
#endif
}
if (decode_PE1_ACT_CHILD_PE1_act_child_initiate()) {
  update_PE1_ACT_CHILD_PE1_act_child_initiate();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_act_child_initiate");
#endif
}
if (decode_PE1_ACT_CHILD_PE1_act_child_fetch()) {
  update_PE1_ACT_CHILD_PE1_act_child_fetch();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_act_child_fetch");
#endif
}
if (decode_PE1_ACT_CHILD_PE1_act_child_do_incr()) {
  update_PE1_ACT_CHILD_PE1_act_child_do_incr();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_act_child_do_incr");
#endif
}
if (decode_PE1_ACT_CHILD_PE1_act_child_send_done()) {
  update_PE1_ACT_CHILD_PE1_act_child_send_done();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_act_child_send_done");
#endif
}
if (decode_PE1_ACT_CHILD_PE1_act_child_op_load_zero()) {
  update_PE1_ACT_CHILD_PE1_act_child_op_load_zero();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_act_child_op_load_zero");
#endif
}
if (decode_PE1_ACT_CHILD_PE1_act_child_op_load()) {
  update_PE1_ACT_CHILD_PE1_act_child_op_load();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_act_child_op_load");
#endif
}
if (decode_PE1_ACT_CHILD_PE1_act_child_op_store()) {
  update_PE1_ACT_CHILD_PE1_act_child_op_store();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_act_child_op_store");
#endif
}
if (decode_PE1_ACT_CHILD_PE1_act_child_op_inpe()) {
  update_PE1_ACT_CHILD_PE1_act_child_op_inpe();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_act_child_op_inpe");
#endif
}
if (decode_PE1_ACT_CHILD_PE1_act_child_op_outgb()) {
  update_PE1_ACT_CHILD_PE1_act_child_op_outgb();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_act_child_op_outgb");
#endif
}
if (decode_PE1_ACT_CHILD_PE1_act_child_op_copy()) {
  update_PE1_ACT_CHILD_PE1_act_child_op_copy();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_act_child_op_copy");
#endif
}
if (decode_PE1_ACT_CHILD_PE1_act_child_op_eadd()) {
  update_PE1_ACT_CHILD_PE1_act_child_op_eadd();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_act_child_op_eadd");
#endif
}
if (decode_PE1_ACT_CHILD_PE1_act_child_op_emul()) {
  update_PE1_ACT_CHILD_PE1_act_child_op_emul();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_act_child_op_emul");
#endif
}
if (decode_PE1_ACT_CHILD_PE1_act_child_op_sigm()) {
  update_PE1_ACT_CHILD_PE1_act_child_op_sigm();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_act_child_op_sigm");
#endif
}
if (decode_PE1_ACT_CHILD_PE1_act_child_op_tanh()) {
  update_PE1_ACT_CHILD_PE1_act_child_op_tanh();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_act_child_op_tanh");
#endif
}
if (decode_PE1_ACT_CHILD_PE1_act_child_op_relu()) {
  update_PE1_ACT_CHILD_PE1_act_child_op_relu();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_act_child_op_relu");
#endif
}
if (decode_PE1_ACT_CHILD_PE1_act_child_op_onex()) {
  update_PE1_ACT_CHILD_PE1_act_child_op_onex();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_act_child_op_onex");
#endif
}
if (decode_PE1_ACT_CHILD_PE1_act_child_reg_store()) {
  update_PE1_ACT_CHILD_PE1_act_child_reg_store();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE1_act_child_reg_store");
#endif
}
if (decode_PE2_ACT_CHILD_PE2_act_child_initiate()) {
  update_PE2_ACT_CHILD_PE2_act_child_initiate();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_act_child_initiate");
#endif
}
if (decode_PE2_ACT_CHILD_PE2_act_child_fetch()) {
  update_PE2_ACT_CHILD_PE2_act_child_fetch();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_act_child_fetch");
#endif
}
if (decode_PE2_ACT_CHILD_PE2_act_child_do_incr()) {
  update_PE2_ACT_CHILD_PE2_act_child_do_incr();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_act_child_do_incr");
#endif
}
if (decode_PE2_ACT_CHILD_PE2_act_child_send_done()) {
  update_PE2_ACT_CHILD_PE2_act_child_send_done();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_act_child_send_done");
#endif
}
if (decode_PE2_ACT_CHILD_PE2_act_child_op_load_zero()) {
  update_PE2_ACT_CHILD_PE2_act_child_op_load_zero();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_act_child_op_load_zero");
#endif
}
if (decode_PE2_ACT_CHILD_PE2_act_child_op_load()) {
  update_PE2_ACT_CHILD_PE2_act_child_op_load();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_act_child_op_load");
#endif
}
if (decode_PE2_ACT_CHILD_PE2_act_child_op_store()) {
  update_PE2_ACT_CHILD_PE2_act_child_op_store();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_act_child_op_store");
#endif
}
if (decode_PE2_ACT_CHILD_PE2_act_child_op_inpe()) {
  update_PE2_ACT_CHILD_PE2_act_child_op_inpe();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_act_child_op_inpe");
#endif
}
if (decode_PE2_ACT_CHILD_PE2_act_child_op_outgb()) {
  update_PE2_ACT_CHILD_PE2_act_child_op_outgb();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_act_child_op_outgb");
#endif
}
if (decode_PE2_ACT_CHILD_PE2_act_child_op_copy()) {
  update_PE2_ACT_CHILD_PE2_act_child_op_copy();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_act_child_op_copy");
#endif
}
if (decode_PE2_ACT_CHILD_PE2_act_child_op_eadd()) {
  update_PE2_ACT_CHILD_PE2_act_child_op_eadd();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_act_child_op_eadd");
#endif
}
if (decode_PE2_ACT_CHILD_PE2_act_child_op_emul()) {
  update_PE2_ACT_CHILD_PE2_act_child_op_emul();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_act_child_op_emul");
#endif
}
if (decode_PE2_ACT_CHILD_PE2_act_child_op_sigm()) {
  update_PE2_ACT_CHILD_PE2_act_child_op_sigm();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_act_child_op_sigm");
#endif
}
if (decode_PE2_ACT_CHILD_PE2_act_child_op_tanh()) {
  update_PE2_ACT_CHILD_PE2_act_child_op_tanh();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_act_child_op_tanh");
#endif
}
if (decode_PE2_ACT_CHILD_PE2_act_child_op_relu()) {
  update_PE2_ACT_CHILD_PE2_act_child_op_relu();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_act_child_op_relu");
#endif
}
if (decode_PE2_ACT_CHILD_PE2_act_child_op_onex()) {
  update_PE2_ACT_CHILD_PE2_act_child_op_onex();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_act_child_op_onex");
#endif
}
if (decode_PE2_ACT_CHILD_PE2_act_child_reg_store()) {
  update_PE2_ACT_CHILD_PE2_act_child_reg_store();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE2_act_child_reg_store");
#endif
}
if (decode_PE3_ACT_CHILD_PE3_act_child_initiate()) {
  update_PE3_ACT_CHILD_PE3_act_child_initiate();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_act_child_initiate");
#endif
}
if (decode_PE3_ACT_CHILD_PE3_act_child_fetch()) {
  update_PE3_ACT_CHILD_PE3_act_child_fetch();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_act_child_fetch");
#endif
}
if (decode_PE3_ACT_CHILD_PE3_act_child_do_incr()) {
  update_PE3_ACT_CHILD_PE3_act_child_do_incr();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_act_child_do_incr");
#endif
}
if (decode_PE3_ACT_CHILD_PE3_act_child_send_done()) {
  update_PE3_ACT_CHILD_PE3_act_child_send_done();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_act_child_send_done");
#endif
}
if (decode_PE3_ACT_CHILD_PE3_act_child_op_load_zero()) {
  update_PE3_ACT_CHILD_PE3_act_child_op_load_zero();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_act_child_op_load_zero");
#endif
}
if (decode_PE3_ACT_CHILD_PE3_act_child_op_load()) {
  update_PE3_ACT_CHILD_PE3_act_child_op_load();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_act_child_op_load");
#endif
}
if (decode_PE3_ACT_CHILD_PE3_act_child_op_store()) {
  update_PE3_ACT_CHILD_PE3_act_child_op_store();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_act_child_op_store");
#endif
}
if (decode_PE3_ACT_CHILD_PE3_act_child_op_inpe()) {
  update_PE3_ACT_CHILD_PE3_act_child_op_inpe();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_act_child_op_inpe");
#endif
}
if (decode_PE3_ACT_CHILD_PE3_act_child_op_outgb()) {
  update_PE3_ACT_CHILD_PE3_act_child_op_outgb();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_act_child_op_outgb");
#endif
}
if (decode_PE3_ACT_CHILD_PE3_act_child_op_copy()) {
  update_PE3_ACT_CHILD_PE3_act_child_op_copy();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_act_child_op_copy");
#endif
}
if (decode_PE3_ACT_CHILD_PE3_act_child_op_eadd()) {
  update_PE3_ACT_CHILD_PE3_act_child_op_eadd();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_act_child_op_eadd");
#endif
}
if (decode_PE3_ACT_CHILD_PE3_act_child_op_emul()) {
  update_PE3_ACT_CHILD_PE3_act_child_op_emul();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_act_child_op_emul");
#endif
}
if (decode_PE3_ACT_CHILD_PE3_act_child_op_sigm()) {
  update_PE3_ACT_CHILD_PE3_act_child_op_sigm();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_act_child_op_sigm");
#endif
}
if (decode_PE3_ACT_CHILD_PE3_act_child_op_tanh()) {
  update_PE3_ACT_CHILD_PE3_act_child_op_tanh();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_act_child_op_tanh");
#endif
}
if (decode_PE3_ACT_CHILD_PE3_act_child_op_relu()) {
  update_PE3_ACT_CHILD_PE3_act_child_op_relu();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_act_child_op_relu");
#endif
}
if (decode_PE3_ACT_CHILD_PE3_act_child_op_onex()) {
  update_PE3_ACT_CHILD_PE3_act_child_op_onex();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_act_child_op_onex");
#endif
}
if (decode_PE3_ACT_CHILD_PE3_act_child_reg_store()) {
  update_PE3_ACT_CHILD_PE3_act_child_reg_store();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("PE3_act_child_reg_store");
#endif
}
if (decode_GB_ATTENTION_CHILD_gb_attention_child_idle()) {
  update_GB_ATTENTION_CHILD_gb_attention_child_idle();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_attention_child_idle");
#endif
}
if (decode_GB_ATTENTION_CHILD_gb_attention_child_prep()) {
  update_GB_ATTENTION_CHILD_gb_attention_child_prep();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_attention_child_prep");
#endif
}
if (decode_GB_ATTENTION_CHILD_gb_attention_child_bmm_rd()) {
  update_GB_ATTENTION_CHILD_gb_attention_child_bmm_rd();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_attention_child_bmm_rd");
#endif
}
if (decode_GB_ATTENTION_CHILD_gb_attention_child_bmm_tp()) {
  update_GB_ATTENTION_CHILD_gb_attention_child_bmm_tp();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_attention_child_bmm_tp");
#endif
}
if (decode_GB_ATTENTION_CHILD_gb_attention_child_bmm_mv()) {
  update_GB_ATTENTION_CHILD_gb_attention_child_bmm_mv();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_attention_child_bmm_mv");
#endif
}
if (decode_GB_ATTENTION_CHILD_gb_attention_child_bmm_next()) {
  update_GB_ATTENTION_CHILD_gb_attention_child_bmm_next();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_attention_child_bmm_next");
#endif
}
if (decode_GB_ATTENTION_CHILD_gb_attention_child_next_shift()) {
  update_GB_ATTENTION_CHILD_gb_attention_child_next_shift();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_attention_child_next_shift");
#endif
}
if (decode_GB_ATTENTION_CHILD_gb_attention_child_next_max()) {
  update_GB_ATTENTION_CHILD_gb_attention_child_next_max();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_attention_child_next_max");
#endif
}
if (decode_GB_ATTENTION_CHILD_gb_attention_child_next_wr()) {
  update_GB_ATTENTION_CHILD_gb_attention_child_next_wr();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_attention_child_next_wr");
#endif
}
if (decode_GB_ATTENTION_CHILD_gb_attention_child_sfm1_rd()) {
  update_GB_ATTENTION_CHILD_gb_attention_child_sfm1_rd();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_attention_child_sfm1_rd");
#endif
}
if (decode_GB_ATTENTION_CHILD_gb_attention_child_sfm1_comp()) {
  update_GB_ATTENTION_CHILD_gb_attention_child_sfm1_comp();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_attention_child_sfm1_comp");
#endif
}
if (decode_GB_ATTENTION_CHILD_gb_attention_sfm2_rd()) {
  update_GB_ATTENTION_CHILD_gb_attention_sfm2_rd();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_attention_sfm2_rd");
#endif
}
if (decode_GB_ATTENTION_CHILD_gb_attention_sfm2_comp0()) {
  update_GB_ATTENTION_CHILD_gb_attention_sfm2_comp0();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_attention_sfm2_comp0");
#endif
}
if (decode_GB_ATTENTION_CHILD_gb_attention_sfm2_comp1()) {
  update_GB_ATTENTION_CHILD_gb_attention_sfm2_comp1();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_attention_sfm2_comp1");
#endif
}
if (decode_GB_ATTENTION_CHILD_gb_attention_sfm2_comp2()) {
  update_GB_ATTENTION_CHILD_gb_attention_sfm2_comp2();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_attention_sfm2_comp2");
#endif
}
if (decode_GB_ATTENTION_CHILD_gb_attention_sfm2_comp3()) {
  update_GB_ATTENTION_CHILD_gb_attention_sfm2_comp3();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_attention_sfm2_comp3");
#endif
}
if (decode_GB_ATTENTION_CHILD_gb_attention_sfm3()) {
  update_GB_ATTENTION_CHILD_gb_attention_sfm3();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_attention_sfm3");
#endif
}
if (decode_GB_ATTENTION_CHILD_gb_attention_child_out1()) {
  update_GB_ATTENTION_CHILD_gb_attention_child_out1();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_attention_child_out1");
#endif
}
if (decode_GB_ATTENTION_CHILD_gb_attention_child_out2()) {
  update_GB_ATTENTION_CHILD_gb_attention_child_out2();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_attention_child_out2");
#endif
}
if (decode_GB_ATTENTION_CHILD_gb_attention_child_fin()) {
  update_GB_ATTENTION_CHILD_gb_attention_child_fin();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_attention_child_fin");
#endif
}
if (decode_Child_GB_Control_gb_control_child_prep()) {
  update_Child_GB_Control_gb_control_child_prep();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_control_child_prep");
#endif
}
if (decode_Child_GB_Control_gb_control_child_send_prep()) {
  update_Child_GB_Control_gb_control_child_send_prep();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_control_child_send_prep");
#endif
}
if (decode_Child_GB_Control_gb_control_child_send()) {
  update_Child_GB_Control_gb_control_child_send();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_control_child_send");
#endif
}
if (decode_Child_GB_Control_gb_control_child_pe_start()) {
  update_Child_GB_Control_gb_control_child_pe_start();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_control_child_pe_start");
#endif
}
if (decode_Child_GB_Control_gb_control_child_recv()) {
  update_Child_GB_Control_gb_control_child_recv();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_control_child_recv");
#endif
}
if (decode_Child_GB_Control_gb_control_child_recv_next()) {
  update_Child_GB_Control_gb_control_child_recv_next();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_control_child_recv_next");
#endif
}
if (decode_Child_GB_Control_gb_control_child_send_back_prep()) {
  update_Child_GB_Control_gb_control_child_send_back_prep();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_control_child_send_back_prep");
#endif
}
if (decode_Child_GB_Control_gb_control_child_send_back()) {
  update_Child_GB_Control_gb_control_child_send_back();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_control_child_send_back");
#endif
}
if (decode_Child_GB_Control_gb_control_child_next()) {
  update_Child_GB_Control_gb_control_child_next();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_control_child_next");
#endif
}
if (decode_Child_GBLayerNorm_gb_layer_norm_timestep_level_op()) {
  update_Child_GBLayerNorm_gb_layer_norm_timestep_level_op();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_layer_norm_timestep_level_op");
#endif
}
if (decode_Child_GBLayerNorm_gb_layer_norm_sum_vector_level_prep()) {
  update_Child_GBLayerNorm_gb_layer_norm_sum_vector_level_prep();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_layer_norm_sum_vector_level_prep");
#endif
}
if (decode_Child_GBLayerNorm_gb_layer_norm_sum_byte_op()) {
  update_Child_GBLayerNorm_gb_layer_norm_sum_byte_op();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_layer_norm_sum_byte_op");
#endif
}
if (decode_Child_GBLayerNorm_gb_layer_norm_mean_op()) {
  update_Child_GBLayerNorm_gb_layer_norm_mean_op();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_layer_norm_mean_op");
#endif
}
if (decode_Child_GBLayerNorm_gb_layer_norm_norm_vector_prep()) {
  update_Child_GBLayerNorm_gb_layer_norm_norm_vector_prep();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_layer_norm_norm_vector_prep");
#endif
}
if (decode_Child_GBLayerNorm_gb_layer_norm_norm_byte_op()) {
  update_Child_GBLayerNorm_gb_layer_norm_norm_byte_op();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_layer_norm_norm_byte_op");
#endif
}
if (decode_Child_GBLayerNorm_gb_layer_norm_child_next()) {
  update_Child_GBLayerNorm_gb_layer_norm_child_next();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_layer_norm_child_next");
#endif
}
if (decode_GB_LAYER_REDUCE_gb_layer_reduce_prep()) {
  update_GB_LAYER_REDUCE_gb_layer_reduce_prep();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_layer_reduce_prep");
#endif
}
if (decode_GB_LAYER_REDUCE_gb_layer_reduce_timestep_level_op()) {
  update_GB_LAYER_REDUCE_gb_layer_reduce_timestep_level_op();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_layer_reduce_timestep_level_op");
#endif
}
if (decode_GB_LAYER_REDUCE_gb_layer_reduce_vector_level_op()) {
  update_GB_LAYER_REDUCE_gb_layer_reduce_vector_level_op();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_layer_reduce_vector_level_op");
#endif
}
if (decode_GB_LAYER_REDUCE_gb_layer_reduce_byte_level_op()) {
  update_GB_LAYER_REDUCE_gb_layer_reduce_byte_level_op();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_layer_reduce_byte_level_op");
#endif
}
if (decode_GB_LAYER_REDUCE_gb_layer_reduce_done()) {
  update_GB_LAYER_REDUCE_gb_layer_reduce_done();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_layer_reduce_done");
#endif
}
if (decode_Child_GBZeroPadding_gb_zero_padding_child_prep()) {
  update_Child_GBZeroPadding_gb_zero_padding_child_prep();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_zero_padding_child_prep");
#endif
}
if (decode_Child_GBZeroPadding_gb_zero_padding_child_timestep()) {
  update_Child_GBZeroPadding_gb_zero_padding_child_timestep();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_zero_padding_child_timestep");
#endif
}
if (decode_Child_GBZeroPadding_gb_zero_padding_child_vector()) {
  update_Child_GBZeroPadding_gb_zero_padding_child_vector();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_zero_padding_child_vector");
#endif
}
if (decode_Child_GBZeroPadding_gb_zero_padding_child_byte()) {
  update_Child_GBZeroPadding_gb_zero_padding_child_byte();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_zero_padding_child_byte");
#endif
}
if (decode_Child_GBZeroPadding_gb_zero_padding_child_state_next()) {
  update_Child_GBZeroPadding_gb_zero_padding_child_state_next();
  schedule_counter++;
#ifdef ILATOR_VERBOSE
  LogInstrSequence("gb_zero_padding_child_state_next");
#endif
}
  if (schedule_counter == 0) {
    break;
  }
}
}
