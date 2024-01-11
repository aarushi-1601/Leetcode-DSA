class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector <string> arr;
        for (int i = 1 ; i<=n ; i++ ){
            if(i%3==0){
                if(i%5==0){
                    arr.push_back("FizzBuzz");
                }
                else{
                    arr.push_back("Fizz");
                }
            }
            else if(i%5==0){
                arr.push_back("Buzz");
            }
            else{
                int m = i;
                string j ;
                while(m!=0){
                    int k = m%10;
                    char h = k + '0';
                    m = m/10;
                    j = h +j;
                }
                arr.push_back(j);
            }
        }
        return arr; 
    }
};