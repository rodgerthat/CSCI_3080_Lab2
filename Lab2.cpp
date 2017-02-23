/*
 * =====================================================================================
 *
 *       Filename:  Lab2.cpp
 *
 *    Description:  Output the tables of truth for wffs in postfix notation
 *
 *        Version:  1.0
 *        Created:  02/08/2017 02:25:48 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Norris, Joel R.
 *          Class: CSCI_3080  
 *        Section: 001
 *     Instructor: Dr. Pettey
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

// variables
const int boolArraySize = 4;
// hard coded truth table values for P and Q
bool P[boolArraySize] = { true, true, false, false };
bool Q[boolArraySize] = { true, false, true, false };
bool A[boolArraySize];  // working array 1
bool B[boolArraySize];  // working array 2  

// function protorypes
void printTruthTable( char logicOperator );
void loadArray( bool *A, bool *B );

// main program ogic
int main() {

    char c;     // holder for incomming chars from cin
    int i=1;    // position counter for postfix entries

    // get a wffs from the user
    cout << "Please input the wff: ";

    // read in each char from user input until enter ('/n') key
    while ( ( c = cin.get() ) != '\n' ) {

        // establish a counter for the postfix position
        // eval first postfix character
        if ( i == 1 ) {
            if ( c == 'P') loadArray( A, P );
            else loadArray( A, Q );
        }

        // evaluate second postfix character
        if ( i == 2 ) {

            if ( c == 'N') {

                printTruthTable( c );
                return 0;

            } else if ( c  == 'P' ) {

                loadArray( B, P);

            } else {

                loadArray( B, Q );
            }
        }
        
        // evaluate third postfix character
        if ( i == 3 ) { 

            printTruthTable( c ); 
        }

        i++;

    }

    return 0;
}

void printTruthTable( char logicOperator ) {

    int i=0;

    switch( logicOperator ) {

        // negation
        case 'N' :

            for (i=0; i<boolArraySize; i++) {
                if ( !A[i] ) cout << "T" << endl;
                else cout << "F" << endl;
            }
            break;

        // AND
        case 'A' :

            for (i=0; i<boolArraySize; i++) {
                if ( A[i] && B[i] ) cout << "T" << endl;
                else cout << "F" << endl;
            }
            break;

        // OR
        case 'O' :
        
            for (i=0; i<boolArraySize; i++) {
                if ( A[i] || B[i] ) cout << "T" << endl;
                else cout << "F" << endl;
            }
            break;
            

        // IMPLIES
        case 'I' : 

            for (i=0; i<boolArraySize; i++) {
                if ( (!A[i]) || B[i] ) cout << "T" << endl;
                else cout << "F" << endl;
            }
            break;

    }

}

// loadArray function to handle assigning P, Q hardcoded arrays to whichever working array
void loadArray( bool *A, bool *B ) {
    
    for (int i=0; i<boolArraySize; i++) A[i] = B[i];

}

