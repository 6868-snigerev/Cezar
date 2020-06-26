#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[])
{
    char encode[8] = "-encode";
    char decode[8] = "-decode";
    char arr_en[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char arr_EN[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int n = atoi(argv[2]);
    int pos2 = 0;
    int flag = -1;
    FILE *p1;
    FILE *p2;
    p1 = fopen(argv[3], "r");
    p2 = fopen(argv[4], "w");
    //cout << "work";
    if (strcmpi(argv[1], encode) == 0){
        char c;
        c = getc(p1);
        while (c != EOF){
            for (int i = 0; i < 26; i++){
                if (arr_en[i] == c){
                    if ((i + n) < 26){
                        pos2 = i + n;
                    } else if ((i + n) > 26){
                        pos2 = ((i + n) % 26) - 1;
                    }
                    flag = 1;
                } else if (arr_EN[i] == c){
                    if ((i + n) <= 26){
                        pos2 = i + n;
                    } else if ((i + n) > 26){
                        pos2 = ((i + n) % 26) - 1;
                    }
                    flag = 0;
                }
            }
            if (flag == 1){
                fprintf(p2, "%c", arr_en[pos2]);
            } else if (flag == 0){
                fprintf(p2, "%c", arr_EN[pos2]);
            } else if (flag == -1) {
                fprintf(p2, "%c", c);
            }
            flag = -1;
        c = getc(p1);
        }
    }
    if (strcmpi(argv[1], decode) == 0){
        char c;
        c = getc(p1);
        while (c != EOF){
            for (int i = 0; i < 26; i++){
                if (arr_en[i] == c){
                    if ((i - n) < 0){
                        pos2 = 25 - ((i + n) % 26);
                    } else if ((i - n) > 0){
                        pos2 = i - n;
                    }
                    flag = 1;
                } else if (arr_EN[i] == c){
                    if ((i + n) <= 26){
                        pos2 = 25 - ((i + n) % 26);
                    } else if ((i + n) > 26){
                        pos2 = i - n;
                    }
                    flag = 0;
                }
            }
            if (flag == 1){
                fprintf(p2, "%c", arr_en[pos2]);
            } else if (flag == 0){
                fprintf(p2, "%c", arr_EN[pos2]);
            } else if (flag == -1) {
                fprintf(p2, "%c", c);
            }
            flag = -1;
        c = getc(p1);
        }
    }
    return 0;
}
