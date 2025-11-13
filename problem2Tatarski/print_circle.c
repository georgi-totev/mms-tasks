#include <stdio.h>
#include <math.h>


void print_circle(int r, char sym, int filled_or_hollow){
    for (int y = 0; y <= 2 * r; y++) {
        for (int x = 0; x <= 2 * r; x++) {
            double dx = x - r;
            double dy = y - r;
            double distance = sqrt(dx*dx + dy*dy);

            if(filled_or_hollow == 0){
                if (fabs(distance - r) < 0.5)
                    printf("%c", sym);
                else
                    printf(" ");
            }
            else if(filled_or_hollow == 1){
                if (distance <= r)
                    printf("%c", sym);
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
}


int main(){
    
    int r;
    char sym;
    int filled_or_hollow;
    printf("provide radius, symbol and 1 or 0 for filled or hollow: ");
    scanf("%d %c %d", &r, &sym, &filled_or_hollow);

    print_circle(r, sym, filled_or_hollow);

    return 0;
}