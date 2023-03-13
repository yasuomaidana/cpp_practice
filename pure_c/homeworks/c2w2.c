#include <stdio.h>
enum month { jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
typedef enum month month;
void print_month(month m){
    switch (m)
    {
    case jan:
        printf(" january ");
        break;
    case feb:
        printf(" february ");
        break;
    case mar:
        printf(" march ");
        break;
    case apr:
        printf(" april ");
        break;
    case may:
        printf(" may ");
        break;
    case jun:
        printf(" june ");
        break;
    case jul:
        printf(" july ");
        break;
    case aug:
        printf(" august ");
        break;
    case sep:
        printf(" september ");
        break;
    case oct:
        printf(" october ");
        break;
    case nov:
        printf(" november ");
        break;
    case dec:
        printf(" december ");
        break;
    default:
        printf("%d is an error\n",m);
        break;
    }
}

month next_month(month m){
    return( (m + 1) % 12);
}

typedef struct date{
    int day;
    month m;
} date;

void printdate(date *da){
    print_month(da->m);
    printf("%d\n",da->day);
}

void nextday(date *da){
    int limit;
    int next_day = da->day+1;
    if(da->m==jan||da->m==mar || da->m==may || da->m==jul || da->m== aug || da->m==oct || da->m==dec){
        limit = 31;
    }
    else if (da->m==apr||da->m==jun || da->m==sep || da->m==nov)
    {
        limit = 30;
    }
    else{
        limit = 28;
    }
    da->day = (next_day > limit ) ? 1:next_day;
    if(da->day == 1){
        da->m = next_month(da->m);
    }
}

void main(){
    month mon = feb;
    date current_date={27,mon};
    printdate(&current_date);
    nextday(&current_date);
    printdate(&current_date);
    nextday(&current_date);
    printdate(&current_date);
};