#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void initBoard(){
    fstream init ("dama.dat",ios::out);
    char initialFile[]="                \nw w w w w w w w \nw w w w w w w w \n                \n                \nb b b b b b b b \nb b b b b b b b \n                \nw";

    if(!init){
        cout << "\n*** Cannot open file ***\n" << endl;
    }else{
        cout << "opened successfully" << endl;
        init << initialFile;
    }
    init.close();
    if(init.is_open()==NULL) //error checker, if file still open:
    {
        cout<<"File has been Closed" <<endl;
    }else{
        cout<<" File still Open: "<<endl;
    }
}

void initMoves(){
    fstream initM ("moves.dat", ios::out |ios::trunc);
    initM.close();
}

void recordMove(string turn, string command){
    fstream moves("moves.dat",ios::out | ios::app);
     if(!moves){
        cout << "\n*** Cannot open file ***\n" << endl;
    }else{
        if(turn=="white"){
        moves << "w:" << command << "\n";
        }else{
        moves << "b:" << command << "\n";
        }
    }

}

void printBoard(){
    string line;
    int i=8;
    ifstream board( "dama.dat" );
    if (board)
    {
        cout << "\n";
        while (getline( board, line ))  // same as: while (getline( myfile, line ).good())
        {
            if(i==0){
                cout << " \tA B C D E F G H\n" <<endl;
                break;
            }
            cout << i << "\t" << line << endl;
            i--;
        }
    board.close();
    }
}

//void doMove(string command){
//}

void alternateTurn(string turn){
    fstream outfile;
    outfile.open("dama.dat", ios::in| ios::out |ios::binary);

    outfile.seekp(-1,ios::end);
    if(turn == "white"){
        outfile << "w";
    }else{
        outfile << "b";
    }

    outfile.close();
}

void beginGame(){
    string turn = "white";
    string command ="";
    while(1){
        system("CLS");
        printBoard();
        cout << "Team " << turn << " please enter your command.\n";
        cin >> command;
        recordMove(turn, command);
        if(turn == "white"){
            turn = "black";
        }else{
            turn = "white";
        }
        alternateTurn(turn);
    }
}

int main()
{
    int chosen;

    while(1){
        cout << "Choose:\n1.New game\n2.Continue game\n3.End Game\n";
        cin >> chosen;

        if(chosen==1){
            initBoard();//yeni bir tahta olusturuldu
            initMoves();//hamlelerin olacagi bos bir sayfa acildi

            beginGame();

        }
        else if (chosen==2){

        }

    }




    return 0;
}
