#include <stdio.h>

struct current_time{
    int hours, minutes;                //current time of India entered by user
    int new_hours, new_minutes;        //current time of the country choosen by user 
}ct;

int corrected_time();

int time_of_other_countries()       
{
    int country;
    printf("Choose a country : ");
    printf("\n\t{1} Afghanistan\n\t{2} Bangladesh\n\t{3} Bhutan\n\t{4} Burma\n\t{5} China\n\t{6} Maldives\n\t{7} Myanmar\n\t{8} Nepal\n\t{9} Pakistan\n\t{10} Sri Lanka \n >>> ");
    scanf("%d", &country);
    
    switch(country)
    {
        case 1:
            ct.new_hours = ct.hours - 1;                    
            ct.new_minutes = ct.minutes;
            printf("Time in Afghanistan : ");
            corrected_time();
            break;
        case 2:
            ct.new_hours = ct.hours;                       
            ct.new_minutes = ct.minutes + 30;
            printf("Time in Bangladesh : ");
            corrected_time();
            break;
        case 3:
            ct.new_hours = ct.hours;
            ct.new_minutes = ct.minutes + 30;             
            printf("Time in Bhutan : ");
            corrected_time();
            break;
        case 4:
            ct.new_hours = ct.hours + 1;                 
            ct.new_minutes = ct.minutes;
            printf("Time in Burma : ");
            corrected_time();
            break;
        case 5:
            ct.new_hours = ct.hours + 2;
            ct.new_minutes = ct.minutes + 30;
            printf("Time in China : ");
            corrected_time();
            break;
        case 6:
            ct.new_hours = ct.hours;
            ct.new_minutes = ct.minutes - 30;
            printf("Time in Maldives : ");
            corrected_time();
            break;
        case 7:
            ct.new_hours = ct.hours + 1;
            ct.new_minutes = ct.minutes;
            printf("Time in Myanmar : ");
            corrected_time();
            break;
        case 8:
            ct.new_hours = ct.hours;
            ct.new_minutes = ct.minutes + 15;
            printf("Time in Nepal : ");
            corrected_time();
            break;
        case 9:
            ct.new_hours = ct.hours;
            ct.new_minutes = ct.minutes - 30;
            printf("Time in Pakistan : ");
            corrected_time();
            break;
        case 10:
            ct.new_hours = ct.hours;
            ct.new_minutes = ct.minutes;
            printf("Time in Sri Lanka : ");
            corrected_time();
            break;
    }
}

int corrected_time()
{
    if(ct.new_minutes < 0)
    {
        ct.new_hours -= 1;                              
        ct.new_minutes = 60 + ct.new_minutes;           
    }
    
    while(ct.new_minutes >= 60)
    {
        ct.new_minutes -= 60;                           
        ct.new_hours++;                                 
    }
    
    printf("%02d:%02d", ct.new_hours, ct.new_minutes);
}

int is_time_correct()                                 //This will take care of hr < 23 and min < 59
{
    if(ct.minutes >= 60)                                   
        printf("Minutes should be less than 59.");
    else if(ct.hours >= 24)
        printf("Hours should be less than 23.");
    else
        time_of_other_countries();
}


int main()
{
    printf("Enter the current time in India (in hh:mm format)\n >>> ");
    scanf("%d:%d", &ct.hours, &ct.minutes);
    
    is_time_correct();
}



