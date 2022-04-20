/* Name: (Jaskaran Chawla)
Date: (1/27/2022) Section:
 Module 9:
Section: 0006
Assignment: (Assignment#9)
Due Date: (3/27/2022)
About this project: (Develop, compile, and run a C++ program that requires the definition and use of functions and
 arrays to perform common tasks, such as finding the max and min of a data set, counting, summing, tracking a previous
 value, searching and sorting, reading until EOF, pointers. in programs to solve problems)
Assumptions: ()
 All work below was performed by (Jaskaran Chawla) */
#include <iostream>
#include <iomanip>
using namespace std;

int getValidNumAppearances(int);                 //Prototyes
int getValidAvenger(int);
void displayNumAppearances(int *, int);
void ChangeANumAppearances(int *, int);
void displayMaxNumAppearances(int *, int);
void createCumulativeTotalEachRange(int *, int *, int);
void swap(int *, int *);
void displaySortedTotals(int *, int);
int * AddAnotherAvenger(int *numAppearances,int & NUM_AVENGERS);


int main()
{
    int NUM_AVENGERS =173;
    int *numAppearances = new int[NUM_AVENGERS]
            {          //Array of avengers
                    1269, 1165, 3068, 2089, 2402,
                    612, 3458, 1456, 769, 1214,
                    115, 741, 780, 1036, 482,
                    1112, 160, 1886, 332, 557,
                    197, 106, 692, 109, 100,
                    132, 108, 100, 156, 254,
                    935, 576, 141, 355, 933,
                    348, 206, 533, 374, 2,
                    2305, 83, 402, 352, 565,
                    112, 218, 149, 168, 1561,
                    217, 158, 86, 41, 68,
                    70, 61, 2125, 1761, 293,
                    36, 22, 31, 34, 33,
                    4, 47, 7, 3, 16,
                    575, 58, 237, 4333, 126,
                    158, 355, 517, 202, 31,
                    28, 50, 27, 18, 302,
                    330, 101, 43, 126, 24,
                    886, 159, 3130, 241, 67,
                    23, 103, 123, 110, 160,
                    132, 121, 59, 629, 1324,
                    236, 663, 525, 205, 108,
                    359, 299, 333, 88, 369,
                    380, 545, 6, 126, 417,
                    31, 310, 40, 26, 63,
                    2, 73, 22, 153, 73,
                    59, 66, 43, 55, 108,
                    64, 62, 94, 18, 81,
                    1598, 1375, 746, 561, 592,
                    679, 491, 65, 55, 44,
                    65, 877, 176, 24, 25,
                    35, 44, 78, 22, 77,
                    115, 77, 69, 173, 75,
                    12, 14, 13, 198, 29,
                    45, 49, 35
            };
    int * eArray = nullptr;
    eArray = numAppearances;
    int userProgramOption = -1;          //Define variables
    bool whileRunner = true;             //Keeps while loops running until told to quit
    cout << "Welcome to the Avengers program!" <<endl;
    cout <<"1) Display the number of appearances\n"           //choose what program to run
           "2) Change the number of appearances for an Avenger\n"
           "3) Display the max number of appearances\n"
           "4) Create a cumulative total for each number of appearances by ranges, sort and display "
           "these sorted totals\n"
           "5) Add another Avenger\n"
           "6) quit "<<endl;
    cout << "Select an option (1..6)..";
    cin >> userProgramOption;
    while (whileRunner)
        switch (userProgramOption)
        {
            case 1:
                displayNumAppearances(numAppearances, NUM_AVENGERS);
                userProgramOption =-1; //Allows switch statement to keep running
                break;
            case 2:
                ChangeANumAppearances(numAppearances, NUM_AVENGERS);
                userProgramOption =-1;
                break;
            case 3:
                displayMaxNumAppearances(numAppearances, NUM_AVENGERS);
                userProgramOption = -1;
                break;
            case 4:
                displaySortedTotals(numAppearances, NUM_AVENGERS);
                userProgramOption = -1;
                break;
            case 5:
                numAppearances = AddAnotherAvenger(numAppearances, NUM_AVENGERS);
                userProgramOption = -1;
                break;
            case 6:
                whileRunner = false;        //Breaks the loop
                delete [] numAppearances;
                break;
            default:
                while (userProgramOption < 1 || userProgramOption > 5)     //Forces use of the correct input
                {
                    cout << "Select an option (1..5)..";
                    cout <<endl;
                    cin >> userProgramOption;
                }
        }
    return 0;
}

int getValidNumAppearances()
{
    int getUserResponse = -1;
    while (getUserResponse < 1)       //Forces user to give a response greater than one
    {
        cout << "Please enter in a valid Number of Appearances (>=1)"<<endl;
        cin >> getUserResponse;

    }
    return getUserResponse;
}

