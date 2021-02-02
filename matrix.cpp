#include <iostream>
using namespace std;

// Code to calculate matrix using multiplication and addition.

void multiply() {
    int matrixA[10][10],matrixB[10][10],mul[10][10],row,column,i,j,k;

    cout<<"Enter the number of row: ";
    cin>>row;
    cout<<"Enter the number of column: ";
    cin>>column;
    cout<<"Enter the first matrix element:\n";
    for(i=0; i<row; i++) {
        for(j=0; j<column; j++) {
            cin>>matrixA[i][j];
        }
    }

    cout<<"Enter the second matrix element:\n";
    for(i=0; i<row; i++) {
        for(j=0; j<column; j++) {
            cin>>matrixB[i][j];
        }
    }

    cout<<"Multiplication of the matrix:\n";
    for(i=0; i<row; i++) {
        for(j=0; j<column; j++) {
            mul[i][j]=0;
            for(k=0; k<column; k++) {
                mul[i][j]+=matrixA[i][k]*matrixB[k][j];
            }
        }
    }
    //for printing result
    for(i=0; i<row; i++) {
        for(j=0; j<column; j++) {
            cout<<mul[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void add() {
    int row, column, matrixA[100][100], matrixB[100][100], sum[100][100], i, j;
    cout << "Enter number of rows (between 1 and 100): ";
    cin >> row;
    cout << "Enter number of columns (between 1 and 100): ";
    cin >> column;
    cout<<"Enter the first matrix element:\n";
    for(i=0; i<row; i++) {
        for(j=0; j<column; j++) {
            cin>>matrixA[i][j];
        }
    }

    cout<<"Enter the second matrix element:\n";
    for(i=0; i<row; i++) {
        for(j=0; j<column; j++) {
            cin>>matrixB[i][j];
        }
    }
    // Adding Two matrices
    for(i = 0; i < row; ++i)
        for(j = 0; j < column; ++j)
            sum[i][j] = matrixA[i][j] + matrixB[i][j];
    // Displaying the resultant sum matrix.
    cout << endl << "Sum of two matrix is: " << endl;
    for(i = 0; i < row; ++i)
        for(j = 0; j < column; ++j)
        {
            cout << sum[i][j] << "  ";
            if(j == column - 1)
                cout << endl;
        }
}
int main() {
    int choice;
    char answer;
    do {
        cout<<"What do you want to do?\n";
        cout<<"1. Multiply\n";
        cout<<"2. Add\n";
        cout<<"Answer: ";
        cin>>choice;

        if(choice == 1) {
            cout<<"\nMATRIX MULTIPLICATION\n\n";
            multiply();
        } else if (choice == 2) {
            cout<<"\nMATRIX ADDITION\n\n";
            add();
        } else {
            cout<<"Invalid Input!";
        }
        // Do the user want to try again
        cout<<"\nDo you want to try again? (Y/N)\n";
        cout<<"Answer: ";
        cin>>answer;
        cout<<"\n";
    } while (answer == 'Y' || answer == 'y');
    return 0;
}
