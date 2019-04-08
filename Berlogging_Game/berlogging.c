// gcc 6.3

// Route to the file 'problem_statement.md' for steps to execute the following code

#include  <stdio.h>
#include  <string.h>

int current_winner, final_score[1000];
int total_rounds, score[1000];
char names[1000][32], name[1000][32];

void getNamesOccuringAtLeastOnce()
{
    int iter1, iter2, index = 0, flag = 0;
    
    for(iter1 = 0; iter1 < total_rounds; ++iter1)
    {
        for(iter2 = 0; iter2 < total_rounds; ++iter2)
        {
            if(strcmp(names[iter1], name[iter2]) == 0)
            {
                flag = 1;
                
                continue;
            }    
        }
        
        if(flag == 0)
        
            strcpy(name[index++], names[iter1]);
            
        else
        
            flag = 0;
    }
}

void fetchInput()
{
    int iter, index;
    
    scanf("%d", &total_rounds);
    
    for(iter = 0; iter < total_rounds; ++iter)
    {
        scanf("%s", &names[iter]);
        
        scanf("%d", &score[iter]);
    }
    
    getNamesOccuringAtLeastOnce();
}

void getNextNameAndScore(char next_name[], int *next_score)
{
    static int round_number = 0;
    
    strcpy(next_name, names[round_number]);
    *next_score = score[round_number];
    
    ++round_number;
}

int returnNameIndex(char *inp_name)
{
    int iter;

    for(iter = 0; iter < total_rounds; ++iter)
    {
        if((strcmp(inp_name, name[iter])) == 0)
            
            return iter;
    }
}

void checkIfScoreIsMax(int score, int name_index)
{
    int iter;

    if(score > final_score[current_winner])
    
        current_winner = name_index;
}

char * getWinner()
{
    return name[current_winner];
}

int main()
{
    int iter1, score, round, name_index, isWinner, index;
    char name[32];
    
    fetchInput();

    for(round = 1; round <= total_rounds; ++round)
    {
        getNextNameAndScore(name, &score);

        name_index = returnNameIndex(name);

        final_score[name_index] += score;

        checkIfScoreIsMax(final_score[name_index], name_index);
    }

    printf("%s", getWinner());
    
    return 0;
}
