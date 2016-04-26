/*
 * File:   healthNetDriver.c
 * Author: marlin
 *
 * Created on April 24, 2016, 10:07 PM
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "UI.h"

void addUsers();

int displayLogin();

//***NOTE!!***: for an actual implementation a dynamic allocation would be required



/*
 *
 */
int main(int argc, char** argv) {

    addUsers();
    printUsers(doctors);

    //TODO: display login UI here:
    /*
    switch(){
        case 0: //NO login detected login should FAIL
            break;

        case 1: //Doctors case:
            displayDoctorOptions();
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        default: printf("Invalid login status detected: terminating program");
            exit();
            break;
    }
     */

    return (EXIT_SUCCESS);
}



int displayLogin() {

}

