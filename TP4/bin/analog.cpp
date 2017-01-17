// tp2.cpp : Defines the entry point for the console application.
//

#include <string>
#include <cstring>
#include "CollectionDeLog.h"
#include <iostream>


using namespace std;

int  main(void) {

    char * commande;
    cin >> commande;
    string commandetypes(commande);
    //cout<<commandetypes<<endl;
    //cout<<"here"<<endl;
    const char *condi = "$./analog ";
    int begin = 0;
    begin = commandetypes.find(" ", begin);
    while (begin != -1) {
        commandetypes.replace(begin, 1, "");
        begin = commandetypes.find(" ", begin);
    }
    cout << "commandetypes" << commandetypes << endl;

    if (commandetypes.at(9) == '[') {
        string nomdeficher = commandetypes.substr(commandetypes.find("]") + 1);
        cout << "nomdeficher" << nomdeficher << endl;
       // system("pause");
        int num = commandetypes.find("]") - commandetypes.find("[");
        string option = commandetypes.substr(10, num - 1);
        cout << "option" << option << endl;
      //  system("pause");
        /*string suboption1=option.substr(0,2);
        cout<<"suboption1"<<suboption1<<endl;
        system("pause");
        */
        if (option.find("-g") != -1) {
            int position = option.find(".dot");
            string nomdegraphe = option.substr(option.find("-g"), position + 4);
            cout << "nomdegraphe" << nomdegraphe << endl;
        }

        if (option.find("-t") != -1) {
     //       system("pause");
            string heure11 = option.substr(option.find("-t") + 1, 2);
            cout << heure11 << endl;
            char &heure1 = heure11.at(0);
            char &heure2 = heure11.at(1);
            int time1 = heure1 - '0';
            if (time1 > 2 || time1 < 0) {
                std::cout << "invalide time" << endl;
      //          system("pause");
                return 0;
            }
            int time2 = heure2 - '0';
            if (time1 > 9 || time1 < 0) {
                std::cout << "invalide time" << endl;
        //        system("pause");
                return 0;
            }
            int heure = time1 * 10 + time2;
        }
        if (option.find("-g") != -1 && option.find("-t") == -1 && option.find("-e") == -1) {
        //    CollectionDeLog(nomdeficher, 'g', nomdegraphe);
            //system ("pause");
            return 0;
        }
        if (option.find("-g") != -1 && option.find("-t") != -1 && option.find("-e") != -1) {
      //      CollectionDeLog(nomdeficher, 'e', heure,'g', nomdegraphe);
            //system ("pause");
            return 0;
        }
        if (option.find("-g") != -1 && !option.find("-t") == -1 && option.find("-e") != -1) {

         //   CollectionDeLog(nomdeficher,heure, 'g', nomdegraphe);
            //system ("pause");
            return 0;
        }
        if (option.find("-g") != -1 && option.find("-t") != -1 && option.find("-e") == -1) {
            //CollectionDeLog(nomdeficher, 'e', 'g', nomdegraphe);
            //system ("pause");
            //return 0;
        }
        if (option.find("-g") == -1 && option.find("-t") != -1 && option.find("-e") != -1) {
            //CollectionDeLog(nomdeficher, 'e',heure);
            //system ("pause");
            //return 0;
        }
        if (option.find("-g") == -1 && option.find("-t") == -1 && option.find("-e") != -1) {
            //CollectionDeLog(nomdeficher, 'e');
            //system ("pause");
            //return 0;
        }
        if (option.find("-g") == -1 && option.find("-t") != -1 && option.find("-e") == -1) {
            //CollectionDeLog(nomdeficher,heure);
            //system ("pause");
            //return 0;
        }
        if (option.find("-g") == -1 && option.find("-t") == -1 && option.find("-e") == -1) {
            //CollectionDeLog(nomdeficher);
            //system ("pause");
            //return 0;
        }


    } else {
        string nomdeficher = strstr(commande, " ") + 1;
        cout << "nomdeficher" << nomdeficher << endl;
        //CollectionDeLog(nomdeficher, 'n');

    }


    /*else{

                cout<<"wrong commande"<<endl;
        system ("pause");
        return 0;
    }
    */
   // system("pause");
    return 0;
}