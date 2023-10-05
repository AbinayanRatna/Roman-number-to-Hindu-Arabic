#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

//function to check the value of characters except last character
int checkCharacterFunction(char letter, char nextLetter)
{
    //checking for i
    if(nextLetter == 'i' || nextLetter=='I')
    {
        if(letter=='x' || letter=='X')
        {
            return 10;
        }
        else if(letter=='i' || letter=='I')
        {
            return 1;
        }

        else if(letter=='v' || letter=='V')
        {
            return 5;
        }
        else if(letter=='l' || letter=='L')
        {
            return 50;
        }
        else if(letter=='c' || letter=='C')
        {
            return 100;
        }
    }
    //checking for v
    else if(nextLetter == 'v' || nextLetter=='V')
    {
        if(letter=='i' || letter=='I')
        {
            return -1;
        }
        else if(letter=='v' || letter=='V')
        {
            return 5;
        }
        else if(letter=='x' || letter=='X')
        {
            return 10;
        }
        else if(letter=='l' || letter=='L')
        {
            return 50;
        }
        else if(letter=='c' || letter=='C')
        {
            return 100;
        }
    }
    //checking for x
    else if(nextLetter == 'x' || nextLetter=='X')
    {
        if(letter=='i' || letter=='I')
        {
            return -1;
        }
        else if(letter=='x' || letter=='X')
        {
            return 10;
        }
        else if(letter=='v' || letter=='V')
        {
            return -5;
        }
        else if(letter=='l' || letter=='L')
        {
            return 50;
        }
        else if(letter=='c' || letter=='C')
        {
            return 100;
        }
    }
    //checking for l
    else if(nextLetter == 'l' || nextLetter=='L')
    {
        if(letter=='i' || letter=='I')
        {
            return -1;
        }
        else if(letter=='v' || letter=='V')
        {
            return -5;
        }
        else if(letter=='x' || letter=='X')
        {
            return -10;
        }
        else if(letter=='l' || letter=='L')
        {
            return 50;
        }
        else if(letter=='c' || letter=='C')
        {
            return 100;
        }
    }
    //checking for c
    else if(nextLetter == 'c' || nextLetter=='C')
    {
        if(letter=='i' || letter=='I')
        {
            return -1;
        }
        else if(letter=='v' || letter=='V')
        {
            return -5;
        }
        else if(letter=='l' || letter=='L')
        {
            return -50;
        }
        else if(letter=='x' || letter=='X')
        {
            return -10;
        }
        else if(letter=='c' || letter=='C')
        {
            return 100;
        }
    }
    else
    {
        return -1;
    }
}

//function to check the value of last character
int lastCharacterCheckerFunction(char lastLetter)
{

    if(lastLetter=='i' || lastLetter=='I')
    {
        return 1;
    }
    else if(lastLetter=='x' || lastLetter=='X')
    {
        return 10;
    }
    else if(lastLetter=='v' || lastLetter=='V')
    {
        return 5;
    }
    else if(lastLetter=='l' || lastLetter=='L')
    {
        return 50;
    }
    else if(lastLetter=='c' || lastLetter=='C')
    {
        return 100;
    }
    else
    {
        return -1;
    }
}

//function to check whether the letter is used thrice continuously
int tripleChecker(char smallCharacter,char capitalCharacter, string romanNumber)
{

    for(int i=0; i<romanNumber.length()-3; i++)
    {
        if(romanNumber[i]==smallCharacter || romanNumber[i]==capitalCharacter)
        {
            if(romanNumber[i+1]==smallCharacter || romanNumber[i+1]==capitalCharacter)
            {
                if(romanNumber[i+2]==smallCharacter || romanNumber[i+2]==capitalCharacter)
                {
                    if(romanNumber[i+3]==smallCharacter || romanNumber[i+3]==capitalCharacter)
                    {
                        return -1;
                    }

                }
            }
        }
    }
    return 0;
}

//function to evaluate whether a letter is used twice (continuously or not)
int nonRepeatingChecker(char capitalCharacter,char smallCharacter, string romanNumber)
{
    int numberOfRepeatings=0;
    for(int i=0; i<romanNumber.length(); i++)
    {
        if(romanNumber[i]==smallCharacter || romanNumber[i]==capitalCharacter)
        {
            numberOfRepeatings++;
        }
    }
    if(numberOfRepeatings>=2)
    {
        return -1;
    }
    else
    {
        return 0;
    }

}

