//This code takes in a series of numbers between 0 and 26 and converts it into a message, where 1 corresponds to a, 2 corresponds to b and so on. 
//The number 0 corresonds to the space bar.
#include <stdio.h>
int main(){
        char alphabet[27] = {' ','a','b','c','d','e','f','g','h',
                'i','j','k','l','m','n','o','p','q','r','s',
                't','u','v','w','x','y','z'};
        int encodedMessage[100]; //the max length of the message is 100
        int encodedMessageLength = 0;
        char message[101]; //the length of this is 101 since the null character at the end takes up a spot;

        printf("This is an alphanumeric decoder!\n \
        To start decoding a message, Type a number between 0 and 26 inclusive and click enter.\n \
        Keep writing numbers and pressing enter until you have written what you want to decode.\n \
        Once you have finished your message, type a number that is not between 0 and 26 inclusive or any letter and your message will display!\n");

        //This for loop enters user inputs into the decoded message array
        for (int i = 0; i < 100; i++)
        {
                int inputNum;
                int retValue = scanf("%d", &inputNum);
                //if a letter is inputted instead of a number, int retValue will equal zero.
                //EOF can also be returned if the end of input is reached before a matching failure or a conversion occurs.
                //In both cases, the program breaks out of the for loop.
                if (retValue == 0 || retValue == EOF) {
                        break;
                }
                if (inputNum < 0 || inputNum > 26)
                {
                        break;
                }
                encodedMessage[i] = inputNum;
                encodedMessageLength ++;
        }

        //This for loop converts the decoded message characters into their corresponding letters using the alphabet array
        for (int i = 0; i < encodedMessageLength; i++)
        {
                int encodedChar = encodedMessage[i];
                char decodedChar = alphabet[encodedChar];
                message[i] = decodedChar;
        }

        message[encodedMessageLength] = '\0'; //string ends with a null character
        printf("*The message is: \n\n%s\n\n*Have a good day! \n",message); //the output
}
