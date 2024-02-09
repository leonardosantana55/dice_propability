#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* sumAllCombinations(int dice, int sides, int* current, int index, int* sum_combinations, int* temp, int* fucking_index);
int** getValues(int* input_list, int size);
int** valueCounts(int* input_list, int size, int** values);
void printlist(int** list);
//value_counts

int main(){
    int dice;
    printf("Inform the number of dice: ");
    scanf("%d", &dice);
    int sides;
    printf("Inform the number of dice sides: ");
    scanf("%d", &sides);
    double max_size = pow((double)sides, (double)dice);
    int current[dice];
    int* temp = current;
    int index = 0;
    int fucking_index = 0;
    int* sum_combinations = calloc((int)max_size, sizeof(int));
    sumAllCombinations(dice, sides, current, index, sum_combinations, temp, &fucking_index);
    
    // # print sum of combinations
    /*
    for (int i = 0; i < (int)max_size; i++)
    {
        printf("%p: -", sum_combinations);
        printf("%d\n", *sum_combinations);
        sum_combinations++;
    }
    sum_combinations -= (int)max_size;
    */

    int** values = getValues(sum_combinations, max_size);
    int** value_counts = valueCounts(sum_combinations, max_size, values);
    
    int values_size = *values[1];
    for (int i = 0; i < values_size; i++){
            printf("dice_sum: %i, chance: %0.3f%%\n", 
            value_counts[i][0], 
            ((float)value_counts[i][1] / (float)max_size)*100.0);
        }
    
    free(sum_combinations);
    free(values);
    free(value_counts);
    return 0;
}


int* sumAllCombinations(int dice, int sides, int* current, int index, int* sum_combinations, int* temp, int* fucking_index){
    int* psum_combinations = 0;
    //printf("index: %i, dice %i\n", index, dice);
    if (index == dice)
    {
        int sum = 0;
        for (int j = 0; j < dice; j++)
        {
            //printf("%i, ", *temp);
            sum += *temp;
            temp++;
        }
        //printf("\n");
        sum_combinations += *fucking_index;
        *sum_combinations = sum;
        (*fucking_index)++;  
        return sum_combinations;
    }
    for (int i = 0; i < sides; i++)
    {
        *current = i + 1;
        psum_combinations = sumAllCombinations(dice, sides, ++current, index + 1, sum_combinations, temp, fucking_index);
        current--;
        
    }

}

int** getValues(int* input_list, int size){
    int new_size = 1;
    int* new_list = (int*) malloc(new_size * sizeof(int));
    new_list[0] = 0;

    int flag = 0;
    for (int l = 0; l < size; l++){
        flag = 0;
        for (int n = 0; n < new_size; n++){
            if(input_list[l] == new_list[n] && flag == 0){
                flag = 1;
            }
        }
        if(flag == 0){
                new_size++;
                new_list = realloc(new_list, new_size * sizeof(int));
                new_list[new_size-1] = input_list[l];
        }
        
    }

    int** arr = (int**)calloc(2, sizeof(int));
    arr[0] = new_list+1;
    new_size -= 1;
    arr[1] = &new_size;

    return arr;

}

int** valueCounts(int* input_list, int input_size, int** values){
    // cria uma lista com tamanho list[size][2] - done
    // para cada item da values 
    // variavel contagem 
    // atravessa a input_list
    // se o valor da input list for igual a valor da value, contagem++
    // lista[i][0] = values
    // lista[i][1] = contagem
    int len_values = *values[1];
    int count = 0;
    
    int** list2d = (int**)calloc(len_values, sizeof(int**));
    for (int i = 0; i < len_values; i++){
        list2d[i] = (int*)calloc(2, sizeof(int*));
    }
   
    for (int i = 0; i < len_values; i++){
        //printf("%i: ", values[0][i]);
        count = 0;
        for (int j = 0; j < input_size; j++){
            if(values[0][i] == input_list[j]){
                count++;
            }
        }
        list2d[i][0] = values[0][i];
        list2d[i][1] = count;
    }
    
    return list2d;
}

void printlist(int** list){
    int bug = *list[1];
    for (int i = 0; i < bug; i++){
    printf("%i\n", list[0][i]);
    } 

}


//Fucking did it!!!