//function to find the value of the roman number
string romanNumberEvaluator(string romanNumber)
{
    //checking whether the c is repeated more than twice continuously
    if(romanNumber.length()>2)
    {
        for(int i=0; i<romanNumber.length()-1; i++)
        {
            if(romanNumber[i]=='c' || romanNumber[i]=='C')
            {
                if(romanNumber[i+1]=='c' || romanNumber[i+1]=='C')
                {
                    return "error";
                }
            }
        }

        //checking whether iiv is found or not
        for(int i=0; i<romanNumber.length()-2; i++)
        {
            if(romanNumber[i]=='i' || romanNumber[i]=='I')
            {
                if(romanNumber[i+1]=='i' || romanNumber[i+1]=='I')
                {
                    if(romanNumber[i+2]=='v' || romanNumber[i+2]=='V'|| romanNumber[i+2]=='x' || romanNumber[i+2]=='X')
                    {
                        return "error";
                    }
                }
            }
        }



    }

    //checking whether lc is found
    if(romanNumber.length()>=2)
    {
        for(int i=0; i<romanNumber.length()-1; i++)
        {
            if(romanNumber[i]=='l' || romanNumber[i]=='L')
            {
                if(romanNumber[i+1]=='c' || romanNumber[i+1]=='C')
                {
                    return "error";
                }
            }
        }
    }


    if(romanNumber.length()>3)
    {
         //checking whether x,i are repeated thrice continuosly
        int errorCheckerforx=tripleChecker('x','X',romanNumber);
        int errorCheckerfori=tripleChecker('i','I',romanNumber);
        if(errorCheckerfori==-1 || errorCheckerforx==-1)
        {
            return "error";
        }

        //checking whether iiiv is found or not
         for(int i=0; i<romanNumber.length()-3; i++)
        {
            if(romanNumber[i]=='i' || romanNumber[i]=='I')
            {

                if(romanNumber[i+1]=='i' || romanNumber[i+1]=='I'){

                    if(romanNumber[i+2]=='i' || romanNumber[i+2]=='I'){

                         if(romanNumber[i+3]=='v' || romanNumber[i+3]=='V'|| romanNumber[i+3]=='x' || romanNumber[i+3]=='X'){

                        return "error";
                    }
                    }
                }
            }
        }
    }

    //checking whether l,v are repeated or not
    int repeatingErrorCheckerForL=nonRepeatingChecker('l','L',romanNumber);
    int repeatingErrorCheckerForV=nonRepeatingChecker('v','V',romanNumber);
    if(repeatingErrorCheckerForL==-1 || repeatingErrorCheckerForV==-1)
    {
        return "error";
    }

    int finalValue=0;

    //finding the final value of roman number
    for(int i=0; i<romanNumber.length()-1; i++)
    {
        finalValue+=checkCharacterFunction(romanNumber[i],romanNumber[i+1]);
    }

    finalValue+=lastCharacterCheckerFunction(romanNumber[romanNumber.length()-1]);

    if(finalValue>=100)
    {
        if(romanNumber[0] == 'c' || romanNumber[0] == 'C')
        {

        }
        else
        {
            return "error";
        }
    }
    if(finalValue>=50 && finalValue <90)
    {
        if(romanNumber[0] == 'l' || romanNumber[0] == 'L')
        {

        }
        else
        {
            return "error";
        }
    }

    if(finalValue>=90 && finalValue <100)
    {
        if(romanNumber[0] == 'x' || romanNumber[0] == 'X')
        {

        }
        else
        {
            return "error";
        }
    }
    if(finalValue>=10 && finalValue <50)
    {
        if(romanNumber[0] == 'x' || romanNumber[0] == 'X')
        {

        }
        else
        {
            return "error";
        }
    }


    if(finalValue!=-1)
    {
        //converting int value to string
        string finalHinduValue=to_string(finalValue);
        return finalHinduValue;
    }
    else
    {
        return "error";
    }

}

int main()
{
    ifstream inputFile("roman_numbers.txt");
    string line;


    if (!inputFile)
    {
        cout << "Failed to open input file!" << endl;
        return 1;
    }

    while (getline(inputFile, line))
    {
        cout<<line<<" : "<<romanNumberEvaluator(line)<<endl;
    }

    return 0;
}
