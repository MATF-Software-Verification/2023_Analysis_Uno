g++ -o UNO ../2020_Uno/test.cpp 
./UNO
valgrind --leak-check=full --log-file="leak-report-fixed" ./UNO