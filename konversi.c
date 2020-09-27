/* Samuel Gondokusumo / 18219024
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
void dectooct(int dec);
void dectohex(int temp_dec_2);
void dectobin(int dec);
int main(){
    int n;
    printf(R"EOF(
    ___ _       _ _     ___                          _            
   /   (_) __ _(_) |_  / __\___  _ ____   _____ _ __| |_ ___ _ __ 
  / /\ / |/ _` | | __|/ /  / _ \| '_ \ \ / / _ \ '__| __/ _ \ '__|
 / /_//| | (_| | | |_/ /__| (_) | | | \ V /  __/ |  | ||  __/ |   
/___,' |_|\__, |_|\__\____/\___/|_| |_|\_/ \___|_|   \__\___|_|   
          |___/                                                   
)EOF");
    printf("Masukkan kategori bilangan yang kamu inginkan: \n");
    printf("1. Decimal\n2. Binary \n3. Octal \n4. Hex\n5. Exit Program\n");
    printf("Enter a category: ");
    scanf("%d", &n);
    while(n!=5){
            if(n==1){
                printf("Enter a decimal number: ");
                int oct = 0, dec = 0, i = 1, temp_dec, temp_dec_2, temp_dec_3, temp_oct;
                scanf("%d",&dec);
                temp_dec = dec;
                temp_dec_2 = dec;
                temp_dec_3 = dec;

                //converting decimal to binary
                printf("%d in decimal = ",temp_dec);
                dectobin(dec);

                //converting decimal to octal
                printf("%d in decimal = ",temp_dec);                
                dectooct(dec);
                
                //converting decimal to hex
                printf("%d in decimal = ",temp_dec);                
                dectohex(dec);
            }

            else if (n==2){
                printf("Enter a binary number: ");
                long long bin;
                scanf("%lld", &bin);
                int oct = 0, dec = 0, i = 0, temp_dec, temp_oct;
                long long temp_bin = bin;
                printf("%lld in binary ",bin);

                // converting binary to decimal
                while (bin != 0) {
                    dec += (bin % 10) * pow(2, i);
                    ++i;
                    bin /= 10;
                }
                printf("= %d in decimal\n", dec);
                i = 1;
                temp_dec=dec;

                // converting to decimal to octal
                printf("%lld in binary = ",temp_bin);
                dectooct(dec);

                //converting decimal to hex
                printf("%lld in binary = ",temp_bin);
                dectohex(temp_dec);
            }

            else if (n==3){

                //convert octal to decimal
                printf("Enter an octal number: ");
                int oct;
                scanf("%d", &oct);
                printf("%d in octal ",oct);
                int dec = 0, i = 0, temp_oct=oct;

                while(oct != 0)
                {
                    dec += (oct%10) * pow(8,i);
                    ++i;
                    oct/=10;
                }
                printf("= %d in decimal\n",dec);

                //convert octal to binary
                printf("%d in octal = ",temp_oct);
                dectobin(dec);

                //convert octal to hex
                printf("%d in octal = ", temp_oct);
                dectohex(dec);
            }
            else if (n==4){
                int decnum=0, rem, i=0, len=0;
                char hexnum[20];
                printf("Enter a Hexadecimal Number (Please capitalise letters): ");
                scanf("%s", hexnum);
                printf("%s in hex =", hexnum);
                while(hexnum[i]!='\0')
                {
                    len++;
                    i++;
                }
                len--;
                i=0;
                while(len>=0)
                {
                    rem = hexnum[len];
                    if(rem>=48 && rem<=57)
                        rem = rem-48;
                    else if(rem>=65 && rem<=90)
                        rem = rem-55;
                    else
                    {
                        printf("\nYou've entered an invalid Hexadecimal digit");
                    }
                    decnum = decnum + (rem*pow(16, i));
                    len--;
                    i++;
                }
                printf(" %d in decimal\n", decnum);

                //convert hex to binary
                printf("%s in hex = ",hexnum);
                dectobin(decnum);
                
                //convert hex to octal
                printf("%s in hex = ",hexnum);
                dectooct(decnum);

            } 
                
            else{
                printf("Please enter a valid input.\n");
            }
             
                

        printf("Enter a category: ");
        scanf("%d",&n);        
    }
    printf("Thank you for using this program.");

    return 0;
}
void dectobin(int dec){
    long long bin = 0;
    int rem, i = 1, step = 1;
    while (dec!=0){
        rem = dec%2;
        dec/=2;
        bin += rem*i;
        i*=10;
    }
    printf("%lld in binary\n", bin);
}
void dectooct(int dec){
    int oct = 0, i = 1, temp_dec, temp_oct;
    temp_dec = dec;
    //converting decimal to octal
    while (dec != 0) {
        oct += (dec % 8) * i;
        dec /= 8;
        i *= 10;
    }                
    printf("%d in octal\n", oct);
}

void dectohex(int temp_dec){
    long int remainder,quotient;
    int I=1,j,temp,temp_dec_2=temp_dec;
    char hexadec[100];
    quotient = temp_dec;
    while(quotient!=0) {
        temp = quotient % 16;
        //To convert integer into character
        if( temp < 10)
                temp =temp + 48; else
                temp = temp + 55;
        hexadec[I++]= temp;
        quotient = quotient / 16;
    }
    for (j = I -1 ;j> 0;j--)
        printf("%c",hexadec[j]);
    printf(" in hex\n");
            
}

