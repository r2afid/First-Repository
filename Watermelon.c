#include <stdio.h>
int main(){
    int weight, result;
    
    printf("Enter the weight of watermelon: ");
    scanf("%d", &weight);

    if(weight % 2 == 0 && weight > 2){
        printf("YES");
    }
    else{
        printf("NO");
    }

    return 0;
}