int getValidAvenger(int NUM_AVENGERS)
{
    int avengerInput = -1;
    while (avengerInput <= 0 || avengerInput > NUM_AVENGERS ) //Forces user to input valid avenger
    {
        cout << "Please enter a valid avenger" <<endl;
        cin >> avengerInput;
    }
    return avengerInput;
}

void displayNumAppearances(int numAppearances[], int NUM_AVENGERS)
{
    for(int i = 0; i < NUM_AVENGERS; i++)       //Goes through the loop to display ever integer
    {
        cout << numAppearances[i] << endl;
    }
}

void ChangeANumAppearances(int numAppearances[], int NUM_AVENGERS)
{
    int avengerNumber = 0, changeNumber = 0;  //Sets variables up for other functions
    cout<< "Change A Number of Appearances"<<endl;
    avengerNumber = getValidAvenger(NUM_AVENGERS);     //calls from other functions
    changeNumber = getValidNumAppearances();


    numAppearances[avengerNumber - 1] = changeNumber;
}

void displayMaxNumAppearances(int numAppearances[], int NUM_AVENGERS)
{
    int maximum = numAppearances[0];
    for(int i = 0; i < NUM_AVENGERS; i++)
    {
        if(maximum < numAppearances[i]) //replaces max with new max
        {
            maximum = numAppearances[i];


        }

    }
    cout << maximum << " is the greatest value\n";

}

void createCumulativeTotalEachRange(int *numAppearances, int NUM_AVENGERS, int * cumulativeTotalEachRange)
{
    int ran = 0;
    for(int i = 0; i < NUM_AVENGERS; i++)         //Fits each number in the numApp. array into there respected group
    {
        if(numAppearances[i] <= 750)
        {
            cumulativeTotalEachRange[0]++;
        }
        else if(numAppearances[i] > 750 && numAppearances[i] <= 1500)
        {
            cumulativeTotalEachRange[1]++;
        }
        else if(numAppearances[i] > 1500 && numAppearances[i] <= 2250)
        {
            cumulativeTotalEachRange[2]++;
        }
        else if(numAppearances[i] > 2250 && numAppearances[i] <= 3000)
        {
            cumulativeTotalEachRange[3]++;
        }
        else if(numAppearances[i] > 3000 && numAppearances[i] <= 3750)
        {
            cumulativeTotalEachRange[4]++;
        }
        else
            cumulativeTotalEachRange[5]++;
    }
}
void displaySortedTotals(int * numAppearances, int NUM_AVENGERS)
{
    int minValue, minIndex;
    int RangeUpperLimitNum[6] = {750,1500,2250,3000,3750,4500};  //establish a joint array
    int * cumulativeTotalEachRange = new int[6]{0,0,0,0,0,0};
    createCumulativeTotalEachRange(numAppearances, NUM_AVENGERS ,cumulativeTotalEachRange);
    for (int i =0; i < (6); i++)        //sorting nested for loops
    {

        minValue = *(cumulativeTotalEachRange + i);
        minIndex = i;
        for(int checker = i +1; checker < 6;checker++) //Checks "minValue" with every other i
        {

            if(minValue > *(cumulativeTotalEachRange + checker)) //if the min value is bigger, the two will swap
            {
                minValue = *(cumulativeTotalEachRange + checker);
                minIndex = checker;
            }

        }
        swap((cumulativeTotalEachRange+ i), (cumulativeTotalEachRange +minIndex)); //Swap both relevant arrays
        swap(&RangeUpperLimitNum[i],&RangeUpperLimitNum[minIndex]);
    }
    cout << "    "<< setw(15) << "Upper Limit Range " << setw(15) <<" Number of Avengers" <<endl;  //formating
    for (int i = 0; i < 6; i++)
    {
        cout <<"   " << setw(17) << *(RangeUpperLimitNum + i) << setw(20) << *(cumulativeTotalEachRange+i) <<endl;
    }
   delete [] cumulativeTotalEachRange;

}
int * AddAnotherAvenger(int *numAppearances, int & NUM_AVENGERS)
{
    int userInput =0;
    int orgSize =NUM_AVENGERS;
    NUM_AVENGERS += 1;
    int *newArray = new int[NUM_AVENGERS];
    cout << "what avenger appearance would you like to add?";
    cin >> userInput;
    for(int i =0;i < (NUM_AVENGERS) ;i++)
    {
        if(i < orgSize)
        {
            *(newArray+ i)=*(numAppearances + i);
        }
        else
            *(newArray+ i) = userInput;

    }
    delete [] numAppearances;
    return newArray;
}





void swap(int * a, int * b)
{
    int temp = *b; //temporary made because b will lose its value
    *b = *a;
    *a = temp;
}

