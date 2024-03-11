#include <stdio.h>

int main(){
    int i =0;
    int score;
    //While loop runs until user input is equal to 1 or 0
    while (i == 0){
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &score);
        //if score equals 1 or 0 i becomes 1 and program ends
        if(score == 1||score == 0){
            i = 1;
        }else{
            //using given score, the program loops from the greatest point value to lowest
            //The program runs each loop until no more of the point denomination can divide into the total score
            for (int td2 = 0; td2 <= score/8; td2++ ){
                int scoretd2 = score - td2*8;
                for (int td1 = 0; td1 <= scoretd2/7; td1++ ){
                    int scoretd1 = scoretd2-td1*7;
                    for (int td = 0; td <= scoretd1/6; td++ ){
                        int scoretd = scoretd1-td*6;
                        for (int fg = 0; fg <= scoretd/3; fg++ ){
                            int scorefg = scoretd-fg*3;
                            for (int s = 0; s <= scorefg/2; s++ ){
                                int scores = scorefg-s*2;
                                //if the point combination has no remaining score value, the combination is printed
                                if(scores == 0){
                                    printf("%d%s%d%s%d%s%d%s%d%s\n",td2," TD + 2pt, ",td1," TD + FG, ",td," TD, ",fg," 3pt FG, ",s," Safety");
                                }
                            }
                        }
                    }
                }
            }
        }



    }
}