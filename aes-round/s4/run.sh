for i in {1..8000..80}; 
do 
    ./tandem-aes-exe ../tv_verilog_only.csv $i >> result_s4; 
done