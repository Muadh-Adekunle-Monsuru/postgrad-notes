int countAlpha(char str[]){
    int numDigits = 0;
    int len = strlen(str);
    for(int i = 0; i<len;i++){
        if(isalpha(str[i])){
            numDigits++;
        }
    }
    return numDigits;
} 


long long int factorial(int N){
    if(N<=1){
        return 1;
    }else{
        return (N * factorial(N-1));
    }
}