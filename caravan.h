/*----------------------------------------------------------
 *                              HTBLA-Leonding / Klasse: <your class name here>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * File:                        caravan.h
 * Author:                      Peter Bauer
 * Due Date:            #due#
 * ----------------------------------------------------------
 * Description:
 * <Add description>
 * ----------------------------------------------------------
 */
 #ifndef CARAVAN_H
 #define CARAVAN_H

 #include "pack_animal.h"

 Caravan new_caravan();

 int get_length(Caravan caravan);

 void delete_caravan(Caravan caravan);

 void add_pack_animal(Caravan caravan, PackAnimal animal);

 void remove_pack_animal(Caravan caravan, PackAnimal animal);

 int get_caravan_speed(Caravan caravan);

 int get_caravan_load(Caravan caravan);

 void unload(Caravan caravan);

 void optimize_load(Caravan caravan);

 #endif
