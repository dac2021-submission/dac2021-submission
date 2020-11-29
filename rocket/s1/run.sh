for i in {1..30}; 
do 
    ./tandem-rocket-exe ../tv.txt >> result_s1; 
done

for i in {1..30}; 
do 
    ./tandem-rocket-exe ../tv.txt ./ >> result_s1p5; 
done