for i in {1..100}; do ./tandem-gb-exe ../tv_v.csv ../tv_i.csv 1 >> result_s3_1_monitor_only; done
for i in {1..100}; do ./tandem-gb-exe ../tv_v.csv ../tv_i.csv 2 >> result_s3_2_monitor_only; done
for i in {1..100}; do ./tandem-gb-exe ../tv_v.csv ../tv_i.csv 3 >> result_s3_3_monitor_only; done