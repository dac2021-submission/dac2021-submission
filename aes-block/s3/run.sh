for i in {1..100}; do ./tandem-aes-exe ../tv_verilog_only.csv ./ ./ 1 >> result_s3_1_monitor_only; done
for i in {1..100}; do ./tandem-aes-exe ../tv_verilog_only.csv ./ ./ 2 >> result_s3_2_monitor_only; done
for i in {1..100}; do ./tandem-aes-exe ../tv_verilog_only.csv ./ ./ 3 >> result_s3_3_monitor_only; done
