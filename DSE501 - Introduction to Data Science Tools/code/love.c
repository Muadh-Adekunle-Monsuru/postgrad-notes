#include <stdio.h>

void very_repeat(int count){
    while(count>0)
    {
        printf("\n very ");
        count--;
    }
    printf("much...");

}
int main(){
    int count =0;
    printf("%s","How much do you love me 1-10: ");
    scanf("%d",&count);
    printf("I love you very");
   very_repeat(count);
    return 0;
}